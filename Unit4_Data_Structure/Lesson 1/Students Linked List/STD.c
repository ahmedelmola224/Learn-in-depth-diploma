#include "STD.h"

static struct SStudent * gFirstStudent=NULL;

static void fill_the_record(struct SStudent* newstudent)
{
	char temp_text[40];
	newstudent->PNextStudent=NULL;
	DPRINTF("\nEnter ID : ");
	gets(temp_text);
	newstudent->Student.ID=atoi(temp_text);
	DPRINTF("\nEnter Full Name: ");
	gets(newstudent->Student.name);
	DPRINTF("\nEnter Height: ");
	gets(temp_text);
	newstudent->Student.height=atof(temp_text);
}


static void ViewStudent(struct SStudent*student)
{
	struct SStudent *pCurrent=student;
	DPRINTF("\n Id  %d",pCurrent->Student.ID);
	DPRINTF("\n Name  %s",pCurrent->Student.name);
	DPRINTF("\n Height  %f",pCurrent->Student.height);

}

void AddStudent()
{
	struct SStudent * pNewStudent=(struct SStudent *)malloc(sizeof(struct SStudent));
	fill_the_record(pNewStudent);
	if(gFirstStudent==NULL)
	{
		gFirstStudent=pNewStudent;
	}
	else
	{
		struct SStudent *pCurrentStudent=gFirstStudent;
		while(pCurrentStudent->PNextStudent)
			pCurrentStudent=pCurrentStudent->PNextStudent;

		pCurrentStudent->PNextStudent=pNewStudent;
	}

}

int DeleteStudent()
{
	if(gFirstStudent==NULL)
	{
		DPRINTF("\nThere's No Student ");
		return 0;
	}
	int founded=0;
	struct SStudent * selected_student=gFirstStudent;
	struct SStudent * prev=gFirstStudent;
	char temp_text[40];
	int selected_id;
	DPRINTF("\nEnter ID To Be Deleted : ");
	gets(temp_text);
	selected_id=atoi(temp_text);
	if(selected_id==gFirstStudent->Student.ID)
	{
		founded=1;
		gFirstStudent=gFirstStudent->PNextStudent;
	}
	else
	{
		while(selected_student)
		{
			if(selected_id==selected_student->Student.ID)
			{
				founded=1;
				prev->PNextStudent=selected_student->PNextStudent;
				selected_student->PNextStudent=NULL;
				break;
			}
			prev=selected_student;
			selected_student=selected_student->PNextStudent;
			
		}

	}
	if(founded)
	{
		free(selected_student);
		return 1;
	}
	else
	{
		printf("No Student With This ID");
		return 0;
	}

}
void ViewStudents()
{
	int count =1;
	struct SStudent *pCurrent=gFirstStudent;
	if(gFirstStudent==NULL)
	{
		DPRINTF("\nEMPTY LIST");
	}
	else
	{
		while(pCurrent)
		{
			DPRINTF("\n Record Number %d",count);
			DPRINTF("\n Id  %d",pCurrent->Student.ID);
			DPRINTF("\n Name  %s",pCurrent->Student.name);
			DPRINTF("\n Height  %f",pCurrent->Student.height);
			pCurrent=pCurrent->PNextStudent;
			count++;
		}
	}

}

void DeleteAll()
{
	struct SStudent *pCurrent=gFirstStudent;
	struct SStudent *pTemp=pCurrent;
	if(gFirstStudent==NULL)
	{
		DPRINTF("\nEMPTY LIST");
	}
	else
	{
		while(pCurrent)
		{
			pTemp=pCurrent;
			pCurrent=pCurrent->PNextStudent;
			free(pTemp);

		}
		gFirstStudent=NULL;
	}

}



void Nth_Node_End(unsigned int n)
{

	unsigned int i=0;
	struct SStudent *pCurrent=gFirstStudent;
	struct SStudent *pTemp=pCurrent;
	if(n==0)
		return;

	while(i<n)
	{
		if(pCurrent==NULL)
		{
			DPRINTF("Number of students is less than %d \n ",n);
			return ;
		}
		pCurrent=pCurrent->PNextStudent;
		i++;
	}

	while(pCurrent)
	{
		pCurrent=pCurrent->PNextStudent;
		pTemp=pTemp->PNextStudent;
		printf("Hi");
	}
	ViewStudent(pTemp);
}


void GetMiddle()
{
	if(gFirstStudent==NULL)
	{
		DPRINTF("\nEMPTY LIST");
		return;
	}
	struct SStudent *pCurrent=gFirstStudent;
	struct SStudent *pMiddle=gFirstStudent;
	while(pCurrent)
	{
		if(pCurrent->PNextStudent)
			{
				pCurrent=pCurrent->PNextStudent->PNextStudent;
				pMiddle=pMiddle->PNextStudent;	
			}

			else
			     pCurrent=NULL;
	}

	ViewStudent(pMiddle);
}


void Reverse()
{
	struct SStudent *pCurrent=gFirstStudent;
	struct SStudent *pNext=NULL;
	struct SStudent *pPrev=NULL;
	
	while(pCurrent)
	{
		pNext=pCurrent->PNextStudent;
		pCurrent->PNextStudent=pPrev;
		pPrev=pCurrent;
		pCurrent=pNext;
	}
	gFirstStudent=pPrev;

}