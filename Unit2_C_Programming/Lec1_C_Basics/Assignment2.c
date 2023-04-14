/*
 * main.c
 *
 *  Created on: Apr 7, 2023
 *      Author: ahmed
 */
#include <stdio.h>

/*Even VS Odd*/
void Ex1(void)
{
	int num=0;
	printf("Enter the Intger you want to check: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
	((num&1)==0)?printf("%d is even",num):printf("%d is odd",num);
}

/*Vowel VS Constant*/
void Ex2(void)
{
	char ch;
	printf("Enter an alphabet: ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&ch);
	switch(ch)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
		printf("%c is Vowel",ch);
		break;
	default:
		printf("%c is const",ch);
		break;

	}

}

/*largest between three*/
void Ex3(void)
{
	float num,largest,i=0;
	printf("Enter 3 numbers");
	fflush(stdin);fflush(stdout);
	scanf("%f",&num);
	largest=num;
	for(i=0;i<2;i++)
	{
		fflush(stdin);fflush(stdout);
		scanf("%f",&num);
		if(num>largest)
			largest=num;
	}
	printf("Largest number = %f",largest);

}

/*Positive VS Negative*/
void Ex4(void)
{
	float num;
	printf("Enter a number");
	fflush(stdin);fflush(stdout);
	scanf("%f",&num);
	if(num>0)
		printf("Positive");
	else if (num<0)
		printf("Negative");
	else
		printf("Zero");
}

/*Alphabet or not*/
void Ex5(void)
{
	char ch;
	printf("Enter a character : ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&ch);
	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		printf("%c is an alphabet",ch);
	else
		printf("%c is not an alphabet",ch);
}

/*sum from 0 to n*/
void Ex6(void)
{
	int n,i=0,sum=0;
	printf("Enter an intger");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	for(i=0;i<=n;i++)
		sum+=i;
	printf("sum= %d",sum);

}

/*Factorial*/
void Ex7(void)
{
	int num=0,i,fact=1;
	printf("Enter an intger");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
	if(num<0)
	{
		printf("Error !!! Factorial of negative doesn't exist");
		return;
	}
	else if(num==0)
	{
		printf("Factorial is 1");
		return;
	}
	for(i=1;i<=num;i++)
		fact*=i;
	printf("Factorial is %d",fact);
}


/*Simple Calculator*/
void Ex8(void)
{
	float num1 ,num2,res=0;
	char op;
	printf("Enter an operator either + or - or * or / : ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&op);
	printf("Enter two operands: ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&num1);
	fflush(stdin);fflush(stdout);
	scanf("%f",&num2);
	switch(op)
	{
	case '+':
		res=num1+num2;
		break;
	case '-':
		res=num1-num2;
		break;
	case '*':
		res=num1*num2;
		break;
	case '/':
		res=num1/num2;
		break;
	}
	printf("%f %c %f =%f",num1,op,num2,res);

}

int main()
{
	Ex8();
	return 0;
}

