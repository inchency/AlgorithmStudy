class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i=1; i<=amount; i++){
            for(auto num : coins){
                if(i - num >= 0){
                    if(dp[i-num] != INT_MAX){
                        dp[i] = min(dp[i-num] + 1, dp[i]);
                    }
                }
            }
        }
        for(int i=1; i<=amount; i++)
            cout << dp[i] << " ";
        if(dp[amount] == INT_MAX) return -1;
        else return dp[amount];
    }
};

