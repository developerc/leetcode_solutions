package main;

import java.util.LinkedList;
import java.util.List;

public class Solution4 {
	public static final int SIZE = 10000;	//������ ������ ���-�������
	
	public int[] twoSum(int[] nums, int target) {
		int[] resArr = new int[2];			//������� ������ ����������
		int desiredInt;						//����� ��� ������
		int hashIndex;
		for(int i=0; i<nums.length; i++){	//���������� �� 
			System.out.print(nums[i] + ", ");
		}
		System.out.println();
		System.out.println("target = " + target);
		
		//��������� ���-������� ������ �������
		List[] hashArray = new List[SIZE];
		for(int i = 0; i < hashArray.length; i++){
			hashArray[i] = new LinkedList<>();
		}
		
		for(int i = 0; i < nums.length; i++){
			int[] itemArr = new int[2];
			itemArr[0] = i;			//������ ������ �����
			itemArr[1] = nums[i];	//������ �����
			hashIndex = hashFunc(nums[i]);		//���� ������ ���-������� ���� ����� ��������� ������ �������� ���-�������
			hashArray[hashIndex].add(itemArr);	//��������� ������ � ���-�������
			System.out.println("hashIndex = " + hashIndex + ", hashArray[hashIndex].size() = " + hashArray[hashIndex].size() + ", itemArr[0] = " + itemArr[0] + ", itemArr[1] = " + itemArr[1]);
			desiredInt = target - nums[i];		//��������� ����� ����������� �� target
			hashIndex = hashFunc(desiredInt);	//��������� ������ ���-������� ��� ���������������� ��������� ��������� �����
			if(hashArray[hashIndex].size() > 0){//���� � ���-������� �� ����� ������� ���-�� ���������
				for(int j = 0; j < hashArray[hashIndex].size(); j++){	//���������� ������-����� ������������� �� ����� �������
					System.out.println(" - desiredInt =" + desiredInt + ", hashIndex = " + hashIndex + ", hashArray[hashIndex].get(j) = " + hashArray[hashIndex].get(j));
					int[] desArr = new int[2];
					desArr = (int[]) hashArray[hashIndex].get(j);	//�������� ������ ������� � ������ ������-�����
					System.out.println(" - desArr[0] = " + desArr[0] + ", desArr[1] = " + desArr[1]);
					if(((desArr[1] + itemArr[1]) == target) && (desArr[0] != itemArr[0])){	//���� ����� ������ ����� target � ������� ����������
						resArr[0] = itemArr[0];												//��������� ������ ����������
						resArr[1] = desArr[0];
						System.out.println(" : resArr[0] = " + resArr[0] + ", resArr[1] = " + resArr[1]);
						return resArr;														//���������� ������ ���������� � ���������� �������
					}
				}
			}
		}
		
		return resArr;
	}
	
	private int hashFunc(int numsItem){	//���������� ���-�������
		if(numsItem > 0){
			return numsItem % SIZE;
		} else {
			return -(numsItem % SIZE);
		}
	}
}
