#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int lastRemaining(int n)
{
    if(n==1) { return 1; }
    return 2*((n/2)-lastRemaining(n/2)+1);
}

int main()
{
   int n = 0;
   cin >> n;
   int a = lastRemaining(n);
   cout << a;
}
