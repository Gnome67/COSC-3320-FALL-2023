#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

/*
Imagine that a skiier (S) is skiing down a mountain depicted as an n x n mountain of characters. The skiier starts at the top of the mountain (top-left square) and can only go downhill (down or to the right). In the skiier's path, there is regular snow (.), obstacles (O), and flags (F). Passing through regular snow or flags takes 1 second on each square, while obstacles require slowing down to avoid and take 3 seconds to pass through. Each flag is collected when passed through. Upon reaching the bottom of the mountain (bottom-right square) the player receives 5 points for every flag collected, and loses one point for every second taken more than a pace time.
Return the highest score possible, and the number of flags collected on that run. If there are multiple runs with the same highest score, pick one with the maximum number of flags. A dynamic programming solution should have runtime O(n^2).
*/

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
