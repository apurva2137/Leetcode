class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        int n = nums.length;

        List<List<Integer>>  ans= new ArrayList<>();
        Set<List<Integer>> s = new HashSet<>();

        Arrays.sort(nums);

        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                int k = j+1;
                int m = n-1;
                while( k < m){
                    long sum = (long) nums[i] + nums[j] + nums[k] + nums[m];
                    if(sum < target){
                        k++;
                    }
                    else if(sum > target){
                        m--;
                    }
                    else{
                        s.add(Arrays.asList(nums[i], nums[j], nums[k], nums[m]));
                        k++;
                        m--;
                    }
                }
           }
        }

        ans.addAll(s);
        return ans;
    }
}