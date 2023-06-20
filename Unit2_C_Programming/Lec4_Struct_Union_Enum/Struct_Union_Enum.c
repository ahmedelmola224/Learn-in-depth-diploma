#include <stdio.h>
#include <stdlib.h>
#include <math.h>




void Ex1_Disp(struct SStudent *s)
{
	printf("\nDisplaying Information \n");
		printf("name: %s \n",s->name);
		printf("Marks: %d\n",s->roll_num);
		printf("roll number: %d",s->marks);
}
void Ex1_Scan(struct SStudent *s)
{
	fflush(stdin);
		fflush(stdout);
		printf("Enter information of students: \n");
		printf("Enter name: ");
		fflush(stdin);
		fflush(stdout);
		gets(s->name);
		fflush(stdin);
		fflush(stdout);
		printf("Enter roll number: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&(s->roll_num));
		fflush(stdin);
		fflush(stdout);
		printf("Enter marks: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&(s->marks));
}

void Ex1(struct SStudent *s)
{
	Ex1_Scan(s);
	Ex1_Disp(s);
}





void EnterComplex(struct SComplex *c)
{

	printf("Enter real part: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&(c->real));
	printf("Enter img part: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&(c->img));

}


void Ex3(struct SComplex *num1,struct SComplex *num2)
{
	EnterComplex(num1);
	EnterComplex(num2);
	printf("Result: %d + %di",num1->real+num2->real,num1->img+num2->img);
}


void Ex4(struct SStudent *s)
{
	for(int i=0;i<10;i++)
	{
		Ex1_Scan(s+i);
	}

	for(int i=0;i<10;i++)
	{
		Ex1_Disp(s+i);
	}

}

void Ex5()
{
	int r;
	printf("Radius= ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&r);
	printf("Area is %f",CIR_AREA(r));
}

// Ex6  size of union is ->32  structure with alignment-> 42 with no  alignment-> 40