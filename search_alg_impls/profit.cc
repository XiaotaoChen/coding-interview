#include<cstdio>
#include<vector>
#include<algorithm> // minmax_element
#include<climits> // INT_MIN


#include "../search_algs.h"

// int search::maxProfit_error(std::vector<int> &prices) {
//     // int min, max;
//     // std::vector<int>::iterator iter;
//     // iter = std::min_element(prices.begin(), prices.end());
//     // min = *iter;
//     // iter = std::max_element(prices.begin(), prices.end());
//     // max = *iter;

//     std::pair<std::vector<int>::iterator, std::vector<int>::iterator> minmax;
//     minmax = std::minmax_element(prices.begin(), prices.end());
//     return *minmax.second - *minmax.first;
// }

int search::maxProfit(std::vector<int> &prices) {
    int len = prices.size();
    if (len<2) return 0;
    int start = prices[0];
    int curr_max = 0;
    for (int i=1; i<len; i++) {
        if (prices[i]<start) start = prices[i];
        else if (prices[i] - start > curr_max) curr_max = prices[i] - start;
    }
    return curr_max;
}

int search::maxProfit_v2(std::vector<int> &prices) {
    int len = prices.size();
    if (len<2) return 0;
    int start = prices[0];
    int sum=0;
    int curr_max = 0;
    for (int i=1; i<len; i++) {
        if (prices[i]<prices[i-1]) {
            start = prices[i];
            sum += curr_max;
            curr_max = 0;
        }
        else if (prices[i] - start > curr_max) curr_max = prices[i] - start;
    }
    return sum+curr_max;
}

int search::maxProfit_v3(std::vector<int> &prices) {
    int len = prices.size();
    if (len<2) return 0;
    int buy1, sell1, buy2, sell2;
    buy1 = INT_MIN;
    sell1 = 0;
    buy2 = INT_MIN;
    sell2 = 0;
    
    for (int i=0; i<len; i++) {
        buy1 = std::max(buy1, -prices[i]);
        sell1 = std::max(sell1, buy1 + prices[i]);
        buy2 = std::max(buy2, sell1 - prices[i]);
        sell2 = std::max(sell2, buy2 + prices[i]);
    }
    return sell2;
}

// 参考：https://www.cnblogs.com/lillcol/p/14218940.html 买卖股票的最佳时机(最多交易两次)
int search::max_profit_2(std::vector<int>& nums) {
    if (nums.size() < 2) return 0;
    int n = nums.size();
    // pair.first,second 表示手上没有股票，手上有股票；
    // dp[i][j] 表示前i天做第j次交易。
    std::vector<std::vector<std::pair<int, int>>> dp(n+1, std::vector<std::pair<int, int>>(3, {INT32_MIN>>1, INT32_MIN>>1}));

    dp[0][0].first = 0;
    dp[0][0].second = -nums[0];

    for(int i=1; i<n;i++) {
        dp[i][0].first = 0; // 第0次操作，没有股票
        dp[i][1].first = std::max(dp[i-1][1].first, dp[i-1][0].second + nums[i]);
        dp[i][2].first = std::max(dp[i-1][2].first, dp[i-1][1].second + nums[i]);
        // 第0次操作，手上有股票
        dp[i][0].second = std::max(dp[i-1][0].second, dp[i-1][0].first - nums[i]);
        dp[i][1].second = std::max(dp[i-1][1].second, dp[i-1][1].first - nums[i]);
        dp[i][2].second = 0; //第2次操作，手上有股票，不合法
    }
    return dp[n-1][2].first;
}