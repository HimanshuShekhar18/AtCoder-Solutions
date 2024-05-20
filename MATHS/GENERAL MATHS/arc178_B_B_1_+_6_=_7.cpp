// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */


// <-----------------------------------------------------------------MINE APPROACH GOT WA-------------------------------------------------------------------------------------------->


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;    // for Policy Based DS
const int MOD = 998244353;


#define ll long long

ll a,b,c,d,e,f,g,h, i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans, maxi;
bool flag;
string str;

ll expo(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%MOD;
        a = (a * a)%MOD;
        b >>= 1;
    }
    return res%MOD;
}


/*

Algorithm Approach

10^(a1-1)<=x1<10^a1
10^(a2-1)<=x2<10^a2
10^(a3-1)<=x3<10^a3
a2=a3:
a1=a2: sum(10^a2-10^(a2-1)-x1 for 10^(a1-1)<=x1<10^(a1))   here a1=a2
a1<a2: sum(10^a2-10^(a2-1)-x1 for 10^(a1-1)<=x1<10^a1)
a2<a3:
If A3=A2+1 We can find the count when A3=A2 and subtract that value from 81×10^(A1+A2−2).
ans=(10^a1-10^(a1-1))*(10^a2-10^(a2-1))-solve(a1,a2,a3-1)

*/

/*

In the range [10,11,12,13,.............................99]

the sum of all these elements = number_of_terms*(10+99)/2;

number_of_terms = 100-10 = 90;

This concept is used in Subcase 2: of Case 1:
*/

void solve(){

    cin >> a >> b >> c;

    if(a>b) swap(a,b);

    if(c!=b+1 && c!=b) {
      cout << 0 << endl;
      return;
    }


    // case 1: if b == c
    if(b==c){
      // subcase1: a==b
      if(a==b){
        cout << ((8*expo(10,a-1)%MOD * (8*expo(10,a-1)%MOD + 1))/2)%MOD << endl;
      }
      // subcase2: a!=b
      else {
        cout << (9*expo(10,a-1)%MOD * (9*expo(10,b-1)%MOD - (11*expo(10,a-1)%MOD -1)/2 )%MOD)%MOD << endl;
      }
    }
    // case 2: if b+1=c
    else {
      if(a==b) cout << (81*expo(10,(a+b-2))%MOD -  ((8*expo(10,a-1)%MOD * (8*expo(10,a-1)%MOD + 1))/2)%MOD)%MOD << endl;
      else cout << (81*expo(10,(a+b-2))%MOD -  (9*expo(10,a-1)%MOD * (9*expo(10,b-1)%MOD - (11*expo(10,a-1)%MOD -1)/2 )%MOD)%MOD)%MOD << endl;
    }

       fflush(stdout);
       cout << flush;
    }


int main() {

    cin >> t;
    for (int T = 1; T <= t; ++T)
    {
      
       solve();

    }

       return 0;
}


// <-------------------------------------------------------------------------ATCODER FILE INCLUSION AND MINT USAGE--------------------------------------------------------------------------------->

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/modint>
using mint = atcoder::modint998244353;
mint ten = 10;

mint solve(int a1, int a2, int a3){
    if (a1 > a2) swap(a1, a2);
    if (a2 != a3 && a2 + 1 != a3) return 0;
    if (a2 + 1 == a3){
        return 81 * ten.pow(a1 + a2 - 2) - solve(a1, a2, a3 - 1);
    }
    if (a1 == a2){
        return (8 * ten.pow(a1 - 1)) * (8 * ten.pow(a1 - 1) + 1) / 2;
    }
    return 9 * ten.pow(a1 - 1) * (9 * ten.pow(a2 - 1) - (11 * ten.pow(a1 - 1) - 1) / 2);
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        cout << solve(a1, a2, a3).val() << "\n";
    }
}


// <-----------------------------------------------------------------------------ITERATIVE MINT APPROACH------------------------------------------------------------------------------------------------------->

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/modint>
using mint = atcoder::modint998244353;
mint ten = 10;

#define ll long long

/*

10^(a1-1)<=x1<10^a1
10^(a2-1)<=x2<10^a2
10^(a3-1)<=x3<10^a3
a2=a3:
a1=a2: sum(10^a2-10^(a2-1)-x1 for 10^(a1-1)<=x1<10^(a1))   here a1=a2
a1<a2: sum(10^a2-10^(a2-1)-x1 for 10^(a1-1)<=x1<10^a1)
a2<a3:
If A3=A2+1 We can find the count when A3=A2 and subtract that value from 81×10^(A1+A2−2).
ans=(10^a1-10^(a1-1))*(10^a2-10^(a2-1))-solve(a1,a2,a3-1)

*/



void solve(){
    
    int a, b, c;
    cin >> a >> b >> c;

    if(a>b) swap(a,b);

    if(c!=b+1 && c!=b) {
      cout << 0 << endl;
      return;
    }

    mint ans, whole;


    // case 1: if b == c
    if(b==c){
      // subcase1: a==b
      if(a==b){
        ans = (mint(8)*ten.pow(a-1)) * (mint(8)*ten.pow(a-1) + 1)/2;
        cout << ans.val() << endl;
      }
      // subcase2: a!=b
      else {
        ans = mint(9)*ten.pow(a-1) * (mint(9)*ten.pow(b-1) - (mint(11)*ten.pow(a-1) -1)/2);
        cout << ans.val() << endl;
      }
    }
    // case 2: if b+1=c
    else {
        
      if(a==b) {
        
       whole = mint(81)*ten.pow(a+b-2);
       ans = (mint(8)*ten.pow(a-1)) * (mint(8)*ten.pow(a-1) + 1)/2;
       cout << whole.val() - ans.val()   << endl;

      }
      else {
        whole = mint(81)*ten.pow(a+b-2);
        ans = mint(9)*ten.pow(a-1) * (mint(9)*ten.pow(b-1) - (mint(11)*ten.pow(a-1) -1)/2);
        cout << whole.val() - ans.val()   << endl;
      }
    }

       fflush(stdout);
       cout << flush;
    }


int main() {
    int t;
    cin >> t;
    for (int T = 1; T <= t; ++T)
    {
      
       solve();

    }

       return 0;
}


