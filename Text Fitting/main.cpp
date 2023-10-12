#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int width, height;
    string text;
    cin >> width;
    cin >> height;
    cin.ignore();
    getline(cin, text);
    int count = text.size() + 1;
    vector<int> wordLengths;
    size_t pos = 0;
    while ((pos = text.find(' ')) != string::npos)
    {
        wordLengths.push_back(pos);
        text.erase(0, pos + 1);
    }
    wordLengths.push_back(text.size());
    int size = wordLengths.size();
    vector<int> dpArray(width + 1, 0);
    int index = 0;
    int spaceTaken = 0;
    int widthIndex = 0;
    int textCounter = 0;
    do
    {
        if (height >= count)
        {
            int linesFit = height / count;
            textCounter += linesFit;
            dpArray[widthIndex] = textCounter;
            spaceTaken = height - (height % count);
        }
        else { spaceTaken = 0; }
        while (wordLengths[index] <= height - spaceTaken)
        {
            spaceTaken += wordLengths[index] + 1;
            index++;
            if (index == size)
            {
                textCounter++;
                index = 0;
                dpArray[widthIndex] = textCounter;
            }
        }
        widthIndex++;
    } while (index != 0 && widthIndex < width);
    int temp = widthIndex;
    while (widthIndex < width)
    {
        dpArray[widthIndex] = textCounter + dpArray[widthIndex - temp];
        widthIndex++;
    }
    cout << dpArray[width - 1] << endl;
    return 0;
}
