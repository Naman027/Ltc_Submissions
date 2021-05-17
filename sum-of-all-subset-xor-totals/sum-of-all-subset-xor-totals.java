class Solution {
    static int ans = 0;
    public int subsetXORSum(int[] nums) {
        int n = nums.length;
        ans = 0;
        ArrayList<Integer> ls = new ArrayList<>();
        solve(nums,0,ls);
        return ans;
    }
    
    public void solve(int[] nums,int ind,ArrayList<Integer> ls){
        int temp = 0;
        for(int num:ls) temp = myxor(temp,num);
        ans+=temp;
        for(int i=ind;i<nums.length;i++){
            ls.add(nums[i]);
            solve(nums,i+1,ls);
            ls.remove(ls.size()-1);
        }
    }
    
    public int myxor(int a,int b){
        return (a|b)&(~a|~b);
    }
    
}



