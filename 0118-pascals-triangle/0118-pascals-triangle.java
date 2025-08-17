class Solution {
    public List<Integer> gen(int row){
        int temp = 1;
        List<Integer> v = new ArrayList<>();
        v.add(1);

        for(int col = 1 ; col < row ; col++){
            temp = temp * (row - col);
            temp /= col;
            v.add(temp);
        }
        return v;
    }
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList();
        for(int i = 1 ; i <= numRows ; i++){
            ans.add(gen(i));
        }
        return ans;
    }
}