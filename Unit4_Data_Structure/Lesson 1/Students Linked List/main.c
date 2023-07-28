#include "STD.h"


int main()
{
	char temp_text[40];
	char temp_text2[20];
	while(1)
	{
		DPRINTF("\n==================================");
		DPRINTF("\n\t Choose one of the following options\n");
		DPRINTF("\n 1.AddStudent");
		DPRINTF("\n 2.DeleteStudent");
		DPRINTF("\n 3.ViewStudent");
		DPRINTF("\n 4.DeleteAll");
		DPRINTF("\n 5.NthStudentFromEnd");
		DPRINTF("\n 6.GetMiddle");
		DPRINTF("\n 7.Reverse");
		printf("\nEntered option number : ");
		gets(temp_text);

		switch(atoi(temp_text))
		{
			case 1:
				AddStudent();
				break;
			case 2:
				DeleteStudent();
				break;
			case 3:
				ViewStudents();
				break;
			case 4:
				DeleteAll();
				break;
			case 5:
				DPRINTF("\nNumber of student from end:")
				gets(temp_text2);
				Nth_Node_End(atoi(temp_text2));
				break;
			case 6:		
				GetMiddle();
				break;
			case 7:		
				Reverse();
				break;
			default:
				printf("\n Wrong option\n");
				break;			

		}
	}
}