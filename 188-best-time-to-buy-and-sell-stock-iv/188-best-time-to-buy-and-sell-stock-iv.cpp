class Solution {
 public:
  // Here we are using the transactionNumber as a metric for the buying and
  // selling It will always be BSBSBSBS . Like buy and sell and then buy again
  // thus buy will be at odd idx and sell will always be at even idx . Thus this
  // reduces our space from [N] *[ 2] *[ K] -> [N] * [2*K];
  int rec(int i, int txnNo, vector<int>& prices, int k) {
    if (i == prices.size() || txnNo == k) return 0;
    // BUY
    if (txnNo % 2 == 0) {
      return max(-prices[i] + rec(i + 1, txnNo + 1, prices, k),
                 rec(i + 1, txnNo, prices, k));
    } else {
      return max(prices[i] + rec(i + 1, txnNo + 1, prices, k),
                 rec(i + 1, txnNo, prices, k));
    }
  }

  int mem(int i, int txnNo, vector<int>& prices, int k,
          vector<vector<int>>& dp) {
    if (i == prices.size() || txnNo == k) return 0;
    // BUY

    if (dp[i][txnNo] != -1) return dp[i][txnNo];
    if (txnNo % 2 == 0) {
      return dp[i][txnNo] =
                 max(-prices[i] + mem(i + 1, txnNo + 1, prices, k, dp),
                     mem(i + 1, txnNo, prices, k, dp));
    } else {
      return dp[i][txnNo] =
                 max(prices[i] + mem(i + 1, txnNo + 1, prices, k, dp),
                     mem(i + 1, txnNo, prices, k, dp));
    }
  }

  int tabulation(vector<int>& prices, int k) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
    for (int i = n - 1; i >= 0; i--)
      for (int txn = 0; txn < 2 * k; txn++)
        if (txn % 2 == 0)
          dp[i][txn] = max(-prices[i] + dp[i + 1][txn + 1], dp[i + 1][txn]);
        else
          dp[i][txn] = max(prices[i] + dp[i + 1][txn + 1], dp[i + 1][txn]);
    return dp[0][0];
  }

  // NBK means using a 3d dp for N -> Number Of Txns , B -> 0 1 BUY / SELL , K
  // -> LIMIT ON TXNS
  int tabulationNBK(vector<int>& prices, int k) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
    // for(int i=0 ; i < n ; i++)
    //     for(int b =0 ;b <=1 ;b++)
    //         dp[i][b][0] =0;
    // for(int b=0;b<=1;b++)
    //     for(int c=0;c<=2;c++)
    //         dp[n-1][b][c] =0;
    for (int i = n - 1; i >= 0; i--) {
      for (int b = 0; b <= 1; b++) {
        for (int c = 1; c <= k; c++) {
          if (b) {
            dp[i][b][c] = max(-prices[i] + dp[i + 1][0][c], dp[i + 1][1][c]);
          } else {
            dp[i][b][c] = max(prices[i] + dp[i + 1][1][c - 1], dp[i + 1][0][c]);
          }
        }
      }
    }
    return dp[0][1][k];
  }

  int maxProfit(int k, vector<int>& prices) {
    // vector<vector<vector<int>>>dp(prices.size()+1 , vector<vector<int>>(2 ,
    // vector<int>(k+1 , -1))); return mem(0 , 1 , k+1 , prices , dp); return
    // tabulation(prices , k); return rec(0 ,0 ,prices , 2*k);
    // vector<vector<int>> dp(prices.size() , vector<int> (2*k , -1));
    // return mem(0 , 0 , prices , 2*k, dp);
    return tabulation(prices, k);
  }
};