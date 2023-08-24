#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int h[N];
int dp[N];



// time complexity: O(n*2)


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

	dp[1] = 0;
	dp[2] = abs(h[1]-h[2]);

	for(int i = 3; i<=n; i++){
		dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
	}
	

	cout << dp[n] << endl;

	
}


