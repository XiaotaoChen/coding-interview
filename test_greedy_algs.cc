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
#include "greedy_algs.h"

using namespace std;


/*
46. 田忌赛马 参考：https://leetcode.cn/problems/advantage-shuffle/solution/you-shi-xi-pai-by-leetcode-solution-sqsf/
1.对A，B进行排序。2.注意B中可能存在重复的元素。
if A[j]> B[i]:match_map[B[i]].push(A[j]);
else: unmatch.push(A[j]);
*/
void test_advantage_count() {
    std::vector<int> A = {2,0,4,1,2}; // {12,24,8,32}; //{2,7,11,15};
    std::vector<int> B = {1,3,0,0,2}; // {13,25,32,11}; // {1,10,4,11};
    std::vector<int> result = greedy::advantageCount(A, B);
    for (int i=0;i<result.size(); i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

/*
47. 判断是否可以跳到终点
记录当前可到达的最远点k=max(k, nums[i]+i)
*/
void test_can_jump() {
    std::vector<int> data = {3,2,1,0,4}; //{2,3,1,1,4};
    // bool result = greedy::canJump(data);
    // printf("result:%d\n", result);
    int result = greedy::jump(data);
    printf("result:%d\n", result);
}

/*
48. 判断能否环绕一圈
同11
*/
void test_can_complete_circuit() {
    std::vector<int> gas = {1,2,3,4,5}; // {2,3,4}; //{1,2,3,4,5};
    std::vector<int> costs = {3,4,5,1,2}; // {3,4,3}; // {3,4,5,1,2};
    // int result = greedy::canCompleteCircuit(gas, costs);
    int result = greedy::canCompleteCircuit_v2(gas, costs);
    printf("results:%d\n", result);
}

/*
49. 正则表达式，类似31
注意初始化匹配0个元素的情况
*/
void test_match_str() {
    std::string s = "aa"; // "adceb";
    std::string p = "*ab"; // "*a*b";
    bool result = greedy::isMatch(s, p);
    printf("result:%d\n", result);
}

/*
50. 删除冗余字符，并使得保留的字符字典序最小
遍历字符串，查询i以后的字符中是否存在该字符
while (result.back()>s[i] && s.find(result.back(), i)!=string::npos) result.pop_back()
*/
void test_remove_duplicate_letters() {
    std::string s = "cbacdcbc"; // "bcabc";
    std:string result = greedy::removeDuplicateLetters(s);
    printf("result:%s\n", result.c_str());
}


int main() {
    test_advantage_count();
    // test_can_jump();
    // test_can_complete_circuit();
    // test_match_str();
    // test_remove_duplicate_letters();
    return 0;
}
