//66. Plus One
//Given a non-empty array of digits representing a non-negative integer, increment one to the integer.
//The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
//You may assume the integer does not contain any leading zero, except the number 0 itself.
//Example 1:
//Input: digits = [1,2,3]
//Output: [1,2,4]
//Explanation: The array represents the integer 123.

#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize);

void main(){
	int digits[3] = {1,2,3};
	int digitsSize = 3;
	int returnSize;
	int * digPlusOne = plusOne(digits, digitsSize, &returnSize);
	for(int i=0; i<returnSize; i++){
		printf("%d", *(digPlusOne + i));
	}
	free(digPlusOne);
}

int* plusOne(int* digits, int digitsSize, int* returnSize){
	char overload = 0;
	int * digPlusOne = NULL;
	
	for(int i=digitsSize - 1; i>=0; i--){
		if(i == digitsSize - 1){
			*(digits + i) = *(digits + i) + 1;
			if(*(digits + i) > 9){
				*(digits + i) = 0;
				overload = 1;
			} else {
				overload = 0;
			}
		} else {
			*(digits + i) = *(digits + i) + overload;
			if(*(digits + i) > 9){
				*(digits + i) = 0;
				overload = 1;
			} else {
				overload = 0;
			}
		}
		printf("digits[i] = %d, overload = %d\n", *(digits + i), overload);
	}
	
	if(overload == 0){
		digPlusOne = (int*) malloc(digitsSize * sizeof(int));
		for(int i=digitsSize - 1; i>=0; i--){
			*(digPlusOne + i) = *(digits + i);
		}
		*returnSize = digitsSize;
	} else {
		digPlusOne = (int*) malloc((digitsSize+1) * sizeof(int));
		for(int i=digitsSize - 1; i>=0; i--){
			*(digPlusOne + i + 1) = *(digits + i);
			
		}
		*(digPlusOne) = overload;
		*returnSize = digitsSize + 1;
	}
	return digPlusOne;
}