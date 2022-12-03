// C-Lab10-String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*nhap chuoi va ki tu
* kiem tra so lan xuat hien
*/
#include<stdio.h>
#include<string.h>

int countCharacterX(const char* str, const char x);

int main() {
	char str[100];
	char x;

	printf("\nEnter string: ");
	scanf("%99[^\n]", str);

	printf("\nThe string that yoy just enter from keyboard: %s\n", str);

	printf("\nEnter character that find in the string: ");
	scanf("%*c%c", &x);

	int count = countCharacterX(str, x);

	printf("\nThe number of occurrences of \'%c\' in the string: %d \n", x, count);

	puts(" ");
	return 0;
}

int countCharacterX(const char* str, const char x) {

	int i;
	int count = 0;
	int size = strlen(str);

	for (i = 0; i < size; i++) {
		if (str[i] == x) {
			count++;
		}
	}
	return count;
}
