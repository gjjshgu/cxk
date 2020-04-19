//
// Created by ��پ�� on 2020/4/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "qgsort.h"

int c0[200000], c1[100000][100],cp1[100000][100],tmp1[100000][100];
int copy[200000], temp[200000];

void long_test(int n){
    int max = 0;
    for (int i = 0; i < n; ++i) {
        if (c0[i] > max) max = c0[i];
    }
    // ��������
    memcpy(copy, c0, sizeof(int)*n);
    clock_t start = clock();
    insertSort(copy, n);
    start = clock() - start;
    printf("���������ʱ��%dms\n", start);
    //�鲢����
    memcpy(copy, c0, sizeof(int)*n);
    start = clock();
    MergeSort(copy, 0, n-1, temp);
    start = clock() - start;
    printf("�鲢�����ʱ��%dms\n", start);
    // �������򣨵ݹ飩
    memcpy(copy, c0, sizeof(int)*n);
    start = clock();
    QuickSort_Recursion(copy, 0, n-1);
    start = clock() - start;
    printf("�������򣨵ݹ飩��ʱ��%dms\n", start);
    // �������򣨷ǵݹ飩
    memcpy(copy, c0, sizeof(int)*n);
    start = clock();
    QuickSort(copy, n);
    start = clock() - start;
    printf("�������򣨷ǵݹ飩��ʱ��%dms\n", start);
    // ��������
    memcpy(copy, c0, sizeof(int)*n);
    start = clock();
    CountSort(copy, n, max);
    start = clock() - start;
    printf("���������ʱ��%dms\n", start);
    // ������������
    memcpy(copy, c0, sizeof(int)*n);
    start = clock();
    RadixCountSort(copy, n);
    start = clock() - start;
    printf("�������������ʱ��%dms\n", start);
}
void small_test(){
    int max[100000], n = 100000;
    memset(max, 0, sizeof(int)*n);
    for (int i = 0; i < 100000; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (c1[i][j] > max[i]) max[i] = c1[i][j];
        }
    }
    // ��������
    memcpy(cp1, c1, sizeof(cp1));
    clock_t start = clock();
    for (int i = 0; i < n; ++i) {
        insertSort(cp1[i], 100);
    }
    start = clock() - start;
    printf("���������ʱ��%dms\n", start);
    // �鲢����
    memcpy(cp1, c1, sizeof(cp1));
    start = clock();
    for (int i = 0; i < n; ++i) {
        MergeSort(cp1[i], 0, 99, tmp1[i]);
    }
    start = clock() - start;
    printf("�鲢�����ʱ��%dms\n", start);
    // �������򣨵ݹ飩
    memcpy(cp1, c1, sizeof(cp1));
    start = clock();
    for (int i = 0; i < n; ++i) {
        QuickSort_Recursion(cp1[i], 0, 99);
    }
    start = clock() - start;
    printf("�������򣨵ݹ飩��ʱ��%dms\n", start);
    // �������򣨷ǵݹ飩
    memcpy(cp1, c1, sizeof(cp1));
    start = clock();
    for (int i = 0; i < n; ++i) {
        QuickSort(cp1[i], 100);
    }
    start = clock() - start;
    printf("�������򣨷ǵݹ飩��ʱ��%dms\n", start);
    // ��������
    memcpy(cp1, c1, sizeof(cp1));
    start = clock();
    for (int i = 0; i < n; ++i) {
        CountSort(cp1[i], 100, max[i]);
    }
    start = clock() - start;
    printf("���������ʱ��%dms\n", start);
    // ������������
    start = clock();
    for (int i = 0; i < n; ++i) {
        RadixCountSort(c1[i], 100);
    }
    start = clock() - start;
    printf("�������������ʱ��%dms\n", start);

}
void screen2(){
	system("cls"); 
    printf("�X=======================================================�[\n");
    printf("�U                   �����ھ� ��پ��                     �U\n");
    printf("�U*********        1��1 x 1e4 �����ݶ�ȡ        *********�U\n");
    printf("�U*********        2��1 x 5e4 �����ݶ�ȡ        *********�U\n");
    printf("�U*********        3��1 x 2e5 �����ݶ�ȡ        *********�U\n");
    printf("�U*********        4��100 x 1e5 ����С�����ȡ  *********�U\n");
    printf("�U*********        5�������Ļ                  *********�U\n");
    printf("�U*********        6���˳�����                  *********�U\n");
    printf("�^=======================================================�a\n");
}
int read_long_data(int n){
    FILE *fpRead=fopen("data_long.txt","r");
    if(fpRead==NULL){
        printf("��ȡ����\n");
        return -1;
    }
    int check = 0;
    for (int i = 0; i < n; ++i) {
        check = fscanf(fpRead, "%d ", &c0[i]);
        if (check==EOF){
            printf("��������\n");
            return -1;
        }
    }
    fclose(fpRead);
    return 0;
}
int read_small_data(int n){
    FILE *fpRead=fopen("data_small.txt","r");
    if(fpRead==NULL){
        printf("��ȡ����\n");
        return -1;
    }
    int check = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 100; ++j) {
            check = (fpRead, "%d ", &c1[i][j]);
            if (check == EOF){
                printf("��ȡ����\n");
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
        printf("��ѡ����>>");
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
