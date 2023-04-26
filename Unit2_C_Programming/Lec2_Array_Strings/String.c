#include <stdio.h>

/*frequency of character*/
void Ex1(void) {
	char str[100], ch;
	int counter = 0, i = 0;
	printf("Enter the String: ");
	fflush(stdin);
	fflush(stdout);
	gets(str);
	printf("Enter the character to find the frequency: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c", &ch);
	for (i = 0; str[i]; i++) {
		if (str[i] == ch) {
			counter++;
		}
	}
	printf("Frequency of %c = %d", ch, counter);
}

/*str len*/
void Ex2(void) {
	char str[100];
	int i = 0;
	printf("Enter the String: ");
	fflush(stdin);
	fflush(stdout);
	gets(str);
	for (i = 0; str[i]; i++)
		;
	printf("Length of string: %d", i);

}

/*str reverse*/
void Ex3(void) {
	char str[100], temp;
	int i = 0, j = 0;
	printf("Enter the String: ");
	fflush(stdin);
	fflush(stdout);
	gets(str);
	for (i = 0; str[i]; i++)
		;
	for (j = 0; j < i / 2; j++) {
		temp = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = temp;
	}
	printf("%s", str);

}