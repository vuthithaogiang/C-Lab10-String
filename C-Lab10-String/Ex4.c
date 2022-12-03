

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<ctype.h>
#include<string.h>
#define N 100


void split(char* str, char** words, int* n);

void listedWords(char** words, int n);

void trimHead(char* str);

void trimTail(char* str);

void trimMidle(char* str);

void toNormalizeString(char* str);

void countWordInString(char* str, char** words, int* n);

int numberOfVowelInString(char* str);

float rateVowelInString(char* str);

int main() {
	char str[10000];
	printf("\nEnter string: ");
	scanf("%999[^\n]", str);

	printf("\nNumber of characters in the string: %u\n", strlen(str));

	float rate = rateVowelInString(str);

	printf("\nRate characters are vowel in the string: %.2f \n", rate);

	int n; 
	char** words = (char**)malloc(N * sizeof(char*));

	for (int i = 0; i < N; i++) {
		words[i] = (char*)malloc(30 * sizeof(char));
	}

	toNormalizeString(str);

	countWordInString(str, words, &n);
	

	puts(" ");
	return 0;
}

void countWordInString(char* str, char** words, int* n) {
	split(str, words, n);

	printf("\nHave %d words in string.\n", *n);
	printf("\nListed words in sentence: \n");

	listedWords(words,*n);


	puts(" ");

}

void split(char* str, char** words, int* n) {
	const char* delim = " ,.?:;!";

	char* p = strtok(str, delim);

	int count = 0;
	while (p != NULL) {
		strcpy(words[count], p);
		count++;
		p = strtok(NULL, delim);
	}

	*n = count;
}

void toNormalizeString(char* str) {
	trimTail(str);
	printf("\nThe string after remove last space: %s ", str);

	trimHead(str);
	printf("\nThe string after remove first space: %s ", str);

	trimMidle(str);
	printf("\nThe string after remove midle space: %s", str);

	puts(" ");
}


void listedWords(char** words, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s\n ", words[i]);
	}

	puts(" ");
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

int numberOfVowelInString(char* str) {
	int n = strlen(str);
	int count = 0;

	for (int i = 0; i < n - 1; i++) {

		if (str[i] == 'u' || str[i] == 'e' || str[i] == 'o' || str[i] == 'a'
			|| str[i] == 'i') {
			count++;
		}
	}
	return count;

}

float  rateVowelInString(char* str) {
	int n = strlen(str);

	int count = numberOfVowelInString(str);

	return (float) 100 * count / (n-1) ;

}