//
// Created by 黄倬熙 on 2020/4/4.
//

#include "SqStack.h"
#include <stdlib.h>
#include <stdio.h>

Status initStack(SqStack *s,int sizes){
    s->elem = (ElemType*)malloc(sizeof(ElemType)*sizes);
    if (!s->elem)
        return ERROR;
    s->top = -1;
    s->size = sizes;
    return SUCCESS;
}
Status isEmptyStack(SqStack *s){
    if (!s->size){
        printf("空栈！");
        return SUCCESS;
    }
    printf("非空栈");
    return ERROR;
}
Status getTopStack(SqStack *s,ElemType *e){
    if (flag==0){
        printf("你还没创建栈！\n");
        return ERROR;
    }
    if (!(s->top+1)){
        printf("空栈！\n");
        return ERROR;
    }
    *e = s->elem[s->top];
    printf("栈顶元素为%d\n", *e);
    return SUCCESS;
}
Status clearStack(SqStack *s){
    if (flag==0){
        printf("你还没创建栈！\n");
        return ERROR;
    }
    s->top = -1;
    printf("成功\n");
    return SUCCESS;

}
Status destroyStack(SqStack *s){
    if (flag==0){
        printf("你还没创建栈！\n");
        return ERROR;
    }
    free(s->elem);
    free(s);
    flag = 0;
    printf("成功！\n");
    return SUCCESS;
}
Status stackLength(SqStack *s,int *length){
    *length = s->top + 1;
    return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data){
//    if (s->top == max){
//        printf("栈已满！\n");
//        return ERROR;
//    }
    s->elem[s->top+1] = data;
    s->top++;
    return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data){
    *data = s->elem[s->top];
    s->top--;
    return SUCCESS;
}
void traverse(SqStack *s){
    if (flag==0){
        printf("你还没创建栈！\n");
        return;
    }
    if (!(s->top+1)) {
        printf("空栈！\n");
        return;
    }
    printf("栈底--");
    for (int i = 0; i < s->top+1; ++i) {
        printf("%d--", s->elem[i]);
    }
    printf("栈顶\n");
}
int input(int min, int max){
    float num;
    int check = scanf("%f", &num);
    fflush(stdin);
    while (check!=1){
        printf("师兄不要乱输啦！请重新输入：\n");
        check = scanf("%f", &num);
        fflush(stdin);
    }
    num = (int)num;
    if (num < min){
        printf("太小啦！自动取范围内最小值\n");
        return min;
    } else if (num >max){
        printf("太大啦！自动取范围内最大值\n");
        return max;
    }
    return num;
}
void screen(){
    system("cls");
    printf("╔════════════════════════════════════════════════════╗\n");
    printf("║                   数据挖掘 黄倬熙                  ║\n");
    printf("║*********            1.初始化栈            *********║\n");
    printf("║*********            2.查询栈长            *********║\n");
    printf("║*********            3.遍历此栈            *********║\n");
    printf("║*********            4.清空此栈            *********║\n");
    printf("║*********            5.摧毁此栈            *********║\n");
    printf("║*********            6.数据入栈            *********║\n");
    printf("║*********            7.数据出栈            *********║\n");
    printf("║*********            8.查询栈顶            *********║\n");
    printf("║*********            9.清空屏幕            *********║\n");
    printf("║*********            0.退出程序            *********║\n");
    printf("╚════════════════════════════════════════════════════╝\n");
}
void init(){
    if (flag == 1){
        printf("栈已存在！\n");
        return;
    }
    stack = (SqStack*)malloc(sizeof(SqStack));
    printf("请输入栈的最大容量：");
    int n = input(1, 2147483647);
    initStack(stack, n);
    flag = 1;
    printf("成功！\n");
}
void find_length(){
    if (flag==0){
        printf("你还没创建栈！\n");
        return;
    }
    int length;
    stackLength(stack, &length);
    printf("栈的元素个数为：%d\n栈的最大容量为：%d\n", length, stack->size);
}
void add(){
    if (!flag){
        printf("你还没创建栈！\n");
        return;
    }
    printf("入栈多少个数据？：");
    int n = input(1, stack->size-stack->top-1);
    for (int i = 0; i < n; ++i) {
        printf("请输入数据：");
        int data = input(-2147483647, 2147483647);
        pushStack(stack, data);
        printf("成功！\n");
    }
}
void pop(){
    if (!flag){
        printf("你还没创建栈！\n");
        return;
    }
    if (!(stack->top+1)){
        printf("空栈！\n");
        return;
    }
    printf("出栈多少个数据？：");
    int n = input(1, stack->top+1);
    for (int i = 0; i < n; ++i) {
        int data;
        popStack(stack, &data);
        printf("%d已成功出栈\n", data);
    }
}

