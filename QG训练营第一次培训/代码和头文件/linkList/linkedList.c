#include "../head/linkedList.h"
#include <stdio.h>
#include <stdlib.h>

LNode* reverse(LNode *p) {
    if (p == NULL) return NULL;
    if (p->next==NULL) return p;
    LNode *q = reverse(p->next); //递归
    p->next->next = p; //把当前点的后一个点的末尾接到现在的点
    p->next = NULL; //现在的点末尾接空
    return q; //永远返回末尾的点，便于接上头部
}

/**
 *  @name        : Status InitList(LinkList *L);
 *  @description : initialize an empty linked list with only the head node without value
 *  @param       : L(the head node)
 *  @return      : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    *L = (LNode*)malloc(sizeof(LNode)); //申请内存空间
    if (*L==NULL) return ERROR;
    (*L)->next = NULL; //链表头接null
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *  @description : destroy a linked list, free all the nodes
 *  @param       : L(the head node)
 *  @return      : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
    LinkedList p;
    while (*L){ 
        p = (*L)->next; //遍历，不断释放经过点的内存，直到*L为空
        free(*L);
        (*L) = p;
    }
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *  @description : insert node q after node p
 *  @param       : p, q
 *  @return      : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
    if (p == NULL) return ERROR;
    q->next = p->next;
    p->next = q;
    return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *  @description : delete the first node after the node p and assign its value to e
 *  @param       : p, e
 *  @return      : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    if (p == NULL) return ERROR;
    *e = p->next->data; //把删除数据赋值到*e上
    LNode *q = p->next; //记录要删除的点
    p->next = p->next->next; //目标点的前一个点接上目标点的后一个点
    free(q); //释放内存空间
    return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *  @description : traverse the linked list and call the funtion visit
 *  @param       : L(the head node), visit
 *  @return      : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    LNode *p = L;
    printf("head->"); //表示链表头
    do{
        p = p->next;
        printf("%d->", p->data);
        
    } 
    while (p->next!=NULL); //遍历结束判断

    printf("NULL\n");
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *  @description : find the first node in the linked list according to e
 *  @param       : L(the head node), e
 *  @return      : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    LNode *p = L;
    while (p){
        if (p->data == e) { //遍历 搜索释放存在
            printf("包含\n");
            return SUCCESS;
        }
        p = p->next;
    }
    printf("找不到\n"); //遍历运行完了也找不到就真的没有了
    return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *  @description : reverse the linked list
 *  @param       : L(the head node)
 *  @return      : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    if ((*L)==NULL) return ERROR; 
    (*L)->next = reverse((*L)->next); //把头结点以外的结点传入递归函数，然后头结点再接上返回的尾结点
    return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *  @description : judge whether the linked list is looped
 *  @param       : L(the head node)
 *  @return      : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    LNode *p=L, *q=L;
    while (p && p->next){
        q = q->next; //快慢指针法，慢指针追上快指针则有环
        p = p->next->next;
        if (p == q) {
            printf("是循环链表\n");
            return SUCCESS;
        }
    }
    printf("不是循环链表");
    return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *  @description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *  @param       : L(the head node)
 *  @return      : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
    LNode *pre=(*L), *cur=(*L)->next; //设置两个指针，cur在pre的后面
    while (cur && cur->next) { //循环 结束条件为cur到了尾结点
        pre->next = cur->next; //转换过程
        cur->next = pre->next->next;
        pre->next->next = cur;
        pre = cur; //更新两个指针
        cur = cur->next;
    }
    return (*L);
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *  @description : find the middle node in the linked list
 *  @param       : L(the head node)
 *  @return      : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
    LNode *p = (*L);
    int count = 0;
    while (p){
        p = p->next;
        count++; //计算链表长度
    }
    p = (*L);
    for (int i = 0; i < count / 2; ++i) { //得到中间结点为第几个 再做一次遍历
        p = p->next;
    }
    return p;
}
void visit(ElemType e){
    printf("%d", e);
}

//自己定义的函数
//防止崩溃
int input(int min, int max){
    int num, check;
    check = scanf("%d", &num);
    while (check!=1){ //scanf正确读取时返回1，非1则输入了其他东西（eof还是字符）
        while (getchar()!='\n'){ //enter检测
            printf("不爱别伤害，为什么要让我崩溃呢？请重新输入：\n");
            check = scanf("%d", &num); //重新输入
        }
    }
    //数字不在区间内自动转换
    if (num < min){
        printf("太小啦！自动取范围内最小值\n");
        return min;
    } else if (num >max){
        printf("太大啦！自动取范围内最大值\n");
        return max;
    }
    return num;
}
LNode* create(LinkedList list){ //传入空指针 
    InitList(&list);
    printf("输入长度：");
    length = input(1, 2147483647);
    LNode *p = list;
    for (int i = 0; i < length; ++i) { //根据输入长度生成链表 
        LNode *q = (LNode*)malloc(sizeof(LNode));
        printf("输入数据：");
        q->data = input(-2147483647, 2147483647);
        InsertList(p, q);
        printf("成功\n");
        p = p->next;
    }
    printf("已生成链表:\n");
    TraverseList(list, visit);  //打印链表 
    return list;
}
void insert(LinkedList list){ //往链表插入数据 
    int n;
    printf("输入插入结点位置（第几个结点）：");
    n = input(1, length);
    LNode *p = list, *add = (LNode*)malloc(sizeof(LNode));
    for (int i = 0; i < n; ++i) {
        p = p->next;
    }
    printf("输入插入数据：");
    add->data = input(-2147483647, 2147483647);  
    InsertList(p, add);
    TraverseList(list, visit);
}
void delete(LinkedList list){ //删除第几个节点的数据 
    int n;
    printf("输入删除结点的位置（第几个结点）：");
    n = input(1, length);
    LNode *p = list;
    for (int i = 0; i < n - 1; ++i) { //搜索目标节点的前一个节点 
        p = p->next;
    }
    DeleteList(p, &n);
    printf("删除的数据为%d\n已更新链表:\n",n);
    TraverseList(list, visit);
}
void rev(LinkedList list){ //转置和寄偶互换 
    printf("转置后为：\n");
    ReverseList(&list);
    TraverseList(list, visit);
    printf("寄偶互换为：\n");
    TraverseList(ReverseEvenList(&list), visit);
}
void loop(LinkedList list){ //检验是否有环 
    IsLoopList(list);
    printf("\n把尾端接到头上后\n");
    LNode *p = list;   
    while (p->next)
        p = p->next;
    p->next = list->next;  //把结尾接到头头上 
    IsLoopList(list);

}
void search(LinkedList list){ //搜索数字是否存在 
    int n;
    printf("输入要搜索的是否存在数字：");
    n = input(-2147483647, 2147483647);
    SearchList(list, n);
}