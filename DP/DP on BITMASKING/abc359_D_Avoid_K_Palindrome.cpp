#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 998244353;

long long dp[1001][1200];
int k, n;
  string str; 

  bool checkpalindrome(int &mask){
    int start = 0;
    int end = k-1;

    while(start<=end){


      int last  =  (mask&(1<<start));
      
      int first = (mask&(1<<end));

      if((last>0 && first==0) || (last==0 && first>0)) return 0;

      start++;
      end--;
    }

    return 1;
  }

int newmask(int index,int &mask,int binary){

    if(index<k) return mask+binary*(1<<index);
    else return (mask>>1)+binary*(1<<(k-1));
}

long long dpmask(int index, int mask){
  if(index>=k && checkpalindrome(mask)==1) {

    return 0;
  }

  if(index==n) return 1;

  if(dp[index][mask]!=-1) return dp[index][mask];

  long long ans = 0;

  if(str[index]!='?') {
    ans+=dpmask(index+1,newmask(index,mask,(str[index]=='A')));
  }
  else ans+=(dpmask(index+1,newmask(index,mask,0))+dpmask(index+1,newmask(index,mask,1)))%MOD;

  return dp[index][mask]=ans%MOD;
}

void solve(){
    
      
      cin >> n >> k;

    
      cin >> str;

      memset(dp,-1,sizeof(dp));
      cout << dpmask(0,0) << endl;
    
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

    
       solve();

       return 0;
}
