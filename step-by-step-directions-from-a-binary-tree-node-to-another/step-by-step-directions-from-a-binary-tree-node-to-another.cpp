class Solution {
    string s1,s2;
    int v1,v2;
    void dfs(TreeNode *t,string &st){
        if(t->val==v1){
            s1=st;
        }else if(t->val==v2){
            s2=st;
        }
        if(t->left){
            st+='L';
            dfs(t->left,st);
            st.pop_back();
        }
        if(t->right){
            st+='R';
            dfs(t->right,st);
            st.pop_back();
        }
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        v1=startValue;
        v2=destValue;
        string st;
        dfs(root,st);
        int d=0;
        while(d<s1.size()&&d<s2.size()&&s1[d]==s2[d])
            d++;
        return string(s1.size()-d, 'U')+s2.substr(d);
    }
};