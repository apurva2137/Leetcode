class Solution {
public:
    struct TrieNode {
        TrieNode* children[26]; 
        string word = "";       

        TrieNode() {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    void insertWord(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr)
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->word = word; 
        }
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node,
             vector<string>& result) {
        char ch = board[i][j];
        if (ch == '#' || node->children[ch - 'a'] == nullptr)
            return;

        node = node->children[ch - 'a'];
        if (node->word != "") {
            result.push_back(node->word);
            node->word = ""; 
        }

        board[i][j] = '#'; 

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int d = 0; d < 4; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if (ni >= 0 && nj >= 0 && ni < board.size() &&
                nj < board[0].size()) {
                dfs(board, ni, nj, node, result);
            }
        }

        board[i][j] = ch; 
        }
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (const string& word : words)
            insertWord(root, word);

        vector<string> result;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }

        return result;
    }
};