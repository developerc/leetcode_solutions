package main;

import java.util.LinkedList;
import java.util.List;

public class Solution4 {
	public static final int SIZE = 10000;	//Задаем размер Хэш-массива
	
	public int[] twoSum(int[] nums, int target) {
		int[] resArr = new int[2];			//создаем массив результата
		int desiredInt;						//число для поиска
		int hashIndex;
		for(int i=0; i<nums.length; i++){	//посмотрели на 
			System.out.print(nums[i] + ", ");
		}
		System.out.println();
		System.out.println("target = " + target);
		
		//заполняем Хэш-таблицу линкед листами
		List[] hashArray = new List[SIZE];
		for(int i = 0; i < hashArray.length; i++){
			hashArray[i] = new LinkedList<>();
		}
		
		for(int i = 0; i < nums.length; i++){
			int[] itemArr = new int[2];
			itemArr[0] = i;			//храним индекс числа
			itemArr[1] = nums[i];	//храним число
			hashIndex = hashFunc(nums[i]);		//ищем индекс хэш-таблицы куда будем добавлять данные вычисляя хэш-функцию
			hashArray[hashIndex].add(itemArr);	//добавляем данные в хэш-таблицу
			System.out.println("hashIndex = " + hashIndex + ", hashArray[hashIndex].size() = " + hashArray[hashIndex].size() + ", itemArr[0] = " + itemArr[0] + ", itemArr[1] = " + itemArr[1]);
			desiredInt = target - nums[i];		//требуемое число недостающее до target
			hashIndex = hashFunc(desiredInt);	//вычисляем индекс хэш-таблицы где предположительно находится требуемое число
			if(hashArray[hashIndex].size() > 0){//если в хэш-таблице по этому индексу что-то находится
				for(int j = 0; j < hashArray[hashIndex].size(); j++){	//перебираем линкед-листы расположенные по этому индексу
					System.out.println(" - desiredInt =" + desiredInt + ", hashIndex = " + hashIndex + ", hashArray[hashIndex].get(j) = " + hashArray[hashIndex].get(j));
					int[] desArr = new int[2];
					desArr = (int[]) hashArray[hashIndex].get(j);	//получаем массив лежащий в данном линкед-листе
					System.out.println(" - desArr[0] = " + desArr[0] + ", desArr[1] = " + desArr[1]);
					if(((desArr[1] + itemArr[1]) == target) && (desArr[0] != itemArr[0])){	//если сумма данных равна target и индексы отличаются
						resArr[0] = itemArr[0];												//заполняем массив результата
						resArr[1] = desArr[0];
						System.out.println(" : resArr[0] = " + resArr[0] + ", resArr[1] = " + resArr[1]);
						return resArr;														//возвращаем массив результата в вызывающую функцию
					}
				}
			}
		}
		
		return resArr;
	}
	
	private int hashFunc(int numsItem){	//вычисление хэш-функции
		if(numsItem > 0){
			return numsItem % SIZE;
		} else {
			return -(numsItem % SIZE);
		}
	}
}
