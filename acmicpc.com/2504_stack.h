

#include <stdio.h>
#include <string.h>
#define MAX 51
struct Stack1 {
	int data[MAX];
	int top;
};
void init(Stack1 *s) {
	s->top = -1;
}
int isempty(Stack1 *s) {
	if (s->top == -1) return 1;
	else return 0;
}

void push(int data, Stack1 *s) {
	s->top++;
	s->data[s->top] = data;
	//printf("%d push\n", data);
	return;
}
int pop(Stack1 *s) {
	int a;
	if(isempty(s) == 1 ){ return -1; }
	a = s->data[s->top];
	s->top--;
	//printf("%d pop\n", a);
	return a;
}

Stack1 s;

int main(void) {
	int i,j,a,tmp,p;
	int end;
	char c[51];

	init(&s);
	end = 0;
	scanf("%s", c);
	for (j = 0; j < strlen(c); j++) {
		if (c[j] == '(') push(0, &s);
		else if (c[j] == '[') push(1, &s);
		else if (c[j] == ')') {
			a = pop(&s);
			if (a == 1 || a==-1 ) {
				end = -1;
				break;
			}
			else if(a==0){
				push(2, &s);
			}
			else {
				p = a;
				do {
					tmp = pop(&s);
					if (tmp == 0) {
						break;
					}
					else if (tmp == 1 || tmp == -1) {
						end = -1;
						break;
					}
					else {
						p += tmp;
					}
				} while (1);
				if (end == -1) break;
				push(2 * p, &s);
			}
		}
		else if(c[j] == ']'){
			a = pop(&s);
			if (a<1) {
				end = -1;
				break;
			}
			else if(a==1){
				push(3, &s);
			}
			else {
				p = a;
				do {
					tmp = pop(&s);
					if (tmp == 1) {
						break;
					}
					else if (tmp == 0 || tmp == -1) {
						end = -1;
						break;
					}
					else {
						p += tmp;
					}
				} while (1);
				if (end == -1) break;
				push(3 * p, &s);
			}
		}
	}
	a = 0;
	if (end != -1) {
		while (1) {
			tmp = pop(&s);
			if (tmp == -1) break;
			else if (tmp == 0 || tmp == 1) {
				end = -1; 
				break;
			}
			else a += tmp;
		}
	}

	//if (isempty(&s) == 1&&a!=-1) end = 1;

	if (end == -1) printf("0");
	else printf("%d",a);



	return 0;
}