class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int a = 0, b = n - 1;
        int index = - 1;
        while(a <= b){
            int k = (a + b) / 2;
            if(nums[k] == target){
                return k;
            }
            if(nums[k] > target)b = k - 1;
            else a = k + 1;
        }

        while(a <= b ){
            int k = (a + b) / 2;
            if(nums[k] > nums[n]) a = k + 1;
            else n = k - 1;
        }
        
        index = a;
        a = 0;
        b = n - 1;
        if(target >= nums[index] &&  target <= nums[b]){
            a = index;
        }else{
            b = index - 1;
        }

        while(a <= b){
            int k = (a + b) / 2;
            if(nums[k] == target){
                return k;
            }
            if(nums[k] > target){
                b = k - 1;
            }else b = k + 1;
        }
        return -1;
    }
}
