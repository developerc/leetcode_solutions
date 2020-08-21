//9. Palindrome Number
//Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
//Example 1:
//Input: 121
//Output: true
//Example 2:
//Input: -121
//Output: false
//Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
//Example 3:
//Input: 10
//Output: false
//Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

#include <stdio.h>

int main(){
	int srcInt = 1332;  //исходное число
	int inArr[10];
	int outArr[10];
	int i = 0;
	int flagPalindrom = 1;
	
	if(srcInt<0){
		printf("Отрицательное число %d не палиндром!\n", srcInt);
		return 1;
	}
	
	while(srcInt){
		inArr[i] = srcInt%10;
		srcInt = srcInt/10;
		i++;
	}
	for(int k=0; k<i; k++){
		outArr[k] = inArr[i-k-1];
	}
	
	printf("число разрядов i=%d\n", i);
	printf("массив в прямом направлении:\n");
	for(int k=0; k<i; k++){
		printf("%d\n", inArr[k]);
	}
	printf("массив в обратном направлении:\n");
	for(int k=0; k<i; k++){
		printf("%d\n", outArr[k]);
	}
	
	for(int k=0; k<i; k++){
		if(inArr[k] != outArr[k]){
			flagPalindrom = 0;
			break;
		}
	}
	if(flagPalindrom == 1){
		printf("Исходное число - палиндром!\n");
	} else {
		printf("Исходное число не палиндром!\n");
	}
	return 0;
}