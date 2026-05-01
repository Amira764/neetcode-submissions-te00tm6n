class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        // build adj list
        vector<vector<vector<int>>> graph = buildGraph(times, n+1);

        // costs set all to max
        vector<int> costs (n+1, INT_MAX);

        // start with the start
        queue<int> q;
        q.push(k);
        costs[k] = 0;

        // while queue not empty -> populated costs
        while(!q.empty())
        {
            int current = q.front();
            q.pop();
            for(const auto& edge: graph[current])
            {
                int neighbour = edge[0];
                int edge_cost = edge[1];
                int new_cost = costs[current] + edge_cost;
                if (new_cost < costs[neighbour])
                {
                    costs[neighbour] = new_cost;
                    q.push(neighbour);
                }
            }
        }

        int max = -1;
        for(int i = 1; i<costs.size(); i++)
        {
            int cost = costs[i];
            if(cost == INT_MAX) return -1;
            if(cost > max) max = cost;
        }
        return max;
    }


    //graph
    //node: [neighbour, cost]
    //  1 :        [2 ,  1],           [4,4]
    vector<vector<vector<int>>> buildGraph(vector<vector<int>>& times, int n)
    {
        vector<vector<vector<int>>> graph (n);
        for (const auto& edge: times)
            graph[edge[0]].push_back({edge[1], edge[2]});
        return graph;
    }
};
