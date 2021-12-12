#include <string.h>

// returns an integer from a number inside a string
int string_to_int(char str[]) {
	int i = 0, sum = 0;
	while(str[i] != 0){
		if(str[i] >= 48 || str[i] <= 57) {
			sum = sum * 10 + (str[i] - 48);
			i++;
		} else return 0;
	}
	return sum;
}

// transform an integer in binary and returns it inside string
char* int_to_bin(char* ret, int val) {
	for (int i = 15; i >= 0; i--) {
		ret[i] = (val % 2) + '0';
		val /= 2;
	}
	return ret;
}

// changes the extentionfrom .asm to .hack in order to create the output file.
char* asm_to_hack(char* foutN, char* fname, char* ext) {
	int len = strlen(fname);
	strcpy(foutN, fname);
	foutN[len-4] = 0;
	strcat(foutN, ext);
	return foutN;
}

// void function that remove all the comments from the string
void remove_comments(char* str) {
	int i = 0;
	while(str[i] != '\0') {
		if (str[i] == '/') {
			str[i] = 0;
			break;
		}
		i++;
	}
}

// void function that take a string pointer and cleans the spaces tabs and newlines
void clean_string(char* str) {
	int i = 0;
	int j = 0;
	while (str[i] != '\0') {
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	remove_comments(str);
}

// returns the index of the "c" in "str"
int char_search(char *str, char c) {
	for (int i = 0; i < strlen(str); i++){
		if (str[i]==c){
			return i;
		}	
	}
	return -1;
}
