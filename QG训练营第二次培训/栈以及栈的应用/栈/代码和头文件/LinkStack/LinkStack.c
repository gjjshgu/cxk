//
// Created by 黄倬熙 on 2020/4/4.
//

#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

Status initLStack(LinkStack *s){
//    s->top = (LinkStackPtr)malloc(sizeof(StackNode));
//    if (!s->top) return ERROR;
    s->top = NULL;
    s->count = 0;
//    s->top->next=NULL;
    return SUCCESS;
}
Status isEmptyLStack(LinkStack *s){
    if (s->count){
        printf("非空栈\n");
        return SUCCESS;
    }
    printf("空栈\n");
    return ERROR;
}
Status getTopLStack(LinkStack *s,ElemType *e){
    if (flag==0){
        printf("你还没创建链栈！\n");
        return ERROR;
    }
    if (!s->count){
        printf("空栈\n");
        return ERROR;
    }
    *e = s->top->data;
    printf("栈顶元素为：%d\n", *e);
    return SUCCESS;
}
Status clearLStack(LinkStack *s){
    if (flag==0){
        printf("你还没创建链栈！\n");
        return ERROR;
    }
    LinkStackPtr p=s->top, q;
    while (p){
        q = p;
        p = p->next;
        free(q);
    }
    s->count = 0;
    printf("成功！\n");
    return SUCCESS;
}
Status destroyLStack(LinkStack *s){
    if (flag==0){
        printf("你还没创建链栈！\n");
        return ERROR;
    }
    clearLStack(s);
    free(s);
    flag = 0;
    return SUCCESS;
}
Status LStackLength(LinkStack *s,int *length){
    *length = s->count;
    return SUCCESS;
}
Status pushLStack(LinkStack *s,ElemType data){
    LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));
    p->data = data;
    p->next = s->top;
    s->top = p;
    s->count++;
    return SUCCESS;
}
Status popLStack(LinkStack *s,ElemType *data){
    if (!s->count)
        return ERROR;
    LinkStackPtr p=s->top;
    *data = s->top->data;
    s->top = s->top->next;
    free(p);
    s->count--;
    return SUCCESS;
}

void traverse(LinkStack *s){
    if (flag==0){
        printf("你还没创建链栈！\n");
        return;
    }
    if (s->count==0){
        printf("空栈！\n");
        return;
    }
    LinkStackPtr p = s->top;
    printf("栈顶");
    while (p){
        printf("--%d",p->data);
        p = p->next;
    }
    printf("--栈底\n");
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
void init(){
    if (flag == 1){
        printf("链栈已存在！\n");
        return;
    }
    stack = (LinkStack*)malloc(sizeof(LinkStack));
    initLStack(stack);
    flag = 1;
    printf("成功！\n");
}
void find_length(){
    if (flag==0){
        printf("你还没创建链栈！\n");
        return;
    }
    int length;
    LStackLength(stack, &length);
    printf("您的栈长为：%d\n",length);
}
void add(){
    if (flag==0){
        printf("你还没创建链栈！\n");
        return;
    }
    printf("入栈多少个数据？：");
    int n = input(1, 2147483647);
    for (int i = 0; i < n; ++i) {
        printf("请输入数据：");
        int data = input(-2147483647, 2147483647);
        pushLStack(stack, data);
        printf("成功！\n");
    }
}
void pop(){
    if (flag==0){
        printf("你还没创建链栈！\n");
        return;
    }
    if (!stack->count){
    	printf("空栈无元素可以出栈！\n");
		return; 
	}
    printf("出栈多少个数据？：");
    int n = input(1, stack->count);
    for (int i = 0; i < n; ++i) {
        int data;
        popLStack(stack, &data);
        printf("%d已成功出栈\n", data);
    }
}


int main(void){
    screen();
    while (1){
        printf("请选择功能：");
        int choice = input(0,9);
        switch(choice) {
            case 1:{
                init();
                break;}
            case 2:{
                find_length();
                break;}
            case 3:{
                traverse(stack);
                break;
            }
            case 4:{
                clearLStack(stack);
                break;
            }
            case 5:{
                destroyLStack(stack);
                break;
            }
            case 6:{
                add();
                break;
            }
            case 7:{
                pop();
                break;
            }
            case 8:{
                int data;
                getTopLStack(stack, &data);
                break;
            }
            case 9:{
                screen();
                break;
            }
            case 0:{
                return 0;
            }
        }
    }
}
     break;
            }
            case 7:{
                pop();
                break;
            }
            case 8:{
                int data;
                getTopLStack(stack, &data);
                break;
            }
            case 9:{
                screen();
                break;
            }
            case 0:{
                return 0;
            }
        }
    }
}