#include "../head/duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void visit(DuLNode *p){ //打印当前结点
    if (p->prior==NULL)
        printf("head->");
    else if (p->next==NULL)
        printf("%d->null\n", p->data);
    else printf("%d<->", p->data);
}
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) { 
    *L = (DuLNode*)malloc(sizeof(DuLNode)); //申请内存空间
    if (*L == NULL) return ERROR;
    (*L)->next = NULL; //单个头结点的前面和后面都为空
    (*L)->prior = NULL;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
    DuLinkedList p; 
    while (*L) { //遍历且不断释放内存空间，直到*L为空
        p = (*L)->next;
        free(*L);
        (*L) = p;
    }
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    if (p==NULL) return ERROR;
    if (p->prior->prior==NULL) { //如果是第一个点前面插入
        DuLNode *head = p->prior; 
        q->prior = head; //插入点前面接头
        head->next = q; //头后面接插入点
        p->prior = q; //p前接q，q后接p
        q->next = p;
    } else {
        DuLNode *r = p->prior; 
        q->prior = r; //和上面同理
        q->next = p;
        r->next = q;
        p->prior = q;
    }
    return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    if (p==NULL)
        {
        printf("错误\n");
        return ERROR;}
    if (p->next==NULL){ //在尾结点后面接q，要让q后面指向null，其他类似
        q->next = NULL;
        q->prior = p;
        p->next = q;
    } else{
        DuLNode *r = p->next;
        q->prior = p;
        q->next = r;
        p->next = q;
        r->prior = q;
    }
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    if (p==NULL)
        return ERROR;
    DuLNode *del = p->next;
    if (del->next==NULL){ //尾结点处理
        free(del);
        p->next = NULL;
        return SUCCESS;
    }
    del->next->prior = p; //普通结点处理
    p->next = del->next;
    *e = del->data;
    free(del);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(DuLNode *q)) {
    DuLNode *p = L;
    while (p!=NULL) { //遍历 打印链表
        (*visit)(p);
        p = p->next;
    }
}
//自己定义的函数
//输入防崩溃
int input(int min, int max){
    int num, check;
    check = scanf("%d", &num);
    while (check!=1){ //scanf返回正确读取的个数，当不为1则是输入了别的东西（字符或eof）
        while (getchar()!='\n'){ //回车检测
            printf("不爱别伤害，为什么要让我崩溃呢？请重新输入：\n");
            check = scanf("%d", &num);
        }
    }
    //输入数据超出区间的自动调整
    if (num < min){
        printf("太小啦！自动取范围内最小值\n");
        return min;
    } else if (num >max){
        printf("太大啦！自动取范围内最大值\n");
        return max;
    }
    return num;
}

DuLinkedList create(DuLinkedList list){ //生成
    InitList_DuL(&list);

    DuLNode *p = list;
    printf("输入链表长度：");
    length = input(1, 2147483647);
    for (int i = 0; i < length; ++i) { //迭代并输入
        DuLNode *q = (DuLNode*)malloc(sizeof(DuLNode));
        printf("输入数据：");
        q->data = input(-2147483647, 2147483647);
        InsertAfterList_DuL(p, q);
        printf("成功\n");
        p = p->next;
    }
    printf("已生成链表:\n");
    TraverseList_DuL(list, visit); //遍历链表
    return list;
}
//插入
void insert(DuLinkedList list){
    int n;
    printf("输入插入结点位置（第几个结点）：");
    n = input(1, length);
    DuLNode *p = list, *add=(DuLNode*)malloc(sizeof(DuLNode));
    for (int i = 0; i < n; ++i){ //迭代，找到目的结点
        p = p->next;
    }
    printf("输入插入数据：");
    add->data = input(-2147483647, 2147483647);
    printf("前插还是后插(1为前，其余为后)：");
    n = input(-2147483647, 2147483647);
    switch (n) {
        case 1:{
            InsertBeforeList_DuL(p, add);
            break;
        }
        default: InsertAfterList_DuL(p, add);
    }
    printf("已更新链表:\n");
    TraverseList_DuL(list, visit);
    length++;
}
//删除结点
void delete(DuLinkedList list){
    int n;
    printf("输入删除结点的位置（第几个结点）：");
    n = input(1, length);
    DuLNode *p = list;
    for (int i = 0; i < n-1; ++i){ //迭代，找到目的结点的前一个结点
        p = p->next;
    }
    DeleteList_DuL(p, &n);
    printf("已更新链表:\n",n);
    TraverseList_DuL(list, visit); //遍历链表
    length--;
}