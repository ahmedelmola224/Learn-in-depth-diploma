/*
 * STD.c
 *
 *  Created on: Aug 6
 *  Author: Ahmed Essam
 */

#include "stdio.h"
#include "STD.h"
#include "DB_management.h"


/*==========================================================================================
 * @Fn						- 	STD_print
 * @brief					- 	print student data 
 * @param[in]				-	sinfo *
 * @retval					-	void
 * Note						-	Static Function can't be used in another files.
 *==========================================================================================
 */
static void STD_print(sinfo *std)
{
	DPRINTF("Student Name: %s %s\n",std->fname,std->lname);
	DPRINTF("Student roll number: %d\n",std->roll);
	DPRINTF("Student GPA: %.2f\n",std->gpa);
	DPRINTF("Student's Subjects ID: %d %d %d %d %d\n",std->cid[0],std->cid[1],std->cid[2],std->cid[3],std->cid[4]);
	DPRINTF("============================\n");
}



/*==========================================================================================
 * @Fn						- 	STD_init
 * @brief					- 	intialize the student module 
 * @retval					-	void
 *==========================================================================================
 */
void STD_init()
{
	DB_init();
	DPRINTF("Intializtion Done ....\n");
	DPRINTF("============================\n");

}


/*==========================================================================================
 * @Fn						- 	STD_add_student_file
 * @brief					- 	open the data base file 
 * @retval					-	void
 * Note						-	pass the file to the DB module 
 *==========================================================================================
 */
void STD_add_student_file()
{
	DPRINTF("Enter the data in the file in the specified format\n");
	DPRINTF("Reading from DB.txt file...\n");
	DPRINTF("============================\n");
	FILE *fp =fopen("DB.txt","r");
	DB_read(fp);
}


/*==========================================================================================
 * @Fn						- 	STD_add_student_manually
 * @brief					- 	add student to the DB
 * @retval					-	void
 * Note						-	collect student data and send it to DB module 
 *==========================================================================================
 */
void STD_add_student_manually()
{
	DPRINTF("Adding Student...\n");
	DPRINTF("============================\n");
	sinfo temp;
	DPRINTF("Enter First Name: ");
	scanf("%s",temp.fname);
	DPRINTF("Enter Last Name: ");
	scanf("%s",temp.lname);
	DPRINTF("Enter roll Number: ");
	scanf("%d",&(temp.roll));
	DPRINTF("Enter GPA: ");
	scanf("%f",&(temp.gpa));
	for(int i=0;i<5;i++)
	{
		DPRINTF("Enter Subject %d Id Number: ",i+1);
		scanf("%d",&(temp.cid[i]));
	}
	if(DB_add_row(&temp)==DB_NO_ERROR)
		DPRINTF("Added Sucessfully...\n");
}


/*==========================================================================================
 * @Fn						- 	STD_find_rl
 * @brief					- 	search for student with roll number
 * @retval					-	void
 *==========================================================================================
 */
void STD_find_rl()
{
	sinfo temp;
	DPRINTF("Searching for Student...\n");
	DPRINTF("============================\n");
	DPRINTF("Enter Roll Number: ");
	scanf("%d",&(temp.roll));
	if(DB_find_roll(&temp)==DB_NO_ERROR)
	{
		STD_print(&temp);
	}

}


/*==========================================================================================
 * @Fn						- 	STD_find_fn
 * @brief					- 	search for student with first name
 * @retval					-	void
 *==========================================================================================
 */
void STD_find_fn()
{
	DPRINTF("Searching for Student...\n");
	DPRINTF("============================\n");
	sinfo std_arr[50];
	unsigned int count=0;
	char name[20];
	printf("Enter the First Name: ");
	scanf("%s",name);
	if(DB_find_with_firstname(std_arr,name,&count)==DB_NOT_FOUND)
		DPRINTF("No Student Found With This Name")
	else
	{
		for(unsigned int i=0;i<count;i++)
			STD_print(std_arr+i);
	}
}


/*==========================================================================================
 * @Fn						- 	STD_find_c
 * @brief					- 	get all students rolled in specific subject
 * @retval					-	void
 *==========================================================================================
 */
void STD_find_c()
{
	DPRINTF("Searching for Student...\n");
	DPRINTF("============================\n");
	sinfo std_arr[50];
	unsigned int count=0;
	unsigned int sub_id;
	printf("Enter the Subject ID: ");
	scanf("%d",&sub_id);
	if(DB_find_with_subjects(std_arr,sub_id,&count)==DB_NOT_FOUND)
	{
		DPRINTF("No Students Rolled In This Subject");
	}
	else
	{
		for(unsigned int i=0;i<count;i++)
			STD_print(std_arr+i);
	}
}


/*==========================================================================================
 * @Fn						- 	STD_tot_s
 * @brief					- 	get students total number
 * @retval					-	void
 *==========================================================================================
 */
void STD_tot_s()
{
	DPRINTF("Counting Students...\n");
	DPRINTF("============================\n");
	unsigned int count =0;
	DB_count_rows(&count);
	DPRINTF("The Total Number Of Students is %d\n",count);
}


/*==========================================================================================
 * @Fn						- 	STD_del_s
 * @brief					- 	delete student with specific roll number
 * @retval					-	void
 *==========================================================================================
 */
void STD_del_s()
{
	unsigned int roll;
	DPRINTF("Deleting Students...\n");
	DPRINTF("============================\n");
	DPRINTF("Enter Roll Number: ");
	scanf("%d",&roll);
	if(DB_delete_row(roll)==DB_NO_ERROR)
	{
		printf("Deleted Sucessfully...\n");
	}
	else
	{
		printf("No Student With This Roll Number\n");
	}
}


/*============================================================================================
 * @Fn						- 	STD_up_s
 * @brief					- 	update student with specific roll number
 * @retval					-	void
 * Note						-	Delete the student firstly if it exists then add him\her again
 *============================================================================================
 */
void STD_up_s()
{
	unsigned int roll;
	DPRINTF("Updaing Students...\n");
	DPRINTF("============================\n");
	DPRINTF("Enter Roll Number: ");
	scanf("%d",&roll);
	if(DB_delete_row(roll)!=DB_NO_ERROR)
	{
		printf("No Student With This Roll Number\n");
		return;
	}
	sinfo temp;
	DPRINTF("Enter First Name: ");
	scanf("%s",temp.fname);
	DPRINTF("Enter Last Name: ");
	scanf("%s",temp.lname);
	DPRINTF("Enter roll Number: ");
	scanf("%d",&(temp.roll));
	DPRINTF("Enter GPA: ");
	scanf("%f",&(temp.gpa));
	for(int i=0;i<5;i++)
	{
		DPRINTF("Enter Subject %d Id Number: ",i+1);
		scanf("%d",&(temp.cid[i]));
	}

	if(DB_add_row(&temp)==DB_NO_ERROR)
		DPRINTF("Updated Sucessfully...\n");

}


/*============================================================================================
 * @Fn						- 	STD_show_s
 * @brief					- 	show the data of all students
 * @retval					-	void
 *============================================================================================
 */
void STD_show_s()
{
	DPRINTF("List Of Students\n");
	DPRINTF("==========================\n");
	DB_print_table();
}



