//
// Created by 黄倬熙 on 2020/4/12.
//
#include <stdio.h>
#include "AQueue.h"

int main(void){
    screen();
    while (1){
        printf("请选择功能：");
        int n = input(0, 9);
        switch (n){
            case 0:
                return 0;
            case 1:
                init();
                break;
            case 2:
                if (!flag){
                    printf("你还没有创建队列\n");
                    break;
                }
                printf("队列长度为: %d\n", LengthAQueue(aqueue));
                break;
            case 3:
                traverse();
                break;
            case 4:
                clea();
                break;
            case 5:
                destory();
                break;
            case 6:
                push();
                break;
            case 7:
                pop();
                break;
            case 8:
                find_head();
                break;
            case 9:
                screen();
        }
    }
}