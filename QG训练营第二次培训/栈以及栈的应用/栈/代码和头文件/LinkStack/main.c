#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    screen();
    while (1){
        printf("请选择功能：");
        int choice = input(0,9);
        switch(choice) {
            case 1:{
                init();
                break;}
            case 2:{
                find_length();
                break;}
            case 3:{
                traverse(stack);
                break;
            }
            case 4:{
                clearLStack(stack);
                break;
            }
            case 5:{
                destroyLStack(stack);
                break;
            }
            case 6:{
                add();
                break;
            }
            case 7:{
                pop();
                break;
            }
            case 8:{
                int data;
                getTopLStack(stack, &data);
                break;
            }
            case 9:{
                screen();
                break;
            }
            case 0:{
                return 0;
            }
        }
    }
}
