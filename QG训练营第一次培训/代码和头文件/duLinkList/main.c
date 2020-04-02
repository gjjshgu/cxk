#include <stdio.h>
#include <stdlib.h>
#include "../head/duLinkedList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	while (1) {
        DuLinkedList list;
        list = create(list);
        insert(list);
        delete(list);
        int n;
        printf("÷ÿ¿¥ ‰»Î1:");
        scanf("%d", &n);
        if (n!=1) break;
        DestroyList_DuL(&list);
        
    }
    return 0;
}
