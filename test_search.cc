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
#include "search_algs.h"

using namespace std;


/*
17. 去掉空格，标点符号，屏蔽大小写差异，判断是否为回文串。
（1）遍历字符串去掉空格，标点符号；interview 48 最长不重复的子字符串
（2）转成小写字符，std::transform(begin(), end(), ::tolower);
（3）判断是否为回文串，即str==std::string(str.rbegin(), str.rend())
*/
void test_is_palindrome() {
    std::string s = "A man, a plan, a canal: Panama";
    bool result = search::isPalindrome(s);
    printf("result:%d\n", result);
}

/*
18. 求二叉树最大的路径之和。dfs
当前节点的最大路径之和=val + left_node_result + right_node_result;
return val + max(left_node_result, right_node_result);
再刷感想：1.dfs过程中要计算两个值：１．包含当前节点的单边path的最大值，２．包含当前节点的最大路径之和．
２．因为是可以选择任意节点，所以只有在路径大于零时才将该路径并入，单边path,最大路径和都需要比较左右子树的路径大小是否＞０
*/
void test_maxPathSum() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    int result = search::binary_tree::maxPathSum(root);
    // int result = search::binary_tree::maxPathSum_V2(root);
    printf("result:%d\n", result);
}

/*
19. 买卖两次股票，收益最大能到多少。
使用buy1, sell1,buy2,sell2模拟两次交易的内容。
buy1=max(buy1, -prices[i]); 买入股票需要掏出的钱，越少越好
sell1=max(sell1, buy1+prices[i]); 卖出股票，剩余的钱越多越好;
buy2=max(buy2, sell1-prices[i]); 第二次买入股票
sell2=max(sell2, buy2+prices[i])
*/
void test_maxprofix() {
    int arr[] = {3,2,1,3,4,5,4,6,1,7};
    std::vector<int> vec(arr, arr+10);
    // int result = search::maxProfit_v3(vec);
    int result = search::max_profit_2(vec);
    printf("result:%d\n", result);
}

/*
22. 给二叉树兄弟节点加上next指针。
通过queue依次得到每一层的所有节点，然后将依次设置节点的next指针。
*/
void test_populating_next_right_pointer() {
    TreeLinkNode* root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    // root->left->left = new TreeLinkNode(4);
    root->left->right = new TreeLinkNode(5);
    // root->right->left = new TreeLinkNode(6);
    // root->right->right = new TreeLinkNode(7);
    search::populating_next_right_pointers_in_each_node(root);

    TreeLinkNode* curr_left=root;
    while(curr_left != nullptr) {
        TreeLinkNode* curr = curr_left;
        while(curr != nullptr) {
            printf("%d ", curr->val);
            curr = curr->next;
        }
        printf("\n");
        curr_left = curr_left->left;
    }

    // delete root->right->right;
    // delete root->right->left;
    // delete root->left->right;
    // delete root->left->left;
    // delete root->left;
    // delete root->right;
    // delete root;
}

/*
24. 遍历二叉树的路径，判断是否存在和为sum的路径，并返回所有可能的路径结果
回溯法。bfs(combinations, curr, res, root)
将val push curr
如果res==root->val && root->left==null && root->right==null 则将curr push到结果中；
bfs(combinations, curr, res, root->left)
bfs(combinations, curr, res, root->right)
*/
void test_haspathsum() {
    TreeNode* root = new TreeNode(-2);
    root->left = new TreeNode(-3);
    // root->right = new TreeNode(1);
    // root->left->right = new TreeNode(11);
    // root->right->left = new TreeNode(13);
    // root->right->right = new TreeNode(4);
    int sum = -5;
    bool result = search::hasPathSum(root, sum);
    printf("result:%d\n", result);
    std::vector<std::vector<int>> results = search::pathSum(root, sum);
    // std::vector<std::vector<int>> results = search::pathSum_bfs(root, sum);
    for (int i=0; i< results.size(); i++) {
        for(int j=0; j<results[i].size(); j++) {
            printf("%d ", results[i][j]);
        }
        printf("\n");
    }
}

/*
26. 两个链表数字相加。
1.将两个链表对应位分别相加，合成一个链表后再转成正常数字。注意最后一位是否进位的问题。
2.将两个链表对应位相加，使用carry位保留前一位的进位，在相加过程中完成进位。
*/
void test_add_two_numbers() {
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(8);
    // l1->next->next = new ListNode(3);
    ListNode *l2 = new ListNode(1);
    // l2->next = new ListNode(6);
    // l2->next->next = new ListNode(4);
    ListNode *result = search::addTwoNumbers_v2(l1, l2);
    while(result != nullptr) {
        printf("%d ", result->val);
        result = result->next;
    }
}

