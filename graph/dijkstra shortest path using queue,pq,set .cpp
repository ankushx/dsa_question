#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int v, int edges, int source) {
    // Write your code here.
    vector<pair<int,int>> adj[v];
    for(auto it:vec)
    {
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    vector<int> dist(v,INT_MAX);
    queue<pair<int,int>> q;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    set<pair<int,int>> mp;
    q.push({0,source});
    dist[source]=0;
    pq.push({0,source});
    dist[source]=0;
    mp.insert({0,source});
    dist[source]=0;
    while(!mp.empty())
    {
        auto it=*(mp.begin());
        int node=it.second;
        int wt=it.first;
        mp.erase(it);
        for(auto it:adj[node])
        {
            int adjNode=it.first;
            int adjWt=it.second;
            if(dist[node]+adjWt<dist[adjNode])
            {
                if(dist[adjNode]!=INT_MAX)
                {
                    mp.erase({dist[adjNode],adjNode});
                }
                dist[adjNode]=dist[node]+adjWt;
                mp.insert({dist[adjNode],adjNode});
            }
        }
    }
    // while(!pq.empty())
    // {
    //     auto it=pq.top();
    //     int node=it.second;
    //     int wt=it.first;
    //     pq.pop();
    //     for(auto it:adj[node])
    //     {
    //         int adjNode=it.first;
    //         int adjWt=it.second;
    //         if(dist[node]+adjWt<dist[adjNode])
    //         {
    //             dist[adjNode]=dist[node]+adjWt;
    //             pq.push({dist[adjNode],adjNode});
    //         }
    //     }
    // }
  
  
  // while(!q.empty())
    // {
    //     auto it=q.front();
    //     int node=it.second;
    //     int wt=it.first;
    //     q.pop();
    //     for(auto it:adj[node])
    //     {
    //         int adjNode=it.first;
    //         int adjWt=it.second;
    //         if(dist[node]+adjWt<dist[adjNode])
    //         {
    //             dist[adjNode]=dist[node]+adjWt;
    //             q.push({dist[adjNode],adjNode});
    //         }
    //     }
    // }
    return dist;


}
