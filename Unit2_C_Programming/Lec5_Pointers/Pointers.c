#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Pointers.h"

void Ex1() {
	int m = 29;
	printf("Address of m is %x\n", &m);
	printf("Value of m is %d\n", m);
	int *ab = &m;
	printf("Now ab is assigned with the address of m.\n");
	printf("Address of pointer ab : %x\n", ab);
	printf("Content of pointer ab : %d\n", *ab);
	m = 34;
	printf(
			"The value of m assigned to 34 now.\n Address of pointer ab : %x\n Content of pointer ab : %d\n",
			ab, *ab);
	*ab = 7;
	printf(
			"The pointer value of ab assigned to 7 now.\n Address of pointer ab : %x\n Content of pointer ab : %d",
			ab, *ab);
}


void Ex2() {
	char alpha = 'A';
	char *p = &alpha;
	for (; alpha <= 'Z';) {
		printf("%c ", (*p)++);
	}
}

 void Ex3(char *str)
 {
	 char i=0,*p=str;
	 for(;str[i];i++);
	 for(i=i-1;i>=0;i--)
	 {
		 printf("%c",p[i]);
	 }
 }

void Ex4() {
	int arr[5], i = 0;
	for (; i < 5; i++) {
		printf("Element %d:", i + 1);
		fflush(stdin);
		fflush(stdout);
		scanf("%d", arr + i);
	}
	printf("Reverse order\n");
	for (i = i - 1; i >= 0; i--) {
		printf("%d ", arr[i]);

	}
}



void Ex5() {
	struct Employee a = { "Ahmed", 1 };
	struct Employee b = { "Mohamed", 2 };
	struct Employee* arr[] = { &a, &b };
	struct Employee* (*p)[2] = arr;
	for (int i = 0; i < 2; i++) {
		printf("Employee name %s\n", ((*((*p) + i)))->name);
		printf("Employee name %d\n", ((*((*p) + i)))->id);
	}
}