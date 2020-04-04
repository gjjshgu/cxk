//
// Created by 黄倬熙 on 2020/4/4.
//
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status
{
    ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack
{
    ElemType *elem;
    int top; //栈顶索引和元素个数
    int size; //栈的最大容量
} SqStack;
int flag = 0;SqStack *stack;

//基于数组的顺序栈
Status initStack(SqStack *s,int sizes);//初始化栈
Status isEmptyStack(SqStack *s);//判断栈是否为空
Status getTopStack(SqStack *s,ElemType *e); //得到栈顶元素
Status clearStack(SqStack *s);//清空栈
Status destroyStack(SqStack *s);//销毁栈
Status stackLength(SqStack *s,int *length);//检测栈长度
Status pushStack(SqStack *s,ElemType data);//入栈
Status popStack(SqStack *s,ElemType *data);//出栈
//自己创建的函数
void traverse(SqStack *s);//从栈底开始遍历
int input(int min, int max);//防崩溃输入
void screen();//绘制界面
void init();//初始化
void find_length();//获得栈长
void add();//入栈
void pop();//出栈
#endif