/*
27. 从两个有序数组中找出中位数。
1. 先对两个数组merge，然后直接找出中位数。
2. 二分查找。每次查找两个数组中的k/2个，直接舍弃较小的那一部分。
dfs(nums1, low1, nums2, low2, k);
注意k==1，low1,low2是否在nums1,nums2之内。
if (low1+k/2-1<nums1.size())mid1=nums1[low1+k/2-1];
if (low2+k/2-1<nums2.size()) mid2 = nums2[low2+k/2-1];
if (mid1<mid2) dfs(nums1, low1+k/2, nums2, low2, k-k/2);
else dfs(nums1, low1, nums2, low2+k/2, k-k/2);
*/
void test_find_mid_num() {
    std::vector<int> a={1, 3};
    std::vector<int> b={2};
    // double result = search::findMedianSortedArrays(a, b);
    double result = search::findMedianSortedArrays_v2(a, b); 
    printf("result:%f \n", result);
}

/*
28. 求字符串中最长的回文子串。
dp[][] 记录i->j是否为回文串
dp[i][j]与 dp[i+1][j-1]的关系，注意考虑a|a,aba两者情况
*/
void test_length_palindrome() {
    std::string str = "abaabca"; //"abcdasdfghjkldcba";
    std::string result = search::longestPalindrome(str);
    // std::string result = dp::longestPalindrome_v2(str);
    // std::string result = dp::longestPalindrome_v3(str);
    // std::string result = dp::longestPalindrome_v4(str);
    // std::string result = dp::longestPalindrome_v5(str);
    printf("result: %s\n", result.c_str());
}

/*
29. 字符按照N字形排列，按行输出最后的顺序。
推导出N字排列的规律。一个周期为2*rows-2,
钱rows个为列，后面row-2个斜向上递增。
*/
void test_z_convert() {
    std::string str = "LEETCODEISHIRING";
    int rows = 4;
    std::string result = search::z_convert(str, rows);
    printf("result:%s\n", result.c_str());
}

/*
30. 数字转换
1. 特殊处理第一个字符，判断是否存在正负号
2. 使用double保存中间结果避免int溢出，然后对int32_max,int32_min进行判断
*/
void test_my_atoi() {
    std::string str= "-2147483647";
    int result = search::myAtoi(str);
    printf("result:%d\n", result);
}

/*
32. 最大的矩形面积
1.维护一个升序的栈，纪录对于数字的index，当当前数值>stack.top()时，直接push
2.当小于时，记录以当前栈顶元素为高，i-当前栈顶元素前一个元素的idx
3.最后依次pop stack中的元素，(len-i)* high
再刷心得：维护一个升序栈，当前元素小于栈顶元素时，一直pop,并计算area,而不是只pop 一次栈顶元素．
*/
void test_largest_rectangle_area() {
    std::vector<int> arr = {2,1,5,6,2,3}; //{4, 1000, 1000, 1000, 1000};  // {7, 2, 1, 4, 5, 1, 3, 3}; // {3, 1, 6, 5, 2, 3}; // {2,1,5,6,2,3};
    // int result = search::largestRectangleArea(arr);
    int result = search::largestRectangleAreaV2(arr);
    // int result = stack_algs::largestRectangleArea(arr);
    printf("result:%d\n", result);
}

/*
34. 求水箱的最大容量
从两边往中间依次遍历即可。
*/
void test_max_area_in_water_tank() {
    std::vector<int> arr= {1,8,6,2,5,4,8,3,7}; //{1,2,4,3}; // {1,2}; // {1,8,6,2,5,4,8,3,7};
    // int result = search::maxArea(arr);
    // int result = search::maxArea_v2(arr);
    int result = search::maxArea_v3(arr);
    printf("result:%d\n", result);
}

/*
35. 转换成罗马数字
建立一个<int, string>的map，
列举所有可能的值：1，4，5，9.... 对应的string "I", "IV"
降序排列。
*/
void test_int_to_map() {
    // std::string result = search::intToRoman_v2(1994);
    std::string result = search::intToRoman_v3(1994);
    
    printf("result:%s\n", result.c_str());
}

/*
36. 判断一棵数是不是另一棵树的子树
需要额外判断子树是否相等。因为是否是子树必须是两者相等。
if （root->val!=sub->val） 
(issame(root->left, sub->left)&& issame(root->right, sub->right)||
isSub(root->left, sub)||isSub(root->right, sub)
else:
isSub(root->left, sub)||isSub(root->right, sub)
)
*/
void test_is_subtree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->right->left = new TreeNode(2);
    // root->left->left = new TreeNode(0);
    TreeNode* sub = new TreeNode(3);
    sub->left = new TreeNode(1);
    sub->right = new TreeNode(2);
    bool result = search::isSubtree(root, sub);
    printf("result:%d\n", result);
}

