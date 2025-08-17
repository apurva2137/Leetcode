class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> ans = new ArrayList<>();

        HashMap<Integer, Integer> mp = new HashMap<>();

        for(Integer num : nums) mp.put(num , mp.getOrDefault(num , 0 ) + 1);

        int n = nums.length;
        n = n/3;

        for(Map.Entry<Integer,Integer> it : mp.entrySet()){
            int key = it.getKey();
            int value = it.getValue();
            if(value > n){
                ans.add(key);
            }
        }
        return ans;
    }
}