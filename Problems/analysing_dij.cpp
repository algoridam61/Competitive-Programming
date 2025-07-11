#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define f(i,n) for(int i = 0;i<n;i++)

void dij(vector<int>& dist, const vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start}); // {distance, node}

    while (!pq.empty()) {
        auto [currDist, node] = pq.top();
        pq.pop();

        // Skip processing if the distance in queue is outdated
        if (currDist > dist[node]) {
            continue;
        }

        for (const auto& [neighbor, weight] : graph[node]) {
            int newDist = dist[node] + weight;
            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                pq.push({newDist, neighbor});
            }
        }
    }
}

int main()
{
    vi dist(4,INT_MAX);
    vector<vector<pair<int,int>>> graph;

    graph = {{{1,1},{2,4}},{{3,-2}},{},{{2,2}}};

    dij(dist,graph,0);

    f(i,4)
    {
        cout<<"node: "<<i+1<<" dist from 1: "<<dist[i]<<"\n";
    }
}