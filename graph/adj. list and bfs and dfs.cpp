// A simple representation of graph using STL
#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> adj[],int source,vector<bool>& visited)
{
    visited[source]=true;
    cout<<source<<" ";
    for(auto it:adj[source])
    {
       // cout<<it<<" ";
        if(visited[it]==false)
        {
            visited[it]=1;
            helper(adj,it,visited);
        }
        
    }
}
void dfs(vector<int> adj[], int u)
{
    int source=1;
    vector<bool> visited(u+1,false);
    helper(adj,source,visited);
}
void bfs(vector<int> adj[], int u)
{
    vector<bool> visited(u+1,0);
    visited[1]=1;
    queue<int> st;
    st.push(1);
    while(!st.empty())
    {
        int node=st.front();
        st.pop();
        cout<<node<<" ";
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                visited[it]=true;
                st.push(it);
            }
        }
    }
}
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V)
{
   
	for (int v = 1; v <= V; ++v) {
		cout  <<v<<"-> ";
		for (auto x : adj[v])
			cout << x<<" , ";
			cout<<endl;
	}
}

// Driver code
int main()
{
	int V =8;
	vector<int> adj[V+1];
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 5);
	addEdge(adj, 2, 6);
	addEdge(adj, 1, 3);
	addEdge(adj, 3,7);
	addEdge(adj, 4,8);
	addEdge(adj, 7, 8);
	addEdge(adj, 3, 4);
	printGraph(adj, V);
	bfs(adj,V);
	cout<<endl;
	dfs(adj,V);
	return 0;
}
