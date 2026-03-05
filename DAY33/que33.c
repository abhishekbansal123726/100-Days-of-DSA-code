#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char x){
    stack[++top] = x;
}

char pop(){
    return stack[top--];
}

int priority(char x){
    if(x=='+' || x=='-')
        return 1;
    if(x=='*' || x=='/')
        return 2;
    if(x=='^')
        return 3;
    return 0;
}

int main(){
    char exp[100];
    scanf("%s", exp);

    for(int i=0;i<strlen(exp);i++){
        char c = exp[i];

        if(isalnum(c))
            printf("%c", c);
        else if(c=='(')
            push(c);
        else if(c==')'){
            while(stack[top] != '(')
                printf("%c", pop());
            pop();
        }
        else{
            while(top!=-1 && priority(stack[top]) >= priority(c))
                printf("%c", pop());
            push(c);
        }
    }

    while(top!=-1)
        printf("%c", pop());

    return 0;
}
