#ifndef STD_H_
#define STD_H_

#include <stdio.h>
#include <string.h>
#include  <stdlib.h>

#define DPRINTF(...) {fflush(stdout); \
					  fflush(stdin); \
					  printf(__VA_ARGS__); \
					  fflush(stdout); \
					  fflush(stdin);}

struct Sdata
{
	int ID;
	char name[40];
	float height;
};

struct SStudent
{
	struct Sdata Student;
	struct SStudent* PNextStudent;
};

static void fill_the_record(struct SStudent* newstudent);
static void ViewStudent(struct SStudent*student);
void AddStudent();
int DeleteStudent();
void ViewStudents();
void DeleteAll();
void Nth_Node_End(unsigned int n);
void GetMiddle();
void Reverse();



#endif