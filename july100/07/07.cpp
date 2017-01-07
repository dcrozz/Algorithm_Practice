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

//判断有没有环,
bool isExistLoop(slist *head){
	slist *slow = head, *fast = head;
	while(fast && fast->next != null){ //为什么fast 和后面的节点同时不为null
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			break;
		}
	}
	return !(fast == NULL || fast->next == NULL) //return一个bool表达式更加高效一点
}

//判断入口
slist* getEntry(slist *head){
	slist *slow = head, *fast = head;
	while(fast && fast->next != null){ //为什么fast 和后面的节点同时不为null
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			break;
		}
	}
	if(fast == NULL || fast->next == NULL){
		return NULL;
	} 
	
	slow = head;

	// 我原来的代码真垃圾
	// while(1){
	while(slow != fast)
		slow = slow->next;
		fast = fast->next;
		// if(slow == fast){
		//     break;
		// }
	}
	return slow;


}
