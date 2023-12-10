 #include<bits/stdc++.h>
using namespace std;



long long dp[310][100010];


long long knapsack(long long ind,long long W, vector<pair<long long,long long>>&value){

	if(W==0) return 0;
	if(ind<0) return 0;
  

	if(dp[ind][W]!=-1) return dp[ind][W];
	
	
	long long pick = 0;

	if(W-value[ind].first>=0)
	pick = knapsack(ind-1,W-value[ind].first,value)+value[ind].second;
	long long non_pick = knapsack(ind-1,W,value)+0;

	return dp[ind][W]= max(pick,non_pick);
}




int main(){
	 

	#ifndef ONLINE_JUDGE
//for getting input from input.txt
freopen("input1.txt", "r", stdin);
//for writing output to output.txt
freopen("output.txt", "w", stdout);
#endif


long long N,W;
cin >> N >> W;

vector<pair<long long,long long>> value(N+1);

memset(dp,-1,sizeof(dp));

for (int i = 0; i < N; ++i)
{
	cin >> value[i].first >> value[i].second;
}


cout << knapsack(N-1,W,value) << endl;
	 
}

