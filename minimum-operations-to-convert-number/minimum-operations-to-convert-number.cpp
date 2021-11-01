class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        set<int> dp;
        queue<int> q;
        dp.insert(start);
        q.push(start);
        int ans = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int top = q.front();
                q.pop();
                if(top==goal) return ans;
                if(top>1000 || top<0) continue;
                for(int num:nums){
                    int v1 = num+top;
                    int v2 = top-num;
                    int v3 = top^num;  
                    if(v1==goal) return ans+1;
                    if(v2==goal) return ans+1;
                    if(v3==goal) return ans+1;
                    if(v1>=0 && v1<=1000 && dp.count(v1)==0){
                        q.push(v1);
                        dp.insert(v1);
                    }
                    if(v2>=0 && v2<=1000 && dp.count(v2)==0){
                        q.push(v2);
                        dp.insert(v2);
                    }
                    if(v3>=0 && v3<=1000 && dp.count(v3)==0){
                        q.push(v3);
                        dp.insert(v3);
                    }
                }
            }
            ans++;
        }

        return -1;

    }
};