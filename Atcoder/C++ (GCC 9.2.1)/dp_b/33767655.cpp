#include <iostream>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

int frogJump(int n, vector<int> &h, int k, vector<int> &dp)
{

    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int mm_steps = INT_MAX;

        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(h[i] - h[i - j]);
                mm_steps = min(mm_steps, jump);
            }
        }

        dp[i] = mm_steps;
    }

    return dp[n];
}

int main()
{

    int n, k;
    vector<int> h;
    cin >> n >> k;
    vector<int> dp(n, -1);
    for (int i = 0; i < n; i++)
    {
        int height;
        cin >> height;
        h.push_back(height);
    }

    cout << frogJump(n - 1, h, k, dp) << endl;
}

// time complexity: O(n*k)
// space complexity: O(n