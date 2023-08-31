#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

// int maxDifference(vector<int> question)
// {
//     int minimum = question[0];
// 		int maximum = 0;
//     for(int i=1;i<question.size();i++)
//     {
//       maximum = max(maximum,question[i]-minimum);
//       minimum = min(question[i],minimum);
//     }
//     return maximum;
// }

void maxDifference(vector<int>& question, int& minimum, int& maximum, int i)
{         
  //base condition
  if(i>=question.size()) { return; }
  if(question[i]<minimum) { minimum=question[i]; }
	int sum=question[i]-minimum;
  if(sum>maximum) { maximum=sum; }
	maxDifference(question, minimum , maximum, i+1);
}

int maxDifference2(vector<int>& question)
{
  int minimum=INT_MAX;
  int maximum=INT_MIN;
  int i=0;
  maxDifference(question, minimum , maximum, i);
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
	int answer = maxDifference2(question);
	cout << answer;
	return 0;
}
