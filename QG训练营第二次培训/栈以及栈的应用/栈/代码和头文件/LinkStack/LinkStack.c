//
// Created by ��پ�� on 2020/4/4.
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
        printf("�ǿ�ջ\n");
        return SUCCESS;
    }
    printf("��ջ\n");
    return ERROR;
}
Status getTopLStack(LinkStack *s,ElemType *e){
    if (flag==0){
        printf("�㻹û������ջ��\n");
        return ERROR;
    }
    if (!s->count){
        printf("��ջ\n");
        return ERROR;
    }
    *e = s->top->data;
    printf("ջ��Ԫ��Ϊ��%d\n", *e);
    return SUCCESS;
}
Status clearLStack(LinkStack *s){
    if (flag==0){
        printf("�㻹û������ջ��\n");
        return ERROR;
    }
    LinkStackPtr p=s->top, q;
    while (p){
        q = p;
        p = p->next;
        free(q);
    }
    s->count = 0;
    printf("�ɹ���\n");
    return SUCCESS;
}
Status destroyLStack(LinkStack *s){
    if (flag==0){
        printf("�㻹û������ջ��\n");
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
        printf("�㻹û������ջ��\n");
        return;
    }
    if (s->count==0){
        printf("��ջ��\n");
        return;
    }
    LinkStackPtr p = s->top;
    printf("ջ��");
    while (p){
        printf("--%d",p->data);
        p = p->next;
    }
    printf("--ջ��\n");
}
int input(int min, int max){
    float num;
    int check = scanf("%f", &num);
    fflush(stdin);
    while (check!=1){
        printf("ʦ�ֲ�Ҫ�����������������룺\n");
        check = scanf("%f", &num);
        fflush(stdin);
    }
    num = (int)num;
    if (num < min){
        printf("̫С�����Զ�ȡ��Χ����Сֵ\n");
        return min;
    } else if (num >max){
        printf("̫�������Զ�ȡ��Χ�����ֵ\n");
        return max;
    }
    return num;
}
void screen(){
    system("cls");
    printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
    printf("�U                   �����ھ� ��پ��                  �U\n");
    printf("�U*********            1.��ʼ��ջ            *********�U\n");
    printf("�U*********            2.��ѯջ��            *********�U\n");
    printf("�U*********            3.������ջ            *********�U\n");
    printf("�U*********            4.�����ջ            *********�U\n");
    printf("�U*********            5.�ݻ���ջ            *********�U\n");
    printf("�U*********            6.������ջ            *********�U\n");
    printf("�U*********            7.���ݳ�ջ            *********�U\n");
    printf("�U*********            8.��ѯջ��            *********�U\n");
    printf("�U*********            9.�����Ļ            *********�U\n");
    printf("�U*********            0.�˳�����            *********�U\n");
    printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
}
void init(){
    if (flag == 1){
        printf("��ջ�Ѵ��ڣ�\n");
        return;
    }
    stack = (LinkStack*)malloc(sizeof(LinkStack));
    initLStack(stack);
    flag = 1;
    printf("�ɹ���\n");
}
void find_length(){
    if (flag==0){
        printf("�㻹û������ջ��\n");
        return;
    }
    int length;
    LStackLength(stack, &length);
    printf("����ջ��Ϊ��%d\n",length);
}
void add(){
    if (flag==0){
        printf("�㻹û������ջ��\n");
        return;
    }
    printf("��ջ���ٸ����ݣ���");
    int n = input(1, 2147483647);
    for (int i = 0; i < n; ++i) {
        printf("���������ݣ�");
        int data = input(-2147483647, 2147483647);
        pushLStack(stack, data);
        printf("�ɹ���\n");
    }
}
void pop(){
    if (flag==0){
        printf("�㻹û������ջ��\n");
        return;
    }
    if (!stack->count){
    	printf("��ջ��Ԫ�ؿ��Գ�ջ��\n");
		return; 
	}
    printf("��ջ���ٸ����ݣ���");
    int n = input(1, stack->count);
    for (int i = 0; i < n; ++i) {
        int data;
        popLStack(stack, &data);
        printf("%d�ѳɹ���ջ\n", data);
    }
}


int main(void){
    screen();
    while (1){
        printf("��ѡ���ܣ�");
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