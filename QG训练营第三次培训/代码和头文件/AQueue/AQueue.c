//
// Created by 黄倬熙 on 2020/4/12.
//

#include "AQueue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void InitAQueue(AQueue *Q){
    Q->front = -1;
    Q->rear = -1;
    Q->length = 0;
}
void DestoryAQueue(AQueue *Q){
    for (int i = 0; i < Q->length; ++i) {
        int index = (Q->front + i) % MAXQUEUE;
        free(Q->data[index]);
    }
    free(Q);
}
Status IsFullAQueue(const AQueue *Q){
    if (Q->length == MAXQUEUE) return TRUE;
    return FALSE;
}
Status IsEmptyAQueue(const AQueue *Q){
    if (!Q->length) return TRUE;
    return FALSE;
}
Status GetHeadAQueue(AQueue *Q, void *e){
    if (IsEmptyAQueue(Q)==TRUE) return FALSE;
    memcpy(e, Q->data[Q->front], sizeof(all_data));
    return TRUE;
}
int LengthAQueue(AQueue *Q){
    return Q->length;
}
Status EnAQueue(AQueue *Q, void *data){
    if (IsFullAQueue(Q)==TRUE) return FALSE;
    Q->rear =(Q->rear+1)%MAXQUEUE;
    if (Q->front==-1)
        Q->front = 0;
    Q->data[Q->rear] = data;
    Q->length++;
    return TRUE;
}
Status DeAQueue(AQueue *Q){
    if (IsEmptyAQueue(Q)==TRUE) return FALSE;
    Q->front = (Q->front+1)%MAXQUEUE;
    Q->length--;
    return TRUE;
}
void ClearAQueue(AQueue *Q){
    InitAQueue(Q);
}
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
    if (IsEmptyAQueue(Q)==TRUE) {
        printf("空队列！\n");
        return FALSE;
    }
    printf("队头->");
    for (int i = 0; i < Q->length; ++i) {
        int index = (Q->front + i) % MAXQUEUE;
        (*foo)(Q->data[index]);
        printf("->");
    }
    printf("队尾\n");
    return TRUE;
}
void APrint(void *q){
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
AQueue *aqueue;
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
void initdata(all_data *p){
    for (int i = 0; i < 4; ++i) {
        p->count[i] = 0;
    }
}
void init(){
    if (flag==1){
        printf("队列已存在！\n");
        return;
    }
    aqueue = (AQueue*)malloc(sizeof(AQueue));
    InitAQueue(aqueue);
    printf("成功\n");
    flag = 1;
}
void push(){
    if (!flag){
        printf("您还没有创建队列！\n");
        return;
    }
    if (IsFullAQueue(aqueue)==TRUE){
        printf("队列已满！\n");
        return;
    }
    all_data *data = (all_data*)malloc(sizeof(all_data));
    printf("1.int\n2.float\n3.string\n4.double\n您想输入的类型是：");
    int n = input(1, 4);
    initdata(data);
    data->count[n-1] = 1;
    printf("请输入数据：");
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
    EnAQueue(aqueue, (void*)data);
    printf("成功\n");
}
void pop(){
    if (!flag){
        printf("你还没有创建队列\n");
        return;
    }
    if (!aqueue->length){
        printf("空队列！\n");
        return;
    }
    DeAQueue(aqueue);
    printf("成功\n");
}
void find_head(){
    if (!flag){
        printf("你还没有创建队列\n");
        return;
    }
    if (!aqueue->length){
        printf("空队列！\n");
        return;
    }
    all_data *head_data;
    head_data = (all_data*)malloc(sizeof(all_data));
    GetHeadAQueue(aqueue, head_data);
    printf("队头元素为:");
    APrint(head_data);
    printf("\n");
}
void traverse(){
    if (!flag){
        printf("你还没有创建队列\n");
        return;
    }
    TraverseAQueue(aqueue, APrint);
}
void destory(){
    if (!flag){
        printf("你还没有创建队列\n");
        return;
    }
    DestoryAQueue(aqueue);
    flag = 0;
    printf("成功！\n");
}
void clea(){
    if (!flag){
        printf("你还没有创建队列\n");
        return;
    }
    ClearAQueue(aqueue);
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
//                printf("队列长度为: %d\n", LengthAQueue(aqueue));
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
