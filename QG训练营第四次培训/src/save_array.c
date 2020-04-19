//
// Created by ��پ�� on 2020/4/19.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
void create_long_data(int n){
    FILE *fpWrite=fopen("data_long.txt","w");
    if(fpWrite==NULL) {
        printf("д��ʧ��\n");
        return;
    }
    srand((unsigned) time(NULL));
    for (int i = 0; i < n; ++i) {
        fprintf(fpWrite,"%d ",rand() % 400);
    }
    fclose(fpWrite);
    printf("�ɹ���\n");
}
void create_small_data(int n){
    FILE *fpWrite=fopen("data_small.txt","w");
    if(fpWrite==NULL) {
        printf("д��ʧ��\n");
        return;
    }
    srand((unsigned) time(NULL));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 100; ++j) {
            fprintf(fpWrite,"%d ",rand() % 400);
        }
        fprintf(fpWrite,"\n");
    }
    fclose(fpWrite);
    printf("�ɹ���\n");
}
void screen1(){
    printf("�X=====================================================�[\n");
    printf("�U                   �����ھ� ��پ��                   �U\n");
    printf("�U*********        1��1 x 1e4 ����������      *********�U\n");
    printf("�U*********        2��1 x 5e4 ����������      *********�U\n");
    printf("�U*********        3��1 x 2e5 ����������      *********�U\n");
    printf("�U*********     4��100 x 1e5 ����С��������   *********�U\n");
    printf("�^=====================================================�a\n");
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
    if (num < 1 || num > 4)
        return -1;
    return num;
}

int main()
{
	screen1();
	printf("��ѡ����>>");
	int choice = input();
	switch (choice){
		case 1:
			create_long_data(10000);
			break;
		case 2:
			create_long_data(50000);
			break;
		case 3:
			create_long_data(200000);
			break;
		case 4:
			create_small_data(100000);
			break;
		case -1:
			break;
	}
    printf("�밴������Լ���....");
	getchar();  
    return 0;
}

