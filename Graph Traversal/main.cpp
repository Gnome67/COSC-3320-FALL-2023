#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &grid, int i, int j, int n)
{
  if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0) { return; }
  grid[i][j] = 0;
  dfs(grid, i-1, j, n);
  dfs(grid, i+1, j, n);
  dfs(grid, i, j-1, n);
  dfs(grid, i, j+1, n);
}

int numIslands(vector<vector<int> > &grid, int n)
{
  int ans = 0;
  for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) { if (grid[i][j] == 1) { dfs(grid, i, j, n); ans++; } }  }
  return ans;
}

int main()
{
  int n = 0;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n));
  for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) { cin >> grid[i][j]; } }
  cout << numIslands(grid, n); return 0;
}
