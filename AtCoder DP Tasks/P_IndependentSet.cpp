// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;

# define ll long long

vector<vector<int>> graph;

ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi;
bool flag;
string str;

//Time Complexity: O(n*2) at each node two times computation
//Space Complexity: O(n+n)
ll dp[MAX_N][3];  // par[i][j] = 2^(j)th parent of ith node

// 0 --> white,  1--> black
ll dfs(int source, int prevcolour, int parent){
  if(dp[source][prevcolour]!=-1) return dp[source][prevcolour];

  ll colourwhite = 1;
  ll colourblack = 1;

  for(auto it: graph[source]){
    if(it!=parent){
      // source k  whitecolour karke, child pe jao
      // leftsubree*rightsubtree
      colourwhite=(colourwhite%MOD)*dfs(it,0,source)%MOD;
      // source ko blackcolour karke, child pe jao
      // leftsubtree*rightsubtree
      colourblack=(colourblack%MOD)*dfs(it,1,source)%MOD;
    }
  }

  // wapas aate waqt(backtrack) check karlo ki parent kya coloured tha
  if(prevcolour==1) colourblack=0;

  return dp[source][prevcolour]=(colourblack+colourwhite)%MOD;
}

void solve(){
    
    cin>> n;
    graph.resize(n+1);

    // constructing the graph
    for(int i = 1; i<n; i++){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
    }

    fill_n(&dp[0][0], MAX_N*3, -1);

    cout << dfs(1,2,-1)%MOD << endl;   

       fflush(stdout);
       cout << flush;
}

int main() {

    #ifndef ONLINE_JUDGE
//for getting input from input.txt
freopen("input1.txt", "r", stdin);
//for writing output to output.txt
freopen("output.txt", "w", stdout);
#endif

ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

   solve();
       return 0;
}


