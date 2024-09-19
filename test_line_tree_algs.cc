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
#include "line_tree_algs.h"

using namespace std;


/**
 * 97. 画出天际线：　用线段树．
 * 题目链接：https://leetcode.cn/problems/the-skyline-problem/
 * １．先对所有的点进行排序<x, height>,　其中开始节点的height为负数．排序后的节点按照横坐标递增．
 * ２．遍历排序后的点，如果为开始节点则将高度放入最大堆中，结束点则将该高度删除．
 * ３．得到当前堆中最大高度，如果当前最大高度和先前最大高度不同，则该点是关键点．
*/
void test_get_skyline() {
    std::vector<std::vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}}; // {{0,1,3}};
    std::vector<std::vector<int>> result = line_tree_alg::getSkyline(buildings);
    for (int i=0; i<result.size(); i++) {
        printf("%d %d\n", result[i][0], result[i][1]);
    }
}

/**
 * 98. 线段树求和. 两种方法：１．树状数组．　２．线段树
 * １．　树状数组．sum[i]存放的是sum(i) + sum(i-lowbit(i))的结果，直到ｉ变为０
 * sum[0+1]=sum(0), sum[1+1]=sum(0->1), 
 * sum[2+1]=sum(2), sum[3+1] = sum(0->3)
 * 则更新第ｉ个值为value时，其只会影响sum(i), sum(i+lowbit(i))的值，直到ｉ>n,;
 * 求i,j区间的和时，为sum(0->j)-sum（０－ｉ）, sum(0->j)= sum（j）+sum(j-=lowbit((j)), 直到j=0;
 * 注意在初始化sum数组时，sum[i] = pre_sum[i]-pre_sum[i-lowbit[i]]; 如sum[5]=pre[5]-pre[4]; sum[6]=pre[6]-pre[4];
 * 2. 线段树. SegNode{sum, begin, end, SegNode* left, SegNode* right} 在更新idx值时，当root->begin==root->right, root->sum=val; 
 * 否则mid=(root->begin+root->end)/2; if (idx<=mid) update(root->left, idx, val); else(root->right, idx, val)
 * 在查询求和时，if (root->begin==root->end) return root->sum 
 * 否则计算当前线段树的中间点，若求和范围left小于等于中间点，则计算左子树中left,right范围的和，若求和范围right大于中间点，再计算右子树中left,right范围的和．
 * 注意：　１．初始化线段树时，更新树的begin/end值．　２. 更新的if/else 条件可以并列; 但求和的两个if条件必须分别判断．
*/
void test_numarray() {
    std::vector<int> nums = {0,9,5,7,3}; // {1,3,5}; //{7,2,7,2,0}; //{}; //{1,3,5};
    // line_tree_alg::NumArray* obj = new line_tree_alg::NumArray(nums);
    // line_tree_alg::NumArray_v2* obj = new line_tree_alg::NumArray_v2(nums);
    line_tree_alg::NumArray_v3* obj = new line_tree_alg::NumArray_v3(nums);
    int param_0 = obj->sumRange(4,4);
    int param_1 = obj->sumRange(2,4);
    obj->update(1,2);
    int param_2 = obj->sumRange(0,2);
    printf("param1:%d, params2:%d\n", param_1, param_2);
    // obj->update(4,6);
    // obj->update(0,2);
    // obj->update(0,9);
    // int sum1 = obj->sumRange(4,4);
    // obj->update(3,8);
    // int sum2 = obj->sumRange(0,4);
    // printf("sum1:%d, sum2:%d\n", sum1, sum2);
}

/**
 * 99. 求未排序数组的逆序对．
 * 题目讲解：https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/solutions/216984/shu-zu-zhong-de-ni-xu-dui-by-leetcode-solution/
 * 1. 使用归并排序，在对各自排好序的nums1,nums2求逆序对，然后再对num1, num2进行merge.　其中num1所有元素均小于num2;
*/
void test_reverse_pairs() {
    std::vector<int> nums = {1,3,2,3,1}; //{2,4,3,5,1}; // {1,3,2,3,1};
    // int result = sort::merge_sort_reverse_pair(nums, 0, nums.size()-1);
    int result = line_tree_alg::reversePairs(nums);
    printf("result:%d\n", result);
}


int main() {
    // test_get_skyline();
    // test_numarray();
    test_reverse_pairs();
    return 0;
}
