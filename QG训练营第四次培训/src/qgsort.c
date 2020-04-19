//
// Created by 黄倬熙 on 2020/4/18.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "qgsort.h"

void pushLStack(LinkStack *s,int data){ //入栈
    StackNode* p=(StackNode*)malloc(sizeof(StackNode));
    p->data = data;
    p->next = s->top;
    s->top = p;
    s->count++;
}
void popLStack(LinkStack *s,int *data){ //出栈
    if (!s->count)
        return ;
    StackNode* p=s->top;
    *data = s->top->data;
    s->top = s->top->next;
    free(p);
    s->count--;
}
void insertSort(int *a, int n){  //插入排序
    int result[n];
    result[0] = a[0];
    for (int i = 1; i < n; ++i) { //从前往后遍历
        for (int j = i-1; j >= 0; --j) { //从后往前遍历
            if (a[i] < result[j]){
                result[j+1] = result[j]; //元素后移
                if (!j) {
                    result[j] = a[i];
                    break;
                }
                continue;
            }
            result[j+1] = a[i]; //填数
            break;
        }
    }
    memcpy(a, result, n * sizeof(int)); //把结果复制到原来的数组指针
}
void MergeArray(int* a,int begin, int mid, int end,int* temp) { //归并操作
    int i = begin, j = mid + 1, k = 0;//k为临时数组的下标
    while (i <= mid && j <= end) {
        if (a[j] < a[i]) {
            temp[k++] = a[j++];
        } else {
            temp[k++] = a[i++];
        }
    }
    //判断两个有序子序列，哪个已经全部放入临时数组，另外一个剩下的直接全部拷贝到temp
    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= end) {
        temp[k++] = a[j++];
    }
    //将临时数组的已排序数据拷贝回原数组
    for (k = 0, i = begin; k < end - begin + 1; k++) {
        a[i++] = temp[k];
    }
}
void MergeSort(int *a,int begin,int end,int *temp){ //递归法归并排序
    if(begin>=end) return ;
    int q = (begin+end)/2; //找中间点
    MergeSort(a, begin, q, temp); //递归 下同
    MergeSort(a,q+1, end, temp);
    MergeArray(a, begin, q, end, temp); //归并
}
int Partition(int *a, int begin, int end){ //快速排序找枢轴
    int basic=a[begin]; //设第一个元素为基
    while (begin < end){
        while (begin < end && a[end] >= basic) end--; //大于基则左移
        if (begin < end) a[begin++] = a[end]; //挖坑法
        while (begin < end && a[begin] < basic) begin++;
        if(begin < end) a[end--] = a[begin];
    }
    a[begin] = basic; //最后再把基填入
    return begin;
}
void QuickSort_Recursion(int *a, int begin, int end){ //递归法快速排序
    if (begin < end){
        int mid = Partition(a, begin, end); //找枢轴
        QuickSort_Recursion(a, begin, mid-1); //左边的继续递归排序
        QuickSort_Recursion(a, mid+1, end); //右边的也是
    }
}
void QuickSort(int *a,int size){ //非递归法快速排序
    LinkStack s;
    s.top = NULL;
    s.count = 0;
    pushLStack(&s, 0); //把头索引和尾索引入栈
    pushLStack(&s, size-1);
    while (s.count!=0){
        int right = s.top->data , c; //右为尾索引，左为头索引
        popLStack(&s, &c); //出栈，下同
        int left = s.top->data;
        popLStack(&s, &c);
        int mid = Partition(a, left, right); //找枢轴
        if ((mid-1) > left){ //检测左边是否有元素，下同
            pushLStack(&s, left); //有则入栈
            pushLStack(&s, mid-1);
        }
        if ((mid+1) < right){
            pushLStack(&s, mid+1);
            pushLStack(&s, right);
        }
    }
}
void CountSort(int *a, int size , int max){ //计数排序
    int mid[max+1], res[size];
    memset(mid, 0, sizeof(int)*(max+1)); //元素全部归0
    for (int i = 0; i < size; ++i) { //记录出现次数
        mid[a[i]]++;
    }
    for (int i = 1; i <= max; ++i) { //统计小于等于该值的个数
        mid[i] += mid[i-1];
    }
    for (int i = size-1; i >=0 ; --i) { //小于该值个数-1则为排序索引
        mid[a[i]]--;
        res[mid[a[i]]] = a[i]; //赋值
    }
    memcpy(a, res, sizeof(int)*size); //复制结果
}
int getDValue(int value, int d) { //获得第几位数的值
    while (d > 0 && value > 0) {
        value = value / MAXK;
        d--;
    }
    return value % MAXK;
}
void innerCountingSort(int *a, int n, int d) { //基数计数排序
    int i, j, k[MAXK], ip[n], bp[n];
    memset(k, 0, sizeof(int)*MAXK);
    for (i = 0; i < n; i++) {
        ip[i] = getDValue(a[i], d); //获得第几位的值
        k[ip[i]]++; //统计出现次数
    }
    for (j = 1; j < MAXK; j++) {
        k[j] = k[j] + k[j-1]; //小于该值个数-1则为排序索引
    }
    for (i = n - 1; i >= 0; i--) {// 根据索引找值
        k[ip[i]]--;
	bp[k[ip[i]]] = a[i];
    }
    memcpy(a, bp, sizeof(int)*n); //复制结果到原数组
}
void RadixCountSort(int *a, int size) {
    for (int i = 0; i < WIDTH; i++) {
        innerCountingSort(a, size, i); //不同基数下排序
    }
}
void ColorSort(int *a,int size){ //颜色排序
    int p0 = 0, p2 = size-1;
    for (int i = 0; i <= p2; ++i) { //结束条件为i与p0相遇
        if (a[i]==2 ){ //遇到2则交换
            a[i--] = a[p2];
            a[p2--] = 2; //并且退一位
        }
        else if (a[i]==0) { //遇到0也要交换
            a[i] = a[p0];
            a[p0++] = 0;
        }
    }
}
void find_k(int *a, int begin, int end, int k){ //根据快速排序来找第k个最小值（找第k个最大值的话用size-k就好）
    if (begin>=end) {
        printf("%d ", a[begin]); //找到了就打印
        return;
    }
    int mid = Partition(a, begin, end);
    if (mid-begin+1>=k) //如果在左边
        find_k(a, begin, mid, k); //往左找
    else
        find_k(a, mid+1, end, k-(mid-begin+1)); //往右找
}
int data[200000], temp[200000], copy[200000], max = 0;
void test_long_data(int n){
    
    srand((unsigned) time(NULL));
    for (int i = 0; i < n; ++i) {
        data[i] = rand() % 400; //随机生成数据
        if (data[i]>max) max = data[i]; //顺便找最大值，给计数排序用
    }
    printf("****** 1 x %d规模数组 ******\n", n);
    // 插入排序
    memcpy(copy, data, sizeof(int)*n); //复制，利用复制值来排序，以免影响后面
    clock_t start = clock(); //计时，下同
    insertSort(copy, n);
    start = clock() - start;
    printf("插入排序耗时：%dms\n", start);
    //归并排序
    memcpy(copy, data, sizeof(int)*n);
    start = clock();
    MergeSort(copy, 0, n-1, temp);
    start = clock() - start;
    printf("归并排序耗时：%dms\n", start);
    // 快速排序（递归）
    memcpy(copy, data, sizeof(int)*n);
    start = clock();
    QuickSort_Recursion(copy, 0, n-1);
    start = clock() - start;
    printf("快速排序（递归）耗时：%dms\n", start);
    // 快速排序（非递归）
    memcpy(copy, data, sizeof(int)*n);
    start = clock();
    QuickSort(copy, n);
    start = clock() - start;
    printf("快速排序（非递归）耗时：%dms\n", start);
    // 计数排序
    memcpy(copy, data, sizeof(int)*n);
    start = clock();
    CountSort(copy, n, max);
    start = clock() - start;
    printf("计数排序耗时：%dms\n", start);
    // 基数计数排序
    memcpy(copy, data, sizeof(int)*n);
    start = clock();
    RadixCountSort(copy, n);
    start = clock() - start;
    printf("基数计数排序耗时：%dms\n", start);
}
int data1[100000][100], copy1[100000][100], temp1[100000][100], max1[100000];
void test_small_array(){
    int n = 100000;
    memset(max1, 0, sizeof(int)*n); //数组初始化一波
    srand((unsigned) time(NULL));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 100; ++j) {
            data1[i][j] = rand() % 400; //随机生成数据
            if (data1[i][j] > max1[i]) max1[i] = data1[i][j]; //顺便找最大值
        }
    }
    printf("****** 100 x %d规模数组 ******\n", n);
    // 插入排序
    memcpy(copy1, data1, sizeof(copy1)); //同样也是用复制值来测试排序
    clock_t start = clock();
    for (int i = 0; i < n; ++i) {
        insertSort(copy1[i], 100);
    }
    start = clock() - start;
    printf("插入排序耗时：%dms\n", start);
    // 归并排序
    memcpy(copy1, data1, sizeof(copy1));
    start = clock();
    for (int i = 0; i < n; ++i) {
        MergeSort(copy1[i], 0, 99, temp1[i]);
    }
    start = clock() - start;
    printf("归并排序耗时：%dms\n", start);
    // 快速排序（递归）
    memcpy(copy1, data1, sizeof(copy1));
    start = clock();
    for (int i = 0; i < n; ++i) {
        QuickSort_Recursion(copy1[i], 0, 99);
    }
    start = clock() - start;
    printf("快速排序（递归）耗时：%dms\n", start);
    // 快速排序（非递归）
    memcpy(copy1, data1, sizeof(copy1));
    start = clock();
    for (int i = 0; i < n; ++i) {
        QuickSort(copy1[i], 100);
    }
    start = clock() - start;
    printf("快速排序（非递归）耗时：%dms\n", start);
    // 计数排序
    memcpy(copy1, data1, sizeof(copy1));
    start = clock();
    for (int i = 0; i < n; ++i) {
        CountSort(copy1[i], 100, max1[i]);
    }
    start = clock() - start;
    printf("计数排序耗时：%dms\n", start);
    // 基数计数排序
    start = clock();
    for (int i = 0; i < n; ++i) {
        RadixCountSort(data1[i], 100);
    }
    start = clock() - start;
    printf("基数计数排序耗时：%dms\n", start);
}
void screen1(){
	system("cls");
    printf("╔======================================================╗\n");
    printf("║                   数据挖掘 黄倬熙                    ║\n");
    printf("║*********          1.1 x 1e4 大数据测试      *********║\n");
    printf("║*********          2.1 x 5e4 大数据测试      *********║\n");
    printf("║*********          3.1 x 2e5 大数据测试      *********║\n");
    printf("║*********          4.100 x 1e5 大量小数组    *********║\n");
    printf("║*********          5.清空屏幕                *********║\n");
    printf("║*********          6.退出程序                *********║\n");
    printf("╚======================================================╝\n");
}
int input(){ //防崩溃
    float num;
    int check = scanf("%f", &num);
    fflush(stdin);
    while (check!=1){
        printf("师兄不要乱输啦！请重新输入：\n");
        check = scanf("%f", &num);
        fflush(stdin);
    }
    num = (int)num;
    if (num < 1 || num > 6)
        return -1;
    return num;
}





