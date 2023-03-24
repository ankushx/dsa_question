class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        vector<int> ans;
        sort(properties.begin(),properties.end(),cmp);
        for(auto it:properties)
        {
            if(ans.empty() or it[1]>ans.back())
                ans.push_back(it[1]);
            else
            {
                int idx=lower_bound(ans.begin(),ans.end(),it[1])-ans.begin();
                ans[idx]=it[1];
                
            }
        }
        return ans.size();
    }
};
