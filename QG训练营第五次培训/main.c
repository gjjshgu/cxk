//
// Created by ��پ�� on 2020/4/26.
//
#include <stdio.h>
#include "LinkBiTree.h"



BiTree one;
int main(void){
    screen();
    while (1){
        printf("��ѡ���ܣ�");
        int choice = input();
        switch (choice){
            case -1:
                continue;
            case 9:
                return 0;
            case 1:
                one = (BiTree)malloc(sizeof(BiTNode));
                InitBiTree(&one);
                printf("�����������������������������ʽ\n����ʽ��ABD##E##C##��'#'��ʾ�������ķ��ţ�\n��");
                char c;
                scanf(" %c", &c);
                CreateBiTree(&one, &c);
                flag = 1;
                printf("�����ɹ���\n");
                break;
            case 2:
                if (!flag){
                    printf("����û�д�����������\n");
                    continue;
                }
                pre(one, visit);
                break;
            case 3:
                if (!flag){
                    printf("����û�д�����������\n");
                    continue;
                }
                in(one, visit);
                break;
            case 4:
                if (!flag){
                    printf("����û�д�����������\n");
                    continue;
                }
                post(one, visit);
                break;
            case 5:
                if (!flag){
                    printf("����û�д�����������\n");
                    continue;
                }
                LevelOrderTraverse(one, visit);
                break;
            case 6:
                if (!flag){
                    printf("����û�д�����������\n");
                    continue;
                }
                DestroyBiTree(one);
                flag = 0;
                printf("�ɹ���\n"); 
                break;
            case 7:
                calculator();
                break;
            case 8:
                screen();
                break;
        }
    }
}
