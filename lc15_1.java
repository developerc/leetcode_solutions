package main;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Solution {
	public List<List<Integer>> threeSum(int[] nums) {
		List<List<Integer>> resultList = new ArrayList<>();
		for(int i = 0; i < nums.length; i++){
			System.out.print(nums[i] + ", ");
		}
		System.out.println();
		
		for(int i = 0; i < nums.length-2; i++){
			System.out.print("i= ");
			System.out.print(nums[i] + ", ");
			System.out.println();
			for(int j = 1+i; j < nums.length-1; j++){
				System.out.print("j= ");
				System.out.print(nums[j] + ", ");
				//System.out.println();
				for(int k = 1+j; k < nums.length; k++){
					System.out.print("k= ");
					System.out.print(nums[k] + ", ");
					//System.out.println();
					if((nums[i] + nums[j] + nums[k]) == 0){
						//System.out.println(nums[i] + ", " + nums[j] + ", " + nums[k]);
						List<Integer> list = new ArrayList<>();
						list.add(nums[i]);
						list.add(nums[j]);
						list.add(nums[k]);
						Collections.sort(list);
						//System.out.println(list);
						if(!resultList.contains(list)){
							resultList.add(list);
						}
					}
				}
				System.out.println();
			}
			System.out.println();
		}
		System.out.println(resultList);
		return resultList;
    }
}
