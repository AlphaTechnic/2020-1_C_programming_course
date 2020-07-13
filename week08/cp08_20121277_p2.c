#include <stdio.h>
#define SIZE_MAX 100

int getString(char string[]);
void printString(char string[], int sizeString);
void reverseString(char string[], int sizeString);

int main() {
	char string[SIZE_MAX];
	int sizeString;

	while ((sizeString = getString(string)) != EOF) {
		reverseString(string, sizeString);
		printString(string, sizeString);
	}
	return 0;
}

int getString(char string[]) {
	char ch;
	int i = 0;

	printf("\n문자열을 입력하시기 바랍니다.");
	printf("\n(단, 종료는 CTRL-Z) : ");

	while (1) {
		ch = getchar();
		string[i] = ch;
		i++;

		if (ch == '\n') {
			break;
		}
		else if (ch == EOF) {
			return EOF;
		}
	}
	return i - 1;
}

void printString(char string[], int sizeString) {
	int i = 0;
	char ch;

	for (i = 0; i < sizeString; i++) {
		putchar(string[i]);
	}
	printf("\n");
	return;
}

void reverseString(char string[], int sizeString) {
	int front;
	int rear;
	char temp;

	printf("역으로 배열한 문자열은 : ");

	for (front = 0, rear = sizeString - 1; front < rear; front++, rear--) {
		temp = string[front];
		string[front] = string[rear];
		string[rear] = temp;
	}
	return;
}