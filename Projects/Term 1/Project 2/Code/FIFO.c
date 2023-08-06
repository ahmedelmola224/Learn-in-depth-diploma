/*
 * FIFO.c
 *
 *  Created on: Aug 6
 *  Author: Ahmed Essam
 */



#include "FIFO.h"


/*==========================================================================================
 * @Fn						- 	FIFO_init
 * @brief					- 	Initialize the Queue
 * @param[in]				-	Fifo_Buffer_t*
 * @param[in]				-	element_t*
 * @param[in]				-	unsigned int
 * @retval					-	Fifo_Buffer_Status
 * Note						-	This Function Check Null Pointer Error.If There's No Error ,
 								It Intialize The Queue.
 *==========================================================================================
 */

Fifo_Buffer_Status FIFO_init(Fifo_Buffer_t* fBuf,element_t* arr,unsigned int length)
{
	if(arr==NULL || fBuf==NULL)
		return FIFO_null;

	fBuf->length=length;
	fBuf->count=0;
	fBuf->base=arr;
	fBuf->head=arr;
	fBuf->tail=arr;
	return FIFO_no_error;
}


/*==========================================================================================
 * @Fn						- 	FIFO_enqueue
 * @brief					- 	Add Element To The Queue
 * @param[in]				-	Fifo_Buffer_t*
 * @param[in]				-	element_t
 * @retval					-	Fifo_Buffer_Status
 * Note						-	This Function Check Null Pointer Error.If There's No Error ,
 								It Add The Element and Adjust The Queue Structure Members.
 *==========================================================================================
 */

Fifo_Buffer_Status FIFO_enqueue(Fifo_Buffer_t* fBuf,element_t item)
{
	if(fBuf==NULL||fBuf->head==NULL||fBuf->base==NULL||fBuf->tail==NULL)
		return FIFO_null;

	if(FIFO_isfull(fBuf)==FIFO_full)
	{

		return FIFO_full;
	}

	*(fBuf->head)=item;
	 (fBuf->count)++;

	if(fBuf->head==(fBuf->base+((fBuf->length) *sizeof(element_t))-1))
		fBuf->head=fBuf->base;
	else
		(fBuf->head)++;


	return FIFO_no_error;

}

/*==========================================================================================
 * @Fn						- 	FIFO_dequeue
 * @brief					- 	Remove Element From The Queue
 * @param[in]				-	Fifo_Buffer_t*
 * @param[in]				-	element_t*
 * @retval					-	Fifo_Buffer_Status
 * Note						-	This Function Check Null Pointer Error.If There's No Error ,
 								It Remove The Element and Adjust The Queue Structure Members.
 *==========================================================================================
 */

Fifo_Buffer_Status FIFO_dequeue(Fifo_Buffer_t* fBuf,element_t *item)
{
	if(fBuf==NULL||fBuf->head==NULL||fBuf->base==NULL||fBuf->tail==NULL)
		return FIFO_null;

	if((fBuf->count)==0)
		return FIFO_empty;

	*item=*(fBuf->tail);
	(fBuf->count)--;

	if(fBuf->tail==(fBuf->base+((sizeof(element_t)* fBuf->length))-1))
		fBuf->tail=fBuf->base;
	else
		fBuf->tail++;

	return FIFO_no_error;

}

/*==========================================================================================
 * @Fn						- 	FIFO_isfull
 * @brief					- 	Check If The Buffer Is Full Or Not
 * @param[in]				-	Fifo_Buffer_t*
 * @retval					-	Fifo_Buffer_Status
 * Note						-	This Function Check Null Pointer Error.If There's No Error ,
 								It Compares The Count With Length.
 *==========================================================================================
 */

Fifo_Buffer_Status FIFO_isfull(Fifo_Buffer_t* fBuf)
{
	if(fBuf==NULL||fBuf->head==NULL||fBuf->base==NULL||fBuf->tail==NULL)
	{

		return FIFO_null;
	}

	if(fBuf->count==fBuf->length)
	{

		printf("FIFO FULL");
		return FIFO_full;
	}
	return FIFO_no_error;
}

