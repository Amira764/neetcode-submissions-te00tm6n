class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges)
    {
        //build adjacency list
        vector<vector<int>> graph(n);
        for(const vector<int>& e: edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        //build is_visited
        unordered_set<int> is_visited;

        //dfs
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            if(!is_visited.contains(i))
            {
                count++ ;
                mark_connected(i, graph, is_visited);
            }
        }
        return count;
    }

    void mark_connected(int i, vector<vector<int>>& graph, unordered_set<int>& is_visited)
    {
        if(is_visited.contains(i)) return;
        is_visited.insert(i);

        for(const int& neighbour: graph[i])
        {
            mark_connected(neighbour, graph, is_visited);
        }
        return;
    }
};
