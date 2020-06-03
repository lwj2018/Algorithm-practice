#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    double new21Game(int N, int K, int W) {
        int maxK = K - 1 + W;
        vector<double> dp(maxK+1,0);
        if(K==0) return 1;
        for (int i = K; i <= N && i<=K+W-1; i++)
        {
            dp[i] = 1.0;
        }
        dp[K-1] = (1.0 * (N-K+1<W)?N-K+1:W )/ (double) W;
        for (int i = K-2; i >= 0; i--)
        {
            dp[i] = dp[i+1] - (dp[i+W+1]-dp[i+1]) / W;
        }
        return dp[0];
    }
};