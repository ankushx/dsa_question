class Solution {
public:
    void find_subset(vector<int> nums,vector<int> output,int idx,vector<vector<int>>& ans)
    {
        if(idx>=nums.size())
        {
            ans.push_back(output);
            return ;
            }
        //exclude
          find_subset(nums,output,idx+1,ans);
        
        //include
        int temp=nums[idx];
        output.push_back(temp);
          find_subset(nums,output,idx+1,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int idx=0;
        find_subset(nums,output,idx,ans);
        return ans;
    }
};
