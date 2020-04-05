//
// Created by »ÆÙ¾Îõ on 2020/4/4.
//

#ifndef QG_CALCULATER_H
#define QG_CALCULATER_H

#endif //QG_CALCULATER_H
#define MAX 20

typedef double ElemType;

typedef enum Status
{
    ERROR = 0,
    SUCCESS = 1
} Status;

typedef  struct StackNode
{
    ElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
    LinkStackPtr top;
    int	count;
}LinkStack;

typedef struct char_stack{
    char data[100];
    int top_index;
} char_stack;
int flag = -1;

Status clearLStack(LinkStack *s);
Status initLStack(LinkStack *s);
Status pushLStack(LinkStack *s,ElemType data);
Status popLStack(LinkStack *s,ElemType *data);
void init(char_stack *s);
void push(char_stack *s, char e);
Status pop(char_stack *s, char *e);
char data(char s[]);
int count(char s[]);
char* input(char c);
void screen();
