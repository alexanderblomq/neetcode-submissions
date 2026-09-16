class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        vector<vector<int>> connections(n);

        for(vector<int> edge : edges) {
            connections[edge[0]].push_back(edge[1]);
            connections[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        dfs(visited, connections, 0);

        for(bool visit : visited) {
            if(!visit) return false;
        }
        return true;
    }

    void dfs(vector<bool>& visited, vector<vector<int>>& connections, int currNode) {
        if(visited[currNode]) return;
        
        visited[currNode] = true;
        
        for(int connection : connections[currNode]) {
            dfs(visited, connections, connection);
        }
    }
};
