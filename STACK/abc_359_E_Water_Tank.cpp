#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 998244353;

int n;

void solve(){
    
      
      cin >> n;

    
      vector<int> height(n);

      for(int i = 0; i<n; i++){
        cin >> height[i];
      }

      stack<int> st;
      vector<long long> ans(n,0);
      vector<long long> prev(n,0);

      st.push(0);
      prev[0]=height[0];
      ans[0]=prev[0]+1;
      

      for(int i = 1; i<n; i++){

          while(!st.empty() && height[st.top()]<height[i]){

            st.pop();

          }

          if(st.empty()) {
            ans[i]=(i+1)*1LL*height[i];
            prev[i]=ans[i];
            ans[i]+=1;
          }
          else{
            ans[i]=prev[st.top()]+(i-st.top())*1LL*height[i];
            prev[i]=ans[i];
            ans[i]+=1;
          } 

          st.push(i);
      }

      for(int i = 0; i<n; i++){
        cout << ans[i] << " ";
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

    
       solve();

       return 0;
}
