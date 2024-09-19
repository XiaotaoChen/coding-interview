#include <cstdio>
#include <vector>

#include "../search_algs.h"

std::vector<int> search::spiralOrder(std::vector<std::vector<int>>& matrix) {
    std::vector<int> result;
    int row = matrix.size();
    if (row == 0) return result;
    int col = matrix[0].size();
    if (row==1) return matrix[0];

    int total_count = ((row < col ? row:col) + 1) / 2;

    int i=-1;
    int j=-1;
    for (int count=0; count < total_count; count++) {
        i++;
        j++;
        // i = count;
        // j = count;
        if (j >= col - count) break;
        // left --> right
        for (j=count; j<col - count; j++) {
            result.push_back(matrix[i][j]);
        }
        // top -> down
        j--;
        i++;
        // i = count +1;
        // j = col - count - 1;
        if (i >= row - count) break;
        for(; i<row - count; i++) {
            result.push_back(matrix[i][j]);
        }
        // right --> left
        i--;
        j--;
        // i = row - count -1;
        // j = col -count -2;
        if (j < count) break;
        for (; j>=count; j--) {
            result.push_back(matrix[i][j]);
        }
        // down --> top
        j++;
        i--;
        // i = row - count - 2;
        // j = count; 
        if (i <= count) break;
        for (; i>count; i--) {
            result.push_back(matrix[i][j]);
        }
    }
    return result;
}

std::vector<int> search::spiralOrderV2(std::vector<std::vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    if (row == 1) return matrix[0];

    std::vector<int> res;
    if (col == 1) {
        for(int i=0; i<row; i++) {
            res.push_back(matrix[0][0]);
        }
    }
    int round = std::min(row+1, col+1) / 2;
    for (int round_id=0; round_id<round; round_id++) {
        int i = round_id;
        int j = round_id;
        int end_row = row - round_id;
        int end_col = col - round_id;
        // left --> right
        while(j<end_col) {
            res.push_back(matrix[i][j]);
            j++;
        }
        // top --> down
        i = round_id+1;
        j = end_col-1;
        if (i >= end_row) break;
        while(i<end_row) {
            res.push_back(matrix[i][j]);
            i++;
        }
        // right --> left
        i = end_row-1;
        j = end_col-2;
        if (j < round_id) break;
        while(j>=round_id) {
            res.push_back(matrix[i][j]);
            j--;
        }
        // down --> top
        i = end_row - 2;
        j = round_id;
        if (i <= round_id) break;
        while(i > round_id) {
            res.push_back(matrix[i][j]);
            i--;
        }
    }
    return res;
}

std::vector<std::vector<int>> search::generateMatrix(int n) {
    if (n ==0) {
        std::vector<std::vector<int>> result_vec;
        return result_vec;
    }
    
    std::vector<std::vector<int>>  result(n, std::vector<int>(n, 0));

    int total_count = (n+1) / 2;
    int num = 0;
    int i = -1;
    int j = -1;

    for (int count = 0; count<total_count; count++) {
        i++;
        j++;
        // if (num > n*n) break;
        if (j >= n - count) break;
        for (; j<n-count; j++) {
            result[i][j] = ++num;
        }

        i++;
        j--;
        if (i >= n - count) break;
        for (; i<n-count; i++) {
            result[i][j] = ++num;
        }

        i--;
        j--;
        if (j<count) break;
        for (; j>=count;j--){
            result[i][j] = ++num;
        }

        i--;
        j++;
        if (i<=count) break;
        for (; i>count; i--) {
            result[i][j] = ++num;
        }
    }
    return result;
}