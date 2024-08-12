#include "../huawei_online.h"
#include <vector>
#include <stack>
#include <numeric>

namespace huawei_online
{
// base math alg
// HJ44 Sudoku
bool check(const std::vector<std::vector<int>>& matrix, int row, int col) {
    for (int i=0; i<9; i++) {
        if (i != row && matrix[i][col] == matrix[row][col]) return false;
        if (i != col && matrix[row][i] == matrix[row][col]) return false;
    }
    int start_row = row / 3 * 3;
    int start_col = col / 3 * 3;
    for (int i=start_row; i<start_row+3; i++) {
        for (int j=start_col; j<start_col+3; j++) {
            if (i != row && j != col && matrix[i][j] == matrix[row][col]) return false;
        }
    }
    return true;
}

void dfs(std::vector<std::vector<int>>& matrix, int idx, bool& flag) {
    if(idx == 81) {
        flag = true;
        return;
    }
    int row = idx / 9;
    int col = idx % 9;
    if (matrix[row][col] != 0) {
        dfs(matrix, idx + 1, flag);
    } else {
        for (int i=1; i<10; i++) {
            matrix[row][col] = i;
            if (check(matrix, row, col)) {
                dfs(matrix, idx + 1, flag);
                if (flag) return;
            }
        }
    }
}

bool sudoku(std::vector<std::vector<int>>& matrix) {
    bool flag = false;
    dfs(matrix, 0, flag);
    return true;
}

// HJ55 挑7
bool include_seven(int n) {
    while (n) {
        if (n % 10 == 7) return true;
        n /= 10;
    }
    return false;
}

int pick_seven(int n) {
    int count = 0;
    for (int i=1; i<=n; i++) {
        if (i % 7 == 0) count++;
        else if (include_seven(i)) count++;
    }
    return count;
}

// HJ56 完全数计算
std::vector<int> cal_factors(int n) {
    std::vector<int> res;
    int val = std::sqrt(n);
    for (int i=2; i<=val; i++) {
        if (n% i ==0) {
            res.push_back(i);
            res.push_back(n/i);
        }
    }
    return res;
}

int perfect_number(int n) {
    int count = 0;
    for (int i=4; i<=n; i++) {
        std::vector<int> factors = cal_factors(i);
        int sum = std::accumulate(factors.begin(), factors.end(), 1);
        if (sum == i) count++;
    }
    return count;
}

// HJ107 求解立方根
double cube_root(double n) {
    double left = -n;
    double right = n;
    while((right - left) > 0.001) {
        double mid = (left + right) / 2;
        if (mid * mid * mid > n) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return left;
}
} // namespace huawei_online