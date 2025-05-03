#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
	
};
struct node* createNode(int data)
{
	struct node* n =(struct node*)malloc(sizeof(struct node));
	n->data=data;
	n->left=n->right=NULL;
	return n;
}
struct node* buildTree()
{
	int data;
	printf("\n\tEnter data");
	scanf("%d",&data);
	if(data==-1)
		return NULL;
	struct node* root=createNode(data);
	printf("\n\t left child %d :\n",data);
	root->left=buildTree();
	printf("\n\t the right child %d :\n",data);
	root->right=buildTree();
	return root;
	
}
void inOrder(struct node* root)
{
	if(root==NULL)
	{
		
	}
	inOrder(root->left);
	printf("%d",root->data);
	inOrder(root->right);
}
int main()
{
	struct node* root=buildTree();
	inOrder(root);
	printf("\n");
}
