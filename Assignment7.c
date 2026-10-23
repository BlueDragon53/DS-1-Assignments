#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int n){
    stack[top++] = n;
}

int pop(){
    return stack[top--];
}

int evaluate(char exp[]){
    int op1, op2, result =0;

    for(int i = 0; exp[i] != '\0'; i++){
        if(isdigit(exp[i])){
            push(exp[i] - '0');
        }
        else{
            op2 = pop();
            op1 = pop();

            switch(exp[i]){
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
            }

            push(result);
        }
    }

    return pop();
}

int main(){
    char exp[100];
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    printf("Result = %d\n", evaluate(exp));

    return 0;
}
