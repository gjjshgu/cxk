//
// Created by ��پ�� on 2020/4/11.
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
        printf("�ն��У�\n");
        return FALSE;
    }
    printf("��ͷ->");
    Node *p=Q->front->next;
    do{
        (*foo)(p->data);
        printf("->");
        p = p->next;
    }
    while (p!=NULL);
    printf("��β\n");
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
        printf("ʦ�ֲ�Ҫ�����������������룺");
        check = scanf("%lf", &num);
        fflush(stdin);
    }
    if (num < min){
        printf("̫С�����Զ�ȡ��Χ����Сֵ\n");
        return (double)min;
    } else if (num >max){
        printf("̫�������Զ�ȡ��Χ�����ֵ\n");
        return (double)max;
    }
    return num;
}
void init(){
    if (flag == 1){
        printf("�����Ѵ��ڣ�\n");
        return;
    }
    lqueue = malloc(sizeof(LQueue));
    InitLQueue(lqueue);
    printf("�ɹ���\n");
    flag = 1;
}
void initdata(all_data *p){
    for (int i = 0; i < 4; ++i) {
        p->count[i] = 0;
    }
}
void push(){
    if (!flag){
        printf("�㻹û�д�������\n");
        return;
    }
    all_data *data = (all_data*)malloc(sizeof(all_data));
    printf("1.int\n2.float\n3.string\n4.double\n��������������ǣ�");
    int n = input(1, 4);
    printf("���������ݣ�");
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
        printf("�㻹û�д�������\n");
        return;
    }
    if (!lqueue->length){
        printf("�ն��У�\n");
        return;
    }
    DeLQueue(lqueue);
}
void find_head(){
    if (!flag){
        printf("�㻹û�д�������\n");
        return;
    }
    if (!lqueue->length){
        printf("�ն��У�\n");
        return;
    }
    all_data *head_data;
    head_data = (all_data*)malloc(sizeof(all_data));
    GetHeadLQueue(lqueue, head_data);
    printf("��ͷԪ��Ϊ:");
    LPrint(head_data);
    printf("\n");
}
void traverse(){
    if (!flag){
        printf("�㻹û�д�������\n");
        return;
    }
    TraverseLQueue(lqueue, LPrint);
}
void destory(){
    if (!flag){
        printf("�㻹û�д�������\n");
        return;
    }
    DestoryLQueue(lqueue);
    flag = 0;
    printf("�ɹ���\n");
}
void clea(){
    if (!flag){
        printf("�㻹û�д�������\n");
        return;
    }
    ClearLQueue(lqueue);
    printf("�ɹ���\n");
}
void screen(){
    system("cls");
    printf("�X====================================================�[\n");
    printf("�U                   �����ھ� ��پ��                  �U\n");
    printf("�Uxxxxxxxxx            1.��������            xxxxxxxxx�U\n");
    printf("�U---------            2.��ѯ�ӳ�            ---------�U\n");
    printf("�Uxxxxxxxxx            3.��������            xxxxxxxxx�U\n");
    printf("�U---------            4.��ն���            ---------�U\n");
    printf("�Uxxxxxxxxx            5.�ݻٶ���            xxxxxxxxx�U\n");
    printf("�U---------            6.�������            ---------�U\n");
    printf("�Uxxxxxxxxx            7.���ݳ���            xxxxxxxxx�U\n");
    printf("�U---------            8.��ѯ��ͷ            ---------�U\n");
    printf("�Uxxxxxxxxx            9.�����Ļ            xxxxxxxxx�U\n");
    printf("�U---------            0.�˳�����            ---------�U\n");
    printf("�^====================================================�a\n");
}
//int main(void){
//    screen();
//    while (1){
//        printf("��ѡ���ܣ�");
//        int n = input(0, 9);
//        switch (n){
//            case 0:
//                return 0;
//            case 1:
//                init();
//                break;
//            case 2:
//                if (!flag){
//                    printf("�㻹û�д�������\n");
//                    break;
//                }
//                printf("���г���Ϊ: %d\n", LengthLQueue(lqueue));
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
