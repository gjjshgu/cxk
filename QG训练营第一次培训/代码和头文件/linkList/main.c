#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	LinkedList list;
    list = create(list);
    insert(list);
    delete(list);
    rev(list);
    printf("�м���Ϊ��%d\n", FindMidNode(&list)->data);
    search(list);
    loop(list);
    int n;
    printf("�������������˳�:");
    scanf("%d", &n);
    return 0;
}
