//
// Created by 黄倬熙 on 2020/4/19.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
void create_long_data(int n){ //写入长数组
    FILE *fpWrite=fopen("data_long.txt","w"); //打开文件
    if(fpWrite==NULL) {
        printf("写入失败\n");
        return;
    }
    srand((unsigned) time(NULL));
    for (int i = 0; i < n; ++i) {
        fprintf(fpWrite,"%d ",rand() % 400); //遍历，写入随机生成的数据
    }
    fclose(fpWrite); //关闭
    printf("成功！\n");
}
void create_small_data(int n){ //写入n*100的二维数组
    FILE *fpWrite=fopen("data_small.txt","w");
    if(fpWrite==NULL) {
        printf("写入失败\n");
        return;
    }
    srand((unsigned) time(NULL));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 100; ++j) {
            fprintf(fpWrite,"%d ",rand() % 400); //遍历，写入随机生成的数据
        }
        fprintf(fpWrite,"\n");
    }
    fclose(fpWrite); //关闭
    printf("成功！\n");
}
void screen1(){
    printf("╔=====================================================╗\n");
    printf("║                   数据挖掘 黄倬熙                   ║\n");
    printf("║*********        1、1 x 1e4 大数据生成      *********║\n");
    printf("║*********        2、1 x 5e4 大数据生成      *********║\n");
    printf("║*********        3、1 x 2e5 大数据生成      *********║\n");
    printf("║*********     4、100 x 1e5 大量小数组生成   *********║\n");
    printf("╚=====================================================╝\n");
}
int input(){ //防止崩溃
	float num;
    int check = scanf("%f", &num);
    fflush(stdin);
    while (check!=1){
        printf("师兄不要乱输啦！请重新输入：\n");
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
	printf("请选择功能>>");
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
    printf("请按任意键以继续....");
	getchar();  
    return 0;
}

