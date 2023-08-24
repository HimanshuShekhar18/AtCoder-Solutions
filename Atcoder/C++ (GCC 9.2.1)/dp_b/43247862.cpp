#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int h[N];
int dp[N];

int func(int i, int k ){

	if(i==1) return 0;
	int cost = INT_MAX;
	if(dp[i]!=-1) return dp[i];

	for (int j = 1; j <= k; ++j)
	{

		// int cost = INT_MAX;

	if(i-j>=1){
		cost = min(cost,func(i-j,k)+abs(h[i]-h[i-j]));
		// cout << cost << endl;
	}

}

	return dp[i] = cost;

}


int main(){
	 

	#ifndef ONLINE_JUDGE
//for getting input from input.txt
freopen("input1.txt", "r", stdin);
//for writing output to output.txt
freopen("output.txt", "w", stdout);
#endif

	int n,k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> h[i];
	}
	memset(dp,-1,sizeof(dp));
	cout << func(n,k) << endl;
}


