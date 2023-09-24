#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int robertPts = 0;
int rachelPts = 0;

using namespace std;

int helper(vector<int> &left, vector<int> &right)
{
    int index = 0, temporaryScore = 0, finalScore = 0;
    while(index < right.size())
    {
        while(temporaryScore < left.size() && right[index] > left[temporaryScore])
        {
            temporaryScore++;
        }
        finalScore += temporaryScore;
        index++;
    }
    return finalScore;
}

void merge(vector<int> &robertStuff, vector<int> &rachelStuff, int left, int middle, int right)
{
    vector<int> robertLeft, robertRight, rachelLeft, rachelRight;
    int leftMiddle = middle - left + 1, rightMiddle = right - middle;
    for(int i = 0; i < leftMiddle; i++)
    {
        robertLeft.push_back(robertStuff[left + i]);
        rachelLeft.push_back(rachelStuff[left + i]);
    }
    for(int j = 0; j < rightMiddle; j++)
    {
        robertRight.push_back(robertStuff[middle + j + 1]);
        rachelRight.push_back(rachelStuff[middle + j + 1]);
    }

    int robertI = 0, robertJ = 0;
    int rachelI = 0, rachelJ = 0;
    int robertIndex = left, rachelIndex = left;
    if(robertI < leftMiddle && robertJ < rightMiddle) { robertPts += helper(rachelLeft, robertRight); }
    if(rachelI < leftMiddle && rachelJ < rightMiddle) { rachelPts += helper(robertLeft,rachelRight); }

    while(robertI < leftMiddle && robertJ < rightMiddle)
    {
        if(robertLeft[robertI] <= robertRight[robertJ]) { robertStuff[robertIndex] = robertLeft[robertI++]; }
        else { robertStuff[robertIndex] = robertRight[robertJ++]; }
        robertIndex++;
    }
    while(robertI < leftMiddle) { robertStuff[robertIndex++] = robertLeft[robertI++]; }
    while(robertJ < rightMiddle) { robertStuff[robertIndex++] = robertRight[robertJ++]; }
    while(rachelI < leftMiddle && rachelJ < rightMiddle)
    {
        if(rachelLeft[rachelI] <= rachelRight[rachelJ]) { rachelStuff[rachelIndex] = rachelLeft[rachelI++]; }
        else { rachelStuff[rachelIndex] = rachelRight[rachelJ++]; }
        rachelIndex++;
    }
    while(rachelI < leftMiddle) { rachelStuff[rachelIndex++] = rachelLeft[rachelI++]; }
    while(rachelJ < rightMiddle) { rachelStuff[rachelIndex++] = rachelRight[rachelJ++]; }
}

void mergeSort(vector<int> &robertStuff, vector<int> &rachelStuff, int begin, int end)
{
	if(begin < end)
    {
		int midpoint = (begin + end)/ 2;
		mergeSort(robertStuff, rachelStuff, begin, midpoint);
		mergeSort(robertStuff,rachelStuff , midpoint + 1, end);
		merge(robertStuff, rachelStuff, begin, midpoint, end);
	}
}

int main()
{
    string robert = "";
    string rachel = "";
    getline(cin, robert);
    getline(cin, rachel);
    vector<int> robertStuff;
    vector<int> rachelStuff;
    stringstream robStuff(robert);
    stringstream racStuff(rachel);
    int robPoint;
    int racPoint;
    while(robStuff >> robPoint) { robertStuff.push_back(robPoint); }
    while(racStuff >> racPoint) { rachelStuff.push_back(racPoint); }
    mergeSort(robertStuff, rachelStuff, 0, robertStuff.size()-1);
    cout << robertPts << " " << rachelPts;
    return 0;
}
