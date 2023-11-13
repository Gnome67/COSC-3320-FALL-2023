// fails test case 7, fix later

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

bool isInSlump(const string& games) {
    int winCount = 0, lossCount = 0, drawCount = 0;
    int gamesSinceWin = 0;
    istringstream ss(games);
    char result;

    while (ss >> result) {
        // Update counts based on the result of each game
        if (result == 'W') {
            winCount++;
            gamesSinceWin = 0;
        } else if (result == 'L') {
            lossCount++;
            gamesSinceWin++;
        } else if (result == 'D') {
            drawCount++;
            gamesSinceWin++;
        }

        // Check for slump conditions
        if (lossCount > winCount + drawCount) return true;
        if (gamesSinceWin >= 4) return true;

        // Keep only the last three games' results
        if (winCount + lossCount + drawCount > 3) {
            if (result == 'W') drawCount--;
            else if (result == 'L') winCount--;
            else if (result == 'D') lossCount--;
        }
    }

    return false;
}

int main() {
    string games;
    getline(cin, games);

    cout << (isInSlump(games) ? "T" : "F") << endl;

    return 0;
}
