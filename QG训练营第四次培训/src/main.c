#include <stdio.h>
#include "qgsort.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	screen1();
    while (1){
        printf("ÇëÑ¡Ôñ¹¦ÄÜ£º");
        int choice = input();
        switch (choice){
            case -1:
                continue;
            case 6:
                return 0;
            case 1:
                test_long_data(10000);
                break;
            case 2:
                test_long_data(50000);
                break;
            case 3:
                test_long_data(200000);
                break;
            case 4:
                test_small_array();
                break;
            case 5:
                screen1();
                break;
        }
    }
}
