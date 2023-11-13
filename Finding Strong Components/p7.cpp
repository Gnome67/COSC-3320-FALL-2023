
#include <iostream>
#include <vector>
#include <stack>


using namespace std;
int main() 
{
    int n; 
    cin >> n; 

    vector<vector<int>> adj(n+1); // adj[0] is unused. 
    for(int i=1; i<=n; i++) {
        int j; 
        cin >> j;
        assert( i == j ); 
        int d; 
        cin >> d; 
        //cout << "node " << j << " degree " << d << endl; 
        for(int k=0; k<d; k++) {
            int l; 
            cin >> l;
            adj[i].push_back(l); 
        }
    }

    int count = 0; 
    /* compute the number of strong components in the graph adj[1...n]! */
    //scc(adj, n); 


    cout << count << endl;
    return 0; 
}
