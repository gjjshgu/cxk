//
// Created by ��پ�� on 2020/4/12.
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
        printf("�ն��У�\n");
        return FALSE;
    }
    printf("��ͷ->");
    for (int i = 0; i < Q->length; ++i) {
        int index = (Q->front + i) % MAXQUEUE;
        (*foo)(Q->data[index]);
        printf("->");
    }
    printf("��β\n");
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
void initdata(all_data *p){
    for (int i = 0; i < 4; ++i) {
        p->count[i] = 0;
    }
}
void init(){
    if (flag==1){
        printf("�����Ѵ��ڣ�\n");
        return;
    }
    aqueue = (AQueue*)malloc(sizeof(AQueue));
    InitAQueue(aqueue);
    printf("�ɹ�\n");
    flag = 1;
}
void push(){
    if (!flag){
        printf("����û�д������У�\n");
        return;
    }
    if (IsFullAQueue(aqueue)==TRUE){
        printf("����������\n");
        return;
    }
    all_data *data = (all_data*)malloc(sizeof(all_data));
    printf("1.int\n2.float\n3.string\n4.double\n��������������ǣ�");
    int n = input(1, 4);
    initdata(data);
    data->count[n-1] = 1;
    printf("���������ݣ�");
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
    printf("�ɹ�\n");
}
void pop(){
    if (!flag){
        printf("�㻹û�д�������\n");
        return;
    }
    if (!aqueue->length){
        printf("�ն��У�\n");
        return;
    }
    DeAQueue(aqueue);
    printf("�ɹ�\n");
}
void find_head(){
    if (!flag){
        printf("�㻹û�д�������\n");
        return;
    }
    if (!aqueue->length){
        printf("�ն��У�\n");
        return;
    }
    all_data *head_data;
    head_data = (all_data*)malloc(sizeof(all_data));
    GetHeadAQueue(aqueue, head_data);
    printf("��ͷԪ��Ϊ:");
    APrint(head_data);
    printf("\n");
}
void traverse(){
    if (!flag){
        printf("�㻹û�д�������\n");
        return;
    }
    TraverseAQueue(aqueue, APrint);
}
void destory(){
    if (!flag){
        printf("�㻹û�д�������\n");
        return;
    }
    DestoryAQueue(aqueue);
    flag = 0;
    printf("�ɹ���\n");
}
void clea(){
    if (!flag){
        printf("�㻹û�д�������\n");
        return;
    }
    ClearAQueue(aqueue);
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
//                printf("���г���Ϊ: %d\n", LengthAQueue(aqueue));
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
