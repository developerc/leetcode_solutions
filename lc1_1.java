package main;

public class Solution1 {
public int[] twoSum(int[] nums, int target) {
	int[] resArr = new int[2];
	for(int i=0; i<nums.length; i++){
		System.out.print(nums[i] + ", ");
	}
	System.out.println();
	System.out.println("target = " + target);
	
	for(int i = 0; i < nums.length - 1; i++){
		System.out.println("i = " + nums[i]);
		for(int j = 1 + i; j < nums.length; j++){
			System.out.print(", j = " + nums[j]);
			if((nums[i] + nums[j]) == target){
				resArr[0] = i;
				resArr[1] = j;
				System.out.println();
				System.out.println("resArr = " + resArr[0] + ", " + resArr[1]);
				return resArr;
			}
		}
		System.out.println();
	}
        
	return resArr;
    }
}
