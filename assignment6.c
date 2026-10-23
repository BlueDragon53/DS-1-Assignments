#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

int isfull() {
	return (top == MAX - 1) ? 1 : 0;
}

int isempty() {
	return (top == -1) ? 1 : 0;
}

void push(char element) {
	stack[++top] = element;
}

char pop() {
	return stack[top--];
}

void display() {
	for (int i = 0; i <= top; i++) {
		printf("%c ", stack[i]);
	}
	printf("\n");
}

char* str_stack[MAX]; 
int top_str = -1;

void push_str(char *str) {
	if (top_str < MAX - 1) {
		top_str++;
		str_stack[top_str] = (char*)malloc(strlen(str) + 1);
		strcpy(str_stack[top_str], str);
	}
}

char* pop_str() {
	if (top_str >= 0) {
		return str_stack[top_str--];
	}
	return NULL;
}

int icp(char ch) {
	if (ch == '+' || ch == '-') return 1;
	if (ch == '*' || ch == '/' || ch == '%') return 2;
	if (ch == '^') return 3;
	if (ch == '(') return 4; 
	return 0;
}

int isp(char ch) {
	if (ch == '+' || ch == '-') return 1;
	if (ch == '*' || ch == '/' || ch == '%') return 2;
	if (ch == '^') return 3;
	if (ch == '(') return 0;
	return 0;
}

int icp1(char ch) {
	if (ch == '+' || ch == '-') return 1;
	if (ch == '*' || ch == '/' || ch == '%') return 2;
	if (ch == '^') return 4;
	if (ch == ')') return 5;
	return 0;
}

int isp1(char ch) {
	if (ch == '+' || ch == '-') return 1;
	if (ch == '*' || ch == '/' || ch == '%') return 2;
	if (ch == '^') return 3;
	if (ch == ')') return 0;
	return 0;
}

int isoperand(char ch) {
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
		return 1;
	return 0;
}

void infixToPostfix(char inexp[], char postexp[]) {
	int k = 0, i = 0;
	char tkn = inexp[i];
	
	while (tkn != '\0') {
		if (isoperand(tkn)) {
			postexp[k++] = tkn;
		} 
		else if (tkn == '(') {
			push(tkn);
		} 
		else if (tkn == ')') {
			while (top != -1 && stack[top] != '(') {
				postexp[k++] = pop();
			}
			if (top != -1) pop();
		} 
		else {
			while (top != -1 && isp(stack[top]) >= icp(tkn)) {
				postexp[k++] = pop();
			} 
			push(tkn);
		}
		tkn = inexp[++i];
	}
	
	while (top != -1) {
		postexp[k++] = pop();
	}
	postexp[k] = '\0';
	printf("Postfix expression: %s\n", postexp);
}

void infixToPrefix(char inexp[], char prefexp[]) {
	char temp[MAX * 2];
	int k = 0;
	int i = strlen(inexp) - 1;

	while (i >= 0) {
		char tkn = inexp[i];
		if (isoperand(tkn)) {
			temp[k++] = tkn;
		} 
		else if (tkn == ')') {
			push(tkn);
		} 
		else if (tkn == '(') {
			while (top != -1 && stack[top] != ')') {
				temp[k++] = pop();
			}
			if (top != -1) pop();
		} 
		else {
			while (top != -1 && isp1(stack[top]) > icp1(tkn)) {
				temp[k++] = pop();
			}
			push(tkn);
		}
		i--;
	}

	while (top != -1) {
		temp[k++] = pop();
	}

	int p = 0;
	for (int j = k - 1; j >= 0; j--) {
		prefexp[p++] = temp[j];
	}
	prefexp[p] = '\0';
	printf("Prefix expression: %s\n", prefexp);
}

void postfixToInfix(char postexp[], char inexp[]) { 
	int l = strlen(postexp);
	top_str = -1;

	for (int i = 0; i < l; i++) {
		char x = postexp[i];
		if (isoperand(x)) {
			char temp[2] = {x, '\0'};
			push_str(temp);
		} 
		else {
			char* op2 = pop_str();
			char* op1 = pop_str();
			
			char E1[MAX * 2];
			sprintf(E1, "(%s%c%s)", op1, x, op2);
			push_str(E1);
			
			free(op1);
			free(op2);
		}
	}

	char* result = pop_str();
	strcpy(inexp, result);
	free(result);
	printf("Infix expression: %s\n", inexp);
}

