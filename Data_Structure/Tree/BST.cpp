//问题1，不知道怎么声明新的空间
//问题2，typedef还是不知道该什么时候用
//问题3，命名规范性
//&root->data 这是什么啊
#include<stdio.h>
#include<stdlib.h>//malloc需要这个

struct BSTNode
{
	int data;
	BSTNode *left;
	BSTNode *right;
};

BSTNode* searchNode( BSTNode *root, int num )
{
	if( root == NULL )
	{
		// return Error("can not find");
		printf("no such node");
		return NULL;
	}
	else
	{
		if (root->data == num) return root;
		else if ( root-> data < num ) return searchNode( root->right, num );
		else return searchNode(root->left, num);
	}
}

BSTNode* insertTree( BSTNode  *root, int num )
{
	if( root == NULL) 
	{
		/*IMPORTANT*/
		root = (BSTNode*)malloc(sizeof(struct BSTNode));//注意这边要强转，还有这边的写法
		// if(root == NULL) perror("out of space!!");//注意这边的Error
		// else
		{
			root-> data = num;
			root-> left = NULL;
			root-> right = NULL;
		}
	}
	if(root->data > num)
		// insertTree( root-> right, num );
		// 之前这样写就没连起来
		root-> left = insertTree(root->left,num);
	else if(root-> data < num)
		root-> right = insertTree( root-> right, num );
	return root;//注意是写在最后
}

void printTree( BSTNode *root )
{

	if(root == NULL) return;
	else
	{
		printf("%d",root->data);
	}
	if(root->left != NULL)
	{
		printTree(root->left);
	}
	else if(root->right != NULL)
	{
		printTree(root->right);
	}


}

int main()
{
	// int length;
	// scanf("%d",&length);
	BSTNode *root = NULL;
	insertTree( root,1 );
	insertTree( root,2 );
	insertTree( root,3 );
	insertTree( root,4 );
	printf("ok");
	// int data;
	// for (int i = 0; i < length; i++)
	// {
	//     scanf("%d",&data);
	//     insertTree( root, data );
	// }
	// printf("%d",length); //不知道为什么后面还有个%
	// printTree(root);
}
