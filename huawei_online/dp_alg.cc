#include "../huawei_online.h"
#include <vector>

namespace huawei_online
{
// dp alg
// HJ16
int shopping_list(const std::vector<std::vector<std::pair<int, int>>>& goods, int money) {
    // m1: things: [[value, weight], [value, weight], ...]
    int n = goods.size();
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(money+1, 0));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=money; j++) {
            dp[i][j] = dp[i-1][j];
            int price = goods[i-1][0].first;
            if (j >= price) {
                dp[i][j] = std::max(dp[i][j], dp[i-1][j-price] + goods[i-1][0].second);
            }
            if (goods[i-1].size() > 1) {
                price = goods[i-1][0].first + goods[i-1][1].first;
                if (j >= price) {
                    dp[i][j] = std::max(dp[i][j], dp[i-1][j-price] + goods[i-1][0].second + goods[i-1][1].second);
                }
            }
            if (goods[i-1].size() > 2) {
                price = goods[i-1][0].first + goods[i-1][2].first;
                if (j >= price) {
                    dp[i][j] = std::max(dp[i][j], dp[i-1][j-price] + goods[i-1][0].second + goods[i-1][2].second);
                }
                price = goods[i-1][0].first + goods[i-1][1].first + goods[i-1][2].first;
                if (j >= price) {
                    dp[i][j] = std::max(dp[i][j], dp[i-1][j-price] + goods[i-1][0].second + goods[i-1][1].second + goods[i-1][2].second);
                }
            }
        }
    }
    return dp[n][money];
}

// HJ24
std::vector<int> dp1(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n, 0);
    for (int i=0; i<n; i++) {
        dp[i] = 1;
        for (int j=0; j< i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = std::max(dp[i], dp[j]+1);
            }
        }
    }
    return dp;
}

std::vector<int> dp2(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n, 0);
    for (int i=n-1; i>=0; i--) {
        dp[i] = 1;
        for (int j=n-1; j> i; j--) {
            if (nums[j] < nums[i]) {
                dp[i] = std::max(dp[i], dp[j]+1);
            }
        }
    }
    return dp;
}

int chorus_team(const std::vector<int>& nums) {
    if (nums.size() < 2) return nums.size();
    std::vector<int> dp1_res = dp1(nums);
    std::vector<int> dp2_res = dp2(nums);
    int res = 0;
    for (int i=0; i<nums.size(); i++) {
        res = std::max(res, dp1_res[i] + dp2_res[i] - 1);
    }
    return nums.size() - res;
}

// HJ61
int apple_count(int m, int n) {
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));
    for (int i=0; i<=n; i++) {
        dp[i][0] = 1;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= i) {
                dp[i][j] += dp[i][j-i];
            }
        }
    }
    return dp[n][m];
}

// HJ63
std::pair<float, float> ball_distance(int n) {
    float curr_hight = n;
    float total_distance = 0;
    for (int i=0; i<5; i++) {
        if (i== 4) {
            total_distance += curr_hight;
        } else {
            total_distance += curr_hight *3 /2;
        }
        curr_hight /= 2;
    }
    return std::make_pair(total_distance, curr_hight);
}

} // namespace huawei_online