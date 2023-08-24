#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int h[N];
int dp[N];

int func(int i ){

	if(i==1) return 0;
	int cost = INT_MAX;
	if(dp[i]!=-1) return dp[i];

	// way 1
	cost = min(cost,func(i-1)+abs(h[i]-h[i-1]));

	// way 2 
	if(i>2)
	cost = min(cost,func(i-2)+abs(h[i]-h[i-2]));

	return dp[i] = cost;

}


int main(){
	 

	#ifndef ONLINE_JUDGE
//for getting input from input.txt
freopen("input1.txt", "r", stdin);
//for writing output to output.txt
freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> h[i];
	}
	memset(dp,-1,sizeof(dp));
	cout << func(n) << endl;
}


