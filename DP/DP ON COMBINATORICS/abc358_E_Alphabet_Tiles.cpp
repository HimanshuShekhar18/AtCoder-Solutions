// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;    // for Policy Based DS


# define ll long long

#include <atcoder/modint.hpp>
#include <atcoder/convolution>
using mint = atcoder::modint998244353;

const int maxnCr = 2e6+5;
vector<mint> fact(maxnCr+1),inverse(maxnCr+1);

// Function to calculate nCr
mint nCr(ll n,ll r)
{  
     if(n<0||r<0||r>n) return 0;
     return fact[n] *inverse[r]*inverse[n-r];
}

// calculating the factorial and it's inverse
void pre(ll n)
 {
     fact[0]=1;
     for(int i=1;i<=n;++i) fact[i]=i*fact[i-1];
     inverse[n] = fact[n].pow(mint(-2).val());
     for(int i=n;i>0; i-- ) inverse[i-1]=i*inverse[i];
     inverse[0]=mint(1);
 }



void solve(){

    long long k;
    cin >> k;

    vector<long long> alphabetfreq(27,0);

    for(int i = 1; i<=26; i++){
        cin >> alphabetfreq[i];
    }


     pre(maxnCr);


    vector<vector<mint>> dp(27,vector<mint> (k+1));


    dp[0][0]=1; 

    for(int i = 1; i<=26; i++){
        int maxfrequency = alphabetfreq[i];
        for(int frequency = 0; frequency<=maxfrequency; frequency++){
            for(int prevlen = 0; prevlen+frequency<=k; prevlen++){
                int finallength = prevlen+frequency;
                dp[i][finallength]+=nCr(finallength,frequency)*dp[i-1][prevlen];
            }
        }
    }

    mint ans = 0;

    for(int i = 1; i<=k; i++){
        ans+=dp[26][i];
    }

    cout << ans.val() << endl;

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
