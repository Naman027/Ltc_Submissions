class Solution {
public:
    
    int rec(string str, int ptr1, int ptr2, int curlen, vector<vector<vector<int>>>& dp, int len)
    {
        if(curlen==len)return 0;
        if(dp[ptr1][ptr2][curlen]!=-1)return dp[ptr1][ptr2][curlen];
        
        int pos=str[curlen]-'A'+1;
        if(pos==ptr1 || pos==ptr2)return rec(str, ptr1, ptr2, curlen+1, dp, len);
        int xpos=(pos-1)%6;
        int ypos=(pos-1)/6;
        //using ptr1
        int xptr1=(ptr1-1)%6;
        int yptr1=(ptr1-1)/6;
        int steps1=abs(xpos-xptr1)+abs(ypos-yptr1)+rec(str, pos, ptr2, curlen+1, dp, len);
        int steps2=0;
        //using ptr2
        if(ptr2==0)
        {
            steps2=rec(str, ptr1, pos, curlen+1, dp, len);
        }
        else
        {
            int xptr2=(ptr2-1)%6;
            int yptr2=(ptr2-1)/6;
            steps2=abs(xpos-xptr2)+abs(ypos-yptr2)+rec(str, ptr1, pos, curlen+1, dp, len);
        }
        return (dp[ptr1][ptr2][curlen]=min(steps1, steps2));
    }
    
    int minimumDistance(string str) {
        int len=str.length();
        vector<vector<vector<int>>> dp(27, vector<vector<int>>(27, vector<int>(len+1, -1)));
        if(len<=2)return 0;
        // 0 represent => ptr not started
        return rec(str, str[0]-'A'+1, 0, 1, dp, len);
    }
};