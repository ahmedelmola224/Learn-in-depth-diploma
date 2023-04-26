#include <stdio.h>

/*sum of two multidimensional array*/
void Ex1(void) {
	int i = 0, j = 0, k = 0;
	float arr1[2][2];
	float arr2[2][2];
	for (k = 0; k < 2; k++) {
		printf("Enter Elements Of Matrix %d\n", k + 1);
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 2; j++) {
				printf("Element %d %d : ", i, j);
				fflush(stdin);
				fflush(stdout);
				if (k == 0)
					scanf("%f", arr1[i] + j);
				else
					scanf("%f", arr2[i] + j);

			}
		}

	}
	printf("\nSum of 2 Matrices :\n");
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			printf("%f ", arr1[i][j] + arr2[i][j]);
		}
		printf("\n");
	}
}


/*Average*/
void Ex2(void) {
	float arr[100], sum = 0;
	int n, i;
	printf("Enter the number of data");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("\n%d. Enter Number", i + 1);
		fflush(stdin);
		fflush(stdout);
		scanf("%f", arr + i);
		sum += arr[i];
	}
	printf("Average = %f", sum / n);

}


/*Transpose Of Matrix*/
void Ex3(void) {
	int arr[10][10];
	int r = 0, c = 0, i = 0, j = 0;
	printf("Enter the number of rows and columns :");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d", &r, &c);
	if (r <= 10 && c <= 10) {
		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++) {
				printf("enter element a%d%d:", i, j);
				fflush(stdin);
				fflush(stdout);
				scanf("%d", arr[i] + j);
			}
		}

		printf("Entered Matrix:\n");
		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		printf("Transposed Matrix:\n");
		for (i = 0; i < c; i++) {
			for (j = 0; j < r; j++) {
				printf("%d ", arr[j][i]);
			}
			printf("\n");
		}
	} else {
		printf("The max of rows and columns is 10");
	}
}


/*insert element in an array*/
void Ex4(void) {
	int arr[100], size, i = 0, toBeAdded, index;
	printf("Enter no of elements :");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &size);
	for (i = 0; i < size; i++) {
		fflush(stdin);
		fflush(stdout);
		scanf("%d", arr + i);
	}
	printf("Enter the element to be added:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &toBeAdded);
	printf("Enter the location:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &index);
	for (i = size; i >= index; i--) {
		arr[i] = arr[i - 1];
	}
	arr[i] = toBeAdded;

	for (i = 0; i <= size; i++) {
		printf("%d ", arr[i]);
	}
}


/*Search in array*/
void Ex5(void) {
	int arr[100], size, i = 0, element;
	printf("Enter no of elements :");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &size);
	for (i = 0; i < size; i++) {
		fflush(stdin);
		fflush(stdout);
		scanf("%d", arr + i);
	}
	printf("Enter the element to be searched:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &element);
	for (i = 0; i < size; i++) {
		if (arr[i] == element)
			break;
	}
	if (i < size)
		printf("Number found at location = %d", i+1);

	else
		printf("Not found");

}
