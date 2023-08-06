/*
 * DB_management.c
 *
 *  Created on: Aug 6
 *  Author: Ahmed Essam
 */

#include "FIFO.h"
#include "db_management.h"
#include "stdio.h"
#include <string.h>

Fifo_Buffer_t student_buffer;
sinfo student_arr[DB_SIZE];



/*==========================================================================================
 * @Fn						- 	DB_init
 * @brief					- 	Initialize the DB
 * @retval					-	void
 *==========================================================================================
 */
void DB_init()
{
	FIFO_init(&student_buffer,student_arr,DB_SIZE);

}

/*==========================================================================================
 * @Fn						- 	fill_struct
 * @brief					- 	copy struct to another one
 * @param[in]				-	sinfo *
 * @param[in]				-	sinfo * 
 * @retval					-	void
 * Note						-	Static Function can't be used in another files.
 *==========================================================================================
 */
static void fill_struct(sinfo * std_des,sinfo * std_source)
{
	strcpy(std_des->fname,std_source->fname);
	strcpy(std_des->lname,std_source->lname);
	std_des->roll=std_source->roll;
	std_des->gpa=std_source->gpa;
	for(int i=0;i<5;i++)
	{
		std_des->cid[i]=std_source->cid[i];
	}
}


/*==========================================================================================
 * @Fn						- 	check_repeated_roll
 * @brief					- 	check if the roll number is repeated or not
 * @param[in]				-	sinfo *
 * @retval					-	DB_state_t
 * Note						-	Static Function can't be used in another files.
 *==========================================================================================
 */
static DB_state_t check_repeated_roll(sinfo * std)
{
	unsigned int i=1;
	sinfo temp;
	DB_state_t state=DB_NOT_REPEATED_ROLL;
	while(FIFO_get_element(&student_buffer,&temp,i)==FIFO_no_error)//checked
	{
		if(std->roll==temp.roll)
		{
			state= DB_REPEATED_ROLL;
			break;
		}
		i++;
	}
	return state;
}

/*==========================================================================================
 * @Fn						- 	DB_read
 * @brief					- 	Read DB from file
 * @param[in]				-	FILE *
 * @retval					-	DB_state_t
 * Note						-	read from the file in specific format.
 *==========================================================================================
 */

DB_state_t DB_read(FILE *f)
{
	FILE* fp=f;
	sinfo temp;
	if(fp==NULL)
	{
		DPRINTF("No Such File...\n");
		return DB_FILE_OPENING_ERROR;
	}

	while(fscanf(fp,"%s %s %d %f %d %d %d %d %d",temp.fname,temp.lname,&(temp.roll),&(temp.gpa),&(temp.cid[0]),&(temp.cid[1]),&(temp.cid[2]),&(temp.cid[3]),&(temp.cid[4]))!=EOF)
	{
		if(check_repeated_roll(&temp)==DB_NOT_REPEATED_ROLL)
		{
			if(FIFO_enqueue(&student_buffer,temp)==FIFO_no_error)
			{
				DPRINTF("student read successfully...\n");
			}
			else 
			{
				DPRINTF("DB is full...\n");
				return DB_ERROR;
			}
			
		}
		else
		{
			DPRINTF("%d is Repeated roll...\n",temp.roll);
		}
	}
	return DB_NO_ERROR;
}


/*==========================================================================================
 * @Fn						- 	DB_add_row
 * @brief					- 	Add Row To The DB
 * @param[in]				-	sinfo *
 * @retval					-	DB_state_t
 * Note						-	check if the roll number is repeated if not, it enqueue the 
 								element in the DB.
 *==========================================================================================
 */
DB_state_t DB_add_row(sinfo *std)
{
	
	if(check_repeated_roll(std)==DB_REPEATED_ROLL)
	{
		DPRINTF("%d is Repeated roll...\n",std->roll);
		return DB_REPEATED_ROLL;
	}

	if(FIFO_enqueue(&student_buffer,*std)!=FIFO_no_error)
	{
		DPRINTF("DB is full...\n");
		return DB_ERROR;
	}
	return DB_NO_ERROR;
}


