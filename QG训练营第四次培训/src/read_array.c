//
// Created by 黄倬熙 on 2020/4/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "qgsort.h"

int c0[200000], c1[100000][100],cp1[100000][100],tmp1[100000][100]; //声明全局变量，函数中数组长度过大会报错
int copy[200000], temp[200000];

void long_test(int n){ //测试数据，没什么好说了
    int max = 0;
    for (int i = 0; i < n; ++i) {
        if (c0[i] > max) max = c0[i];
    }
    // 插入排序
    memcpy(copy, c0, sizeof(int)*n);
    clock_t start = clock();
    insertSort(copy, n);
    start = clock() - start;
    printf("插入排序耗时：%dms\n", start);
    //归并排序
    memcpy(copy, c0, sizeof(int)*n);
    start = clock();
    MergeSort(copy, 0, n-1, temp);
    start = clock() - start;
    printf("归并排序耗时：%dms\n", start);
    // 快速排序（递归）
    memcpy(copy, c0, sizeof(int)*n);
    start = clock();
    QuickSort_Recursion(copy, 0, n-1);
    start = clock() - start;
    printf("快速排序（递归）耗时：%dms\n", start);
    // 快速排序（非递归）
    memcpy(copy, c0, sizeof(int)*n);
    start = clock();
    QuickSort(copy, n);
    start = clock() - start;
    printf("快速排序（非递归）耗时：%dms\n", start);
    // 计数排序
    memcpy(copy, c0, sizeof(int)*n);
    start = clock();
    CountSort(copy, n, max);
    start = clock() - start;
    printf("计数排序耗时：%dms\n", start);
    // 基数计数排序
    memcpy(copy, c0, sizeof(int)*n);
    start = clock();
    RadixCountSort(copy, n);
    start = clock() - start;
    printf("基数计数排序耗时：%dms\n", start);
}
void small_test(){ //也是测试数据
    int max[100000], n = 100000;
    memset(max, 0, sizeof(int)*n);
    for (int i = 0; i < 100000; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (c1[i][j] > max[i]) max[i] = c1[i][j];
        }
    }
    // 插入排序
    memcpy(cp1, c1, sizeof(cp1));
    clock_t start = clock();
    for (int i = 0; i < n; ++i) {
        insertSort(cp1[i], 100);
    }
    start = clock() - start;
    printf("插入排序耗时：%dms\n", start);
    // 归并排序
    memcpy(cp1, c1, sizeof(cp1));
    start = clock();
    for (int i = 0; i < n; ++i) {
        MergeSort(cp1[i], 0, 99, tmp1[i]);
    }
    start = clock() - start;
    printf("归并排序耗时：%dms\n", start);
    // 快速排序（递归）
    memcpy(cp1, c1, sizeof(cp1));
    start = clock();
    for (int i = 0; i < n; ++i) {
        QuickSort_Recursion(cp1[i], 0, 99);
    }
    start = clock() - start;
    printf("快速排序（递归）耗时：%dms\n", start);
    // 快速排序（非递归）
    memcpy(cp1, c1, sizeof(cp1));
    start = clock();
    for (int i = 0; i < n; ++i) {
        QuickSort(cp1[i], 100);
    }
    start = clock() - start;
    printf("快速排序（非递归）耗时：%dms\n", start);
    // 计数排序
    memcpy(cp1, c1, sizeof(cp1));
    start = clock();
    for (int i = 0; i < n; ++i) {
        CountSort(cp1[i], 100, max[i]);
    }
    start = clock() - start;
    printf("计数排序耗时：%dms\n", start);
    // 基数计数排序
    start = clock();
    for (int i = 0; i < n; ++i) {
        RadixCountSort(c1[i], 100);
    }
    start = clock() - start;
    printf("基数计数排序耗时：%dms\n", start);

}
void screen2(){
	system("cls"); 
    printf("╔=======================================================╗\n");
    printf("║                   数据挖掘 黄倬熙                     ║\n");
    printf("║*********        1、1 x 1e4 大数据读取        *********║\n");
    printf("║*********        2、1 x 5e4 大数据读取        *********║\n");
    printf("║*********        3、1 x 2e5 大数据读取        *********║\n");
    printf("║*********        4、100 x 1e5 大量小数组读取  *********║\n");
    printf("║*********        5、清空屏幕                  *********║\n");
    printf("║*********        6、退出程序                  *********║\n");
    printf("╚=======================================================╝\n");
}
int read_long_data(int n){ //int类型函数，根据返回值查看是否正确读取
    FILE *fpRead=fopen("data_long.txt","r");
    if(fpRead==NULL){
        printf("读取错误！\n"); //找不到则报错
        return -1;
    }
    int check = 0;
    for (int i = 0; i < n; ++i) {
        check = fscanf(fpRead, "%d ", &c0[i]);
        if (check==EOF){
            printf("遇到错误！\n"); //读不了（数据长度1e4你要读2e5这种情况）
            return -1;
        }
    }
    fclose(fpRead);
    return 0;
}
int read_small_data(int n){
    FILE *fpRead=fopen("data_small.txt","r");
    if(fpRead==NULL){
        printf("读取错误！\n"); //找不到则报错
        return -1;
    }
    int check = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 100; ++j) {
            check = (fpRead, "%d ", &c1[i][j]);
            if (check == EOF){
                printf("读取出错！\n"); //读不了则报错
                return -1;
            }
        }
    }
    fclose(fpRead);
    return 0;
}
int main(void) {
    screen2();
    while (1) {
        printf("请选择功能>>");
        int choice = input();
        switch (choice) {
            case -1:
                continue;
            case 6:
                return 0;
            case 1:
                if (read_long_data(10000)==-1)
                	break;
                long_test(10000);
                break;
            case 2:
                if (read_long_data(50000)==-1)
                	break;
                long_test(50000);
                break;
            case 3:
                if (read_long_data(200000)==-1)
                	break;
                long_test(200000);
                break;
            case 4:
                if (read_small_data(100000)==-1)
                	break;
                small_test();
                break;
            case 5:
                screen2();
                break;
        }
    }
}
