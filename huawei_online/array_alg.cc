#include "../huawei_online.h"
#include <vector>

namespace huawei_online
{
// array alg
// HJ3
std::vector<int> distinct_random(const std::vector<int>& nums) {
    std::vector<bool> flags(501, false);
    for (const auto num: nums) {
        flags[num] = true;
    }
    std::vector<int> res;
    for (int i=0; i<flags.size(); i++) {
        if (flags[i]) {
            res.push_back(i);
        }
    }
    return res;
}

// HJ35
std::vector<std::vector<int>> snake_matrix(int n) {
    std::vector<std::vector<int>> res(n);
    int curr = 1;
    for (int i=0; i<n; i++) {
        for (int j=i; j>=0; j--) {
            res[j].push_back(curr++);
        }
    }
    return res;
}

// HJ64
std::pair<std::vector<int>, int> move(const std::string& s, int n) {
    int range_from = 1;
    int range_to = n < 4?n:4;
    int curr = 1;
    for (int i=0; i<s.length(); i++) {
        if (s[i] == 'U') {
            if (curr == range_from) {
                if (range_from == 1) {
                    if (n > 4) {
                        range_from = n-3;
                        range_to = n;
                    }
                    curr = n;
                } else {
                    range_from -= 1;
                    range_to -= 1;
                    curr = range_from;
                }
            }
            else {
                curr -= 1;
            }
        } else if (s[i] == 'D') {
            if (curr == range_to) {
                if (range_to == n) {
                    if (n > 4) {
                        range_from = 1;
                        range_to = 4;
                    }
                    curr = 1;
                } else {
                    range_from += 1;
                    range_to += 1;
                    curr = range_to;
                }
            }
            else {
                curr += 1;
            }
        }
    }
    std::vector<int> res;
    for (int i=range_from; i<=range_to; i++) {
        res.push_back(i);
    }
    return std::make_pair(res, curr);
}

// HJ69
std::vector<std::vector<int>> matrix_multiply(const std::vector<std::vector<int>>& m1, const std::vector<std::vector<int>>& m2) {
    int n = m1.size();
    int k = m1[0].size();
    int m = m2[0].size();
    std::vector<std::vector<int>> res(n, std::vector<int>(m, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int t=0; t<k; t++) {
                res[i][j] += m1[i][t] * m2[t][j];
            }
        }
    }
    return res;
}

} // namespace huawei_online