/*============================================================================================
 * @Fn						- 	DB_find_roll
 * @brief					- 	Find record with specific roll number
 * @param[in]				-	sinfo *
 * @retval					-	DB_state_t
 * Note						-	Iterate DB's elements and compares it's roll number
 								with specific roll number.
 *============================================================================================
 */
DB_state_t DB_find_roll(sinfo *std)
{
	unsigned int i=1;
	sinfo temp;
	DB_state_t state=DB_NOT_FOUND;
	while(FIFO_get_element(&student_buffer,&temp,i)==FIFO_no_error)//checked
	{
		if(std->roll==temp.roll)
		{
			fill_struct(std,&temp);
			state= DB_NO_ERROR;
			break;
		}
		i++;
	}
	return state;
}


/*============================================================================================
 * @Fn						- 	DB_find_with_firstname
 * @brief					- 	Find all records that have First Name entered
 * @param[in]				-	sinfo *
 * @param[in]				-	char  *
 * @param[in]				-	unsigned int *
 * @retval					-	DB_state_t
 * Note						-	Iterate DB's elements and compares it's first name
 								with specific first name.
 *============================================================================================
 */
DB_state_t DB_find_with_firstname(sinfo *std,char *fname,unsigned int *count)
{
	DB_state_t state=DB_NOT_FOUND;
	sinfo temp;
	unsigned int i=1;
	while(FIFO_get_element(&student_buffer,&temp,i)==FIFO_no_error)
	{
		if(strcmp(fname,temp.fname)==0)
		{
			fill_struct(std+(*count),&temp);
			(*count)++;
			state=DB_NO_ERROR;
		}
		i++;

	}
	return state;
}


/*============================================================================================
 * @Fn						- 	DB_find_with_subjects
 * @brief					- 	Find all records that have specific subject id 
 * @param[in]				-	sinfo *
 * @param[in]				-	unsigned int 
 * @param[in]				-	unsigned int *
 * @retval					-	DB_state_t
 * Note						-	Iterate DB's elements and compares it's subjects id
 								with specific subject id.
 *============================================================================================
 */
DB_state_t DB_find_with_subjects(sinfo *std,unsigned int id,unsigned int *count)
{
	DB_state_t state=DB_NOT_FOUND;
	sinfo temp;
	unsigned int i=1;
	while(FIFO_get_element(&student_buffer,&temp,i)==FIFO_no_error)
	{
		if(id==temp.cid[0]||id==temp.cid[1]||id==temp.cid[2]||id==temp.cid[3]||id==temp.cid[4])
		{
			fill_struct(std+(*count),&temp);
			(*count)++;
			state=DB_NO_ERROR;
		}
		i++;

	}
	return state;
}


/*============================================================================================
 * @Fn						- 	DB_count_rows
 * @brief					- 	Count the number of records in the DB
 * @param[in]				-	unsigned int *
 * @retval					-	DB_state_t
 *============================================================================================
 */
DB_state_t DB_count_rows(unsigned int *count)
{
	FIFO_get_count(&student_buffer,count);
	return DB_NO_ERROR;
}



/*==============================================================================================
 * @Fn						- 	DB_delete_row
 * @brief					- 	Delete records that have specific roll number 
 * @param[in]				-	unsigned int 
 * @retval					-	DB_state_t
 * Note						-	Iterate DB's elements and compares to get the rank of the element
 								then delete it.
 *===============================================================================================
 */
DB_state_t DB_delete_row(unsigned int roll)
{
	DB_state_t state=DB_NOT_FOUND;
	sinfo temp;
	unsigned int i=1;
	unsigned int count=0;
	while(FIFO_get_element(&student_buffer,&temp,i)==FIFO_no_error)
	{
		if(roll==temp.roll)
		{
			count=i;
			state=DB_NO_ERROR;
			break;
		}
		i++;
	}

	if(state==DB_NO_ERROR)
		FIFO_delete_nth_element(&student_buffer,count);

	return state;

}



/*==============================================================================================
 * @Fn						- 	DB_print_table
 * @brief					- 	Print the DB table
 * @retval					-	DB_state_t
 *===============================================================================================
 */
DB_state_t DB_print_table()
{
	FIFO_print(&student_buffer);
}