#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> optimalSkiingRoute(int n, int pace, vector<vector<char>> &mountain) {
    vector<vector<pair<int, int>>> scoreboard(n, vector<pair<int, int>>(n, {-1e9, 0}));
    scoreboard[0][0] = {0, 0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) continue;
            int bestScore = -1e9, bestFlags = 0;
            if (i > 0) {
                int newScore = scoreboard[i-1][j].first - 1;
                int newFlags = scoreboard[i-1][j].second;
                if (mountain[i][j] == 'O') {
                    newScore -= 2;
                }
                else if (mountain[i][j] == 'F') {
                    newScore += 5;
                    newFlags++;
                }
                if (newScore > bestScore || (newScore == bestScore && newFlags > bestFlags)) {
                    bestScore = newScore;
                    bestFlags = newFlags;
                }
            }
            if (j > 0) {
                int newScore = scoreboard[i][j-1].first - 1;
                int newFlags = scoreboard[i][j-1].second;
                if (mountain[i][j] == 'O') {
                    newScore -= 2;
                }
                else if (mountain[i][j] == 'F') {
                    newScore += 5;
                    newFlags++;   
                }
                if (newScore > bestScore || (newScore == bestScore && newFlags > bestFlags)) {
                    bestScore = newScore;
                    bestFlags = newFlags;
                }
            }
            scoreboard[i][j] = {bestScore, bestFlags};
        }
    }
    int finalScore = scoreboard[n-1][n-1].first + pace;
    return {finalScore, scoreboard[n-1][n-1].second};
}

int main()
{
    int n, pace;
    cin >> n >> pace;
    char cell;
    vector<vector<char>> mountain(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cell;
            mountain[i][j] = cell;
        }
    }
    pair<int, int> result = optimalSkiingRoute(n, pace, mountain);
    cout << result.first << " " << result.second << endl;
}
