#include <stdio.h>
#include <sys/malloc.h>
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
   /*
    #节点是从1开始的吗，是的
     #典型的例子：1,E 2,A 3,G 5,C 6,F 10,B 11,D
    E
A        G
   C    F
 B   D
     #先根序遍历:EACBDGF
     #中根序遍历:ABCDEFG
     #后根序遍历:BDCAFGE
    */
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

//为什么不能用preorder 这个词呢，是关键词吗？
void preorder_0(BTCHINALR *bt)
//先序遍历二叉树（递归算法）
{
    if(bt!=NULL)
    {
        printf("%c  ",bt->data);
        preorder_0(bt->lchild);
        preorder_0(bt->rchild);
}
}

int i=0;
void preorder_2(BTCHINALR *bt)
//先序遍历二叉树（递归算法）
{
    if(bt!=NULL)
    {
        printf("%c  ",bt->data);
        preorder_2(bt->lchild);
        preorder_2(bt->rchild);
        if(bt->lchild ==NULL || bt->rchild ==NULL) ++i;
        printf("i的值为%d",i);
}
}

//计算非叶子节点的个数  使用*(count)++;得不到正确的结果(想想为什么)
void PreOrder_3(BTCHINALR *root,int *count)
{ if(root!=NULL)
{    if(root->lchild!=NULL || root->rchild!=NULL){
    //*(count)++;
    ++*(count);
}
             PreOrder_3(root->lchild,count);
             PreOrder_3(root->rchild,count);
}
}

//自己改编的计算叶子节点个数
//这个函数可以得到正确的结果，但是不知道为什么使用*(count)++时，得到的结果为0
void PreOrder_4(BTCHINALR *root,int *count)
{ if(root!=NULL)
{    if(NULL ==root->lchild && NULL == root->rchild){
    //*(count)++;
    ++*(count);
}
             PreOrder_4(root->lchild,count);
             PreOrder_4(root->rchild,count);
}
}






//计算非叶子节点的个数，自己有些好奇，第二个return 0 是跳出程序，还是把0这个值返回给递归调用。我想应该是后者。
int NoLeafCount(BTCHINALR *bt){
    if(NULL== bt)//空树 为什么空树是这样写呢
        return 0;
    else if(NULL == bt->lchild && NULL == bt->rchild) //叶子节点
        return 0;
    else
        return (1+NoLeafCount(bt->lchild)+NoLeafCount(bt->rchild));
}


//叶子节点的个数的算法
int LeafCount_2(BTCHINALR *bt){
    if(NULL== bt)//空树 为什么空树是这样写呢
        return 0;
    if(NULL == bt->lchild && NULL == bt->rchild)
        return 1;
    return (LeafCount_2(bt->lchild)+LeafCount_2(bt->rchild));;
}

//自己改编计算叶子节点的个数
//网上的代码，仔细想想上面自己的改编错误在哪里，碰到第一个节点为非叶子节点，直接return 0了。
int LeafCount(BTCHINALR *bt){
    if(NULL== bt)//空树 为什么空树是这样写呢
        return 0;
    else if(NULL != bt->lchild || NULL != bt->rchild) //非叶子节点
        return 0;
    else
        return (1+LeafCount(bt->lchild)+LeafCount(bt->rchild));
}

//自己改编的非叶子节点个数 (同样是错误的，结果是1)
int NoLeafCount_2(BTCHINALR *bt){
    if(NULL== bt)//空树 为什么空树是这样写呢
        return 0;
    else if(NULL != bt->lchild || NULL != bt->rchild) //非叶子节点
        return 1;
    else
        return (LeafCount(bt->lchild)+LeafCount(bt->rchild));
}



//递归练习，求n的阶乘
int recursive(int n){
    if(n==1) return 1;
    else return n*recursive(n-1);
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


void leave_num(BTCHINALR *bt)
//计算叶子节点的个数
{
    int i=0;
    if(bt==NULL) i=0;
    else
    if(bt->lchild==NULL || bt->rchild==NULL)
        ++i;
    
        printf("%c  ",bt->data);
}


//二叉树深度
//还是没有理解这个递归的含义，最终的结果到底有多少个lh和rh呢，为什么只比较两个呢
int treehight(BTCHINALR *bt)
{
    int lh,rh,h;
    if(bt==NULL)
        h=0;
    else
    {
        lh=treehight(bt->lchild);
        printf("lh:bt->lchild:%c  ",bt->data);
        printf("lh:%d \n",lh);
        rh=treehight(bt->rchild);
        printf("rh:bt->rchild:%c ",bt->data);
        printf("rh:%d \n",rh);
        h=(lh>rh?lh:rh)+1;}
        printf("h:%d ",h);
    return h;
}


int fibo(int n){

    if(n==1 || n==2)
    return 1;
    else return fibo(n-1)+fibo(n-2);
    
}


main()
{
    BTCHINALR *bt;
    bt=createbt();
    
    printf("斐波那契数列的结果为:%d\n",fibo(15));

    printf("\n二叉树深度  %d",    treehight(bt));
    printf("\n\n");

    printf("\n先序遍历二叉树 ");
    preorder_0(bt);
    printf("\n");

    printf("\n中序遍历二叉树 ");
    inorder_notrecursive(bt);
    printf("\n\n");

    printf("\n中序遍历二叉树 ");
    inorder(bt);
    printf("\n");


    printf("\n后序遍历二叉树 ");
    laorder(bt);

        printf("\n");
    
    int count=0;
    PreOrder_3(bt, &count);
    printf("PreOrder_3二叉树非叶子节点的个数为:%d \n",count);
    
    int PreOrder_4_count=0;
     PreOrder_4(bt, &PreOrder_4_count);
     printf("PreOrder_4二叉树叶子节点的个数为:%d \n",PreOrder_4_count);
     
    
    
    int a=NoLeafCount(bt);
    printf("二叉树非叶子节点的个数为:%d \n",a);
    
    int b=LeafCount(bt);
     printf("二叉树叶子节点的个数为:%d \n",b);
    
    int c=LeafCount_2(bt);
      printf("二叉树叶子节点的个数为:%d \n",c);
    
    int d=recursive(5);
    printf("阶乘的结果为:%d \n",d);
    
    printf("自己改编的非叶子节点个数为:%d \n",NoLeafCount_2(bt));
}
