//151. Reverse Words in a String    Medium
//Given an input string, reverse the string word by word
//Example 1:
//Input: "the sky is blue"
//Output: "blue is sky the"
//Example 2:
//Input: "  hello world!  "
//Output: "world! hello"
//Explanation: Your reversed string should not contain leading or trailing spaces.
//Example 3:
//Input: "a good   example"
//Output: "example good a"
//Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
//Note:
//    A word is defined as a sequence of non-space characters.
//    Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
//    You need to reduce multiple spaces between two words to a single space in the reversed string.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	char * str = "   the sky is wery blue ";  //input words here
	int iter = 0;
	int flagBegin = 0;
	char * strRevers = NULL;
	int iRevers = 0;
	
	while(*(str + iter)){
		if((*(str + iter) != ' ') && (*(str + iter - 1) == ' ') && (iter > 0)){
			flagBegin++;
		}
		if((*(str + iter) != ' ') && (iter == 0)){
			flagBegin++;
		}
		
		printf("%c\n", *(str + iter));
		iter++;
	}
	printf("iter=%d\n", iter);
	printf("flagBegin=%d\n", flagBegin);
	
	strRevers = (char *) malloc(sizeof(char)*iter + 1);
	
	for(flagBegin; flagBegin>0; flagBegin--){
		iter = 0;
		int flagB = 0;
		while(*(str + iter)){
			if((*(str + iter) != ' ') && (*(str + iter - 1) == ' ') && (iter > 0)){
			flagB++;
		}
		if((*(str + iter) != ' ') && (iter == 0)){
			flagB++;
		}
		
		if((flagB == flagBegin) && (*(str + iter) != ' ')){
			*(strRevers + iRevers) = *(str + iter);
			iRevers++;
		}
		iter++;
		}
		if(flagBegin > 1){
			*(strRevers + iRevers) = ' ';
			iRevers++;
		}
	}
	*(strRevers + iRevers) = '\0';
	printf("%s\n", strRevers);
	
	free(strRevers);
}
