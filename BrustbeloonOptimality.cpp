#include <iostream>
using namespace std;

int nums[100];
int n;
int dp[100][100];

int f(int i, int j)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int maxi = -1e9;
    for (int k = i; k < j; k++)
    {
        int score;
        if (i == 1 && j == n + 1)
        {
            score = nums[j] * nums[k] * nums[i - 1] + f(i, k) + f(k + 1, j);
        }
        else
        {
            score = nums[i - 1] * nums[j] + f(i, k) + f(k + 1, j);
        }
        maxi = max(maxi, score);
    }
    return dp[i][j] = maxi;
}

int main()
{
    cin >> n;
    nums[0] = 1;
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            dp[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    nums[n + 1] = 1;

    cout << f(1, n + 1) << endl;

    return 0;
}
