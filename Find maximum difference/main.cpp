#include <iostream>
#include <vector>
using namespace std;

int maxDifference(vector<int> question)
{
    int minimum = question[0];
		int maximum = 0;
    for(int i=1;i<question.size();i++)
    {
      maximum = max(maximum,question[i]-minimum);
      minimum = min(question[i],minimum);
    }
    return maximum;
}

int main()
{
  int n;
  int value;
  cin >> n;
  vector<int> question;
  for(int x = 0; x < n; x++)
  {
    cin >> value;
    question.push_back(value);
  }
	int answer = maxDifference(question);
	cout << answer;
	return 0;
}
