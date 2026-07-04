class Solution {
public:

int ans = INT_MAX;
int minScore(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int,int>>> adj(n + 1);

    for (auto &r : roads) {
        adj[r[0]].push_back({r[1], r[2]});
        adj[r[1]].push_back({r[0], r[2]});
    }

    vector<int> vis(n + 1, 0);
    stack<int> st;
    st.push(1);
    vis[1] = 1;

    int ans = INT_MAX;

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        for (auto &[nei, wt] : adj[node]) {
            ans = min(ans, wt);

            if (!vis[nei]) {
                vis[nei] = 1;
                st.push(nei);
            }
        }
    }

    return ans;
}
};