#include "../huawei_online.h"
#include <vector>

namespace huawei_online
{
// sort alg
// HJ16
std::vector<int> prime_factor(int n) {
    std::vector<int> res;
    int sqrt_n = std::sqrt(n);
    for (int i=2; i<=sqrt_n; i++) {
        while(n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        res.push_back(n);
    }
    return res;
}

// HJ28
bool is_prime(int n) {
    if (n < 2) return false;
    int sqrt_n = std::sqrt(n);
    for (int i=2; i<=sqrt_n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool dfs(const std::vector<std::vector<bool>>& flags, const int idx, const std::vector<int>& even_nums, std::vector<bool>& visited, std::vector<int>& match) {
    for (int i=0; i<even_nums.size(); i++) {
        if (flags[idx][i] && !visited[i]) {
            visited[i] = true;
            if (match[i] == -1 || dfs(flags, match[i], even_nums, visited, match)) {
                match[i] = idx;
                return true;
            }
        }
    }
    return false;
}

int prime_partner(const std::vector<int>& nums) {
    std::vector<int> odd_nums;
    std::vector<int> even_nums;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i] % 2 == 0) {
            even_nums.push_back(nums[i]);
        } else {
            odd_nums.push_back(nums[i]);
        }
    }
    std::vector<std::vector<bool>> flags(odd_nums.size(), std::vector<bool>(even_nums.size(), false));
    for (int i=0; i<odd_nums.size(); i++) {
        for (int j=0; j<even_nums.size(); j++) {
            if (is_prime(odd_nums[i] + even_nums[j])) {
                flags[i][j] = true;
            }
        }
    }

    std::vector<int> match(even_nums.size(), -1);
    int res = 0;
    for (int i=0; i<odd_nums.size(); i++) {
        std::vector<bool> visited(even_nums.size(), false);
        if (dfs(flags, i, even_nums, visited, match)) {
            res++;
        }
    }
    return res;
}

// HJ68
std::vector<std::pair<std::string, int>> sort_score(const std::vector<std::pair<std::string, int>>& scores, const bool is_asc) {
    std::vector<std::tuple<std::string, int, int>> tmp_scores;
    for (int i=0; i<scores.size(); i++) {
        tmp_scores.push_back(std::make_tuple(scores[i].first, scores[i].second, i));
    }
    if (is_asc) {
        std::sort(tmp_scores.begin(), tmp_scores.end(), [](const std::tuple<std::string, int, int>& a, const std::tuple<std::string, int, int>& b) {
            return std::get<1>(a) < std::get<1>(b) || (std::get<1>(a) == std::get<1>(b) && std::get<2>(a) < std::get<2>(b));
        });
    } else {
        std::sort(tmp_scores.begin(), tmp_scores.end(), [](const std::tuple<std::string, int, int>& a, const std::tuple<std::string, int, int>& b) {
            return std::get<1>(a) > std::get<1>(b) || (std::get<1>(a) == std::get<1>(b) && std::get<2>(a) < std::get<2>(b));
        });
    }
    std::vector<std::pair<std::string, int>> res;
    for (int i=0; i<tmp_scores.size(); i++) {
        res.push_back(std::make_pair(std::get<0>(tmp_scores[i]), std::get<1>(tmp_scores[i])));
    }

    return res;
}

std::vector<std::pair<std::string, int>> sort_score_v2(const std::vector<std::pair<std::string, int>>& scores, const bool is_asc) {
    std::vector<std::vector<std::string>> tmp(101, std::vector<std::string>());
    for (int i=0; i<scores.size(); i++) {
        tmp[scores[i].second].push_back(scores[i].first);
    }
    std::vector<std::pair<std::string, int>> res;
    if (is_asc) {
        for (int i=0; i<tmp.size(); i++) {
            for (int j=0; j<tmp[i].size(); j++) {
                res.push_back(std::make_pair(tmp[i][j], i));
            }
        }
    } else {
        for (int i=tmp.size()-1; i>=0; i--) {
            for (int j=0; j<tmp[i].size(); j++) {
                res.push_back(std::make_pair(tmp[i][j], i));
            }
        }
    }
    return res;
}

// HJ103
int redraiment_walk(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n, 1);
    int res = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        if (res < dp[i]) {
            res = dp[i];
        }
    }
    return res;
}

} // namespace huawei_online