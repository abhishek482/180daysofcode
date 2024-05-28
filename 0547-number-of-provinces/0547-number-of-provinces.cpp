#include <vector>

class Solution {
public:
    void dfs(int node, std::vector<std::vector<int>>& isConnected, std::vector<bool>& visited) {
        visited[node] = true;
        for (int i = 0; i < isConnected.size(); ++i) {
            if (isConnected[node][i] == 1 && !visited[i]) {
                dfs(i, isConnected, visited);
            }
        }
    }

    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        int n = isConnected.size();
        std::vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                ++count;
            }
        }
        
        return count;
    }
};
