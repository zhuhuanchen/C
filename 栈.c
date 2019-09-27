#include <stdio.h>
#include <malloc.h>

#顺序栈
typedef struct SqStack
{
    int data[maxSize]; //实际上这是一个数组
    int top;   //书本上写的是栈顶指针，我觉得实际上应该是数组第一个元素地方
}SqStack;

#链栈
typedef struct LNode
{
    int data;    //数据域
    struct LNode *next;  //指针域
}LNode;   //链栈的定义


#初始化栈(顺序栈)
#初始化栈，只需要将栈顶指针置为-1即可
void initStack(SqStack &st) {   //初始化栈
  st.top=-1;
}

#判断栈空的代码
#栈为空的时候返回1，否则返回0，
int isEmpty(SqStack &st){
    if(st.top==-1)
        return 1;
    else
        return 0;

}

#进栈代码
int push(SqStack &st,int x){
    if(st.top==maxSize-1){
        return 0;
    }
    st.top++;  //先移动指针再进栈
    st.data[st.top]=x;
    return 1;
}


#出栈代码
int pop(SqStack &st,int &x){
    if(st.top==-1){
        return 0;
    }
    x=st.data[st.top];  //先取出元素，再移动指针
    st.top--;   //书上的例子是--st.top
    return 1;
}





