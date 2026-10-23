#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int icp(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;
    if(ch == '*' || ch == '/')
        return 2;
    if(ch == '^')
        return 4;
    if(ch == '(')
        return 5;
    else
        return 0;
}

int isp(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;
    if(ch == '*' || ch == '/')
        return 2;
    if(ch == '^')
        return 3;
    else
        return 0;
}

void in_post(char inexp[], char postexp[])
{
    int i = 0, k = 0;
    char tkn;
    tkn = inexp[i];
    while(tkn != '\0'){
        if(isalnum(tkn)){
            postexp[k] = tkn;
            k++;
        }
        else{
            if(tkn == '('){
                push('(');
            }
            else{
                if(tkn == ')'){
                    while((tkn = pop()) != '('){
                        postexp[k] = tkn;
                        k++;
                    }
                }
                else{
                    while(top != -1 && isp(stack[top]) >= icp(tkn)){
                        postexp[k] = pop();
                        k++;
                    }
                    push(tkn);
                }
            }
        }

        i++;
        tkn = inexp[i];
    }

    while(top != -1){
        postexp[k] = pop();
        k++;
    }

    postexp[k] = '\0';
}

int main()
{
    char inexp[100], postexp[100];

    printf("Enter infix expression: ");
    scanf("%s", inexp);

    in_post(inexp, postexp);

    printf("Postfix expression: %s\n", postexp);

    return 0;
}