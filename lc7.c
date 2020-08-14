// 7. Reverse Integer  Easy
//Given a 32-bit signed integer, reverse digits of an integer.
//Example 1:
//Input: 123
//Output: 321

#include <stdio.h>
#include <stdlib.h>

void main(int argc, char **argv){
	//int input = 560080;
	if (argc < 2){
		printf("add argument!\n");
		exit;
	}
	int input = atoi(* (argv + 1));
	int rest;
	int out;
	int intArr[10];	 //поскольку самое длинное число int состоит из 10 разрядов
	int count = 0;
	int mul;
	int dec;
	int iter = 0;
	int intPalindr = 0;
	int isNegative;
	
	out = input;
	while(out){	
	rest = out%10;
	out=out/10;
	//intArr = intArr + count;
	intArr[count]  = rest;
	printf("rest = %d\n", rest);
	printf("out = %d\n", out);
	printf("intArr[%d] = %d\n", count, intArr[count]);
	count++;
	}
	printf("count = %d\n", count);
	//count = count - 1;
	//intArr = intArr - sizeof(int);
	
	while(count){
		mul = count;
		dec = 1;
		while(mul){
			dec = dec * 10;
			mul--;
		}
		dec = dec / 10;
		count--;
		printf("dec = %d, %d, %d\n", dec, intArr[iter], dec * intArr[iter]);
		intPalindr = intPalindr + dec * intArr[iter];
		iter++;
	}
	printf("Palindrom of integer: %d\n", intPalindr);
}
