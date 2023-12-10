 #include<bits/stdc++.h>
 #include<climits>

using namespace std;



long long dp[310][100010];


long long knapsack2(long long ind,long long value_left, vector<pair<long long,long long>>&value){

	if(value_left==0) return 0;
	if(ind<0) return 1e15;   // min. weight exist nahi karti hain
  

	if(dp[ind][value_left]!=-1) return dp[ind][value_left];
	
	
	long long pick = 1e15;

	if(value_left-value[ind].second>=0)
	pick = knapsack2(ind-1,value_left-value[ind].second,value)+value[ind].first;
	long long non_pick = knapsack2(ind-1,value_left,value)+0;

	return dp[ind][value_left]= min(pick,non_pick);
}

// time complexity: O(N*V)
// N = no. of items and V = max_value


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

long long max_value = 1e5;
// though in question it is mentioned 1<=v<=1e3
// so why max_value = 1e5
// bcoz, in worst case each weight has value = 1e3
// then max_value = 100*1e3 = 1e5

for (long long i = max_value; i > 0; --i)
{
	if(knapsack2(N-1,i,value)<=W) {
		cout << i << endl;
		break;
	}
}
	 
}

