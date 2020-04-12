//
// Created by 黄倬熙 on 2020/4/11.
//

#include "LQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void InitLQueue(LQueue *Q){
    Node *p = (Node*)malloc(sizeof(Node)); //申请一个头结点
    if (!p) return;
    p->next = NULL; 
    Q->front = p; //队头，队尾指向头结点
    Q->rear = p; 
    Q->length = 0; //长度归0
}
void DestoryLQueue(LQueue *Q){
    ClearLQueue(Q); //先清空，清空的过程伴随着结点的释放
    free(Q->front); //再把队列释放了
}
Status IsEmptyLQueue(const LQueue *Q){
    if (!Q->length) return TRUE;
    return FALSE;
}
Status GetHeadLQueue(LQueue *Q, void *e){
    if (IsEmptyLQueue(Q)==TRUE) return FALSE;
    // 用memcpy函数将结点复制到e上
    memcpy(e, Q->front->next->data, sizeof(all_data));
    return TRUE;
}
int LengthLQueue(LQueue *Q){
    //返回长度
    return (int)Q->length;
}
Status EnLQueue(LQueue *Q, void *data){
    //队列入队，和链表尾增加结点差不多
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    Q->length++;
    return TRUE;
} // 出队，也和链表类似，多了部队列的处理罢了
Status DeLQueue(LQueue *Q){
    Node *p = Q->front->next;
    Q->front->next = p->next; //队尾的转移
    if (Q->rear == p) Q->rear = Q->front;
    free(p);
    Q->length--; //队长-1
    return TRUE;
}
void ClearLQueue(LQueue *Q){
    // 清空队列，也和链表清空一样
    if (IsEmptyLQueue(Q)==TRUE) return ;
    Q->rear = Q->front;
    Node *p = Q->rear->next, *q;
    while (p->next){ //遍历链表
        q = p;
        p = p->next;
        free(q); //释放每个结点
    }
    free(p); //释放最后一个结点
    Q->length = 0; //长度归0
}
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
    //遍历队列
    if (IsEmptyLQueue(Q)==TRUE) {
        printf("空队列！\n");
        return FALSE;
    }
    printf("队头->");
    Node *p=Q->front->next;
    // 循环遍历每一个结点
    do{ 
        (*foo)(p->data); //数据结构体打印函数
        printf("->");
        p = p->next;
    }
    while (p!=NULL); //直到p为NULL
    printf("队尾\n");
    return TRUE;
}
void LPrint(void *q){
    all_data* p = (all_data*)q; //强制类型转换
    if (p->count[0]==1) //类型记录数组
        printf("%d(int)", p->a);
    else if (p->count[1]==1)
        printf("%f(float)", p->b);
    else if (p->count[2]==1)
        printf("%s(string)", p->c);
    else
        printf("%lf(double)", p->d);
}//全局变量
LQueue *lqueue;
int flag = 0;
//防崩溃
double input(int min, int max) {
    double num;
    int check = scanf("%lf", &num);
    fflush(stdin); //吃掉回车等没有读取的字符串
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
}//初始化
void init(){
    if (flag == 1){
        printf("队列已存在！\n");
        return;
    }
    lqueue = malloc(sizeof(LQueue)); //申请内存空间
    InitLQueue(lqueue);
    printf("成功！\n");
    flag = 1; //标记为已创建
} //类型记录数组初始化
void initdata(all_data *p){
    for (int i = 0; i < 4; ++i) {
        p->count[i] = 0;
    }
} //入队
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
            //根据输入类型读取数据
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
} //出队
void pop(){
    if (!flag){
        printf("你还没有创建队列\n");
        return;
    }
    if (!lqueue->length){
        printf("空队列！\n");
        return;
    }
    DeLQueue(lqueue);//出队函数
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
    //申请空间，用于记录复制的值
    head_data = (all_data*)malloc(sizeof(all_data));
    GetHeadLQueue(lqueue, head_data);//得到头结点数据
    printf("队头元素为:");
    LPrint(head_data); //数据结构体打印
    printf("\n");
    free(head_data)
} //遍历
void traverse(){
    if (!flag){
        printf("你还没有创建队列\n");
        return;
    }
    TraverseLQueue(lqueue, LPrint); //遍历函数
}//毁灭
void destory(){
    if (!flag){
        printf("你还没有创建队列\n");
        return;
    }
    DestoryLQueue(lqueue); //摧毁队列
    flag = 0;
    printf("成功！\n");
} //清空
void clea(){
    if (!flag){
        printf("你还没有创建队列\n");
        return;
    }
    ClearLQueue(lqueue); //清空队列
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
