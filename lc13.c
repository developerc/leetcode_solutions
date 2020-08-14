//13. Roman to Integer   Easy
//Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
//Symbol       Value
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//Roman numerals are usually written largest to smallest from left to right. 
//However, the numeral for four is not IIII. Instead, the number four is written as IV. 
//Because the one is before the five we subtract it making four. The same principle applies to 
//the number nine, which is written as IX. There are six instances where subtraction is used:
//
//	I can be placed before V (5) and X (10) to make 4 and 9. 
//  X can be placed before L (50) and C (100) to make 40 and 90. 
//  C can be placed before D (500) and M (1000) to make 400 and 900.

//Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

int getLatinInteger(int, char *);

int main(int argc, char **argv){
	int count;
	int latinInt;
	
	char * charLatin = * (argv + 1);
	count = strlen(charLatin);
	printf("User entered number %s, length = %d\n", charLatin, count);
	
	
	for(int i=0; i<count; i++){
		if((* (charLatin + i) == 'I') || (* (charLatin + i) == 'V') || (* (charLatin + i) == 'X') || (* (charLatin + i) == 'L') || (* (charLatin + i) == 'C') || (* (charLatin + i) == 'D') || (* (charLatin + i) == 'M')){
			printf("%c", * (charLatin + i));
		} else {
			printf("\nUser entered not valid Latin integer number!\n");
			return 1;
		}
	}
	printf("\n");
		latinInt = getLatinInteger(count, charLatin);	
	
}

int getLatinInteger(int count, char * charLatin){
	int sum = 0;
	int num;
	int dig1 = 0;

	for(int i; i<count; i++){
		dig1 = *(charLatin + i);
		if(dig1 == 'I'){
			printf("dig1 == I\n");
			num = 1;
			if(*(charLatin + i + 1) == 'V'){
				num = 4;
				i++;
			}
			if(*(charLatin + i + 1) == 'X'){
				num = 9;
				i++;
			}
		} else if(dig1 == 'V') {
			printf("dig1 == V\n");
			num = 5;
		} else if(dig1 == 'X'){
			printf("dig1 == X\n");
			num = 10;
			if(*(charLatin + i + 1) == 'L'){
				num = 40;
				i++;
			}
			if(*(charLatin + i + 1) == 'C'){
				num = 90;
				i++;
			}
		} else if(dig1 == 'L') {
			printf("dig1 == L\n");
			num = 50;
		} else if(dig1 == 'C'){
			printf("dig1 == C\n");
			num = 100;
			if(*(charLatin + i + 1) == 'D'){
				num = 400;
				i++;
			}
			if(*(charLatin + i + 1) == 'M'){
				num = 900;
				i++;
			}
		} else if(dig1 == 'D') {
			printf("dig1 == D\n");
			num = 500;
		} else if(dig1 == 'M') {
			printf("dig1 == M\n");
			num = 1000;
		}
		printf("integer of %c = %d \n", *(charLatin + i),  *(charLatin + i));
		sum = sum + num;
	}
	printf("sum = %d\n", sum);
	return sum;
}
