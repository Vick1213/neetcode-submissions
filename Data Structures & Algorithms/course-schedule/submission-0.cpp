class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& p : prerequisites)
            adj[p[0]].push_back(p[1]);

        vector<int> state(numCourses, 0); // 0 = unvisited, 1 = in progress, 2 = done

        for (int i = 0; i < numCourses; i++)
            if (state[i] == 0 && !dfs(i, adj, state))
                return false;

        return true;
    }

private:
    bool dfs(int i, vector<vector<int>>& adj, vector<int>& state) {
        state[i] = 1; // mark as "on current path"
        for (int next : adj[i]) {
            if (state[next] == 1) return false;              // back edge -> cycle
            if (state[next] == 0 && !dfs(next, adj, state)) return false;
        }
        state[i] = 2; // safe, fully explored
        return true;
    }
};