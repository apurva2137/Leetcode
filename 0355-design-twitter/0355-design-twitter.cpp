class Twitter {
public:
    int timestamp;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;

    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(timestamp++ , tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        follows[userId].insert(userId);
        for (int followeeId : follows[userId]) {
            const auto& userTweets = tweets[followeeId];
            for (const auto& t : userTweets) {
                pq.push(t);
            }
        }

        vector<int> result;
        int count = 0;
        while (!pq.empty() && count < 10) {
            result.push_back(pq.top().second);
            pq.pop();
            count++;
        }

        return result;


    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */