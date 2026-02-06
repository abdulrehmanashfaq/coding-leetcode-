class Solution {
public:
    void rec(int i, int j, int n, int m, char ch, vector<vector<char>>& grid, 
             vector<vector<bool>>& visited, bool &found, int pi, int pj) {
        
        // 1. Boundary and Character Check
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != ch) {
            return;
        }

        // 2. Cycle Detection Logic
        if (visited[i][j]) {
            // If we hit a visited cell that isn't our parent, it's a cycle!
            found = true;
            return;
        }

        // 3. Mark current as visited
        visited[i][j] = true;

        // 4. Explore neighbors (Passing current i, j as the parent for the next step)
        // We only move to a neighbor if it's NOT the parent we just came from
        if (i + 1 != pi || j != pj) rec(i + 1, j, n, m, ch, grid, visited, found, i, j);
        if (found) return; // Optimization: stop if found
        
        if (i - 1 != pi || j != pj) rec(i - 1, j, n, m, ch, grid, visited, found, i, j);
        if (found) return;

        if (i != pi || j + 1 != pj) rec(i, j + 1, n, m, ch, grid, visited, found, i, j);
        if (found) return;

        if (i != pi || j - 1 != pj) rec(i, j - 1, n, m, ch, grid, visited, found, i, j);
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Use a global visited to avoid re-checking the same areas
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    bool found = false;
                    // Start search: -1, -1 means no parent for the start cell
                    rec(i, j, n, m, grid[i][j], grid, visited, found, -1, -1);
                    if (found) return true;
                }
            }
        }

        return false;
    }
};