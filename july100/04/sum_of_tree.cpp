#include<stdio.h>
#include<iostream>

struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;
}

void printPath( TreeNode * root, int sum)
{
	int path[MAX_HEIGHT];
	helper(root,sum,path,0);
}

void helper( TreeNode * root, int sum, int path[], int top)
{
	path[top++] = root.data;
	sum -= root.data;
	if(root->left == NULL && root->right == NULL)
	{
		if( sum == 0 ) return printPath(path, top);
	}
	else
	{
		if (root->left != NULL) helper(root->left, sum, path, top);
		if (root->right!= NULL) helper(root->right, sum, path, top);
	}
	top--;
	sum += root.data;
}
