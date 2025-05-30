class Solution {
public:
    vector<int> bfs(int start, vector<int>& edges) {
        int n = edges.size();
        vector<int> dist(n, -1);  
        queue<int> q;
        q.push(start);
        dist[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            int neighbor = edges[node];
            if (neighbor != -1 && dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> dist1 = bfs(node1, edges);
        vector<int> dist2 = bfs(node2, edges);

        int minDist = INT_MAX;
        int result = -1;

        for (int i = 0; i < edges.size(); i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    result = i;
                }
            }
        }

        return result;
    }
};