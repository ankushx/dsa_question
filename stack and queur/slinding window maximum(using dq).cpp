class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n-k+1);
        deque<int> dq;
        int idx=0;
        for(int i=0;i<n;i++)
        {
          //for checking topmost element of dq is within k limit
            if(dq.size()>0 && dq.front()==i-k)
                dq.pop_front();
            
          //for checking back element of dq is < than nums[i]
            while(dq.size()>0 && nums[dq.back()]<=nums[i])
                dq.pop_back();
          
             //adding in dq
            dq.push_back(i);
          
          //adding in ans
            if(i>=k-1)
            {
                ans[idx]=nums[dq.front()];
                idx++;
                
            }
        }
        return ans;
    }
};
