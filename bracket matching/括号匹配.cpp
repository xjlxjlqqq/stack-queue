#include <stdio.h>
#include <stdlib.h>
//以字符储存，当左括号时入栈，右括号时判定栈顶元素是否匹配（用！=‘’描述不匹配特定条件更简单）
#define MAX 6//括号数组的数量


typedef struct stack
//储存括号的链栈；
{
	char data;
	stack * next;//头结点的next指向栈顶

}stack , * Pstack;



bool initPstack (Pstack &L)
//初始化头指针，指向新建头结点
{
	L = (Pstack) malloc (sizeof(stack));
	L->next = NULL;
	printf("初始化成功\n");
	return true;
}


bool push(Pstack &L, char b)
//括号入栈
{
	Pstack p = (Pstack) malloc (sizeof(stack));

	p->data = b;
	p->next = L->next;
	L->next = p;
	printf ("'%c'已入栈\n", b);
	return true;
}


bool pop(Pstack &L)
//括号出栈
{
	Pstack p = L->next;
	L->next = p->next;
	printf ("'%c'已出栈\n", p->data);
	return true;
}


bool match(Pstack &L, char b)
//判定括号匹配，通过字符==相应括号，或者是！=所需括号来表达
{
	Pstack P = L->next;//栈顶
	switch (b)
	{
		case '(':;
		case '[':;
		case '{':;
			printf ("左括号可入栈\n");
			push (L, b);
			return true;
		case ')':
			if (P->data != '(')
				return false;
			else
			{
				pop(L);
				return true;
			}
		case ']':
			if (P->data != '[')
				return false;
			else
			{
				pop(L);
				return true;
			}

		case '}':
			if (P->data != '{')
				return false;
			else
			{
				pop(L);
				return true;
			}
	}
}

void main ()
//对括号数组进行判定，成功入栈，失败反馈
{
	Pstack L;
	initPstack (L);

	char B[MAX]= {'(','[','}','}',']',')'};//输入待判定的括号数组

	for (int i=0; i<(MAX); i++)//判定
	{
		if (match (L, B[i]))
			printf ("第%d个元素——'%c'匹配成功\n",i+1, B[i]) ;
	
		else
		{
			printf("第%d个元素——'%c'匹配失败，栈顶为'%c'\n",i+1,B[i], L->next->data);
			break;
		
		}
	}


 return;

}