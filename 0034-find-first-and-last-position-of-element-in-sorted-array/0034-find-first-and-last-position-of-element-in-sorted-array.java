class Solution {
    public int search(int[] arr, int target , boolean isleft){
        int left = 0;
        int n = arr.length;
        int right = n - 1;
        int ans = -1;

        while(left <= right){
            int mid = left + ((right - left) / 2);
            if(arr[mid] < target) left = mid+1;
            else if(arr[mid] > target) right = mid - 1;
            else{
                ans = mid;
                if(isleft) right = mid -1;
                else left = mid + 1;
            }
        }
        return ans;
    }
    public int[] searchRange(int[] nums, int target) {
        int first = search(nums,target,true);
        int last = search(nums,target,false);
        return new int[] {first,last};
    }
}