/*
37. 找到两个节点最近的公共祖先
递归判断一棵树中是否存在p或q节点
left = dfs(root->left, p,q)
right = dfs(root->right, p,q);
if (left==null&& right==null) return null
if(left!=null && right!=null) return root //左右节点均存在p或q
if (left!=null && right==null) return left // 只有left存在p或q
if (left==null && right!=null) return right
*/
void test_is_lowest_ancestor() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    TreeNode* p = root->left;
    TreeNode* q = root->left->right->right;
    TreeNode* result = search::lowestCommonAncestor2(root, p, q);
    printf("result:%lf\n", result->val);
}

/*
38. 找到树中所有可能到sum，并返回出现次数最多的元素
*/
void test_requent_tree_sum() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-5);
    // root->left->left = new TreeNode(6);
    // root->left->right = new TreeNode(2);
    // root->left->right->left = new TreeNode(7);
    // root->left->right->right = new TreeNode(4);
    // root->right->left = new TreeNode(0);
    // root->right->right = new TreeNode(8);
    std::vector<int> result = search::findFrequentTreeSum(root);
    for (int i=0; i<result.size(); i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

/*
39. 简化路径
1. 以‘/’划分字符子串得到items。
2. 遍历items，依次将item压入栈中，当出现'..'时pop；
3. 依次弹出item，result = '/' + item + result;
再刷感想：注意分词时别漏了最后一个词．
*/
void test_simple_path() {
    std::string path = "/a//b////c/d//././/.."; //"/a/../../b/../c//.//"; // "/a/./b/../../c/"; // "/home//foo/"; // "/../"; // "/home/";
    // std::string result = search::simplifyPath(path);
    std::string result = search::simplifyPath_V2(path);
    printf("result:%s\n", result.c_str());
}

/*
40. 反转链表m,n之间的元素
1. 记录m的前一个元素和m元素的指针。然后从m+1个元素开始，
node(m+1)->next=node(m-1)->next;
node(m-1)->next = node(m+1);
2. 在n的时候，node(m)->next=node(n)->next;
*/
void test_reverse_between() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    // ListNode* result = search::reverseBetween(head, 4, 5);
    ListNode* result2 = search::reverseBetweenV2(head, 0, 4);
    // printf("result:");
    // while(result!=nullptr) {
    //     printf("%d ", result->val);
    //     result = result->next;
    // }
    // printf("\n");

    printf("result2:");
    while(result2!=nullptr) {
        printf("%d ", result2->val);
        result2 = result2->next;
    }
    printf("\n");
}

/*
41. 判断4个数是否可以求得24点
1. 递归求解，先从4个数中选取两个数进行一直运算得到结果，
然后从3个数中选两个得到结果，最终只剩一个数时，判断是否等于24
*/
void test_juge_point24() {
    // std::vector<int> nums = {1, 2, 1, 2}; // {4, 1, 8, 7};
    // bool result = search::judgePoint24(nums);
    std::vector<double> nums = {4, 1, 8, 7};
    // char op_types[5] = {'*', '+', '/', '-'};
    // bool result = search::judgePoint24_v2(nums, op_types);
    // printf("result:%d\n", result);
    char op_types[5] = {'+', '-', '*', '/'};
    std::string str = "";
    bool result = search::judgePoint24_v3(nums, op_types, str);
    printf("result:%d, str: %s\n", result, str.c_str());
}

