class Twitter {
private:
    unordered_map<int, list<pair<int, int>>> posts;
    unordered_map<int, unordered_set<int>> follows;
    int timestamp;

public:
    Twitter(): timestamp(0) {}
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({timestamp, tweetId});
        ++timestamp;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int, int>> recent_feeds;

        auto user_post = posts.find(userId);
        if (user_post != posts.end()) {
            for (auto val : user_post->second) {
                recent_feeds.push(val);
            }
        }

        auto it = follows.find(userId);
        if (it != follows.end() && !it->second.empty()) {
            const auto& following_list = it->second;
            for (auto it_list = following_list.begin(); it_list != following_list.end(); it_list++) {
                if (posts.find(*it_list) != posts.end()) {
                    for (auto val : posts.find(*it_list)->second) {
                        recent_feeds.push(val);
                    }
                }
            }
            
        }


        while (recent_feeds.empty() == false && res.size() != 10) {
            res.push_back(recent_feeds.top().second);
            recent_feeds.pop();
        }

        return res;
    }       
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it = follows.find(followerId);

        if (it != follows.end()) {
            auto& following_list = it->second;

            following_list.erase(followeeId);            
        }
    }
};
