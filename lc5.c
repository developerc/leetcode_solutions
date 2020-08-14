//5. Longest Palindromic Substring    Medium
//Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//Example 1:
//Input: "babad"
//Output: "bab"
//Note: "aba" is also a valid answer.
//Example 2:
///Input: "cbbd"
//Output: "bb"


#include <stdio.h>
#include <string.h>

int isPalindrom(char *, int);
void getSubstrings(char *, int);
void savePalIfBigger(char *, int);

char bigChar[1000];
int bigInt;

int main(int argc, char **argv){
	char * str = *(argv + 1);
	int lng = strlen(str);

	getSubstrings(str, lng);
	printf("max palindrom substr: %s", bigChar);
	return 0;
}

void savePalIfBigger(char *partstr, int lng){
	if(lng > bigInt){
		for(int i=0; i<lng; i++){
			bigChar[i] = *(partstr + i);
		}
		bigInt = lng;
	}
}

int isPalindrom(char *partstr, int lng){ //проверяем палиндром или нет
	int is = 1;
	printf("%s\n", partstr);
	for(int i=0; i<lng; i++){
		printf("*(partstr + i) = %c, *(partstr + lng - i - 1) = %c\n",*(partstr + i) , *(partstr + lng - i - 1));
		if(*(partstr + i) != *(partstr + lng - i - 1)){
			is = 0;
			return is;
		}
		if(i >= lng/2){
			break;
		}
	}
	savePalIfBigger(partstr, lng);
	return is;
}

void getSubstrings(char * str, int lng){  //получаем строки для проверки на палиндром
	int lnsub = lng;
	char * substr =  str;
	for(int k=0; k<=(lng-2); k++){
		for(int i=2; i<=lnsub; i++){
			if(isPalindrom(substr+k, i)){
			printf("Is palindrom!\n");
		} else {
			printf("Not palindrom!\n");
		}
		}
		lnsub--;
	}
}