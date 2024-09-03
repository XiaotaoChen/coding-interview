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
#include "hot_100.h"
#include "thot_50.h"

using namespace std;

/*********************************************************************************/
/********************************** hot 100 **************************************/
/*********************************************************************************/
/**
 * 1. 第ｋ个最大值
*/
void test_findkthlargest_hot_100() {
    std::vector<int> arr = {3,2,1,5,6,4};
    int k=2;
    // int result = hot_100::findKthLargest(arr, k);
    int result = hot_100::findKthLargest_min_heap(arr, k);
    std::cout << "test findkthlargest result: " << result << std::endl;
}

/**
 * 2. 滑动窗口最大值
 * 注意使用双向队列．　存放ｋ窗口中降序下标．
 * １．当当前节点值大于dequeue.back时，pop_back,而不是判断当前节点值大于dequeue.front()
 * ２．判断当前front最大值是否超过了k时，也要判断dequeue是否为空，因为k=1时，初始化queue时是空的
*/
void test_max_sliding_window_hot_100() {
    std::vector<int>  nums = {1,3,1,2,0,5}; //{1,3,-1,-3,5,3,6,7};
    int k = 3;
    // std::vector<int> result = hot_100::maxSlidingWindow(nums, k);
    std::vector<int> result = hot_100::maxSlidingWindow_v2(nums, k);
    std::cout << "test max sliding windos:" ;
    for (int i=0; i<result.size(); i++) std::cout << result[i] << " ";
    std::cout << std::endl;
}

/**
 * 3. 搜索二维矩阵
 * 从左下角开始搜，如果［row_idx, col_idx］ > target, 往上走row_idx--; 否则col_idx++;
 * 注意row_idx可能出现小于０的情况，而不会出现＞row的情况
*/
void test_searchMatrix_hot_100() {
    std::vector<std::vector<int>> matrix = {{-1, 3}}; // {{1,4,7}, {2,5,8},{3,6,9}};
    int target = 1; //5;
    bool result = hot_100::searchMatrix(matrix, target);
    std::cout << "test search matrix result: " << std::boolalpha << result << std::endl;
}

/**
 * 4. 完全平方数.　完全0/1背包问题
 * 注意初始化的时候dp[0]=0, 其他为INT_MAX, 然后遍历寻找最小值
*/
void test_numsquare_hot_100() {
    int n =13;
    int result = hot_100::numSquares(n);
    std::cout << "test numsquare result: " << result << std::endl;
}

/**
 * 5. 最长上升子序列
 * 1. 刚开始以为是用栈，求得包含当前值的升序序列，但该种方法忽略了历史最有子序列．
 * 如{1,3,6,7,9,4,10}, 栈方法是会得到{1,3,4,10},而最长的升序应该是{1,3,6,7,9,10}
 * ２．使用ｄｐ方法，如果nums[i]大于nums[j]则dp[i]可以由dp[j]+1得到，
 * 然后从０到ｉ－１遍历j得到０－＞ｉ的最长升序子序列
 * ３．　结果并不是返回dp[n-1],而应该记录整个过程的最大值．
*/
void test_lengthofLIS_hot_100() {
    std::vector<int> arr = {1,3,6,7,9,4,10,5,6}; //{10,9,2,5,3,7,101,18};
    // int result = hot_100::lengthOfLIS(arr);
    int result = hot_100::lengthOfLIS_V2(arr);
    std::cout << "test length of LIS result: " << result << std::endl;

}

/**
 * 6. 根据身高重建队列
*/
void test_reconstruct_queue_hot_100() {
    std::vector<std::vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    std::vector<std::vector<int>> result = hot_100::reconstructQueue(people);
    std::cout << "test reconstruct queue:\n";
    for (int i=0; i<result.size(); i++) {
        std::cout << result[i][0] << ", " << result[i][1] << std::endl;
    }
}

/**
 * 7. 路径总和
 * 思路：　dfs求解．刚开始只考虑到一层ｄｆｓ，导致逻辑有点错误．
 * １．　dfs(root->left, target, cnt), dfs(root->right, target , cnt)
 * 然后　dfs(root->left, target - root->val, cnt), 
 *      dfs(root->right, target-root->val, cnt)
 * 该重dfs其实是结果等于target或target-root->val的结果．而不是结果为target的结果．
 * 应该两层dfs. 第一层　
 * dfs(root, sum, cnt), 
 * dfs(root->left, sum, cnt), 
 * dfs(root->right, sum, cnt)
 * 第二层dfs:
 * dfs_two(root->left, sum-root->val, cnt)
 * dfs_two(root->right, sum-root->val, cnt)
 * 
*/
void test_pathsum_hot_100() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);
    int target = 8;
    int result = hot_100::pathSum(root, target);
    std::cout << "test pathsum result: " << result << std::endl;
}

