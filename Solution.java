// Source: https://leetcode.com/problems/search-insert-position/
class Solution {
    public int searchInsert(int[] nums, int target) {
        int a = 0, b = nums.length - 1;
        while(a <= b){
            int k = (a + b) / 2;

            if(nums[k] == target){
                return k;
            }
            if(nums[k] > target) b = k - 1;
            else a = k + 1;
        }
        return a;
    }
}