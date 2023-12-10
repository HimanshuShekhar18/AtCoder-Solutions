#include <iostream>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

// <-----------------------------------------------------------RECURSION+MEMOIZATION 1--------------------------------------------------------------------------->

int frogJump(int n, vector<int> &h, int k, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int mm_steps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        int jump;
        if (n - j >= 0)
        {
            jump = frogJump(n-j, h, k, dp) + abs(h[n] - h[n - j]);
        }

        mm_steps = min(mm_steps, jump);
    }

    return dp[n] = mm_steps;
}

int main()
{

    int n, k;
    vector<int> h;
    cin >> n >> k;
    vector<int> dp(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        int height;
        cin >> height;
        h.push_back(height);
    }

    cout << frogJump(n - 1, h, k, dp) << endl;
}


// <-----------------------------------------------------------RECURSION+MEMOIZATION 2--------------------------------------------------------------------------->


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


