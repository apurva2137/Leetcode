class Solution {
public:
    int shortestSubarray(vector<int> &nums, int k){
        priority_queue<pair<long long, long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        long long currSum=0, result=INT_MAX;
        for(long long i=0;i<nums.size();i++){
            currSum+=nums[i];
            if(currSum>=k){
                result=min(result,i+1);
            }
            while(!pq.empty() and (currSum-pq.top().first)>=k){
                result=min(result,i-pq.top().second);
                pq.pop();
            }
            pq.push({currSum,i});
        }
    return result==INT_MAX ? -1 : result;
    }
};