#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
char post[50];
//PART 1
struct node
{
	char data;
	struct node *next;


}*top;
//insertion in postfix expression linked list
struct node *insert(char ch,struct node *pstart)
{
	struct node *t,*p;
	p = (struct node *)malloc(sizeof(struct node));
	p->next = NULL;
	p->data = ch;
	t = pstart;
	if(pstart == NULL)
	{
		pstart=p;
	}
	else
	{
		while(t->next != NULL)
		    t = t->next;
		t->next = p;

	}
	return pstart;
}
/* --------- push operation ------- */
void push (char symbol)
{
	struct node *p;
	p = (struct node *)malloc(sizeof(struct node));
	p->data = symbol;
	if(top == NULL)
	{
		top = p;
		p->next = NULL;
	}
	else
	{
		p->next = top;
		top = p;
	}
}
char  pop()
{
	struct node *x;
	char k;
	if(top == NULL)
	{
		printf("Stack Underflow\n");
		return 0;
	}
	else
	{
		x = top;
		top = top->next;
		k = x->data;
		free(x);
		return k;
	}
}
struct node *DisplayPost(struct node *pstart)
{
	struct node *to;
	int i = 0;
	to = pstart;
	while(to != NULL)
	{
		post[i] = to->data;
		++i;
		to = to->next;
	}
	printf("%s\n",post);
	return pstart;
}
//precedence selector
int precedence(char ch)
{
	if(ch == '^')
		return (5);
	else if(ch == '*' || ch == '/')
		return (4);
	else if (ch == '+' || ch == '-')
		return (3);
	else
		return (2);
}
//infix to postfix conversion
struct node *IntoPost(char infix[], struct node *pstart)
{
	int len;
	int index=0;
	char symbol,temp;
	len = strlen(infix);
	while(len > index)
	{
		symbol = infix[index];
		switch(symbol)
		{
			case '(':	push(symbol);
					break;

			case ')':	temp = pop();
					while(temp!='(')
					{
						pstart = insert(temp,pstart);
						temp = pop();
					}
					break;
			case '^':
			case '+':
			case '-':
			case '*':
			case '/':	if(top == NULL)
					{
						push(symbol);
					}
					else
					{
						while(top != NULL && (precedence(top->data) >= precedence(symbol)))
						{
							temp = pop(top);
							pstart = insert(temp,pstart);
						}
						push(symbol);

					}   
					break;
			default:	pstart = insert(symbol,pstart);

		}
		index = index+1;
	}
	while(top != NULL)
	{
		temp = pop();
		pstart = insert(temp,pstart);
	}
	pstart = DisplayPost(pstart);
	return pstart;
}

//PART 2
// Stack type
struct Stack 
{ 
    int top; 
    unsigned capacity; 
    int* array; 
}; 
  
// Stack Operations 
struct Stack* createStack( unsigned capacity ) 
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
  
    if (!stack) return NULL; 
  
    stack->top = -1; 
    stack->capacity = capacity; 
    stack->array = (int*) malloc(stack->capacity * sizeof(int)); 
  
    if (!stack->array) return NULL; 
  
    return stack; 
} 
  
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1 ; 
} 
  
int spop(struct Stack* stack) 
{ 
    if (!isEmpty(stack)) 
        return stack->array[stack->top--] ; 
    return 0; 
} 
  
void spush(struct Stack* stack,int op) 
{ 
    stack->array[++stack->top] = op; 
} 
