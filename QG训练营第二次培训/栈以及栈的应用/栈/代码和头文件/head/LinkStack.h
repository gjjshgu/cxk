//
// Created by 黄倬熙 on 2020/4/4.
//

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status
{
    ERROR = 0,
    SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
    ElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
    LinkStackPtr top;
    int	count;
}LinkStack;
int flag = 0;
LinkStack *stack;



//链栈
Status initLStack(LinkStack *s);//初始化栈
Status isEmptyLStack(LinkStack *s);//判断栈是否为空
Status getTopLStack(LinkStack *s,ElemType *e);//得到栈顶元素
Status clearLStack(LinkStack *s);//清空栈
Status destroyLStack(LinkStack *s);//销毁栈
Status LStackLength(LinkStack *s,int *length);//检测栈长度
Status pushLStack(LinkStack *s,ElemType data);//入栈
Status popLStack(LinkStack *s,ElemType *data);//出栈
//自己创建的函数
void traverse(LinkStack *s); //从栈顶开始遍历
int input(int min, int max); //防崩溃输入
void screen(); //绘制界面
void init();//初始化
void find_length();//获得栈长
void add(); //入栈
void pop(); //出栈
#endif