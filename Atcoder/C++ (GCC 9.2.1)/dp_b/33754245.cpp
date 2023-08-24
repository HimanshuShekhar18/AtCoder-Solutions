#include <iostream>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

int frogJump(int n, vector<int> &h, int k, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int mm_steps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        int jump;
        if (n - j >= 0)
        {
            jump = frogJump(n-j, h, k, dp) + abs(h[n] - h[n - j]);
        }

        mm_steps = min(mm_steps, jump);
    }

    return dp[n] = mm_steps;
}

int main()
{

    int n, k;
    vector<int> h;
    cin >> n >> k;
    vector<int> dp(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        int height;
        cin >> height;
        h.push_back(height);
    }

    cout << frogJump(n - 1, h, k, dp) << endl;
}
