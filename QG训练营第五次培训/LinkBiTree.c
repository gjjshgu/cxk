//
// Created by 黄倬熙 on 2020/4/25.
//

#include "LinkBiTree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


Status InitBiTree(BiTree *T){
    *T = NULL;
    return SUCCESS;
}
Status DestroyBiTree(BiTree T){
    if (T){
        if (T->lchild)
            DestroyBiTree(T->lchild);
        if (T->rchild)
            DestroyBiTree(T->rchild);
        free(T);
    }
    return SUCCESS;
}
Status CreateBiTree(BiTree *T, char* definition){
    if (*definition == '#'){
        *T = NULL;
        return SUCCESS;
    }
    (*T) = (BiTree)malloc(sizeof(BiTNode));
    if (!*T) return ERROR;
    (*T)->data = *definition;
    char c;
    scanf(" %c", &c);
    CreateBiTree(&(*T)->lchild, &c);
    scanf(" %c", &c);
    CreateBiTree(&(*T)->rchild, &c);
    return SUCCESS;
}
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
    if (!T)
        return SUCCESS;
    (*visit)(T->data);
    PreOrderTraverse(T->lchild, (*visit));
    PreOrderTraverse(T->rchild, (*visit));
    return SUCCESS;
}
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
    if (!T)
        return SUCCESS;
    InOrderTraverse(T->lchild, (*visit));
    (*visit)(T->data);
    InOrderTraverse(T->rchild, (*visit));
    return SUCCESS;
}
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
    if (!T)
        return SUCCESS;
    PostOrderTraverse(T->lchild, (*visit));
    PostOrderTraverse(T->rchild, (*visit));
    (*visit)(T->data);
    return SUCCESS;
}
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
    BiTree temp[100];
    int in=0, out=0;
    temp[in++] = T;
    while (in > out){
        if (temp[out]){
            (*visit)(temp[out]->data);
            temp[in++] = temp[out]->lchild;
            temp[in++] = temp[out]->rchild;
        }
        out++;
    }
    printf("\n");
    return SUCCESS;
}
int f=0, k=0, flag=0;
char s[100];
int Value(BiTree T){
    T = (BiTree)malloc(sizeof(BiTNode));
    if (k>=strlen(s)){
        f = 1;
        return 0;
    }
    char c = s[k++];
    if (c-'0'>=0 && c-'0'<='9') {
        return c - '0';
    }
    int a = Value(T->lchild), b = Value(T->rchild), res=0;
    free(T);
    if (c == '+')
        res = a+b;
    else if (c == '-')
        res = a-b;
    else if (c == '*')
        res = a*b;
    else if (c == '/'){
        if (b == 0){
            f = 1;
            return 0;
        }
        res = a / b;
    }
    return res;
}
Status visit(TElemType data){
    printf(" %c ", data);
    return SUCCESS;
}
Status pre(BiTree T, Status (*visit)(TElemType e)){
    BiTree stack[100];
    int i = -1;
    BiTree p = T;
    while (p || i!=-1){
        if (p){
            stack[++i] = p;
            (*visit)(p->data);
            p = p->lchild;
        } else{
            p = stack[i--]->rchild;
        }
    }
    printf("\n");
    return SUCCESS;
}
Status in(BiTree T, Status (*visit)(TElemType e)){
    BiTree stack[100];
    int i = -1;
    BiTree p = T;
    while (p || i!=-1){
        if (p){
            stack[++i] = p;
            p = p->lchild;
        } else{
            p = stack[i--];
            (*visit)(p->data);
            p = p->rchild;
        }
    }
    printf("\n");
    return SUCCESS;
}
Status post(BiTree T, Status (*visit)(TElemType e)){
    BiTree stack[100];
    int i = 0;
    BiTree p = T, cur = NULL;
    stack[i] = p;
    while (i != -1){
        p = stack[i];
        if ((!p->lchild && !p->rchild) || (cur==p->lchild||cur==p->rchild)){
            (*visit)(p->data);
            p = stack[i--];
            cur = p;
        } else{
            if (p->rchild)
                stack[++i] = p->rchild;
            if (p->lchild)
                stack[++i] = p->lchild;
        }
    }
    printf("\n");
    return SUCCESS;
}
void calculator(){
    int i = 0;
    printf("请输入前缀表达式，字符之间带空格，完成后结尾输入#\n（例如：+ + 2 * 3 - 7 4 / 8 4 #）\n：");
    while (1){
        scanf(" %c", &s[i]);
        if (s[i] == '#'){
            s[i] = '\0';
            break;
        }
        i++;
    }
    BiTree T = (BiTree)malloc(sizeof(BiTNode));
    int sum = Value(T);
    printf("结果为：%d\n", sum);
}
int input(){
    float num;
    int check = scanf("%f", &num);
    fflush(stdin);
    while (check!=1){
        printf("师兄不要乱输啦！请重新输入：\n");
        check = scanf("%f", &num);
        fflush(stdin);
    }
    num = (int)num;
    if (num < 1 || num > 9)
        return -1;
    return num;
}
void screen(){
	system("cls");
    printf("╔======================================================╗\n");
    printf("║                   数据挖掘 黄倬熙                    ║\n");
    printf("║*********          1.创建二叉树              *********║\n");
    printf("║*********          2.先序遍历                *********║\n");
    printf("║*********          3.中序遍历                *********║\n");
    printf("║*********          4.后序遍历                *********║\n");
    printf("║*********          5.层次遍历                *********║\n");
    printf("║*********          6.摧毁二叉树              *********║\n");
    printf("║*********          7.前缀表达计算器          *********║\n");
    printf("║*********          8.清空屏幕                *********║\n");
    printf("║*********          9.退出程序                *********║\n");
    printf("╚======================================================╝\n");
}

