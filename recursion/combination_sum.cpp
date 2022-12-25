class Solution {
public:
    vector<vector<int>> ans;
    void solver(vector<int>& c, int t,int idx,vector<int> output)
    {
        if(idx==c.size())
            return;
        if(t==0)
        {
            ans.push_back(output);
            return;
        }
        if(t>0)
        {
            //include
            output.push_back(c[idx]);
            solver(c,t-c[idx],idx,output);
            output.pop_back();
        }
        solver(c,t,idx+1,output);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<int> output;
        solver(c,t,0,output);
        return ans;
    }
};
