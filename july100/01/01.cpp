struct BSTreeNode{
	int m_nValue;
	BSTreeNode *m_pLeft;
	BSTreeNode *m_pRight;
}

struct DoubleList{
	int m_nValue;
	DoubleList *m_pLeft;
	DoubleList *m_pRight;
}

void pre_order_traversal(BSTreeNode* T, DoubleList* L){
	if (T->m_pLeft != NULL)
		pre_order_traversal(T->m_pLeft);

	L->m_nValue = T->m_nValue;


	if (T->m_pRight != NULL)
		pre_orfer_traversal(T->m_pRight);

}
