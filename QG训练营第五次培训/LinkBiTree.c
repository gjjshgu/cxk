//
// Created by 黄倬熙 on 2020/4/25.
//

#include "LinkBiTree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 初始化
Status InitBiTree(BiTree *T){
    *T = NULL;
    return SUCCESS;
}
// 摧毁二叉树
Status DestroyBiTree(BiTree T){
    if (T){
        if (T->lchild)
            DestroyBiTree(T->lchild);
        if (T->rchild)
            DestroyBiTree(T->rchild);
        free(T); //后序遍历
    }
    return SUCCESS;
}
// 前序遍历创建二叉树
Status CreateBiTree(BiTree *T, char* definition){
    if (*definition == '#'){ // #表空子树
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
// 前序遍历
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
    if (!T)
        return SUCCESS;
    (*visit)(T->data);
    PreOrderTraverse(T->lchild, (*visit));
    PreOrderTraverse(T->rchild, (*visit));
    return SUCCESS;
}
// 中序遍历
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
// 层次遍历
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
    BiTree temp[100]; //简易队列
    int in=0, out=0;  //队尾 队头
    temp[in++] = T;
    while (in > out){
        if (temp[out]){
            (*visit)(temp[out]->data);
            temp[in++] = temp[out]->lchild; //入队
            temp[in++] = temp[out]->rchild; //入队
        }
        out++;
    }
    printf("\n");
    return SUCCESS;
}
int f=0, k=0, flag=0; //判断用
char s[100]; //储存前缀表达式
int Value(BiTree T){ //计算前缀表达式
    T = (BiTree)malloc(sizeof(BiTNode));
    if (k>=strlen(s)){
        f = 1;
        return 0;
    }
    char c = s[k++];
    if (c-'0'>=0 && c-'0'<='9') {
        return c - '0';
    }
    int a = Value(T->lchild), b = Value(T->rchild), res=0; // 左右子树值获取
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
    return res; // 运算后返回结果
}
// 打印结点
Status visit(TElemType data){
    printf(" %c ", data);
    return SUCCESS;
}
// 迭代前序遍历
Status pre(BiTree T, Status (*visit)(TElemType e)){
    BiTree stack[100]; //简易栈
    int i = -1; //栈顶元素索引
    BiTree p = T;
    while (p || i!=-1){ //p不为空切或者栈不为空
        if (p){
            stack[++i] = p; //入栈
            (*visit)(p->data);
            p = p->lchild;
        } else{
            p = stack[i--]->rchild; //出栈
        }
    }
    printf("\n");
    return SUCCESS;
}
Status in(BiTree T, Status (*visit)(TElemType e)){ //和前序差不多吧
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
    BiTree stack[100]; //简易栈
    int i = 0;
    BiTree p = T, cur = NULL; //保存上一个结点
    stack[i] = p;
    while (i != -1){
        p = stack[i]; //获取栈顶元素
        if ((!p->lchild && !p->rchild) || (cur==p->lchild||cur==p->rchild)){ //叶子结点或者前一个结点为当前结点的左结点或右结点
            (*visit)(p->data);
            p = stack[i--];
            cur = p;
        } else{
            if (p->rchild) //非空则入栈
                stack[++i] = p->rchild; //入栈
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

