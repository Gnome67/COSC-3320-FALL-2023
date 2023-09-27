#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;
 
int preIndex = 0;
void printPost(vector<int> in, vector<int> pre, int inStrt, int inEnd, map<int, int> hm)
{
    if (inStrt > inEnd) { return; }
    int inIndex = hm[pre[preIndex++]];
    printPost(in, pre, inStrt, inIndex - 1, hm);
    printPost(in, pre, inIndex + 1, inEnd, hm);
    cout << in[inIndex] << " ";
}
 
void printPostMain(vector<int> in, vector<int> pre,int n)
{
    map<int,int> hm;
    for (int i = 0; i < n; i++) { hm[in[i]] = i; }
    printPost(in, pre, 0, n - 1, hm);
}

int main()
{
    int n;
    cin >> n;
    vector<int> pre(n);
    vector<int> in(n);
    for (int i = 0; i < n; i++) { cin >> pre[i]; }
    for (int i = 0; i < n; i++) { cin >> in[i]; }
    printPostMain(in, pre, n);
    return 0;
}
