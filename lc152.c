//152. Maximum Product Subarray <Middle>
//Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
//Example 1:
//Input: [2,3,-2,4]
//Output: 6
//Explanation: [2,3] has the largest product 6.
//Example 2:
//Input: [-2,0,-1]
//Output: 0
//Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

#include <stdio.h>

int goRight(int *, int, int, int);

int iter, st;

int main(){
	iter = 0;  //index of first element in src array
	st = 0;    //amount steps with multiply
	int src[6] = {2,3,-2,4,5,6};  //input source array here
	int * psrc = src;
	int bp = src[0];  //biggest product
	int sizeArr = sizeof(src)/sizeof(int);
	printf("sizeArr=%d\n", sizeArr);
	for(int i=0; i<sizeArr; i++){
		bp = goRight(psrc, i, bp, sizeArr);
	}
	printf("biggest product = %d, iter = %d, st = %d\n", bp, iter, st);
	return 0;
}

int  goRight(int * psrc, int i, int bp, int sizeArr){
	int product=1;
	for(int step=0; (i + step)<sizeArr; step++){
		product = *(psrc + i + step) * product;
		printf("product=%d, i=%d, step=%d\n", product, i, step);
		if(product > bp){
			bp = product;
			iter = i;
			st = step;
		}
	}
	
	return bp;
}
