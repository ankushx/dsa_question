/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
void addedge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void dfs(vector<int> adj[],vector<int>& visited,int s)
{
    visited[s]=1;
    cout<<s<<" ";
    for(auto it:adj[s])
    {
        if(visited[it]==-1)
            {
                dfs(adj,visited,it);
            }
    }
    
}
void bfs(vector<int> adj[],vector<int>& visited,int s)
{
    queue<int> st;
    st.push(s);
    visited[s]=0;
    while(!st.empty())
    {
        int node=st.front();
        st.pop();
        cout<<node<<" ";
        for(auto it:adj[node])
        {
            if(visited[it]==-1)
            {
               // cout<<it<<" "<<node<<endl;
                visited[it]=0;
                st.push(it);
            }
        }
    }
   
    
}
int main()
{
    vector<int> adj[4];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,3);
    addedge(adj,2,3);
    vector<int> visited(4,-1);
    dfs(adj,visited,0);
    cout<<endl;
    bfs(adj,visited,0);
    return 0;
}
