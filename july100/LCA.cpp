//july的暴力解法，只适合于一次查询
node* getLCA(node* root, node* node1, node* node2)
{
	if (root == NULL) return NULL;
	if (root == node1 || root == node2) return root; //根节点为其中一个节点，则该节点为公共节点
	node* left = getLCA(root->left, node1, node2);//左子树是否包含待查找节点
	node* right = getLCA(root->right, node1, node2);

	if (left != NULL && right != NULL) //左右都包含待查找节点，则该节点为公共父节点
		return root;
	else if (left != NULL)
		return left;
	else if (right != NULL)
		return right;
	else
		return NULL;
}


// tarjan算法
