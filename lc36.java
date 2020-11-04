package main;

import java.util.Arrays;

public class Solution1 {
public boolean isValidSudoku(char[][] board) {
	int[] parent = {1,2,3,4,5,6,7,8,9}; 			//эталонный массив
	int[] child = new int[9];
	int indSymb, indNext;
	char[] outArr = new char[243];
	for(int j = 0; j < 9; j++){
	     for(int i = 0; i < 9; i++){
	    	 System.out.print(board[j][i] + ", ");
	     }
	     System.out.println();
	}
	
	for(int i = 0; i < 9; i++){
	     for(int j = 0; j < 9; j++){
	    	 outArr[i*9 + j] = board[i][j];			//помещаем в массив горизонтальные массивы
	    	 outArr[i + j*9 + 81] =  board[i][j];	//Помещаем в массив вертикальные массивы
	    	 if((j>=0) && (j<=2)){					//Помещаем в массив sub-квадраты
	    		 outArr[i*3 + j + 162] = board[i][j];
	    	 }
	    	 if((j>=3) && (j<=5)){					//Помещаем в массив sub-квадраты
	    		 outArr[i*3 + j + 186] = board[i][j];
	    	 }
	    	 if((j>=6) && (j<=8)){					//Помещаем в массив sub-квадраты
	    		 outArr[i*3 + j + 210] = board[i][j];
	    	 }
	     }
	}
	System.out.println();
	
	
	for(int i = 0; i < 243; i++){
		System.out.print(outArr[i] + ", ");
	}
	System.out.println();
	
	indNext = 10;
	for(int i = 0; i < 243; i++){
		if(indNext > 9){
		child = Arrays.copyOf(parent, parent.length);
		System.out.println();
		
		indNext = 1;
		}
		System.out.print(outArr[i]);
		indSymb = (int) outArr[i] - 49;
		if(((0 <= indSymb) && (indSymb <= 8)) || (indSymb == -3)){
			if(indSymb != -3){		//если это не точка а цифра
				if(child[indSymb] > 0){
					child[indSymb] = 0;
				} else {
					System.out.println("Repeated input i = " + i);
					return false;
				}
			}
		} else {
			System.out.println("Invalid input i = " + i);
			return false;
		}
		indNext++;
	}	
	
	System.out.println("true");
	return true;
    }
	
}
