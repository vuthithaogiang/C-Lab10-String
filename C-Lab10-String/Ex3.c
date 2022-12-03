
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void trimHead(char* str); // remove space in first 

void trimTail(char* str); // remove space in last 

void toSentenceCase(char* str); 

void trimMiddle(char* str);

int main() {

	char str[100];

	printf("\nEnter string: ");
	scanf("%[^\n]", str);

	printf("\nThe string that you just enter from keyboard: %s\n", str);

	trimTail(str);
	printf("\nRemove space in the last string: %s\n", str);

	trimHead(str);

	printf("\nRemove space in the first string: %s\n", str);

	trimMiddle(str);
	printf("\nRemove space in midle: %s\n", str);

	toSentenceCase(str);

	printf("\nTo upper first character in sentence: %s\n", str);

	puts(" ");


	return 0;
}

void trimHead(char* str) { 
	int count = 0;
	int n = strlen(str);

	int i = 0; 

	//count space
	while (isspace(str[i])) {
		count++;
		i++;
	}
	
	//dich cac ki tu sang tra count don vi

	for (int i = 0; i < n - count; i++) {
		str[i] = str[i + count];
	}

	// remove n-count

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

	str[n - count] = '\0'; // vi tri dau

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

void trimMiddle(char* str) {

	int n = strlen(str);

	for (int i = 0; i < n - 1; i++) {
		if (isspace(str[i]) && isspace(str[i + 1])) {

			for (int j = i; j < n - 1; j++) {
				

				str[j] = str[j + 1];
			}

			str[n - 1] = '\0';
			n--;
			i--; // quay lai xet tiep
		}
	}
}
