#include <stdio.h>

/*Prime Numbers*/
void Ex1(void) {
	int l, h, j, flag = 0;
	printf("Enter two numbers (intervals)");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d", &l, &h);
	for (; l <= h; l++) {
		flag = 0;
		for (j = 2; j < l; j++) {
			if (l % j == 0) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			printf("%d ", l);
		}
	}
}

/*factoial*/
int Ex2(int n) {

	if (n == 0) {
		return 1;
	}
	return n * Ex2(n - 1);

}

void swap(char*x, char*y) {
	char temp = *x;
	*x = *y;
	*y = temp;
}

/*str reverse*/
void reverseStr(char str[], int n) {

	static char i = 0;
	if (*(str + n) == '\0') {
		return;
	}
	reverseStr(str, n + 1);
	if (i <= n) {
		swap(str + i, str + n);
		i++;

	}

}

/*To make calling reverseStr and passing 0 to it abstracted */
void Ex3(char str[]) {
	reverseStr(str, 0);
}

/*Power of the number*/
int Ex4(int num, int pw) {
	if (pw == 0) {
		return 1;
	}
	return num * Ex4(num, pw - 1);
}