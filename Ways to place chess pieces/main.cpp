#include<bits/stdc++.h>
using namespace std;
bool isSafe(int temp[], int n, int i, int start)
{ // if "i" column contains a chess piece(#)
	for(int j=0; j<start; j++)
	{
		if(temp[j] == i)
		{ return false; }
	}
	return true;
}
int req_function(string arr[], int temp[], int n, int k, int start, int count)
{ // If you have already ploced k pieces, then return
	if(count == k) { return 1; } // If start is n, then there is no row to place pieces
	if(start == n) { return 0; }
	int totalWays = 0; // Start placing in "start" row
	for(int i=0;i<n;i++)
	{ // If # exists and position is safe
		if(arr[start][i] == '#' && isSafe(temp, n, i, start))
		{
			temp[start] = i; // Call recursively to place pieces in the further rows
			totalWays = totalWays + req_function(arr, temp, n, k, start + 1, count + 1); // Backtrack and remmove i from position[start]                     
			temp[start] = -1;             
		}     
	} // We are not placing any peice in the "start" row     
	totalWays = totalWays + req_function(arr, temp, n, k, start + 1, count);          
	return totalWays; 
}  
int main() 
{         
	int n, k; // input n and kl from the user         
	cin>>n>>k;         
	string arr[n]; // input board from the user as . and #         
	for(int i=0;i<n;i++)         
	{             
		cin >> arr[i];         
	} // position[i] => location of chess piece in ith row         
	int temp[n];         
	for(int i=0; i<n; i++)         
	{             
		temp[i] = -1;         
	}         
	int solution = req_function(arr, temp, n, k, 0, 0);         
	cout<<solution<<endl;         
	return 0; 
}