/*==========================================================================================
 * @Fn						- 	FIFO_print
 * @brief					- 	Print Queue's Elments
 * @param[in]				-	Fifo_Buffer_t*
 * @retval					-	void
 * Note						-	Iterate The Queue And Print Queue's Elments
 *==========================================================================================
 */

void FIFO_print(Fifo_Buffer_t* fBuf)
{
	element_t *temp=fBuf->tail;
	for(int i=0;i<fBuf->count;i++)
	{
		DPRINTF("Student Name: %s %s\n",temp->fname,temp->lname);
		DPRINTF("Student roll number: %d\n",temp->roll);
		DPRINTF("Student GPA: %.2f\n",temp->gpa);
		DPRINTF("Student's Subjects ID: %d %d %d %d %d\n",temp->cid[0],temp->cid[1],temp->cid[2],temp->cid[3],temp->cid[4]);
		DPRINTF("============================\n");
		if(temp==(fBuf->base+((sizeof(element_t)* fBuf->length))-1))
			temp=fBuf->base;
		else
			temp++;

	}
}

/*==========================================================================================
 * @Fn						- 	FIFO_get_element
 * @brief					- 	Get nth Element From The First
 * @param[in]				-	Fifo_Buffer_t*
 * @param[in]				-	element_t* 
 * @param[in]				-	int
 * @retval					-	Fifo_Buffer_Status
 * Note						-	Check if the there's n element in the queue then Iterate to
 								get the element
 *==========================================================================================
 */

Fifo_Buffer_Status FIFO_get_element(Fifo_Buffer_t* fBuf,element_t* element,int element_count)
{
	element_t *ptemp=fBuf->tail;
	if(fBuf->count<element_count)
		return FIFO_error;

	element_count--; //mapping nth element to zero based element
	while(element_count!=0)
	{
		if(ptemp==(fBuf->base+((sizeof(element_t)* fBuf->length))-1))
			ptemp=fBuf->base;
		else
			ptemp++;

		element_count--;
	}
	*element=*ptemp;
	return FIFO_no_error;

}

/*==========================================================================================
 * @Fn						- 	FIFO_get_count
 * @brief					- 	Get nth Element From The First
 * @param[in]				-	Fifo_Buffer_t*
 * @param[in]				-	unsigned int
 * @retval					-	Fifo_Buffer_Status
 * Note						-	Check if the there's n element in the queue then Iterate to
 								get the element
 *==========================================================================================
 */

Fifo_Buffer_Status FIFO_get_count(Fifo_Buffer_t* fBuf,unsigned int *count)
{
	*count=fBuf->count;
	return FIFO_no_error;
}


/*============================================================================================
 * @Fn						- 	FIFO_delete_nth_element
 * @brief					- 	Delete nth Element From The First
 * @param[in]				-	Fifo_Buffer_t*
 * @param[in]				-	unsigned int
 * @retval					-	Fifo_Buffer_Status
 * Note						-	Check if the there's n element in the queue then Iterate to
 								get the element and puts other elements in another queue then
 								delete the specified element and puts the elements back to the
 								queue. 
 *============================================================================================
 */
Fifo_Buffer_Status FIFO_delete_nth_element(Fifo_Buffer_t* fBuf,unsigned int n)
{
	if(fBuf->count<n)
		return FIFO_error;

	element_t temp_var;
	Fifo_Buffer_t temp_fifo;
	element_t temp_arr[50];
	FIFO_init(&temp_fifo,temp_arr,50);
	n--;
	while(n!=0)
	{
		FIFO_dequeue(fBuf,&temp_var);
		FIFO_enqueue(&temp_fifo,temp_var);
		n--;
	}
	FIFO_dequeue(fBuf,&temp_var);

	while(temp_fifo.count!=0)
	{
		FIFO_dequeue(&temp_fifo,&temp_var);
		FIFO_enqueue(fBuf,temp_var);
	}

	return FIFO_no_error;

}