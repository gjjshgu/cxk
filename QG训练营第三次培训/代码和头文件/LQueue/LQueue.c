//
// Created by 黄倬熙 on 2020/4/11.
//

#include "LQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void InitLQueue(LQueue *Q){
    Node *p = NULL;
    p = (Node*)malloc(sizeof(Node));
    if (!p) return;
    p->next = NULL;
    Q->front = p;
    Q->rear = p;
    Q->length = 0;
}
void DestoryLQueue(LQueue *Q){
    ClearLQueue(Q);
    free(Q->front);
}
Status IsEmptyLQueue(const LQueue *Q){
    if (!Q->length) return TRUE;
    return FALSE;
}
Status GetHeadLQueue(LQueue *Q, void *e){
    if (IsEmptyLQueue(Q)==TRUE) return FALSE;
//    *e = Q->front->next->data;
    memcpy(e, Q->front->next->data, sizeof(all_data));
//    *p = Q->front->next->data;

    return TRUE;
}
int LengthLQueue(LQueue *Q){

    return (int)Q->length;
}
Status EnLQueue(LQueue *Q, void *data){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    Q->length++;
    return TRUE;
}
Status DeLQueue(LQueue *Q){
    Node *p = Q->front->next;
    Q->front->next = p->next;
    if (Q->rear == p) Q->rear = Q->front;
    free(p);
    Q->length--;
    return TRUE;
}
void ClearLQueue(LQueue *Q){
    if (IsEmptyLQueue(Q)==TRUE) return ;
    Q->rear = Q->front;
    Node *p = Q->rear->next, *q;
    while (p->next){
        q = p;
        p = p->next;
        free(q);
    }
    free(p);
    Q->length = 0;
}
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
    if (IsEmptyLQueue(Q)==TRUE) {
        printf("空队列！\n");
        return FALSE;
    }
    printf("队头->");
    Node *p=Q->front->next;
    do{
        (*foo)(p->data);
        printf("->");
        p = p->next;
    }
    while (p!=NULL);
    printf("队尾\n");
    return TRUE;
}
void LPrint(void *q){
    all_data* p = (all_data*)q;
    if (p->count[0]==1)
        printf("%d(int)", p->a);
    else if (p->count[1]==1)
        printf("%f(float)", p->b);
    else if (p->count[2]==1)
        printf("%s(string)", p->c);
    else
        printf("%lf(double)", p->d);
}
LQueue *lqueue;
int flag = 0;
double input(int min, int max) {
    double num;
    int check = scanf("%lf", &num);
    fflush(stdin);
    while (check!=1){
        printf("师兄不要乱输啦！请重新输入：");
        check = scanf("%lf", &num);
        fflush(stdin);
    }
    if (num < min){
        printf("太小啦！自动取范围内最小值\n");
        return (double)min;
    } else if (num >max){
        printf("太大啦！自动取范围内最大值\n");
        return (double)max;
    }
    return num;
}
void init(){
    if (flag == 1){
        printf("队列已存在！\n");
        return;
    }
    lqueue = malloc(sizeof(LQueue));
    InitLQueue(lqueue);
    printf("成功！\n");
    flag = 1;
}
void initdata(all_data *p){
    for (int i = 0; i < 4; ++i) {
        p->count[i] = 0;
    }
}
void push(){
    if (!flag){
        printf("你还没有创建队列\n");
        return;
    }
    all_data *data = (all_data*)malloc(sizeof(all_data));
    printf("1.int\n2.float\n3.string\n4.double\n您想输入的类型是：");
    int n = input(1, 4);
    printf("请输入数据：");
    initdata(data);
    data->count[n-1] = 1;
    switch (n){
        case 1:
            data->a = (int)input(-2147483647, 2147483647);
            break;
        case 2:
            data->b = (float)input(-2147483647, 2147483647);
            break;
        case 3:
            scanf(" %s", data->c);
            break;
        case 4:
            data->d = input(-2147483647, 2147483647);
            break;
    }
    EnLQueue(lqueue, (void*)data);
}
void pop(){
    if (!flag){
        printf("你还没有创建队列\n");
        return;
    }
    if (!lqueue->length){
        printf("空队列！\n");
        return;
    }
    DeLQueue(lqueue);
}
void find_head(){
    if (!flag){
        printf("你还没有创建队列\n");
        return;
    }
    if (!lqueue->length){
        printf("空队列！\n");
        return;
    }
    all_data *head_data;
    head_data = (all_data*)malloc(sizeof(all_data));
    GetHeadLQueue(lqueue, head_data);
    printf("队头元素为:");
    LPrint(head_data);
    printf("\n");
}
void traverse(){
    if (!flag){
        printf("你还没有创建队列\n");
        return;
    }
    TraverseLQueue(lqueue, LPrint);
}
void destory(){
    if (!flag){
        printf("你还没有创建队列\n");
        return;
    }
    DestoryLQueue(lqueue);
    flag = 0;
    printf("成功！\n");
}
void clea(){
    if (!flag){
        printf("你还没有创建队列\n");
        return;
    }
    ClearLQueue(lqueue);
    printf("成功！\n");
}
void screen(){
    system("cls");
    printf("╔====================================================╗\n");
    printf("║                   数据挖掘 黄倬熙                  ║\n");
    printf("║xxxxxxxxx            1.创建队列            xxxxxxxxx║\n");
    printf("║---------            2.查询队长            ---------║\n");
    printf("║xxxxxxxxx            3.遍历队列            xxxxxxxxx║\n");
    printf("║---------            4.清空队列            ---------║\n");
    printf("║xxxxxxxxx            5.摧毁队列            xxxxxxxxx║\n");
    printf("║---------            6.数据入队            ---------║\n");
    printf("║xxxxxxxxx            7.数据出队            xxxxxxxxx║\n");
    printf("║---------            8.查询队头            ---------║\n");
    printf("║xxxxxxxxx            9.清空屏幕            xxxxxxxxx║\n");
    printf("║---------            0.退出程序            ---------║\n");
    printf("╚====================================================╝\n");
}
//int main(void){
//    screen();
//    while (1){
//        printf("请选择功能：");
//        int n = input(0, 9);
//        switch (n){
//            case 0:
//                return 0;
//            case 1:
//                init();
//                break;
//            case 2:
//                if (!flag){
//                    printf("你还没有创建队列\n");
//                    break;
//                }
//                printf("队列长度为: %d\n", LengthLQueue(lqueue));
//                break;
//            case 3:
//                traverse();
//                break;
//            case 4:
//                clea();
//                break;
//            case 5:
//                destory();
//                break;
//            case 6:
//                push();
//                break;
//            case 7:
//                pop();
//                break;
//            case 8:
//                find_head();
//                break;
//            case 9:
//                screen();
//        }
//    }
//}