/**
 * 8. 找到消失的数字. 通过将nums中的数字映射成下标idx=(nums[i]-1)%n, 然后将nums[idx]+=n, 
 * 最后遍历nums, 若nums[i]　<=n, 则ｉ＋１没出现在原始数组中
 * 
 * */
void test_find_disappearedNumbers_hot_100() {
    std::vector<int> nums = {4,3,2,7,8,2,3,1};
    std::vector<int> result = hot_100::findDisappearedNumbers(nums);
    std::cout << "test find disappeared numbers: ";
    for (int i=0; i<result.size(); i++) std::cout << result[i] << " ";
    std::cout << std::endl;
}

/**
 * 9. 观测每日温度
*/
void test_daily_temperatures_hot_100() {
    std::vector<int> T = {73,74,75,71,69,72,76,73};
    std::vector<int> result = hot_100::dailyTemperatures(T);
    std::cout << "test daily temperatures:";
    for (int i=0; i<result.size(); i++) std::cout << result[i] << " ";
    std::cout << std::endl;
}

/**
 * 10. 股票最大收益. dp＋状态转换
 * dp[i][0] 表示第i天结束，处于可以买入的状态的收益的最大值
 * dp[i][1] 表示第i天结束，手中有股票的状态的收益的最大值
 * dp[i][2] 表示第i天结束，处于冷冻期的收益的最大值
 * 注意初始化不应该全为０，　应该为INT_MIN, dp[0][0]=0
*/
void test_max_profit_hot_100() {
    std::vector<int> prices = {1,2,3,0,2};
    int result = hot_100::maxProfit(prices);
    std::cout << "test max profit: " << result << std::endl;
}

/**
 * 11. 戳气球dp求解，　状态转移方程　dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]+points[i]*points[k]*points[j])
 * 注意是求points的ｉ,j,k数字乘积，而不是k,k-1,k+1
*/
void test_max_coins_hot_100() {
    std::vector<int> nums = {3,1,5,8};
    int result = hot_100::maxCoins(nums);
    std::cout << "test max coins: "<< result << std::endl;
}

/**
 * 12. 最短无序连续子数组. 使用单调栈，分别找出前后从未出过栈的下标．即求得出栈的下标中，最小，最大下标．
 * 则len = r - l +1
*/
void test_find_unsorted_sub_array_hot_100() {
    std::vector<int> nums = {2,6,4,8,10,9,15};
    int  result = hot_100::findUnsortedSubarray(nums);
    std::cout <<  "test find unsorted subarray result: " << result << std::endl;
}

/**
 * 13. 二叉树＋dp求解大家劫舍
*/
void test_rob() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    int result = hot_100::rob(root);
    std::cout << "test rob result: " << result << std::endl;
}

/**
 * 14. 比特位计数，dp求解，奇数比特位数等于dp[i-1]+1, 偶数=dp[i>>1]
*/
void test_count_bits() {
    int num = 5;
    std::vector<int> result = hot_100::countBits(num);
    std::cout << "test count bits result: ";
    for (int i=0; i<result.size(); i++) std::cout << result[i] << " ";
    std::cout << std::endl;
}

/**
 * 15. 字符串解码. 两种方法：栈方法或dfs
 * １．栈方法需要分别记录重复次数，和字符子串．注意记录的重复子串为上一层的结果，而不是当前重复子串的内容．注意num可能大于10
 * 2. dfs(s, index), 如果遇到s[ｉndex]=='['，则dfs(s, ++index). 并且res+= tmp_dfs_result * num. 注意num要重置０
*/
void test_decode_string() {
    std::string s = "3[a]2[bc]";; //"100[leetcode]"; //"3[a]2[bc]";
    // std::string result = hot_100::decodeString(s);
    std::string result = hot_100::decodeString_V2(s);
    std::cout << "test decode string result: " << result << std::endl;
}

/**
 * 16. 分割等和子集．　dfs．或０，１背包问题.
 * 1. dfs定义如下bool dfs(nums, index, target); 如果nums[idx]==target, return ture
 * 如果nums[idx] <target, return dfs(nums, index+1,target-nums[idx]) || dfs(nums, index+1, target)
 * 表示第ｉndex下标的数字取或不取．
 * ２．dp求解．dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i]]　表示第ｉ个数取或不取．
 * 注意是dp[i-1][j-nums[i]] 而不是　dp[i][j-nums[i]]，　dp[i][0]=true,表示前ｉ个数，达到０是否可行．
 * 3.由于dp[i][j]只与前一行dp[i-1]结果有关，可以直接定义dp[j]交替使用．此时遍历应该从j=target->0,
 * 这样可避免dp[j]=dp[j]||dp[j-nums[idx]]时，dp[j-nums[idx]]始终表示上一层的结果而不是统一层的结果．
*/
void test_can_partition() {
    std::vector<int> nums = {1,2,5}; //{1,5,11,5};
    // bool result = hot_100::canPartition(nums);
    // bool result = hot_100::canPartition_V2(nums);
    bool result = hot_100::canPartition_V3(nums);
    std::cout << "test can partition result: " << std::boolalpha << result << std::endl;
}

