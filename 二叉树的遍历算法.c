#include <stdio.h>
#include <malloc.h>
typedef struct node1{
	char data;
	struct node1 *lchild,*rchild;
}node1,BTCHINALR;   //二叉树的定义

BTCHINALR *createbt()   //还是没有看懂这个二叉树的构建。
{
	BTCHINALR *q;
	struct node1 *s[30];
	int j,i,x;
	printf("建立二叉树，输入结点和对应的编号，编号和值之间用逗号隔开,最后输入0结束\n\n");
	#节点是从1开始的吗，是的
	#典型的例子：1,E 2,A 3,G 5,C 6,F 10,B 11,D
	#先根序遍历:EACBDGF
    #中根序遍历:ABCDEFG
    #后根序遍历:BDCAFGE
	printf("i,x=");
	scanf("%d,%c",&i,&x);
	while(i!=0 && x!='$')
	{
		q=(BTCHINALR*)malloc(sizeof(BTCHINALR)); // malloc 动态分配内存
	    q->data=x;  q->lchild=NULL; q->rchild=NULL;
		s[i]=q;
		if(i!=1)
		{j=i/2;
		if(i%2==0)s[j]->lchild=q;
		else s[j]->rchild=q;}
		printf("i,x=");
		scanf("%d,%c",&i,&x);}
	return s[1];   //这个return s[1]是几个意思。
}

void inorder_notrecursive(BTCHINALR *bt)
/*中序遍历二叉树（非递归算法）还是看不懂这个。*/
{
	BTCHINALR *q,*s[20];
	int top=0;
	int bool=1;
	q=bt;
	do{
		while (q!=NULL)
		{
			top++;s[top]=q; q=q->lchild;}
		if(top==0) bool=0;
		else{q=s[top];
		top--;
		printf("%c  ",q->data);
		q=q->rchild;}
	}
	while(bool);
}

void inorder(BTCHINALR *bt)
//中序遍历二叉树算法（递归算法）
{
	if(bt!=NULL)
	{
		inorder(bt->lchild);
		printf("%c  ",bt->data);
		inorder(bt->rchild);}
}

void preorder(BTCHINALR *bt)
//先序遍历二叉树（递归算法）
{
	if(bt!=NULL)
	{
		printf("%c  ",bt->data);
		preorder(bt->lchild);
		preorder(bt->rchild);}
}

void laorder(BTCHINALR *bt)
//后序遍历二叉树（递归算法）
{
	if(bt!=NULL)
	{
		laorder(bt->lchild);
		laorder(bt->rchild);
		printf("%c  ",bt->data);}
}

//二叉树深度
int treehight(BTCHINALR *bt)
{
	int lh,rh,h;
	if(bt==NULL)
		h=0;
	else
	{
		lh=treehight(bt->lchild);
		rh=treehight(bt->rchild);
		h=(lh>rh?lh:rh)+1;}
	return h;
}

main()
{
	BTCHINALR *bt;
	bt=createbt();

	printf("\n二叉树深度  %d",	treehight(bt));
	printf("\n\n");

    printf("\n先序遍历二叉树 ");
    preorder(bt);
	printf("\n");

	printf("\n中序遍历二叉树 ");
	inorder_notrecursive(bt);
	printf("\n\n");

	printf("\n中序遍历二叉树 ");
	inorder(bt);
	printf("\n");


	printf("\n后序遍历二叉树 ");
	laorder(bt);

        printf("\n");}
