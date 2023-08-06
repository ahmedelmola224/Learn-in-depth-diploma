/*
 * STD.h
 *
 *  Created on: Aug 6
 *  Author: Ahmed Essam
 */


#ifndef STUDENT_H_
#define STUDENT_H_

#define DPRINTF(...) {fflush(stdout); \
					  fflush(stdin); \
					  printf(__VA_ARGS__); \
					  fflush(stdout); \
					  fflush(stdin);}
					  


typedef struct 
{
	char fname[50];
	char lname[50];
	float gpa;
	int roll;
	int cid[5];
}sinfo;

void STD_init();
void STD_add_student_file();
void STD_add_student_manually();
void STD_find_rl();
void STD_find_fn();
void STD_find_c();
void STD_tot_s();
void STD_del_s();
void STD_up_s();
void STD_show_s();


#endif