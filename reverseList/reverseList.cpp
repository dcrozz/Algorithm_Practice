//Reverse a linked list in two ways

typedef struct Node
{
	int val;
	struct Node *next;
}Node;

int main()
{

	Node *p1,*p2,*p3;
	p1 = root;
	p2 = root->next;
	p3 = p2.next;

	p2.next = p1;
	p1 = p2;
	p2 = p3;
	p3 = p3.next;
}
