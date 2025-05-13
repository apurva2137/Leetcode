class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        if (dict.find(endWord) == dict.end()) return result;

        unordered_map<string, vector<string>> parents;  // child -> list of parents
        unordered_set<string> currLevel, nextLevel;

        queue<string> q;
        q.push(beginWord);
        currLevel.insert(beginWord);

        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();
            nextLevel.clear();

            while (size--) {
                string word = q.front(); q.pop();
                string original = word;

                for (int i = 0; i < word.size(); ++i) {
                    char ch = word[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[i] = c;
                        if (dict.count(word)) {
                            if (!parents.count(word)) nextLevel.insert(word);
                            parents[word].push_back(original);
                            if (word == endWord) found = true;
                        }
                    }
                    word[i] = ch;
                }
            }

            for (const string& word : nextLevel) {
                q.push(word);
                dict.erase(word); // prune visited words for memory efficiency
            }

            currLevel = nextLevel;
        }

        if (!found) return result;

        vector<string> path = {endWord};
        backtrack(endWord, beginWord, parents, path, result);
        return result;
    }

    void backtrack(string word, string& beginWord,
                   unordered_map<string, vector<string>>& parents,
                   vector<string>& path, vector<vector<string>>& result) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
            return;
        }

        for (const string& parent : parents[word]) {
            path.push_back(parent);
            backtrack(parent, beginWord, parents, path, result);
            path.pop_back();
        }
    }
};
