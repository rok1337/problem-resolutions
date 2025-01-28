//https://leetcode.com/problems/missing-number/description/
class Solution {
    public int missingNumber(int[] nums) {
        int k = nums.length;
        for(int i = 0; i < nums.length; i++){
            k = k ^ i ^ nums[i];
        }
        return k;
    }
}