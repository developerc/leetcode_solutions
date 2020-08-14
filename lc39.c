//39. Combination Sum   Medium
//Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
//find all unique combinations in candidates where the candidate numbers sums to target.
//The same repeated number may be chosen from candidates unlimited number of times.
//Note:
//    All numbers (including target) will be positive integers.
//    The solution set must not contain duplicate combinations.
//Example 1:
//Input: candidates = [2,3,6,7], target = 7,
//A solution set is:
//[
//  [7],
//  [2,2,3]
//]
//Example 2:
//Input: candidates = [2,3,5], target = 8,
//A solution set is:
//[
//  [2,2,2,2],
//  [2,3,3],
//  [3,5]
//]
//Constraints:
//    1 <= candidates.length <= 30
//    1 <= candidates[i] <= 200
//    Each element of candidate is unique.
//    1 <= target <= 500
//Нашел способ решения:
//Создаем массив множителей размером такой же как массив кандидатов.
//В цикле заполняем массив множителей каждый раз больше на единицу
//и умножаем соответствующие элементы массивов друг на друга.
//сравниваем сумму произведений, если равно таргет то добавляем в массив решений.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fillArray(int *, int, int);

int main(){
	int iter = 1;
	//int mult = 1;
	int sum = 0;
	int target = 30;									  //input target here
	int candidates[5] = {2,3,6,7,8};					  //input source array here
	int la = sizeof(candidates)/sizeof(int);		  //размер массива чисел кандидатов
	int * pma = (int *) calloc(la, sizeof(int));	  //создали массив множитель
	double ci = pow(20, la);
	
	int cnt = 0;
	
	for(int i=0; i<ci; i++){
	fillArray(pma,la, i);
	for(int k=0; k<la; k++){
			sum = sum + candidates[k] * pma[k];
		}
	printf("", sum);
	if(sum == target){
			printf("\nsum= %d\n", sum);
			printf("i= %d\n", i);
			for(int m=0; m<la; m++){
				printf("%d\n", *(pma + m));
			}
			cnt++;
		}
	sum = 0;
	}
	
	printf("cnt=%d\n", cnt);
	free(pma);
}

void fillArray(int * pma, int la, int num){
	int n = 0;  //
	int ost;
	int div;
	//printf("la= %d\n", la);
	for(n=0; n<la; n++){	//обноляем элементы массива
		*(pma + n) = 0;
	}
	n=0;
	while(div){ 			//заполняем массив числами от 0 до 8
	ost = num%20;
	div = num/20;
	*(pma + n) = ost;
	//printf("div=%d, ost=%d\n", div, ost);
	num = div;
	n++;
	}
}
