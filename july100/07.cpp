// 判断单链表是否有环
#include <iostream>
using namespace std;
int main(){
}

class slist{
	struct Node{
		int data;
		Node *next;
	};
}

bool isExistLoop(slist *head){
	slist *slow = head, *fast = head;
	while(fast && fast->next != null){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			break;
		}
	}
	return !(fast == NULL || fast->next == NULL)
}
