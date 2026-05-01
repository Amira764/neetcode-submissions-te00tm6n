class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges)
    {
        unordered_map<int, unordered_set<int>> graph = buildGraph(n, edges);
        PrintAdjList(graph);
        int count = 0;
        unordered_set<int> is_visited;
        for (int i = 0; i<n; i++)
        {
            if(explore(i, graph, is_visited)) count += 1;
        }
        return count;
    }

    bool explore(int node, unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& is_visited)
    {
        cout << "exploring node: " << node << endl;
        if(is_visited.contains(node))
        {
            cout << "node visited already" << endl;
            return false;
        }
        
        cout << "node not visited, mark it" << endl;
        is_visited.insert(node);

        for (const auto& neighbour: graph[node])
        {
            bool whatever = explore(neighbour, graph, is_visited);
        }

        cout << "returning true from node: " << node << endl;
        return true;
    }

    unordered_map<int, unordered_set<int>> buildGraph(int n, vector<vector<int>>& edges)
    {
        unordered_map<int, unordered_set<int>> adj_list;
        for (vector<int>& edge : edges) 
        {
            adj_list[edge[0]].insert(edge[1]);
            adj_list[edge[1]].insert(edge[0]);
        }
        return adj_list;
    }

    void PrintAdjList(unordered_map<int, unordered_set<int>>& graph)
    {
        for (auto& [node, neighbors]: graph)
        {
            cout << '[' << node << "] :";
            for (int neighbor: neighbors)
            {
                cout << neighbor << ", ";
            }
            cout << endl;
        }
    }
};


