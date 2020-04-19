//
// Created by ��پ�� on 2020/4/18.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "qgsort.h"



//void print_array(int array[], int length){
//    for (int i = 0; i < length; ++i) {
//        printf("%d ", array[i]);
//    }
//}
void pushLStack(LinkStack *s,int data){
    StackNode* p=(StackNode*)malloc(sizeof(StackNode));
    p->data = data;
    p->next = s->top;
    s->top = p;
    s->count++;
}
void popLStack(LinkStack *s,int *data){
    if (!s->count)
        return ;
    StackNode* p=s->top;
    *data = s->top->data;
    s->top = s->top->next;
    free(p);
    s->count--;
}
void insertSort(int *a, int n){
    int result[n];
    result[0] = a[0];
    for (int i = 1; i < n; ++i) {
        for (int j = i-1; j >= 0; --j) {
            if (a[i] < result[j]){
                result[j+1] = result[j];
                if (!j) {
                    result[j] = a[i];
                    break;
                }
                continue;
            }
            result[j+1] = a[i];
            break;
        }
    }
    memcpy(a, result, n * sizeof(int));
}
void MergeArray(int* a,int begin, int mid, int end,int* temp) {
    mid = (begin + end) / 2;
    int i = begin, j = mid + 1, k = 0;//kΪ��ʱ������±�
    while (i <= mid && j <= end) {
        if (a[j] < a[i]) {
            temp[k++] = a[j++];
        } else {
            temp[k++] = a[i++];
        }
    }
    //�ж��������������У��ĸ��Ѿ�ȫ��������ʱ���飬����һ��ʣ�µ�ֱ��ȫ��������temp
    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= end) {
        temp[k++] = a[j++];
    }
    //����ʱ��������������ݿ�����ԭ����
    for (k = 0, i = begin; k < end - begin + 1; k++) {
        a[i++] = temp[k];
    }
}
void MergeSort(int *a,int begin,int end,int *temp){
    if(begin>=end) return ;
    int q = (begin+end)/2;
    MergeSort(a, begin, q, temp);
    MergeSort(a,q+1, end, temp);
    MergeArray(a, begin, q, end, temp);
}
int Partition(int *a, int begin, int end){
    int basic=a[begin];
    while (begin < end){
        while (begin < end && a[end] >= basic) end--;
        if (begin < end) a[begin++] = a[end];
        while (begin < end && a[begin] < basic) begin++;
        if(begin < end) a[end--] = a[begin];
    }
    a[begin] = basic;
    return begin;
}
void QuickSort_Recursion(int *a, int begin, int end){
    if (begin < end){
        int mid = Partition(a, begin, end);
        QuickSort_Recursion(a, begin, mid-1);
        QuickSort_Recursion(a, mid+1, end);
    }
}
void QuickSort(int *a,int size){
    LinkStack s;
    s.top = NULL;
    s.count = 0;
    pushLStack(&s, 0);
    pushLStack(&s, size-1);
    while (s.count!=0){
        int right = s.top->data , c;
        popLStack(&s, &c);
        int left = s.top->data;
        popLStack(&s, &c);
        int mid = Partition(a, left, right);
        if ((mid-1) > left){
            pushLStack(&s, left);
            pushLStack(&s, mid-1);
        }
        if ((mid+1) < right){
            pushLStack(&s, mid+1);
            pushLStack(&s, right);
        }
    }
}
void CountSort(int *a, int size , int max){
    int mid[max+1], res[size];
    memset(mid, 0, sizeof(int)*(max+1));
    for (int i = 0; i < size; ++i) {
        mid[a[i]]++;
    }
    for (int i = 1; i <= max; ++i) {
        mid[i] += mid[i-1];
    }
    for (int i = size-1; i >=0 ; --i) {
        mid[a[i]]--;
        res[mid[a[i]]] = a[i];
    }
    memcpy(a, res, sizeof(int)*size);
}
int getDValue(int value, int d) {
    while (d > 0 && value > 0) {
        value = value / MAXK;
        d--;
    }
    return value % MAXK;
}
void innerCountingSort(int *a, int n, int d) {
    int i, j, k[MAXK], ip[n], bp[n];
    memset(k, 0, sizeof(int)*MAXK);
    for (i = 0; i < n; i++) {
        ip[i] = getDValue(a[i], d);
        k[ip[i]]++;
    }
    for (j = 1; j < MAXK; j++) {
        k[j] = k[j] + k[j-1];
    }
    for (i = n - 1; i >= 0; i--) {
        bp[k[ip[i]] - 1] = a[i];
        k[ip[i]]--;
    }
    memcpy(a, bp, sizeof(int)*n);
}
void RadixCountSort(int *a, int size) {
    int i;
    for (i = 0; i < WIDTH; i++) {
        innerCountingSort(a, size, i);
    }
}
void ColorSort(int *a,int size){
    int p0 = 0, p2 = size-1;
    for (int i = 0; i <= p2; ++i) {
        if (a[i]==2 ){
            a[i--] = a[p2];
            a[p2--] = 2;
        }
        else if (a[i]==0) {
            a[i] = a[p0];
            a[p0++] = 0;
        }
    }
}
void find_k(int *a, int begin, int end, int k){
    if (begin>=end) {
        printf("%d ", a[begin]);
        return;
    }
    int mid = Partition(a, begin, end);
    if (mid-begin+1>=k)
        find_k(a, begin, mid, k);
    else
        find_k(a, mid+1, end, k-(mid-begin+1));
}
int data[200000], temp[200000], copy[200000], max = 0;
void test_long_data(int n){
    
    srand((unsigned) time(NULL));
    for (int i = 0; i < n; ++i) {
        data[i] = rand() % 400;
        if (data[i]>max) max = data[i];
    }
    printf("****** 1 x %d��ģ���� ******\n", n);
    // ��������
    memcpy(copy, data, sizeof(int)*n);
    clock_t start = clock();
    insertSort(copy, n);
    start = clock() - start;
    printf("���������ʱ��%dms\n", start);
    //�鲢����
    memcpy(copy, data, sizeof(int)*n);
    start = clock();
    MergeSort(copy, 0, n-1, temp);
    start = clock() - start;
    printf("�鲢�����ʱ��%dms\n", start);
    // �������򣨵ݹ飩
    memcpy(copy, data, sizeof(int)*n);
    start = clock();
    QuickSort_Recursion(copy, 0, n-1);
    start = clock() - start;
    printf("�������򣨵ݹ飩��ʱ��%dms\n", start);
    // �������򣨷ǵݹ飩
    memcpy(copy, data, sizeof(int)*n);
    start = clock();
    QuickSort(copy, n);
    start = clock() - start;
    printf("�������򣨷ǵݹ飩��ʱ��%dms\n", start);
    // ��������
    memcpy(copy, data, sizeof(int)*n);
    start = clock();
    CountSort(copy, n, max);
    start = clock() - start;
    printf("���������ʱ��%dms\n", start);
    // ������������
    memcpy(copy, data, sizeof(int)*n);
    start = clock();
    RadixCountSort(copy, n);
    start = clock() - start;
    printf("�������������ʱ��%dms\n", start);
}
int data1[100000][100], copy1[100000][100], temp1[100000][100], max1[100000];
void test_small_array(){
    int n = 100000;
    memset(max1, 0, sizeof(int)*n);
    srand((unsigned) time(NULL));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 100; ++j) {
            data1[i][j] = rand() % 400;
            if (data1[i][j] > max1[i]) max1[i] = data1[i][j];
        }
    }
    printf("****** 100 x %d��ģ���� ******\n", n);
    // ��������
    memcpy(copy1, data1, sizeof(copy1));
    clock_t start = clock();
    for (int i = 0; i < n; ++i) {
        insertSort(copy1[i], 100);
    }
    start = clock() - start;
    printf("���������ʱ��%dms\n", start);
    // �鲢����
    memcpy(copy1, data1, sizeof(copy1));
    start = clock();
    for (int i = 0; i < n; ++i) {
        MergeSort(copy1[i], 0, 99, temp1[i]);
    }
    start = clock() - start;
    printf("�鲢�����ʱ��%dms\n", start);
    // �������򣨵ݹ飩
    memcpy(copy1, data1, sizeof(copy1));
    start = clock();
    for (int i = 0; i < n; ++i) {
        QuickSort_Recursion(copy1[i], 0, 99);
    }
    start = clock() - start;
    printf("�������򣨵ݹ飩��ʱ��%dms\n", start);
    // �������򣨷ǵݹ飩
    memcpy(copy1, data1, sizeof(copy1));
    start = clock();
    for (int i = 0; i < n; ++i) {
        QuickSort(copy1[i], 100);
    }
    start = clock() - start;
    printf("�������򣨷ǵݹ飩��ʱ��%dms\n", start);
    // ��������
    memcpy(copy1, data1, sizeof(copy1));
    start = clock();
    for (int i = 0; i < n; ++i) {
        CountSort(copy1[i], 100, max1[i]);
    }
    start = clock() - start;
    printf("���������ʱ��%dms\n", start);
    // ������������
//    memcpy(copy, data, sizeof(copy));
    start = clock();
    for (int i = 0; i < n; ++i) {
        RadixCountSort(data1[i], 100);
    }
    start = clock() - start;
    printf("�������������ʱ��%dms\n", start);
}
void screen1(){
	system("cls");
    printf("�X======================================================�[\n");
    printf("�U                   �����ھ� ��پ��                    �U\n");
    printf("�U*********          1.1 x 1e4 �����ݲ���      *********�U\n");
    printf("�U*********          2.1 x 5e4 �����ݲ���      *********�U\n");
    printf("�U*********          3.1 x 2e5 �����ݲ���      *********�U\n");
    printf("�U*********          4.100 x 1e5 ����С����    *********�U\n");
    printf("�U*********          5.�����Ļ                *********�U\n");
    printf("�U*********          6.�˳�����                *********�U\n");
    printf("�^======================================================�a\n");
}



int input(){
    float num;
    int check = scanf("%f", &num);
    fflush(stdin);
    while (check!=1){
        printf("ʦ�ֲ�Ҫ�����������������룺\n");
        check = scanf("%f", &num);
        fflush(stdin);
    }
    num = (int)num;
    if (num < 1 || num > 6)
        return -1;
    return num;
}





