class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        //cout << m << " " << n << endl;
        for(int i=0;i<m;i++){
            for(int j=n-1;j>=0;j--){
                int k = j+1;
                if(box[i][j]!='#') continue;
                for(k=j+1;k<n;k++){
                    if(box[i][k]=='#' || box[i][k]=='*') break;
                }
                k--;
                box[i][k] = '#';
                if(j!=k) box[i][j]= '.';
            }
        }
        
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++) cout << box[i][j] << " ";
        //     cout << endl;
        // }
        
        vector<vector<char>> ans;
        for(int i=0;i<n;i++){
            vector<char> cur;
            for(int j=m-1;j>=0;j--){
                cur.push_back(box[j][i]);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};