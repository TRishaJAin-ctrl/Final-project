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