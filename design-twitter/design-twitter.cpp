class Twitter {
public:
    int timeOfTweet = 0;
    map<int,set<pair<int,int>,greater<pair<int,int>>>> posts; //decreasing order
    map<int,set<int>> followedUers;
    int maxTweets = 10;

    /** Initialize your data structure here. */
    Twitter(){
        timeOfTweet = 0;
        posts.clear();
        followedUers.clear();
    }


    set<int> getAllFollowers(int userId){
        return followedUers[userId];
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId){
        posts[userId].insert({timeOfTweet,tweetId});
        timeOfTweet++;    
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId){
        set<pair<int,int>,greater<pair<int,int>>> allLatestTweets;
        for(auto i:posts[userId]) allLatestTweets.insert({i.first,i.second});

        for(auto i:getAllFollowers(userId)){
            int followerId = i;
            int noOfTweets = maxTweets;
            for(auto tweets:posts[followerId]){
                if(noOfTweets<=0) break;
                allLatestTweets.insert({tweets.first,tweets.second});
                noOfTweets--;
            }
        }

        int noOfTweets = maxTweets;
        vector<int> latestTweets;
        for(auto allTweets:allLatestTweets){
            if(noOfTweets<=0) break;
            latestTweets.push_back(allTweets.second);
            noOfTweets--;
        }

        return latestTweets;

    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId){
        followedUers[followerId].insert(followeeId);    
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId){
        followedUers[followerId].erase(followeeId);
    }
};
