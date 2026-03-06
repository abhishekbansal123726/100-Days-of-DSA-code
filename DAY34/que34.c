#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop(){
    struct node* temp = top;
    int x = temp->data;
    top = top->next;
    free(temp);
    return x;
}

int evaluate(char exp[]){
    int i = 0;
    while(exp[i] != '\0'){
        if(isdigit(exp[i])){
            push(exp[i] - '0');
        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            int b = pop();
            int a = pop();
            int res;
            if(exp[i] == '+') res = a + b;
            if(exp[i] == '-') res = a - b;
            if(exp[i] == '*') res = a * b;
            if(exp[i] == '/') res = a / b;
            push(res);
        }
        i++;
    }
    return pop();
}

int main(){
    char exp[100];
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    printf("Result = %d", evaluate(exp));
    return 0;
}
