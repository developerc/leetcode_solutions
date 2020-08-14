//1. Two Sum   Easy
//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//Example:
//Given nums = [2, 7, 11, 15], target = 9,
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].

#include <stdio.h>
#include <stdlib.h>

int sumtwo(int *, int *, int, int);

int main(){
	int alen = 5;
	int arr1[5] = {1,2,5,6,8};
	int resarr[2] = {0,0};
	int target = 10;
	sumtwo(arr1, resarr, target, alen);
	printf("index1 = %d, index2 = %d\n", resarr[0], resarr[1]);
}

int sumtwo(int * arr1, int * resarr, int target, int alen){
	int index1;
	int index2;
	int val1;
	int val2;
	for(int i=0; i<alen; i++){
		val1 = arr1[i];
		for(int k=0; k<alen; k++){
			if(k == i){
				continue;
			} else {
				val2 = arr1[k];
				if((val1 + val2) == target){
					printf("%d, %d\n", val1,val2);
					resarr[0] = i;
					resarr[1] = k;
					return 1;
				}
			}
		}
	}
	return 0;
}