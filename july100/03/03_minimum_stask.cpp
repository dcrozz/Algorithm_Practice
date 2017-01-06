#include<stdio.h>
#include<iostream>
#include<stack>

using namespace std;

typedef struct
{
	stack<int> elements;
	stack<int> minStack;
	void push(int x)
	{
		elements.push(x);
		// if (!minStack.empty() && x <= minStack.top())  //应该是最小栈为空
		if ( minStack.empty() || x <= minStack.top())
		{
			minStack.push(x);
		}
	}
	// void pop()
	bool pop()
	{
		if (elements.empty()) return false;
		if (elements.top() == minStack.top())
		{
			minStack.pop();
		}
		elements.pop();
		return true;
	}
	bool getMin(int &min)
	{
		if(minStack.empty()) 
		{
			return false;
		}
		else
		{
			min =  minStack.top();
			return true;
		}
	}

}min_stack;

int main()
{
	min_stack stackMin;
	stackMin.push(2);
	stackMin.push(6);
	stackMin.push(10);
	stackMin.push(6);
	stackMin.push(6);
	stackMin.push(6);
	int min = 0;
	stackMin.getMin(min);
	cout<< min;
	getchar();
	return 0;

}
