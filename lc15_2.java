package main;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Solution7 {
	public List<List<Integer>> threeSum(int[] nums) {
		List<List<Integer>> resultList = new ArrayList<>();
		Set<List<Integer>> resultSet = new HashSet<>();
		if(nums.length < 3){
			return resultList;
		}
		int left, right, sum;
		Arrays.sort(nums);
		nums = removeRepeate(nums);
		for(int i = 0; i < nums.length; i++){
			System.out.print(nums[i] + ", ");
		}
		System.out.println();
		
		for(int i=0; i<nums.length-2; i++){
			left = i + 1;
			right = nums.length-1;
			if((nums[i]<0 && nums[left]<0 && nums[right]<0) || (nums[i]>0 && nums[left]>0 && nums[right]>0)){ left++; continue; }
			while(left < right){
				sum = nums[i] + nums[left] + nums[right];
				if(sum == 0){
					List<Integer> list = Arrays.asList(nums[i], nums[left], nums[right]);
					resultSet.add(list);
					left++;
					right--;
				} else if(sum < 0){
					left++;
				} else {
					right--;
				}
			}
		}
		resultList.addAll(resultSet);
		System.out.println(resultList);
		return resultList;
	}
	
	int[] removeRepeate(int[] inputArr){
		int inputInt = inputArr[0];
		int countRepeate = 0;
		List <Integer> outputList = new ArrayList<>();
		outputList.add(inputInt);
		for(int i = 1; i < inputArr.length; i++){
			if(inputArr[i] != inputInt){
				outputList.add(inputArr[i]);
				countRepeate = 0;
			} else {
				countRepeate++;
				if((inputArr[i] == 0) && (countRepeate < 3)){
					outputList.add(inputArr[i]);
				}
				if((inputArr[i] != 0) && (countRepeate < 2)){
					outputList.add(inputArr[i]);
				}
			}
			inputInt = inputArr[i];
		}
		
		return outputList.stream().mapToInt(Integer::intValue).toArray();
	}
}
