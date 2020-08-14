//  58. Length of Last Word    Easy
//Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last
//appearing word if we loop from left to right) in the string.
//If the last word does not exist, return 0.
//Note: A word is defined as a maximal substring consisting of non-space characters only.
//Example:
//Input: "Hello World"
//Output: 5

#include <stdio.h>

int getCountLast(char *, int);

int main(int argc, char **argv){
	int cnt=0;
	int i = 0;
	char * srcstr = *(argv + 1);
	
	printf("%s\n", srcstr);
	while(*(srcstr + i)){
	//printf("%c\n", *(srcstr + i));
	i++;
	}
	printf("count cymbols = %d\n", i);
	cnt = getCountLast(srcstr, i);
	printf("Length of last word = %d\n", cnt);
	return 0;
}

int getCountLast(char *srcstr, int i){
	int lgh = 0;
	int flag = 0;
	for(int k=0; k<i; k++){
		printf("%c\n", *(srcstr + k));
		if(*(srcstr + k) == ' '){
			printf("Space! %d\n", k);
			flag = 1;
			lgh = 0;
			continue;
		}
		if(flag == 1){
			lgh++;
		}
	}
	return lgh;
}
