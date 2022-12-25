class Solution {
public:
    void subsetsWithDup(vector<int>& nums, vector<int> output, vector<vector<int>>& ans, int idx) 
        {
        ans.push_back(output);
     
    
    for(int i=idx;i<nums.size();i++)
    {
        if(i>idx && nums[i]==nums[i-1])
            continue;
        output.push_back(nums[i]);
        subsetsWithDup(nums,output,ans,i+1);
        output.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> output;
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    subsetsWithDup(nums,output,ans,0);
    return ans;
}
};