void postfixToPrefix(char postexp[], char prefexp[]) {
	int l = strlen(postexp);
	top_str = -1; 

	for (int i = 0; i < l; i++) {
		char x = postexp[i];
		if (isoperand(x)) {
			char temp[2] = {x, '\0'};
			push_str(temp); 
		} 
		else {
			char* op2 = pop_str();
			char* op1 = pop_str();
			
			char E1[MAX * 2];
			sprintf(E1, "%c%s%s", x, op1, op2);
			push_str(E1);
			
			free(op1); 
			free(op2);
		}
	}
	
	char* result = pop_str(); 
	strcpy(prefexp, result);
	free(result); 
	
	printf("Prefix expression: %s\n", prefexp);
}

void prefixToInfix(char prefexp[], char inexp[]) {
	int l = strlen(prefexp);
	top_str = -1;

	for (int i = l - 1; i >= 0; i--) {
		char x = prefexp[i];
		if (isoperand(x)) {
			char temp[2] = {x, '\0'};
			push_str(temp);
		} 
		else {
			char* op1 = pop_str();
			char* op2 = pop_str();
			
			char E1[MAX * 2];
			sprintf(E1, "(%s%c%s)", op1, x, op2);
			push_str(E1);
			
			free(op1);
			free(op2);
		}
	}

	char* result = pop_str();
	strcpy(inexp, result);
	free(result);
	printf("Infix expression: %s\n", inexp);
}

void prefixToPostfix(char prefexp[], char postexp[]) {
	int l = strlen(prefexp);
	top_str = -1;

	for (int i = l - 1; i >= 0; i--) {
		char x = prefexp[i];
		if (isoperand(x)) {
			char temp[2] = {x, '\0'};
			push_str(temp);
		} 
		else {
			char* op1 = pop_str();
			char* op2 = pop_str();
			
			char E1[MAX * 2];
			sprintf(E1, "%s%s%c", op1, op2, x);
			push_str(E1); 
			free(op1);
			free(op2);
		}
	}

	char* result = pop_str();
	strcpy(postexp, result);
	free(result);
	printf("Postfix expression: %s\n", postexp);
}

int main() {
	char ch;
	char inexp[MAX * 2];
	char postexp[MAX * 2];
	char prefexp[MAX * 2];

	while (1) {
		printf("\nThe choices are:\n");
		printf("1. Infix to Postfix\n");
		printf("2. Infix to Prefix\n");
		printf("3. Postfix to Infix\n");
		printf("4. Postfix to Prefix\n");
		printf("5. Prefix to Infix\n");
		printf("6. Prefix to Postfix\n");
		printf("7. Exit\n");
		printf("Enter choice: ");
		scanf(" %c", &ch);

		switch (ch) {
			case '1':
				top = -1;
				printf("Enter the infix expression: ");
				scanf("%s", inexp);
				infixToPostfix(inexp, postexp);
				break;

			case '2':
				top = -1;
				printf("Enter the infix expression: ");
				scanf("%s", inexp);
				infixToPrefix(inexp, prefexp);
				break;
			
			case '3':
				printf("Enter the postfix expression: ");
				scanf("%s", postexp);
				postfixToInfix(postexp, inexp);
				break;

			case '4':
				printf("Enter the postfix expression: ");
				scanf("%s", postexp); 
				postfixToPrefix(postexp, prefexp);
				break;

			case '5':
				printf("Enter the prefix expression: ");
				scanf("%s", prefexp);
				prefixToInfix(prefexp, inexp);
				break;
			
			case '6':
				printf("Enter the prefix expression: ");
				scanf("%s", prefexp);
				prefixToPostfix(prefexp, postexp);
				break;

			case '7':
				printf("<<<...Exiting the program...>>>\n");
				return 0;

			default:
				printf("Invalid choice entered\n");
		}
	}
	return 0;
}
