class Solution {
public:
    int concatenatedBinary(int n) {
        long long int ans=0;
        for(int i=1;i<=n;i++)
        {
            int temp=(int)log2(i)+1;
            ans=((ans*(1<<temp)%1000000007+i)%1000000007);
        }
        return ans;
    }
};
