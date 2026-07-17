class Solution {
public:
    vector<int> parent, sz;

    int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);   // Path Compression
    }

    void Union(int u, int v) {
        u = find(u);
        v = find(v);

        if (u != v) {
            // Union by Size
            if (sz[u] < sz[v])
                swap(u, v);

            parent[v] = u;
            sz[u] += sz[v];
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        sz.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto &edge : edges) {
            Union(edge[0], edge[1]);
        }

        return find(source) == find(destination);
    }
};