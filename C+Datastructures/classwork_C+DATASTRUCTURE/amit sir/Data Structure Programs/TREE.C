#include<stdio.h>
typedef struct node
{
	struct node *left;
	int n;
	struct node *right;
}NODE;
typedef struct btree
{
	NODE *root;
}BTREE;
void initializetree(BTREE *t)
{
	t->root=NULL;
}
int treeempty(BTREE *t)
{
	if(t->root==NULL)
		return 1;
	else
		return 0;
}
int treefull()
{
	NODE *new;
	new=(NODE *)malloc(sizeof(NODE));
	if(new==NULL)
		return 1;
	else
	{
		free(new);
		return 0;
	}
}
int addnode(BTREE *t,int x)
{
	NODE *new,*t1,*t2;
	if(!treefull())
	{
		new=(NODE *)malloc(sizeof(NODE));
		new->left=new->right=NULL;
		new->n=x;
		if(t->root==NULL)
			t->root=new;
		else
		{
			t1=t2=t->root;
			while(t1!=NULL)
			{
				if(new->n>t1->n)
				{
					t2=t1;
					t1=t1->right;
				}
				else
					if(new->n<t1->n)
					{
						t2=t1;
						t1=t1->left;
					}
					else
					{
						free(new);
						return 0;
					}
			}
			if(new->n>t2->n)
				t2->right=new;
			else
				t2->left=new;
		}
		return 1;
	}
	else
		return 0;
}
void displayinorder(NODE *t)
{
	if(t!=NULL)
	{
		displayinorder(t->left);
		printf("\n%d",t->n);
		displayinorder(t->right);
	}
}
void inorder(BTREE *t)
{
	displayinorder(t->root);
}
void displaypreorder(NODE *t)
{
	if(t!=NULL)
	{
		printf("\n%d",t->n);
		displaypreorder(t->left);
		displaypreorder(t->right);
	}
}
void preorder(BTREE *t)
{
	displaypreorder(t->root);
}
void displaypostorder(NODE *t)
{
	if(t!=NULL)
	{
		displaypreorder(t->left);
		displaypreorder(t->right);
		printf("\n%d",t->n);
	}
}
void postorder(BTREE *t)
{
	displaypostorder(t->root);
}
int searchnode(BTREE *t,int x)
{
	NODE *t1=t->root;
	while(t1!=NULL && t1->n!=x)
	{
		if(t1->n>x)
			t1=t1->left;
		else
			t1=t1->right;
	}
	if(t1==NULL)
		return 0;
	else
		return 1;
}
int modifynode(BTREE *t,int x,int y)
{
	if(searchnode(t,x) && !searchnode(t,y))
	{
		deletenode(t,x);
		addnode(t,y);
		return 1;
	}
	else
		return 0;
}
int deletenode(BTREE *t,int x)
{
	NODE *t1,*t2;
	if(!searchnode(t,x))
		return 0;
	t1=t2=t->root;
	while(t1->n!=x)
	{
		if(x>t1->n)
		{
			t2=t1;
			t1=t1->right;
		}
		else
		{
			t2=t1;
			t1=t1->left;
		}
	}
	if(t1->left==NULL && t1->right==NULL)
	{
		if(t1==t->root)
			t->root=NULL;
		else
		{
			if(t1->n>t2->n)
				t2->right=NULL;
			else
				t2->left=NULL;
		}
	}
	else
		if(t1->left==NULL && t1->right!=NULL)
		{
			if(t1==t->root)
				t->root=t1->right;
			else
			{
				if(t1->n>t2->n)
					t2->right=t1->right;
				else
					t2->left=t1->right;
			}
		}
		else
			if(t1->left!=NULL && t1->right==NULL)
			{
				if(t1==t->root)
					t->root=t1->left;
				else
				{
					if(t1->n>t2->n)
						t2->right=t1->left;
					else
						t2->left=t1->left;
				}
			}
			else
				if(t1->left!=NULL && t1->right!=NULL)
				{
					if(t1==t->root)
						t->root=t->root->right;
					else
					{
						if(t1->n<t2->n)
							t2->left=t1->right;
						else
						              t2->right=t1->right;
					}
					t2=t1->right;
					while(t2->left!=NULL)
						t2=t2->left;
					t2->left=t1->left;
				}
		free(t1);
		return 1;
}
main()
{
	BTREE T;
	int ch=0,x,y;
	initializetree(&T);
	while(ch!=8)
	{
		clrscr();
		puts("1. add node");
		puts("2. inorder display");
		puts("3. preorder display");
		puts("4. postorder display");
		puts("5. search node");
		puts("6. modify node");
		puts("7. delete node");
		puts("8. exit");
		printf("enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter element:");
				   scanf("%d",&x);
				   if(addnode(&T,x))
						printf("node added");
				   else
						printf("node cannot be added");
				   break;
			case 2:inorder(&T);
				   break;
			case 3:preorder(&T);
				   break;
			case 4:postorder(&T);
				   break;
			case 5:printf("enter the no. to search:");
				   scanf("%d",&x);
				   if(searchnode(&T,x))
						printf("element found");
				   else
						printf("element not found");
				   break;
			case 6:printf("enter the no. to modify:");
				   scanf("%d",&y);
				   printf("enter the new no.:");
				   scanf("%d",&y);
				   if(modifynode(&T,x,y))
						printf("node modified");
				   else
						printf("node cannot be modified");
				   break;
			case 7:printf("enter the no. to deleted:" );
				   scanf("%d",&x);
				   if(deletenode(&T,x))
						printf("node deleted");
				   else
						printf("node cannot be deleted");
				   break;
		}
	
}
}
