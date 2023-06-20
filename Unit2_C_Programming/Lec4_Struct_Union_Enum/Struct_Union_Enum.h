#ifndef ASSIGNMENT_H_
#define ASSIGNMENT_H_

#define CIR_AREA(r) ((2)*(3.14)*(r))

struct SStudent
{
	char name[20];
	unsigned int roll_num;
	unsigned int marks;
};

struct SComplex
{
	int real;
	int img;
};

void Ex1(struct SStudent *s);
void Ex3(struct SComplex *num1,struct SComplex *num2);
void Ex4(struct SStudent *s);
void Ex5();


#endif