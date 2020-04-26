//
// Created by 黄倬熙 on 2020/4/26.
//
#include <stdio.h>
#include "LinkBiTree.h"



BiTree one;
int main(void){
    screen();
    while (1){
        printf("请选择功能：");
        int choice = input();
        switch (choice){
            case -1:
                continue;
            case 9:
                return 0;
            case 1:
                one = (BiTree)malloc(sizeof(BiTNode));
                InitBiTree(&one);
                printf("利用先序遍历构造二叉树，请输入格式\n（格式如ABD##E##C##，'#'表示空子树的符号）\n：");
                char c;
                scanf(" %c", &c);
                CreateBiTree(&one, &c);
                flag = 1;
                printf("创建成功！\n");
                break;
            case 2:
                if (!flag){
                    printf("您还没有创建二叉树！\n");
                    continue;
                }
                pre(one, visit);
                break;
            case 3:
                if (!flag){
                    printf("您还没有创建二叉树！\n");
                    continue;
                }
                in(one, visit);
                break;
            case 4:
                if (!flag){
                    printf("您还没有创建二叉树！\n");
                    continue;
                }
                post(one, visit);
                break;
            case 5:
                if (!flag){
                    printf("您还没有创建二叉树！\n");
                    continue;
                }
                LevelOrderTraverse(one, visit);
                break;
            case 6:
                if (!flag){
                    printf("您还没有创建二叉树！\n");
                    continue;
                }
                DestroyBiTree(one);
                flag = 0;
                printf("成功！\n"); 
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
