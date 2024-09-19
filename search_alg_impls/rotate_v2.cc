#include <vector>
#include "../search_algs.h"

namespace search
{

void rotate_v2(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    if (n<2) return;
    int n_1 = n-1;
    for (int i=0; i<n/2; i++) {
        for (int j=i; j<n-i-1; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n_1-j][i];
            matrix[n_1-j][i] = matrix[n_1-i][n_1-j];
            matrix[n_1-i][n_1-j] = matrix[j][n_1-i];
            matrix[j][n_1-i] = tmp;
        }
    }
}

void rotate_v3(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    if (n < 2) return;
    // sysm
    for (int i=1; i<n; i++) {
        for (int j = 0; j<i; j++) {
            std::swap<int>(matrix[i][j], matrix[j][i]);
        }
    }
    // flip
    for (int i=0; i<n; i++) {
        for (int j=0; j<n/2; j++) {
            std::swap<int>(matrix[i][j], matrix[i][n-j-1]);
        }
    }
    return;
}

} // namespace search
