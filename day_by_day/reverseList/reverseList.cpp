//Reverse a linked list in two ways

typedef struct LNode
{
	int val;
	struct LNode *next;
}LNode, *LinkedList;

//Method 1, create a new linked list

LinkedList ReverseList(LinkedList list)
{
	LinkedList newList;
	LNode *tmp;

	if(list == NULL || (newList = (LinkedList)malloc(sizeof(LNode)))==NULL)
	{
		return NULL;
	}

	newList->data = list->data;
	newList->next = NULL;

	while(list->next != NULL)
	{
		tmp = newList;
		newList = list->next;
		newList->next = tmp;
		list->next = list->next->next;
	}

	free(list);
	return newList;
}

Node *reverseList (List head)
{
	Node *pnow = head;
	Node *pre = NULL;
	Node *pnext = NULL;
	Node *tail = NULL; //定义尾指针

	while(pnow != NULL)
	{
		pnext = pnow->next;
		if( pnext != NULL)
		{
			tail = pnow;
		}
		pnow->next = pre;
		pre = pnow;
		pnow = pnext; //往后一个，下一次循环时给pnext赋值往后一个
	}
	return tail;
}

//递归实现

Node *reverseList(List head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	else
	{
		Node *tmp = reverseList(head->next);
		// tmp->next = head; 不对啊擦

		head->next->next = head;
		head->next = NULL;

		return tmp;
	}
}
