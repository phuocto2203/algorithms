#include <iostream>
#include <stdio.h>

using namespace std;

char* strstr(char* haystack, char* needle) {
	int i = 0;
	int j = 0;
	char* p = 0;
	while(*(haystack+i) != 0) {
		j = 0;
		while(*(haystack+i) == *(needle+j)) {
			if(j == 0)
				p = haystack+i;
			if(*(needle+j+1) == 0)
				return p;
			j++;
			i++;
		}
		if(j > 0)
			i--;
		else
			i++;
	}
	return NULL;
}

void print(char* str) {
	if(str == NULL) {
		printf("null\n");
		return;
	}

	int i = 0;
	while(*(str+i) != 0) {
		printf("%c", *(str+i));
		i++;
	}
}

int main() {
	char *a, *b;
	a = new char[12];
	b = new char[5];
	a[0] = 'h';
	a[1] = 'e';
	a[2] = 'l';
	a[3] = 'h';
	a[4] = 'e';
	a[5] = 'l';
	a[6] = 'l';
	a[7] = 'o';
	a[8] = 0;

	b[0] = 'h';
	b[1] = 'e';
	b[2] = 'l';
	b[3] = 'l';
	b[5] = 0;

	print(strstr(a, b));

	delete a;
	delete b;
	return 0;
}