/*
 * DB_management.h
 *
 *  Created on: Aug 6
 *  Author: Ahmed Essam
 */


#ifndef DB_MANAGEMENT_
#define DB_MANAGEMENT_



#define DB_SIZE 50
typedef enum 
{
	DB_ERROR,
	DB_REPEATED_ROLL,
	DB_NOT_REPEATED_ROLL,
	DB_FILE_OPENING_ERROR,
	DB_NO_ERROR,
	DB_NOT_FOUND
}DB_state_t; 


void DB_init();
DB_state_t DB_read(FILE *f);
DB_state_t DB_add_row(sinfo *std);
DB_state_t DB_find_roll(sinfo *std);
DB_state_t DB_find_with_firstname(sinfo *std,char*fname,unsigned int *count);
DB_state_t DB_find_with_subjects(sinfo *std,unsigned int id,unsigned int *count);
DB_state_t DB_count_rows(unsigned int *count);
DB_state_t DB_delete_row(unsigned int roll);
DB_state_t DB_update_row(sinfo *std);
DB_state_t DB_print_table();


#endif