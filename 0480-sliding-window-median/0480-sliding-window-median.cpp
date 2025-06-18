class SlidingMedian {
    multiset<int> low, high;

    void balance() {

        while (low.size() > high.size() + 1) {
            int leftMax = *low.rbegin();
            low.erase(low.find(leftMax));
            high.insert(leftMax);
        }
      
        while (low.size() < high.size()) {
            int rightMin = *high.begin();
            high.erase(high.begin());
            low.insert(rightMin);
        }
    }

public:
    SlidingMedian() {
        low.clear();
        high.clear();
    }

    void insert(int x) {
        if (low.empty() || x <= *low.rbegin()) {
            low.insert(x);
        }
        else {
            high.insert(x);
        }
        balance();
    }

    void remove(int x) {
        if (low.find(x) != low.end()) {
            low.erase(low.find(x));
        }
        else if (high.find(x) != high.end()) {
            high.erase(high.find(x));
        }
        balance();
    }

    double getMedian() {
        if (low.empty()) return 0;
        long double ans = (long double)*low.rbegin();
        if (low.size() == high.size()) {
            ans += *high.begin();
            ans /= 2.0;
        }
        return (double)ans;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> res;

        SlidingMedian s;

        for (int i = 0; i < k; i++) {
            s.insert(nums[i]);
        }

        res.push_back(s.getMedian());

        for (int i = k; i < n; i++) {
            s.insert(nums[i]);
            s.remove(nums[i - k]);

            res.push_back(s.getMedian());
        }

        return res;
    }
};