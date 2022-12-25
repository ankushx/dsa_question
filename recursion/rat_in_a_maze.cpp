//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool is_possible(int r,int c,vector<vector<int>> &visited,vector<vector<int>> &m,int n)
    {
        if((r>=0 && r<n)  && (c>=0 &&c<n) &&( visited[r][c]==0) &&( m[r][c]==1))
        return 1;
        return 0;
    }
     vector<string> ans;
     void solver(vector<vector<int>> &m, int n,vector<vector<int>>& visited,int row,int col,string s)
     {
         if(row==n-1 && col==n-1)
         {
             ans.push_back(s);
             return ;
         }
         visited[row][col]=1;
         //right
         int newr=row;
         int newc=col+1;
         if(is_possible(newr,newc,visited,m,n))
         {
             s.push_back('R');
             solver(m,n,visited,newr,newc,s);
             s.pop_back();
         }
          //down
          newr=row+1;
          newc=col;
         if(is_possible(newr,newc,visited,m,n))
         {
             s.push_back('D');
             solver(m,n,visited,newr,newc,s);
             s.pop_back();
         }
          //left
          newr=row;
          newc=col-1;
         if(is_possible(newr,newc,visited,m,n))
         {
             s.push_back('L');
             solver(m,n,visited,newr,newc,s);
             s.pop_back();
         }
          //UP
          newr=row-1;
          newc=col;
         if(is_possible(newr,newc,visited,m,n))
         {
             s.push_back('U');
             solver(m,n,visited,newr,newc,s);
             s.pop_back();
         }
         visited[row][col]=0;
     }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0]==0)
        return ans;
        vector<vector<int>> visited(n,vector<int> (n,0));
        string s="";
        solver(m,n,visited,0,0,s);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
