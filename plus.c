#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int itemnumber(char* a)
{
    int b;
    int i;
    int v[]={0,1,2,3,4,5,6,7,8,9};
    b=atoi(a);
    for(i=0;i<10;i++)
    {
    	if(v[i]==b)
    	return b;
	}
    
}
int e2(char *a)
{
	int i,j;
	char b[10];
	char c[10];
	int temp=0;
	if(a[0]=='+'||a[0]=='-')
	{
		c[0]=a[1];
		temp=itemnumber(c);
		memset(c, 0, sizeof(c));
		if(a[0]=='-')
		{
			temp=-temp;
		}
		j=0;
		for(i=2;i<10;i++)
		{
			b[j]=a[i];
			j++;
		}
		return temp+e2(b);	
	}
	else
	{
		return temp;
	}
}
int result(char *a)
{
	char b[10];
	char c[10];
	int i,j;
	int x,y;
	b[0]=a[0];
	x=itemnumber(b);
	memset(b,0,sizeof(b));
	j=0;
	for(i=1;i<10;i++)
	{
		c[j]=a[i];
		j++;
	}
	y=e2(c);
	return x+y;
}
int main()
{
	char a[10];
	int sum;
	printf("input an expresion\n");
	scanf("%s",a);
	sum=result(a);
	printf("%d",sum);
	system("pause");
	return 0;
} 
