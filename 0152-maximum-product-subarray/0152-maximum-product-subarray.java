class Solution {
    public int maxProduct(int[] nums) {
        int maxprod = Integer.MIN_VALUE;
        int lprod = 1;
        int rprod = 1;
        int n = nums.length;

        for(int i = 0 ; i < n ; i++){
            lprod *= nums[i];
            rprod *= nums[n-i-1];
            maxprod = Math.max(maxprod , Math.max(lprod , rprod));
            if(lprod == 0) lprod = 1;
            if(rprod == 0) rprod = 1;
        }
        return maxprod;
    }
}