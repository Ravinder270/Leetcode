//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int i,vector<bool>&curr,vector<bool>&vis,vector<int>adj[]){
        vis[i]=true;
        curr[i]=true;
        for(auto x:adj[i]) {
            if(vis[x]==false){ if(dfs(x,curr,vis,adj)) return true;}
            else if(curr[x]) return true;
        }
        curr[i]=false;
        return false;
    }    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool>vis(V,false);
        vector<bool>curr(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]) if(dfs(i,curr,vis,adj))return true;
        }        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends