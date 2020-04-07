//
// Created by 黄倬熙 on 2020/4/4.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculater.h"

Status initLStack(LinkStack *s){
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}
Status pushLStack(LinkStack *s,ElemType data){
    LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));
    p->data = data;
    p->next = s->top;
    s->top = p;
    s->count++;
    return SUCCESS;
}
Status popLStack(LinkStack *s,ElemType *data){
    if (!s->count){
        printf("Error1:表达式有误！\n");
        return ERROR;
    }
    LinkStackPtr p=s->top;
    *data = s->top->data;
    s->top = s->top->next;
    free(p);
    s->count--;
    return SUCCESS;
}
void init(char_stack *s){
    s->top_index = -1;
}
void push(char_stack *s, char e){
    s->data[s->top_index+1] = e;
    s->top_index++;
}
Status pop(char_stack *s, char *e){
    if (s->top_index == -1){
        printf("Error1:表达式有误！\n");
        return ERROR;
    }
    *e = s->data[s->top_index];
    s->top_index--;
    return SUCCESS;
}
char data(char s[]){
    flag++;
    return s[flag];
}
int count(char s[]){
    LinkStack *stack;
    stack = (LinkStack*)malloc(sizeof(LinkStack));
    initLStack(stack); //初始化栈
    int i = 0, check1, check2;
    double d=0.0, e, f;
    char num[MAX], c;
    c = data(s); //读取下一个字符
    while (c!='#'){
        //对负数进行处理
        while ((c>='0' && c<='9') || (c == '.' || c == '-' || c == '+')){
            if (c == '-'){
                c = data(s); //读取
                if (c>='0' && c<='9'){
                    num[i] = '-'; //在缓冲区加入符号，便于计算
                    i++;
                } else{
                    c = '-';
                    break;
                }
            } else if (c == '+'){
                c = data(s);
                if (c>='0' && c<='9'){
                    num[i] = '+';
                    i++;
                } else{
                    c = '+';
                    break;
                }
            }
            num[i] = c;//加入数字
            i++;
            num[i] = '\0'; //加入结尾符
            if (i == MAX-1) return -1;
            c = data(s);
            if (c == ' '){ //遇到空格，则这个数字读取已经结束
                d = atof(num); //转化为double型
                pushLStack(stack, d); //入栈
                i = 0;
                break;
            }
        }
        switch (c){ //出栈运算过程
            case '+': 
                check1 = popLStack(stack, &e);
                check2 = popLStack(stack, &f);
                if (check1==0 || check2==0)
                    return -1;
                pushLStack(stack, f+e);
                break;
            case '-':
                check1 = popLStack(stack, &e);
                check2 = popLStack(stack, &f);
                if (check1==0 || check2==0)
                    return -1;
                pushLStack(stack, f-e);
                break;
            case '*':
                check1 = popLStack(stack, &e);
                check2 = popLStack(stack, &f);
                if (check1==0 || check2==0)
                    return -1;
                pushLStack(stack, f*e);
                break;
            case '/':
                check1 = popLStack(stack, &e);
                check2 = popLStack(stack, &f);
                if (check1==0 || check2==0)
                    return -1;
                if (e == 0){
                    printf("分母不能为0！\n");
                    return -1;
                }
                pushLStack(stack, f/e);
                break;
        }
        c = data(s);
    }
    if (ERROR == popLStack(stack, &d)) //空栈判断
        return 0;
    printf("结果为：%lf\n", d);
    return 0;
}
char* input(char c){
    char result[100] = "\0";
    char_stack *stack = (char_stack*)malloc(sizeof(char_stack));
    init(stack);//初始化字符栈
    char num[100],find;
    int i = 0, check;
    if (c=='-' || c=='+'){
        num[0] = '0';
        num[1] = ' ';
        i = 2;
    } 
    while (c!='\n'){
        //处理（-1）这类数字
        while ((c>='0' && c<='9') || (c == '.' || c == '(')){
            while (c == '('){
                push(stack, '(');//遇到左括号则入栈
                scanf("%c", &c);
                if (c=='-'){//遇到+或-，则加入到缓冲区
                    num[i] = '-';
                    scanf("%c", &c);
                    i++;
                    break;
                } else if (c=='+'){
                    num[i] = '+';
                    scanf("%c", &c);
                    i++;
                    break;
                }
            }
            num[i] = c;
            i++;
            num[i] = '\0';
            if (i == MAX-1){
                printf("数据出错！\n");
                return NULL;}
            scanf("%c", &c);
            if ((c<'0' || c>'9') && c!='.'){
                num[i] = ' ';
                num[i+1] = '\0';
                strcat(result, num); //字符串合并，后加空格，便于读取计算
                i = 0;
                //若栈顶为左括号，c为右括号，可判定负数被括号包起
                if (c==')' && stack->data[stack->top_index]=='('){
                    check = pop(stack, &find); //把左括号出栈
                    if (check == 0)
                        return NULL;
                    scanf("%c", &c);
                }
                break;
            }
        }
        //符号入栈规则
        switch (c){
            case '(':
                push(stack, '(');//左括号直接入栈
                break;
            case '*':
            //优先级小于乘号的，入栈
                if ((stack->data[stack->top_index]=='+'||
                        stack->data[stack->top_index]=='-') ||
                        (stack->top_index==-1 ||
                        stack->data[stack->top_index]=='(')){
                    push(stack, '*');
                } else{ //出栈，直到栈顶元素优先级小于乘号
                    while (1){
                        pop(stack, &find);
                        char sb[3];
                        sb[0] = find;
                        sb[1] = ' ';
                        sb[2] = '\0';
                        strcat(result, sb);
                        if ((stack->data[stack->top_index]=='+'||
                             stack->data[stack->top_index]=='-') || stack->top_index==-1){
                            push(stack, '*'); //找到则入栈
                            break;
                        }
                    }
                }
                break;
            case '/': //与乘法类似
                if ((stack->data[stack->top_index]=='+'||
                     stack->data[stack->top_index]=='-') ||
                    (stack->top_index==-1 ||
                     stack->data[stack->top_index]=='(')){
                    push(stack, '/');
                } else{
                    while (1){
                        check = pop(stack, &find);
                        if (check == 0)
                            return NULL;
                        char sb[3];
                        sb[0] = find;
                        sb[1] = ' ';
                        sb[2] = '\0';
                        strcat(result, sb);
                        if ((stack->data[stack->top_index]=='+'||
                             stack->data[stack->top_index]=='-') || stack->top_index==-1){
                            push(stack, '/');
                            break;
                        }
                    }
                }
                break;
            case ')': //右括号
                while (1){
                    check = pop(stack, &find);//出栈，直到找到左括号
                    if (check == 0)
                        return NULL;
                    if (find=='(') break;
                    char sb[3];
                    sb[0] = find;
                    sb[1] = ' ';
                    sb[2] = '\0';
                    strcat(result, sb); //出栈的运算符输出
                }
                break;
            case '+': 
            //若为空栈，或者栈顶为左括号，则入栈
                if (stack->data[stack->top_index]=='(' || stack->top_index==-1)
                    push(stack, '+');
                else{
                    while (1){
                        check = pop(stack, &find); //不断出栈，直到空栈后
                        if (check == 0)
                            return NULL;
                        char sb[3];
                        sb[0] = find;
                        sb[1] = ' ';
                        sb[2] = '\0';
                        strcat(result, sb);
                        if (stack->top_index==-1){ //空栈判断
                            push(stack, '+'); //再入栈
                            break;
                        }
                    }
                }
                break;
            case '-': //与加号类似
                if (stack->data[stack->top_index]=='(' || stack->top_index==-1)
                    push(stack, '-');
                else{
                    while (1){
                        check = pop(stack, &find);
                        if (check == 0)
                            return NULL;
                        char sb[3];
                        sb[0] = find;
                        sb[1] = ' ';
                        sb[2] = '\0';
                        strcat(result, sb);
                        if (stack->top_index==-1){
                            push(stack, '-');
                            break;
                        }
                    }
                }
        }
        scanf("%c", &c);
    }
        while (stack->top_index!=-1){ //栈非空时，输出栈内元素
            check = pop(stack, &find);
            if (check == 0)
                return NULL;
            char sb[3];
            sb[0] = find;
            sb[1] = ' ';
            sb[2] = '\0';
            strcat(result, sb);
        }
    printf("后缀表达式为：%s\n", result); //输出后缀表达式
    char sb[2] = "#";
    strcat(result, sb);
    count(result); //计算后缀表达式
    return NULL;
}
void screen(){
    system("cls");
    printf("╔====================================================╗\n");
    printf("║                   数据挖掘 黄倬熙                  ║\n");
    printf("║                 小渣渣写的智障计算器               ║\n");
    printf("║                     支持小数运算                   ║\n");
    printf("║                   负数请用括号包起                 ║\n");
    printf("║                      退出请扣q                     ║\n");
    printf("║                      清屏请扣c                     ║\n");
    printf("╚====================================================╝\n");
}
int main(void){
    screen();
    while (1){
        flag = -1;
        printf("请输入中缀表达式（输入后双击回车）：");
        char c;
        scanf(" %c", &c);
        if (c=='q')
            return 0;
        if (c=='c'){
            screen();
            continue;
        }
        input(c);
    }
}
