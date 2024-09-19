#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <cstdlib> // rand, qsort
#include <functional>
#include <fstream>
#include "data_structs/base_struct.h"
#include "merge_set.h"

using namespace std;

/*
75. 将外边界为O的字符的连通区域。
使用stack/queue 递归求解即可
再刷感想：想着dfs从矩阵边界查找＇O'的区域, 将其置为'A'，然后遍历矩阵，其他＇O＇的变成＇X＇, 'A'->'O'即可．
　　　　　其实不用dfs, 直接队列或栈遍历即可．
*/
void test_merge_set() {
    std::vector<std::vector<char>> board={
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    merge_set::solve(board);
    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[0].size(); j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
}

/*
76. 判断图中有几个独立连通区域。类似75.
使用栈遍历所有为1的连通区域。不过多加两层for循环并使用visited数组
*/
void test_num_island() {
    // std::vector<std::vector<char>> grid={
    //     {'1', '1', '0', '0', '0'},
    //     {'1', '1', '0', '0', '0'},
    //     {'0', '0', '1', '0', '0'},
    //     {'0', '0', '0', '1', '1'}
    // };
    std::vector<std::vector<char>> grid = {{'1'},{'1'}};
    int result = merge_set::numIslands(grid);
    printf("result:%d\n", result);
}

/*
77. 求出数组中最大连续数字的个数。
1. 使用unordered_set/map.
方法1. 使用set保存数组，遍历nums，求最大连续数
idx = i;while(nums[idx]-1 in set ) idx--; del set[nums[idx]-1]
idx = i+1;while(nums[idx]+1 in set ) idx++; del set[nums[idx]+1]
方法2：
使用并查集。使用map记录每个数字的父节点，以及和该节点属于同一个群的数量。
1.初始化 map[nums[i]]=nums[i], cnt[nums[i]]=1;
for (int i=0;i<n;i++) {
    if (nums[i]+1 in map) {
        result=max(result, mergetwoset(nums[i], nums[i]+1))
    }
}
2. merge two set: 先找出nums[i], nums[i]+1的父节点，
设置nums[i]+1的父节点为nums[i]; cnt[nums[i]]+=cnt[nums[i]+1]
3. 找出父节点的同时更新该群对应点的父节点：
find_root(nums, x): return nums[x]==nums? x: nums[x] = find_root(nums, nums[x]);
*/
void test_longest_consecutive2() {
    std::vector<int> data = {1,2,0,1}; //{100, 4, 200, 1, 3, 2};
    // int result = merge_set::longestConsecutive(data);
    // int result = merge_set::longestConsecutive_v2(data);
    // int result = merge_set::longestConsecutive_V3(data);
    int result = merge_set::longestConsecutive_V4(data);
    printf("result:%d\n", result);
}

int main() {
    test_merge_set();
    // test_num_island();
    // test_longest_consecutive2();
    return 0;
}
