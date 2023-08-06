#include "FIFO.h"
#include "STD.h"
#include "stdio.h"
#include "STD.h"

int main()
{
	unsigned char choice;
	STD_init();
	while(1)
	{
		
		printf("============================\n");
		printf("1.ADD STUDENTS FROM FILE\n");
		printf("2.ADD STUDENTS MANUALLY\n");
		printf("3.GET STUDENT WITH ID\n");
		printf("4.GET STUDENT WITH FIRST NAME\n");
		printf("5.GET STUDENTS ROLLED IN SPECIFIC SUBJECT\n");
		printf("6.GET THE NUMBER OF STUDENTS \n");
		printf("7.DELETE STUDENT WITH SPECIFIC ID \n");
		printf("8.UPDATE STUDENT WITH SPECIFIC ID \n");
		printf("9.SHOW LIST OF STUDENTS \n");
		printf("Enter the number of your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			STD_add_student_file();
			break;
		case 2:
			STD_add_student_manually();
			break;
		case 3:
			STD_find_rl();
			break;
		case 4:
			STD_find_fn();
			break;
		case 5:
			STD_find_c();
			break;
		case 6:
			STD_tot_s();
			break;
		case 7:
			STD_del_s();
			break;
		case 8:
			STD_up_s();
			break;
		case 9:
			STD_show_s();
			break;
		default:
			printf("No such option\n");

		}
	}

	

}