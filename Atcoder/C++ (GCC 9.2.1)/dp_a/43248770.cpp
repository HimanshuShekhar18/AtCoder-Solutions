#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e5+10;
 
int h[N];
int dp[N];
 
int func(int i){
 
	if(i==1) return 0;
	int cost = INT_MAX;
	if(dp[i]!=-1) return dp[i];
 
	for (int j = 1; j <= 2; ++j)
	{
 
	if(i-j>=1){
	
		cost = min(cost,func(i-j)+abs(h[i]-h[i-j]));
	
	}
 
}
 
	return dp[i] = cost;
 
}
 
// time complexity: O(n) 
 
int main(){
	 
 
	#ifndef ONLINE_JUDGE
//for getting input from input.txt
freopen("input1.txt", "r", stdin);
//for writing output to output.txt
freopen("output.txt", "w", stdout);
#endif
 
	int n,k;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> h[i];
	}
	memset(dp,-1,sizeof(dp));
	cout << func(n) << endl;
}