#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(){
    
    long long Sx, Sy, Tx, Ty;
    cin >> Sx >> Sy >> Tx >> Ty;

    if((Sx+Sy)%2!=0) Sx--;
    if((Tx+Ty)%2!=0) Tx--;



    long long x = abs(Tx - Sx);
    long long y = abs(Ty - Sy);

    
    if(y>=x){
      cout << y << endl;
    }
    else{
      long long ans = y + (x-y)/2;
      cout << ans << endl;
    }
    
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
