# 四则运算器代码部分 #


---

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//node structure

typedef struct nde
{

	float data;
	struct nde *pNext;
}Nde,*pNde;

//stack structure

typedef struct sack
{

	pNde top;
	pNde bottom;
}Sack,*pSack;

void initsack(pSack ps)
{

	ps->top=(pNde)malloc(sizeof(Nde));
		ps->bottom=ps->top;
		ps->top->pNext=NULL;
	
	return ;
}

int psh(pSack ps,float d)
{

	pNde pnew=(pNde)malloc(sizeof(Nde));
	if(NULL==pnew)
	{
		return 0;
	}
	pnew->data=d;
	pnew->pNext=ps->top;
	ps->top=pnew;
	return 1;
}

float popo(pSack ps)
{

	float result;
	result=ps->top->data;
	ps->top=ps->top->pNext;
	return result;
	
}

int sym(char data)
{

	char symbol[]={'+','-','*','/','(',')','#'};//用1,2,3,4,5存+-*/（ 
	 
	int i=0;
	for(;i<strlen(symbol);i++)
	{
		if(data==symbol[i])
		return 1;

	}
	return 0;
}

int num(char data)
{

	char number[]={'0','1','2','3','4','5','6','7','8','9'};
	int i;
	for(i=0;i<10;i++)
	{
		if(data==number[i])
		return 1;
	}
	return 0;
}

int empty(pSack pp)
{

	if(pp->top==pp->bottom)
	{
		return 1;
	}
	else return 0;
}

int sub(char a)
{

	int su;
	if(a=='+')
	{
		su=1;
	}
	if(a=='-')
	{
		su=2;
	}
	if(a=='*')
	{
		su=3;
	}
	if(a=='/')
	{
		su=4;
	}
	if(a=='(')
	{
		su=0;
	}
	return su;
}

int main()
{

	char str[100];//输入字符串 
	float result;//最后结果 
	Sack pp;//符号栈 
	Sack tt;//数值栈 
	int ci=0;//记录数值栈内节点个数 
	int i=0;//输入字符串的第几个字符 
	float x;//用于计算的数1
	float y; //用于计算的数2 
	int k=0;//把字符变成数值用到的参数 
	char ne[10];//暂存一个数值 如23.9 、78、 9 
	char temp; //用于计算的符号 
	float re;//暂时计算的结果 
	int su;//用于符号优先级比较 
	int yu;//存实时括号数量 
	yu=0;
	printf("please input your string\n");
	scanf("%s",str);
	str[strlen(str)]='#';//标识结束 
	initsack(&pp);
	initsack(&tt);
	while(i<=strlen(str))
	{
		if(sym(str[i])==1)
		{
			if(str[i]=='#')
			{
				while(ci>=2)
			{
					ci=ci-1;
			 	y=popo(&tt);
					x=popo(&tt);
					temp=popo(&pp);
					switch (temp)
					{
					  case 1:
					  re=x+y;
					  break;
					  case 2:
					  re=x-y;
					  break;
					  case 3:
					  re=x*y;
					  break;
					  case 4:
					  re=x/y;
					  break;
					}	
					psh(&tt,re);
				}
				break;
			 }
			 
			 if(str[i]!=')')
			 {
			su=sub(str[i]);
			 	if(su==0)
			{
			 	 	yu++;//有括号则加一 
			}
			
			if(pp.top->data<=su||empty(&pp)==1)//优先级高于栈内符号则入栈 
			{
				psh(&pp,su);
					i++;
					continue;
				}
				else
				{
				   if(ci>=2)
				{
					 ci=ci-1;
					 y=popo(&tt);
					 x=popo(&tt);
					 temp=popo(&pp);
				   	switch (temp)
					{
					  case 1:
					  re=x+y;
					  break;
					  case 2:
					  re=x-y;
					  break;
					  case 3:
					  re=x*y;
					  break;
					  case 4:
					  re=x/y;
					  break;
					}	
					psh(&tt,re);
					su=sub(str[i]);
	   	psh(&pp,su);
					i++;
					continue;
				   }
				   else
				   {
				   	continue;
				   }
		   	}
		}
		else
			{	
			   do
				{
				   if(ci>=2)
				 	{
					 ci=ci-1;
					 y=popo(&tt);
					 x=popo(&tt);
					 temp=popo(&pp);
					switch (temp)
					{
					  case 1:
					  re=x+y;
					  break;
					  case 2:
					  re=x-y;
					  break;
					  case 3:
					  re=x*y;
					  break;
					  case 4:
					  re=x/y;
					  break;
					}	
					psh(&tt,re);
				}
			   }while(ci>=2);
				   	popo(&pp);
					i++;
					yu--;
					continue;   
			 }
		}
		else
		{	
			k=0;
			ne[k++]=str[i];
			i=i+1;
			while(num(str[i])==1||str[i]=='.')
			{
				ne[k]=str[i];
				k++;
				i++;
			}
			psh(&tt,atof(ne));
			memset(ne, 0, sizeof(ne));
			ci++;
		}
		
	}
	result=popo(&tt);
	printf("%f",result);
	system("pause");
	return 0;
}
	
![](https://github.com/canyousee/arithmometer/raw/master/1.PNG)

![](https://github.com/canyousee/arithmometer/raw/master/2.PNG)