/*
42. 矩阵旋转遍历
模拟旋转遍历，注意i,j是否越界
*/
void test_spiral_order() {
    std::vector<std::vector<int>> matrix = {{1,2}, {3,4}, {5,6}}; // {{1,2,3}, {4,5,6}}; // {{1,2,3}, {4,5,6}, {7,8,9}}; // {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}}; // {{1,2,3}, {4,5,6}, {7,8,9}};
    // std::vector<int> result = search::spiralOrder(matrix);
    std::vector<int> result = search::spiralOrderV2(matrix);
    for (int i=0; i<result.size(); i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

/*
43. 生成旋转矩阵
与42类似
*/
void test_generate_matrix(){
    std::vector<std::vector<int>> result = search::generateMatrix(3);
    for (int i=0; i< result.size(); i++) {
        for (int j=0; j<result[0].size(); j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

/*
43. 找出递增数组中val与idx一致的数。
递增数组中val与idx一致的数只可能出现连续的一次。不可能出现多次。
mid = (left+right)/2
// 左边不可能存在符合条件的数
if num[mid]<mid: dfs(mid+1, right)
else dfs(left, mid-1)
*/
void test_match_idx_val() {
    std::vector<int> data = {-5,1,2,3,6};
    std::vector<int> result;
    search::match_idx_val(data, result, 0, 4);
    for (int i=0; i<result.size(); i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    result.clear();
    search::match_idx_val_v2(data, result, 0, 4);
    for (int i=0; i<result.size(); i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

/*
45. 三数之和
先对数组排序，设置first，second,thrid指针，不能指向重复的元素
for (int i=0; i<n-2; i++) {
    secod=i+1;
    third = n-1;
    if (nums[first]+nums[secod]==target-nums[third])....
}
注意：1. 不指向重复元素时，　要判断second 始终小于third. 同时该操作只需要在
nums[first]+nums[second] == target - nums[third]时做，而不需要在外面也判断，
因为second+, third--即可达到同样目的．
*/
void test_three_sum() {
    std::vector<int> data = {-1, 0, 1, 2, -1, -4}; //{-2,0,0,2,2}; //{-1, 0, 1, 2, -1, -4};
    // std::vector<std::vector<int>> result = search::threeSum(data);
    // std::vector<std::vector<int>> result = search::threeSum_v2(data);
    std::vector<std::vector<int>> result = search::threeSum_v3(data);
    for (int i=0; i<result.size(); i++) {
        for (int j=0; j<result[i].size(); j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

/**
 * 116. 在不开辟新空间情况下将数组旋转90度. 
 * 主要推导出四个点的相对位置．(i, j) --> (j, n-i-1) --> (n-i-1, n-j-1) --> (n-j-1, i)
 * 便于推导：(1)第ｉ行j列的数，旋转的位置的列数为n-i-1, 行数为j; (2) 第三个点关于第一个点中心对称，即（n-i-1, n-j-1）; (3)第四个点关于第二个点中心对称．
 * 注意若行数为单数，最后一个环只有１个元素，不需要转换
 * 再刷，注意ｉ点：1.注意两层for循环的起始，结束位置．　外层循环应该以环数为主，即0->n/2; 内层循环下标从ｉ－＞n-i-1
*/
void test_rotate_matrix() {
    std::vector<std::vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};; //{{1,2,3}, {4,5,6}, {7,8,9}};
    // search::rotate(matrix);
    // search::rotate_v2(matrix);
    search::rotate_v3(matrix);
    for (int i=0; i<matrix.size(); i++) {
        for (int j=0; j<matrix[i].size(); j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/**
 * 117. 划分字母相同，排列不同的字符串, 1. 对每个单词都sort, 如果sort后的词相同，则相同；
 * 2. 用map<char, int>　记录一个单词的信息，　map<map<char, int>, vector<string>> 作为map. 
 * 这里不能用unordered_map, 只能用map. 因为unordered_map内部实现是std::hash,而pair或unorodered_map<char, int>等这种双值的类型c++ library中没有对应的hash functor, 故报错．
 * 而std::map的内部实现是红黑树，对key的类型没有要求，故这里使用std::map. map内部本身有序，适合对顺序有要求的场景，而unordered_map适合于查找．
*/
void test_groupAnagrams() {
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    // std::vector<std::vector<std::string>> result = search::groupAnagrams(strs);
    // std::vector<std::vector<std::string>> result = search::groupAnagrams_v2(strs);
    std::vector<std::vector<std::string>> result = search::groupAnagrams_v3(strs);
    for (int i=0; i<result.size(); i++) {
        for (int j=0; j<result[i].size(); j++) {
            printf("%s ", result[i][j].c_str());
        }
        printf("\n");
    }
}

/**
 * 187. 求最大股票收益. 记录历史收益pre, 如果pre>=0, 则累加prices[i]-prices[i-1]
 * 否则，　pre=prices[i]-prices[i-1]
*/
void test_max_profit() {
    std::vector<int> arr = {7,1,5,3,6,4};
    // int result = search::maxProfit_v4(arr);
    int result = search::maxProfit_v5(arr);
    std::cout << "test max profit result:" << result << std::endl;
}

int main() {
    // test_is_palindrome();
    // test_maxPathSum();
    // test_maxprofix();
    // test_populating_next_right_pointer();
    // test_haspathsum();
    // test_add_two_numbers();
    // test_find_mid_num();
    // test_length_palindrome();
    // test_z_convert();
    // test_my_atoi();
    // test_largest_rectangle_area();
    // test_max_area_in_water_tank();
    // test_int_to_map();
    // test_is_subtree();
    // test_is_lowest_ancestor();
    // test_requent_tree_sum();
    // test_simple_path();
    // test_reverse_between();
    // test_juge_point24();
    // test_spiral_order();
    // test_generate_matrix();
    // test_match_idx_val();
    // test_three_sum();
    // test_rotate_matrix();
    // test_groupAnagrams();
    test_max_profit();
    return 0;
}
