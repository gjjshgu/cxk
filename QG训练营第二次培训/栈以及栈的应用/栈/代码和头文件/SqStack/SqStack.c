//
// Created by ��پ�� on 2020/4/4.
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
        printf("��ջ��");
        return SUCCESS;
    }
    printf("�ǿ�ջ");
    return ERROR;
}
Status getTopStack(SqStack *s,ElemType *e){
    if (flag==0){
        printf("�㻹û����ջ��\n");
        return ERROR;
    }
    if (!(s->top+1)){
        printf("��ջ��\n");
        return ERROR;
    }
    *e = s->elem[s->top];
    printf("ջ��Ԫ��Ϊ%d\n", *e);
    return SUCCESS;
}
Status clearStack(SqStack *s){
    if (flag==0){
        printf("�㻹û����ջ��\n");
        return ERROR;
    }
    s->top = -1;
    printf("�ɹ�\n");
    return SUCCESS;

}
Status destroyStack(SqStack *s){
    if (flag==0){
        printf("�㻹û����ջ��\n");
        return ERROR;
    }
    free(s->elem);
    free(s);
    flag = 0;
    printf("�ɹ���\n");
    return SUCCESS;
}
Status stackLength(SqStack *s,int *length){
    *length = s->top + 1;
    return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data){
//    if (s->top == max){
//        printf("ջ������\n");
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
        printf("�㻹û����ջ��\n");
        return;
    }
    if (!(s->top+1)) {
        printf("��ջ��\n");
        return;
    }
    printf("ջ��--");
    for (int i = 0; i < s->top+1; ++i) {
        printf("%d--", s->elem[i]);
    }
    printf("ջ��\n");
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
    printf("�U*********            4.��մ�ջ            *********�U\n");
    printf("�U*********            5.�ݻٴ�ջ            *********�U\n");
    printf("�U*********            6.������ջ            *********�U\n");
    printf("�U*********            7.���ݳ�ջ            *********�U\n");
    printf("�U*********            8.��ѯջ��            *********�U\n");
    printf("�U*********            9.�����Ļ            *********�U\n");
    printf("�U*********            0.�˳�����            *********�U\n");
    printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
}
void init(){
    if (flag == 1){
        printf("ջ�Ѵ��ڣ�\n");
        return;
    }
    stack = (SqStack*)malloc(sizeof(SqStack));
    printf("������ջ�����������");
    int n = input(1, 2147483647);
    initStack(stack, n);
    flag = 1;
    printf("�ɹ���\n");
}
void find_length(){
    if (flag==0){
        printf("�㻹û����ջ��\n");
        return;
    }
    int length;
    stackLength(stack, &length);
    printf("ջ��Ԫ�ظ���Ϊ��%d\nջ���������Ϊ��%d\n", length, stack->size);
}
void add(){
    if (!flag){
        printf("�㻹û����ջ��\n");
        return;
    }
    printf("��ջ���ٸ����ݣ���");
    int n = input(1, stack->size-stack->top-1);
    for (int i = 0; i < n; ++i) {
        printf("���������ݣ�");
        int data = input(-2147483647, 2147483647);
        pushStack(stack, data);
        printf("�ɹ���\n");
    }
}
void pop(){
    if (!flag){
        printf("�㻹û����ջ��\n");
        return;
    }
    if (!(stack->top+1)){
        printf("��ջ��\n");
        return;
    }
    printf("��ջ���ٸ����ݣ���");
    int n = input(1, stack->top+1);
    for (int i = 0; i < n; ++i) {
        int data;
        popStack(stack, &data);
        printf("%d�ѳɹ���ջ\n", data);
    }
}
int main(void){
    screen();
    while (1){
        printf("��ѡ���ܣ�");
        int choice = input(0,9);
        switch (choice){
            case 0:
                return 0;
            case 1:{
                init();
                break;
            }
            case 2:{
                find_length();
                break;
            }
            case 3:{
                traverse(stack);
                break;
            }
            case 4:{
                clearStack(stack);
                break;
            }
            case 5:{
                destroyStack(stack);
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
                getTopStack(stack, &data);
                break;
            }
            case 9:{
                screen();
                break;
            }
        }
    }
}
