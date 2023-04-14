/*
 * main.c
 *
 *  Created on: Apr 7, 2023
 *      Author: ahmed
 */
#include <stdio.h>

void Ex1(void)
{
	printf("C programming");
}


void Ex2(void)
{
	int num=0;
	printf("Enter an Intger: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
	printf("You entered: %d",num);
}


void Ex3(void)
{
	int num=0,sum=0,i=0;
	printf("Enter two numbers: ");
	for(i=0;i<2;i++)
	{
		fflush(stdin);fflush(stdout);
		scanf("%d",&num);
		sum+=num;
	}
	printf("sum: %d",sum);
}


void Ex4(void)
{
	float num=0,mul=1,i=0;
	printf("Enter two numbers: ");
	for(i=0;i<2;i++)
	{
		fflush(stdin);fflush(stdout);
		scanf("%f",&num);
		mul*=num;
	}
	printf("product: %f",mul);
}


void Ex5(void)
{
	char ch;
	printf("Enter a character : ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&ch);
	printf("ASCII value of %c = %d",ch,ch);
}


void Ex6(void)
{
	float num1,num2,temp;
	printf("Enter value of a:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&num1);
	printf("Enter value of b:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&num2);
	temp=num1;
	num1=num2;
	num2=temp;
	printf("After swapping, value of a: %f\n",num1);
	printf("After swapping, value of b: %f",num2);
}


void Ex7(void)
{
	int num1,num2;
	printf("Enter value of a:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num1);
	printf("Enter value of b:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num2);
	num1=num1^num2;
	num2=num1^num2;
	num1=num1^num2;
	printf("After swapping, value of a: %d\n",num1);
	printf("After swapping, value of b: %d",num2);
}


int main()
{
	Ex7();
	return 0;
}

