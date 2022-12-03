

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 100


bool haveName(char* str);

void trimTail(char* str);

void trimHead(char* str);

void trimMidle(char* str);

void toSentenceCase(char* str);

void removeSpace(char* str);


int main() {

	char str[1000];

	printf("\nEnter name: ");
	scanf("%99[^\n]", str);
	printf("\nThe Name that you just enter from key board: %s\n ", str);

	bool isName = haveName(str);

	if (!isName) {
		printf("\nPlease enter full name!");
	}
	else {
		
		removeSpace(str);
		toSentenceCase(str);

		printf("\nThe name to normalize: %s\n", str);
		puts(" ");

	}

	
	puts(" ");
	return 0;
}



void removeSpace(char* str) {
	   
	trimTail(str);
	printf("\nThe string after remove last space: %s ", str);

	trimHead(str);
	printf("\nThe string after remove first space: %s ", str);

	trimMidle(str);
	printf("\nThe string after remove midle space: %s", str);



	puts(" ");
}


bool haveName(char* str) {


	int n = strlen(str);

	for (int i = 1; i < n - 2; i++) {
		if (isspace(str[i])) {
			return true;
		}
	}
	return false;
}

void trimTail(char* str) {
	int count = 0; 
	int n = strlen(str);

	int i = n - 1;

	while (isspace(str[i])) {
		count++;
		i--;
	}
	str[n - count] = '\0';
}

void trimHead(char* str) {
	int count = 0;
	int n = strlen(str);

	int i = 0; 
	while (isspace(str[i])) {
		count++;
		i++;
	}

	for (int i = 0; i < n - count; i++) {
		str[i] = str[i + count];
	}

	str[n - count] = '\0';
}

void trimMidle(char* str) {
	int n = strlen(str);
	for (int i = 0; i < n - 1; i++) {
		if (isspace(str[i]) && isspace(str[i + 1])) {
			for (int j = i; j < n - 1; j++) {
				str[j] = str[j + 1];
			}
			str[n - 1] = '\0';
			n--; 
			i--;
		}
	}

}

void toSentenceCase(char* str) {
	int n = strlen(str);

	str[0] = toupper(str[0]);

	for (int i = 0; i < n; i++) {
		if (i < n - 1 && isspace(str[i]) && !isspace(str[i + 1])) {

			str[i + 1] = toupper(str[i + 1]);
		}
	}
}