/**
 * 17 任务调度器
*/
void test_leastInterval() {
    std::vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n =2;
    int result = hot_100::leastInterval(tasks, n);
    std::cout << "test least interval result: " << result << std::endl;
}

/**
 * 18. 得到回文子串
*/
void test_count_substring () {
    std::string s = "aaa";
    int result = hot_100::countSubstrings(s);
    std::cout << "test count substring result: " << result << std::endl;
}

/**
 * 19. 最长递增序列
*/
void test_longest_increasing_path() {
    std::vector<std::vector<int>> matrix = {{9,9,4}, {6,6,8}, {2,1,1}};
    int result = thot_50::longestIncreasingPath(matrix);
    std::cout << "test longest increasing path result: " << result << std::endl;
}

/**
 * 20. 整数反转
*/
void test_reverse_thot50() {
    int n = 123;
    int result = thot_50::reverse(n);
    std::cout << "test reverse result: " << result << std::endl;
}

/**
 * 21. 全排列
*/
void test_permute_thot50() {
    std::vector<int> nums = {1,2,3};
    // std::vector<std::vector<int>> result = thot_50::permute(nums);
    std::vector<std::vector<int>> result = thot_50::permute_v2(nums);
    std::cout << "test permute thot50 result:\n";
    for (int i=0; i<result.size(); i++) {
        for (int j=0;j<result[i].size(); j++) std::cout << result[i][j] << " ";
        std::cout << std::endl;
    }
}

/**
 * 22. 求子集. dfs求解．一定要主要递归的下标为i+1, 而不是index+1, 然后push back的数组也不是nums[index],
 * 而是nums[i]
*/
void test_subset_thot50() {
    std::vector<int> nums = {1,2,3};
    // std::vector<std::vector<int>> result = thot_50::subsets(nums);
    std::vector<std::vector<int>> result = thot_50::subsets_v2(nums);
    std::cout << "test subsets result:\n";
    for (int i=0; i<result.size(); i++) {
        for (int j=0; j<result[i].size(); j++) std::cout << result[i][j] << " ";
        std::cout << std::endl;
    }
}

void test_generate_parenthesis_thot50() {
    int n = 3;
    std::vector<std::string> result = thot_50::legal_partness(n);
    std::cout << "test generate parenthesis result:\n";
    for (int i=0; i<result.size(); i++) std::cout << result[i] << std::endl;
}

/**
 * 23. 高楼仍鸡蛋
 * 方法1. 设dp[i,j]表示共i个鸡蛋，j层楼需要仍的次数；则dp[i,j]=min(max(dp[i-1,j-1],dp[i,j-k])+1) for k in [1,j]
 * 其中dp[i-1,k-1]表示在第k层仍，蛋碎了; dp[i, j-k]表示蛋没碎，剩下j-k层楼；
 * 注意初始化dp[i,0]=0, for(i=1->K, j=1->N; k->1->j)dp[i,j]加一时要判断是否超过表示范围。
 * 方法2: 根据dp[i-1][k]单调不减，dp[i][j-k]单调不增，可用二分法求得最中间的left,right
 * 最后直接dp[i,j]=min(max(dp[i-1][left-1], dp[i][j-left]), max(dp[i-1][right-1], dp[i][j-right])) + 1;
 * 方法3:定义新的更新状态dp[i,j]表示i个鸡蛋，仍j次，最多可用确定多高的楼层，则当dp[K,j]==N时，j即为结果
 * dp[i,j] = dp[i][m-1] + dp[i-1][m-1] + 1
 * 详见分析： https://leetcode-cn.com/problems/super-egg-drop/solution/ji-ben-dong-tai-gui-hua-jie-fa-by-labuladong/
*/
void test_superEggDrop() {
    int K = 2;
    int N = 6;
    int result = thot_50::superEggDrop_v3(K, N);
    std::cout << "test superEggDrop result: " << result << std::endl;
}


int main() {
    // ***************************** hot 100 *************************************
    // test_findkthlargest_hot_100();
    // test_max_sliding_window_hot_100();
    // test_searchMatrix_hot_100();
    // test_numsquare_hot_100();
    // test_lengthofLIS_hot_100();
    test_reconstruct_queue_hot_100();
    // test_pathsum_hot_100();
    // test_find_disappearedNumbers_hot_100();
    // test_daily_temperatures_hot_100();
    // test_max_profit_hot_100();
    // test_max_coins_hot_100();
    // test_find_unsorted_sub_array_hot_100();
    // test_rob();
    // test_count_bits();
    // test_decode_string();
    // test_can_partition();
    // test_leastInterval();
    // test_count_substring();

    // ******************************** thot 50 *************************************
    // test_longest_increasing_path();
    // test_reverse_thot50();
    // test_permute_thot50();
    // test_subset_thot50();
    // test_generate_parenthesis_thot50();
    // test_superEggDrop();

    return 0;
}
