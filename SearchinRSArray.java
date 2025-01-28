class Solution {
    public int search(int[] nums, int target) {
        int a = 0, b = n - 1;
        int n = nums.length;
        while(a <= b){
            int k = (a + b) / 2;
            if(nums[k] == target){
                return k;
            }
            if(nums[k] > target)b = k - 1;
            else a = k + 1;
        }

        while(a < b ){
            int k = (a + b) / 2;
            if(nums[k] > nums[n]) a = k + 1;
            else n = k;
        }
        
        int mid = 1;
        if(mid == 0){
            a = 0;
            b = n - 1;
        }else if(target >= nums[0] && target <= nums[mid - 1]){
            a = 0;
            b = mid - 1;
        }else{
            a = mid;
            b = n - 1;
        }
    
        return -1;
    }
}