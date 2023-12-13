// <----------------------------------------------------------------WRONG APPROACH------------------------------------------------------------------------------------------------->
// <---------------------------------------------CORRECT APPROACH DOWN USE OF PREFIX AND SUFFIX PRODUCT ARRAY------------------------------------------------------>

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

ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,maxi;
bool flag;
string str;


// IN-OUT DP or UP-DOWN DP


ll in[MAX_N]; // // number of ways to colour the nodes outside the subtree of i
ll out[MAX_N]; // number of ways to colour the nodes outside the subtree of i
void dfs(int source, int parent){
  
  in[source]=1;  // for painting black

  for(auto it: graph[source]){
    if(it!=parent){
      dfs(it,source);
      in[source]*=in[it];
    }
  }
  in[source]++; // for painting all whites
}


void dfs2(int source, int parent){
      ll t1 = in[source];
  for(auto it: graph[source]){
      if(it!=parent){

        in[source]-=1;  // wo for all whites wala case pehle remove kiya
        in[source]=in[source]/in[it];  // uske child "it" ka contribution hataya

        out[it]=out[it]*in[source]*out[source];  // out[child] calculate kara out[source] ko dhyan mein rakhte hue
        out[it]++;  // for all whites wale case ke liye increment kardiya --> bahar walo ke liye
        dfs2(it,source);
        in[source]=t1;  // rollback 
      }
  }
}


void solve(){
    
    cin>> n >> m;
    graph.resize(n+1);

    // constructing the graph
    for(int i = 1; i<n; i++){
            cin >> a >> b;
            a--;
            b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
    }

    fill(in,in+MAX_N,1);
    fill(out,out+MAX_N,1);

    dfs(0,-1); // calculation in[i] for each node i
    
    dfs2(0,-1); // calculation out[i] for each node i

    for(int i = 0; i<n; i++){
      cout << ((in[i]-1)%m*out[i]%m)%m << endl; // "-1" to remove case of for all whites we did earlier for "i" while calcualting in[i]
    }

    cout << endl;   

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






// <<-------------------------------------------------------------CORRECT APPROACH USE OF PREFIX AND SUFFIX PRODUCT ARRAY------------------------------------------------------>
// <<--------------------------------------------------------------------------- BUT STILL WA ---------------------------------------------------------------------------------->>


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

ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,maxi;
bool flag;
string str;


// IN-OUT DP or UP-DOWN DP


ll in[MAX_N]; // // number of ways to colour the nodes outside the subtree of i
ll out[MAX_N]; // number of ways to colour the nodes outside the subtree of i
void dfs(int source, int parent){
  
  in[source]=1;  // choice 1: for painting black

  for(auto it: graph[source]){
    if(it!=parent){
      dfs(it,source);
      in[source]=(in[source]*in[it]);
    }
  }
  in[source]++; // for painting all whites
}

void dfs2(int source, int parent){

      vector<ll> pre,suff;

      for(auto it: graph[source]){
        if(it!=parent)
        pre.push_back(in[it]);
        suff.push_back(in[it]);
      }

      int sz = pre.size();

      for(int i = 1; i<sz; i++){
        pre[i]=(pre[i]*pre[i-1]);
      }

      for(int i = sz-2; i>=0; i--){
        suff[i]=(suff[i]*suff[i+1]);
      }

      int cnt = 0;


  for(auto it: graph[source]){
      if(it==parent) continue;

      ll t2 = in[it];

          // re-rooting from node to ch
    ll l=1, r=1;    
    if(i-1>=0)
      l=pre[i-1];
    if(i+1<sz)
     r=suff[i+1];

    out[it]=(l*r*out[source]);  // out[child] calculate kara out[source] ko dhyan mein rakhte hue
    out[it]++;  // for all whites wale case ke liye increment kardiya --> bahar walo ke liye
    dfs2(it,source);
    cnt++;     
  }
}


void solve(){
    
    cin>> n >> m;
    graph.resize(n+1);

    // constructing the graph
    for(int i = 1; i<n; i++){
            cin >> a >> b;
            a--;
            b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
    }

    fill(in,in+MAX_N,-1);
    fill(out,out+MAX_N,1);

    dfs(0,-1); // calculation in[i] for each node i
    
    dfs2(0,-1); // calculation out[i] for each node i

    for(int i = 0; i<n; i++){
      cout << ((in[i]-1)*out[i])%m << endl; // "-1" to remove case of for all whites we did earlier for "i" while calcualting in[i]
    }

    cout << endl;   

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

