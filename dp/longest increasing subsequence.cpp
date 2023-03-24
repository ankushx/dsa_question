//binary search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(auto it:nums)
        {
            if(ans.empty() or it>ans.back())
                ans.push_back(it);
            else
            {
                auto tp=lower_bound(ans.begin(),ans.end(),it)-ans.begin();
                ans[tp]=it;
            }
        }
        return ans.size();
    }
};

//dp
class Solution {
public:
    int helper(int idx,int prev_idx,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(idx==nums.size())
            return 0;
        if(dp[idx][prev_idx+1]!=-1)
            return dp[idx][prev_idx+1];
        int not_take=helper(idx+1,prev_idx,nums,dp);
        int take=0;
        if(prev_idx==-1 or nums[idx]>nums[prev_idx])
            take=1+helper(idx+1,idx,nums,dp);
        return dp[idx][prev_idx+1]=max(not_take,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+2,0));
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int prev_idx=idx-1;prev_idx>=-1;prev_idx--)
            {
                 int not_take=dp[idx+1][prev_idx+1];
                    int take=0;
                    if(prev_idx==-1 or nums[idx]>nums[prev_idx])
                        take=1+dp[idx+1][idx+1];
                     dp[idx][prev_idx+1]=max(not_take,take);
              //  cout<<dp[idx][prev_idx+1]<<" ";
            }
          //  cout<<endl;
        }
        return dp[0][0];
    }
};
