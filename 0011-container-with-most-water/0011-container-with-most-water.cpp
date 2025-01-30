class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int area;
        int max_area=0;
        while(left<=right){
           int min_el=min(height[left],height[right]);
            area=(right-left)*min_el;
            max_area=max(area,max_area);
            if(height[left]<height[right]) left++;
            else right--;
        }
        return max_area;
    }
};