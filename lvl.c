#include<stdio.h>
#include<stdlib.h>
#define N 20

//struture data type for binary tree
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

//creating binary tree
struct node* createnode(int data)
{
	struct node* root;
	root= (struct node*)malloc(sizeof(struct node));
	if(root==NULL)
	{
		printf("Invalid memory allocation\n");
		exit(1);
	}

	root->data= data;
	root->left=NULL;
	root->right=NULL;

    return root;

}


void levelorder(struct node* root)
{
	struct node* q[N];
	struct node* cur;
    
    int front=0;
    int rear=-1;  //queue is empty

   if(root==NULL)
   	return;
   q[++rear]= root; //rear=0
   while(front<=rear)
   {
   		cur=q[front++];
   		printf("%d ",cur->data);

   		if(cur->left!=NULL)
   			q[++rear]=cur->left;
   		if(cur->right!=NULL)
   			q[++rear]=cur->right;

   }
      printf("\n");

}


int main()
{
	struct node* root;
	root=NULL;

	 root=createnode(5);
	 root->left=createnode(11);
	 root->right=createnode(12);
	 root->left->left=createnode(65);
	 root->left->right=createnode(6);

	 levelorder(root);

}