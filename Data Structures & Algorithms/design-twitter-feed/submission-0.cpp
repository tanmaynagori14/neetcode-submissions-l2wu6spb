class Twitter {
    int time = 0;

    // user -> list of {time, tweetId}
    unordered_map<int, vector<pair<int,int>>> tweets;

    // user -> followees
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;

        // user should follow themselves
        following[userId].insert(userId);

        for(auto followee : following[userId]) {
            auto &t = tweets[followee];
            int sz = t.size();

            for(int i = max(0, sz - 10); i < sz; i++) {
                pq.push(t[i]);
            }
        }

        vector<int> res;
        while(!pq.empty() && res.size() < 10) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if(following.count(followerId)) {
            following[followerId].erase(followeeId);
        }
    }
};
