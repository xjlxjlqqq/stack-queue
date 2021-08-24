#include <stdio.h>
#include <stdlib.h>
//���ַ����棬��������ʱ��ջ��������ʱ�ж�ջ��Ԫ���Ƿ�ƥ�䣨�ã�=����������ƥ���ض��������򵥣�
#define MAX 6//�������������


typedef struct stack
//�������ŵ���ջ��
{
	char data;
	stack * next;//ͷ����nextָ��ջ��

}stack , * Pstack;



bool initPstack (Pstack &L)
//��ʼ��ͷָ�룬ָ���½�ͷ���
{
	L = (Pstack) malloc (sizeof(stack));
	L->next = NULL;
	printf("��ʼ���ɹ�\n");
	return true;
}


bool push(Pstack &L, char b)
//������ջ
{
	Pstack p = (Pstack) malloc (sizeof(stack));

	p->data = b;
	p->next = L->next;
	L->next = p;
	printf ("'%c'����ջ\n", b);
	return true;
}


bool pop(Pstack &L)
//���ų�ջ
{
	Pstack p = L->next;
	L->next = p->next;
	printf ("'%c'�ѳ�ջ\n", p->data);
	return true;
}


bool match(Pstack &L, char b)
//�ж�����ƥ�䣬ͨ���ַ�==��Ӧ���ţ������ǣ�=�������������
{
	Pstack P = L->next;//ջ��
	switch (b)
	{
		case '(':;
		case '[':;
		case '{':;
			printf ("�����ſ���ջ\n");
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
//��������������ж����ɹ���ջ��ʧ�ܷ���
{
	Pstack L;
	initPstack (L);

	char B[MAX]= {'(','[','}','}',']',')'};//������ж�����������

	for (int i=0; i<(MAX); i++)//�ж�
	{
		if (match (L, B[i]))
			printf ("��%d��Ԫ�ء���'%c'ƥ��ɹ�\n",i+1, B[i]) ;
	
		else
		{
			printf("��%d��Ԫ�ء���'%c'ƥ��ʧ�ܣ�ջ��Ϊ'%c'\n",i+1,B[i], L->next->data);
			break;
		
		}
	}


 return;

}