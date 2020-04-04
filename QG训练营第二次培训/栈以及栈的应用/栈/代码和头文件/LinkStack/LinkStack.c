//
// Created by 黄倬熙 on 2020/4/4.
//

#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

Status initLStack(LinkStack *s){//初始化栈
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}
Status isEmptyLStack(LinkStack *s){ //判断是否空栈
    if (s->count){
        printf("非空栈\n");
        return SUCCESS;
    }
    printf("空栈\n");
    return ERROR;
}
Status getTopLStack(LinkStack *s,ElemType *e){//获得栈顶元素值，并赋值给*e
    if (flag==0){//flag用于判断栈是否存在
        printf("你还没创建链栈！\n");
        return ERROR;
    }
    if (!s->count){//判断是否空栈
        printf("空栈\n");
        return ERROR;
    }
    *e = s->top->data;//赋值
    printf("栈顶元素为：%d\n", *e);
    return SUCCESS;
}
Status clearLStack(LinkStack *s){
    if (flag==0){//flag用于判断栈是否存在
        printf("你还没创建链栈！\n");
        return ERROR;
    }
    LinkStackPtr p=s->top, q;
    while (p){ //递归 释放结点
        q = p;
        p = p->next;
        free(q);
    }
    s->count = 0;
    printf("成功！\n");
    return SUCCESS;
}
Status destroyLStack(LinkStack *s){
    if (flag==0){//flag用于判断栈是否存在
        printf("你还没创建链栈！\n");
        return ERROR;
    }
    clearLStack(s);//释放内存空间
    free(s);
    flag = 0;
    return SUCCESS;
}
Status LStackLength(LinkStack *s,int *length){
    *length = s->count; //赋值
    return SUCCESS;
}
Status pushLStack(LinkStack *s,ElemType data){//入栈
    LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));//生成结点
    p->data = data;//赋值
    p->next = s->top;//连接
    s->top = p;//指向栈顶元素
    s->count++;//长度+1
    return SUCCESS;
}
Status popLStack(LinkStack *s,ElemType *data){//出栈
    if (!s->count)//判断空栈
        return ERROR;
    LinkStackPtr p=s->top;
    *data = s->top->data;//赋值
    s->top = s->top->next;//连接
    free(p);//释放内存空间
    s->count--;
    return SUCCESS;
}

void traverse(LinkStack *s){
    if (flag==0){//flag用于判断栈是否存在
        printf("你还没创建链栈！\n");
        return;
    }
    if (s->count==0){//判断空栈
        printf("空栈！\n");
        return;
    }
    LinkStackPtr p = s->top;
    printf("栈顶");
    while (p){//遍历
        printf("--%d",p->data);
        p = p->next;
    }
    printf("--栈底\n");
}
int input(int min, int max){
    float num;
    int check = scanf("%f", &num);
    fflush(stdin);//释放输入后的回车，以免被循环中的scanf读取
    while (check!=1){
        printf("师兄不要乱输啦！请重新输入：\n");
        check = scanf("%f", &num);
        fflush(stdin);
    }
    num = (int)num;//强制类型转换，栈内元素类型为int
    if (num < min){
        printf("太小啦！自动取范围内最小值\n");
        return min;
    } else if (num >max){
        printf("太大啦！自动取范围内最大值\n");
        return max;
    }
    return num;
}
void screen(){//打印界面
    system("cls");//清屏函数
    printf("╔════════════════════════════════════════════════════╗\n");
    printf("║                   数据挖掘 黄倬熙                  ║\n");
    printf("║*********            1.初始化栈            *********║\n");
    printf("║*********            2.查询栈长            *********║\n");
    printf("║*********            3.遍历链栈            *********║\n");
    printf("║*********            4.清空链栈            *********║\n");
    printf("║*********            5.摧毁链栈            *********║\n");
    printf("║*********            6.数据入栈            *********║\n");
    printf("║*********            7.数据出栈            *********║\n");
    printf("║*********            8.查询栈顶            *********║\n");
    printf("║*********            9.清空屏幕            *********║\n");
    printf("║*********            0.退出程序            *********║\n");
    printf("╚════════════════════════════════════════════════════╝\n");
}
void init(){//初始化操作汇总
    if (flag == 1){
        printf("链栈已存在！\n");
        return;
    }
    stack = (LinkStack*)malloc(sizeof(LinkStack));//申请内存空间
    initLStack(stack);
    flag = 1;//标记栈已生成
    printf("成功！\n");
}
void find_length(){//获得栈容量
    if (flag==0){//判断是否生成栈 
        printf("你还没创建链栈！\n");
        return;
    }
    int length;
    LStackLength(stack, &length);
    printf("您的栈长为：%d\n",length);
}
void add(){//入栈操作
    if (flag==0){
        printf("你还没创建链栈！\n");
        return;
    }
    printf("入栈多少个数据？：");
    int n = input(1, 2147483647);//统计需要入栈多少个元素
    for (int i = 0; i < n; ++i) {
        printf("请输入数据：");
        int data = input(-2147483647, 2147483647);
        pushLStack(stack, data);//入栈函数
        printf("成功！\n");
    }
}
void pop(){
    if (flag==0){
        printf("你还没创建链栈！\n");
        return;
    }
    if (!stack->count){//判断是否空栈
    	printf("空栈无元素可以出栈！\n");
		return; 
	}
    printf("出栈多少个数据？：");
    int n = input(1, stack->count);//统计出栈元素个数
    for (int i = 0; i < n; ++i) {
        int data;
        popLStack(stack, &data);//出栈函数
        printf("%d已成功出栈\n", data);
    }
}
