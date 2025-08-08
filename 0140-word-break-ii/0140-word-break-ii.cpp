class Solution {
public:
    unordered_set<string> wordSet;
    unordered_map<string, vector<string>> memo;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(s);
    }

private:
    vector<string> dfs(string s) {
        if (memo.count(s)) return memo[s];
        vector<string> res;

        // If the whole string is a word
        if (wordSet.count(s)) res.push_back(s);

        // Try every possible prefix
        for (int i = 1; i < s.length(); ++i) {
            string prefix = s.substr(0, i);
            if (wordSet.count(prefix)) {
                string suffix = s.substr(i);
                vector<string> subRes = dfs(suffix);
                for (const string& sentence : subRes) {
                    res.push_back(prefix + " " + sentence);
                }
            }
        }

        return memo[s] = res;
    }
};
