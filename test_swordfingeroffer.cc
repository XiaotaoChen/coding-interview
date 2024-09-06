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
#include "swordfingeroffer.h"

using namespace std;


/**
 * 120. 打印１->ｎ位最大数
*/

void test_print1ToNdigits() {
    // sword_finger_offer::print1ToMaxNDigits(1);
    sword_finger_offer::print1ToMaxNDigits_v2(2);
}

/**
 * 121. 删除链表中重复节点
*/
void test_deleteduplictednode() {
    ListNode* root = new ListNode(1);
    root->next = new ListNode(1);
    root->next->next = new ListNode(2);
    root->next->next->next = new ListNode(3);
    root->next->next->next->next = new ListNode(3);
    // ListNode* root = nullptr;
    sword_finger_offer::deleteDuplicatedNode(&root);
    ListNode* curr = root;
    while (curr != nullptr)
    {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

/**
 * 122. 正则表达式，类似与４９，３１，　递归实现．
*/
void test_regular_match_v2() {
    std::string str = "aaa";
    std::string pattern = "ab*ac*a*";
    bool result = sword_finger_offer::regular_pattern(str, pattern);
    std::cout << "result: " << std::boolalpha << result << std::endl;
}

/**
 * 123. 判断字符是否为有效数字．将有效数字拆分成A[.B][e|EC], .B[e|EC]的形式, 其中A, C为整数，　Ｂ为正整数. 
 * 1. 注意判断当前字符串为整数应该是s[i]=='.'||s[i]=='e'||s[i]==='E' 且i>0
 * 2. A/B二者存在其中一个就行．即判断条件为scanUnsignedInteger(s, index) || isnumeric,　且必须scanUnsignedInteger放前面，否则isnumeric为true,则不只是scanunsiged函数
*/
void test_isNumeric() {
    std::vector<std::string> cases = {"e+5", "+100", "-1e-12", "3.146", "12e+5.4", "12.e5", ".1e-5"};
    for (auto& str: cases) {
        bool result = sword_finger_offer::isNumeric(str);
        std::cout << "result of: " << str << " is " << std::boolalpha << result << std::endl;
    }
}

/**
 * 124. 抽象判断条件，划分数组，设置奇偶数
*/
void test_reordervec() {
    std::vector<int> vec{5,4,1,2,3,4};
    auto isodd = [](int val)->bool {return (val & 0x1) == 1;};
    sword_finger_offer::reorderVec(vec, isodd);
    for (int i=0; i<vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * 125. 判断链表中是否存在环
*/
void test_detect_cycle(){
    ListNode* root = new ListNode(1);
    ListNode* tmp = root;
    tmp->next = new ListNode(2);
    tmp = tmp->next;
    tmp->next = new ListNode(3);
    tmp = tmp->next;
    tmp->next = new ListNode(4);
    tmp = tmp->next;
    tmp->next = new ListNode(5);
    tmp = tmp->next;
    tmp->next = root->next;
    ListNode* src = root;
    ListNode* result = sword_finger_offer::detectCycle(root);
    if (result != nullptr)
        std::cout << "ring begining value: " << result->val << std::endl;
    else
        std::cout << "the listnode has no ring\n";
}

/**
 * 126. 反转链表，　额外添加一个头指针，可去除判断头指针特殊情况．注意删除额外的头指针
*/
void test_reverse_list() {
    ListNode* root = new ListNode(1);
    ListNode* tmp = root;
    tmp->next = new ListNode(2);
    tmp = tmp->next;
    tmp->next = new ListNode(3);
    tmp = tmp->next;
    tmp->next = new ListNode(4);
    tmp = tmp->next;
    tmp->next = new ListNode(5);

    ListNode* head = sword_finger_offer::reverseList(root);

    std::cout << "reversed list: " ;
    while(head !=nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

/**
 * 127. 合并两个排序链表. 使用dfs方法实现:输入为两个头节点，　返回值为合并链表的头节点．
 * 根据root1,root2的ｖal大小，确定当前head=root1 或root2, head->next = merge(root1->next, root2) 或merge(root1, root2->next);
*/
void test_merge_two_list() {
    ListNode* root1 = new ListNode(1);
    ListNode* tmp = root1;
    tmp->next = new ListNode(2);
    tmp = tmp->next;
    tmp->next = new ListNode(3);

    ListNode* root2 = new ListNode(4);
    tmp = root2;
    // tmp->next = new ListNode(5);
    // tmp = tmp->next;
    // tmp->next = new ListNode(6);


    // ListNode* mergeList = sword_finger_offer::mergetwoList(root1, root2);
    ListNode* mergeList = sword_finger_offer::mergetwoList_v2(root1, root2);

    std::cout << "the two merged list: ";
    while(mergeList != nullptr) {
        std::cout << mergeList->val << " ";
        mergeList = mergeList->next;
    }
    std::cout << std::endl;
}

/**
 * 128. 判断是否为子树
*/
void test_issubtree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->right->left = new TreeNode(2);
    // root->left->left = new TreeNode(0);
    TreeNode* sub = new TreeNode(3);
    // sub->left = new TreeNode(4);
    sub->right = new TreeNode(5);
    bool result = sword_finger_offer::issubtree(root, sub);
    std::cout << "is sub tree: " << std::boolalpha << result << std::endl;
}

/**
 * 129. 判断二叉树是否对称，　即判断二叉树的左子树是否等于右子树．　为了使得左子树与对应右子树匹配．定义输入为两颗二叉树的对比函数，比较二叉树与其自身是否对称．
*/
void test_issymmetrical() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(2);
    // root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(1);
    bool result = sword_finger_offer::isSymmetrical(root);
    std::cout << "is symmetrical tree: " << std::boolalpha << result << std::endl;
}

/**
 * 130. 顺时针打印矩阵，　同42
*/
void test_clockwise_print() {
    std::vector<std::vector<int>> matrix = {{1,2,3}, {5,6,7}, {9,10,11}, {13,14,15}}; // {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}}; // {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}}; // {{1,2,3}, {4,5,6}, {7,8,9}};
    sword_finger_offer::clockwise_print(matrix);

}

/**
 * 131. 包含min函数的栈
*/
void test_min_stack() {
    sword_finger_offer::minStack<int> s;
    int result=-1;
    s.push(5);
    s.push(2);
    bool flag = s.min(result);
    if (flag) std::cout << "min stack is: " << result << std::endl;
    s.pop();

    flag = s.min(result);
    if (flag) std::cout << "min stack is: " << result << std::endl;
    
    s.push(3);
    s.push(1);

    flag = s.min(result);
    if (flag) std::cout << "min stack is: " << result << std::endl;
}


/**
 * 132. 判断入栈，出栈顺序是否合法
*/
void test_is_correct_for_stack() {
    std::vector<int> instack = {1,2,3,4,5};
    std::vector<int> outstack = {4,3,5,1,2}; //{4,3,5,2,1}; //{4,3,5,1,2}; //{4,5,3,2,1};
    bool result = sword_finger_offer::is_correct_for_stack(instack, outstack);
    std::cout << "is correct for stack: "<< std::boolalpha << result << std::endl;
}

/**
 * 133. z字打印二叉树, 同66
 * 方法２使用两个栈实现,左右子树的入栈顺序和奇偶行有关
*/
void test_z_print() {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(9);
    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(4);
    // sword_finger_offer::print_binary_tree_with_z(root);
    sword_finger_offer::print_binary_tree_with_z_v2(root);
}

/**
 * 测试vector按照下标赋值，再使用begin, size等函数会有问题．插入数据应该用pushback
*/
void test_reversetest_reverse() {
    std::vector<int> tmp1;
    std::vector<int> tmp2;
    tmp1.reserve(2);
    // tmp1[0] = 1;
    // tmp1[1] = 2;
    tmp1.push_back(1);
    tmp1.push_back(2);

    std::cout << "tmp1 size: " << tmp1.size() << " cap: " << tmp1.capacity() << std::endl;
    for (int i=0; i<tmp1.size(); i++) std::cout << tmp1[i] << " ";
    std::cout << std::endl;
    std::cout << "tmp1 reverse\n";
    // std::reverse(tmp1.begin(), tmp1.end());
    // for (int i=0; i<2; i++) std::cout << tmp1[i] << " ";
    for (auto iter=tmp1.rbegin(); iter!=tmp1.rend(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

}

/**
 * 134. 判断序列是否为二叉平衡树的后续排列
*/
void test_check_bst_order() {
    std::vector<int> vec = {7,4,6,5}; //{5,7,6,9,11,10,8};
    bool result = sword_finger_offer::check_binary_search_tree_order(vec);
    std::cout << "check bst order: " << std::boolalpha << result << std::endl;
}

/**
 * 135. 打印二叉树中和为某值的路径
*/
void test_sum_path(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    // std::vector<std::vector<int>> result = sword_finger_offer::sum_path(root, 8);
    // for (int i=0; i<result.size(); i++) {
    //     for (int j=0; j<result[i].size(); j++) {
    //         std::cout << result[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    sword_finger_offer::sum_path_v2(root, 3);
}

/**
 * 136. 将二叉树转换成双向链表, 其思路是dfs, 输入为当前节点root,和root节点之前最后一个节点的指针地址，即遍历root->left, root->left=*last; *last->right=root, 遍历root->right.
 * 注意更新last node的内容时，　不能写成last=*root, 应该写成*last=root, 保证last地址不变．其last地址不能由函数返回，　因为函数中首先有使用last, 再更新last.
 * 
*/
void test_bst2list() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    TreeNode* last = nullptr;
    sword_finger_offer::bst2list(root, &last);
    TreeNode* head = sword_finger_offer::get_list_head(last);
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->right;
    }
    std::cout << std::endl;
}

/**
 * 137. 序列化，反序列化二叉树, 注意反序列化的时候string的index要在最开始++
*/
void test_serialize_deserialize() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(9);
    std::string oss = sword_finger_offer::serialize(root);
    TreeNode* head = sword_finger_offer::deserialize(oss);

    std::cout << "serialized: " << oss << std::endl;

    sword_finger_offer::print_bst(head);

    char* fileName = "test.txt";
    ofstream fileOut;
    fileOut.open(fileName);
    sword_finger_offer::serialize_ss(root, fileOut);
    fileOut.close();

    head = nullptr;
    ifstream fileIn;
    fileIn.open(fileName);
    sword_finger_offer::deserialize_ss(&head, fileIn);
    fileIn.close();

    std::cout << "iostream serialize, deserialize:\n";
    sword_finger_offer::print_bst(head);
}


/**
 * 138. 生成排列,组合．其中组合是将当前idx的字符push 进comb, 并且将历史的comb ＋　str[idx]添加进comb
 * 
*/
void test_permutation() {
    std::string str = "abc";
    // std::vector<std::string> result = sword_finger_offer::permutation(str);
    std::vector<std::string> result = sword_finger_offer::combinations(str);
    for (int i=0; i<result.size(); i++) {
        std::cout << result[i] << std::endl;
    }
}

/**
 * 139. ８皇后问题，　正方体８角和
*/
void test_queen_permute() {
    std::vector<std::vector<int>> result = sword_finger_offer::queen_permutation(8);
    std::cout << "eight queen size:" << result.size() << std::endl;
    for (int i=0; i<result.size(); i++) {
        for (int j=0; j<result[i].size(); j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * 140. 查找超过一半的数
*/
void test_morethanhalf() {
    std::vector<int> arr = {4,3,2,3};
    int result = sword_finger_offer::MoreThanHalf(arr);
    std::cout << "more than half result: " << result << std::endl;
}

/**
 * 141. 查找ｋ个最小数. 共四种方法：
 * 1. partition
 * 2. 手写最大堆，　注意初始化堆时，从length/2-1 --> 0,调整堆的顺序，后面依次从k->arr.length判断是否入堆
 * 3. 用make_heap, pop_heap, push_heap等
 * 4. 使用multiset<int, std::greater>, 直接维护最大堆
*/

void test_topKminus() {
    std::vector<int> arr = {3,4,2,5,1, 2};
    int k = 4;
    // std::vector<int> result = sword_finger_offer::TopKminus(arr, k);
    // std::vector<int> result = sword_finger_offer::TopKminus_with_heap(arr, k);
    // std::vector<int> result = sword_finger_offer::TopKminus_with_makeheap(arr, k);
    std::vector<int> result = sword_finger_offer::TopKminus_with_makeheapV2(arr, k);
    // std::vector<int> result = sword_finger_offer::TopKminus_with_set(arr, k);
    std::cout << "top " << k << " minus: ";
    for (int i=0; i<result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * 142. 流数据的中位数. 
 * １.使用partition方法，　分别找出median, median+1的数即可，但该方法要求读取数组所有数据．
 * ２．即时读取，维护最大最小堆．
 * ３．主要std::push_heap, std::multiset中设置最大堆，最小堆的方法．　multiset通过初始化设置，　默认最小堆，即std::less<T>，　最大堆std::greater<T>; 
 *        std::push_heap等，默认最大堆，　std::less<T>(). 
 * 即 std::push_heap默认最大堆，取反用std::greater<T>(), std::multiset默认最小堆，　取反用std::greater<T>
*/
void test_median_number() {
    std::vector<int> arr = {3,2,4,1,5,6};
    // int result = sword_finger_offer::median_number(arr);
    // int result = sword_finger_offer::median_number_with_set(arr);
    // float result = sword_finger_offer::median_number_V2(arr);
    // float result = sword_finger_offer::median_number_V3(arr);
    float result = sword_finger_offer::median_number_multiSet_V3(arr);

    std::cout << "result: " << result << std::endl;
}

void test_heap() {
    std::vector<int> arr;
    arr.push_back(1);
    std::push_heap(arr.begin(), arr.end());
    arr.push_back(2);
    std::push_heap(arr.begin(), arr.end(), std::greater<int>());



    std::multiset<int, std::greater<int>> set;
    set.insert(1);
    set.insert(2);
}

/**
 * 143. 连续子串最大和
*/
void test_continuoussum() {
    std::vector<int> arr = {-4,-3,-2,-6,-5};
    int result = sword_finger_offer::continuoussum(arr);
    std::cout << "result: " << result << std::endl;
}

/**
 * 144. 序列中１出现的次数. 递归思想．　如21345，　可拆成０->1345, 1346->21345两部分，　0->1345可递归求解．
 * 1346->21345中包含的１个数可分为：最高位的１出现的次数part1和其他位出现的次数part2．如果最高位是１，　则part1=int(str.substr(idx+1)) +1, 否则part1=10**(str.length-idx-1);
 * 其他位出现的次数part2=最高位的值＊len(str.length-idx-1)*10**(str.length-idx-2). 如21345的part2=2*4*1000.　
 * 2表示两万个数，后面４位，每一位都包含０－９的遍历．相当于0000->9999重复２遍，　当其中一位为１时，其他三位随意共有1000种可能．即part2 = 2 * 4 * 1000
*/
void test_one_counts() {
    int result = sword_finger_offer::one_counts(1345); // 5, 12, 10,  55, 99, 10000, 21345
    std::cout << "result: " << result << std::endl;
}

/**
 * 147. 序列中第index的数字. z主要分为3部分：
 * １. 求得对应位数数字一共的位数，如个位数，总共９位，　二位数：2*90, 3位数：3*900. 
 * 2. 得到开始的位数的起始点，如1，　１０，　１００
 * 3. 求得具体数字，第ｉ位的值
 * 注意：1中求对应位的数字个数要乘上n
 * 
*/
void test_number_of_digit() {
    int result = sword_finger_offer::numberofindex(190); // 10, 11, 13, 1000, 190
    std::cout << "number of digit: " << result << std::endl;
}

/**
 * 147. 生成最小数, 通过将arr中所有数字转换成string,避免大数问题，　同时转换成对string数组的排序问题，比较string a,b可定义成a+b , b+a的大小比较．升序排序即为最小组合数．
*/
void test_mincombination() {
    std::vector<int> arr = {3, 321, 32};
    std::string result = sword_finger_offer::mincombination(arr);
    std::cout << "mincombination result: " << result << std::endl;
}

/**
 * 148. 数字转字符的排列组合数. 简单dp问题, 如果str[i-1:i] <=25, 则dp[i]=dp[i-1]+dp[i-2],
 * 否则　dp[i]=dp[i-1]
 * 注意dp[0]应该初始化为１，而不是０，如12, dp[2]=dp[1]+dp[0], 如果dp[0]=0, 结果不对
*/
void test_number2ascii() {
    int number = 11258;
    int result = sword_finger_offer::number2ascii(number);
    std::cout << "number2ascii result: "<< result << std::endl;
}

/**
 * 149. 礼物最大价值, 简单dp[i,j]=max(dp[i-1, j], dp[i, j-1]) + val[i,j]. 其中dp数组可以只使用一行，重复利用
*/
void test_giftmaxval() {
    std::vector<std::vector<int>> arr = {{1, 10, 3, 8}, {12, 2, 9, 6}, {5, 7, 4, 11}, {3, 7, 16, 5}};
    int result = sword_finger_offer::giftmaxval(arr);
    std::cout << "git max val result: " << result << std::endl;
}

/**
 * 150 最长不重复子串长度. 两种方法：1. 滑窗
 * ２. dp方法，　使用position[26]记录历史字符最近出现的下标．　
 * 如果ｉ - position[str[i]-'a'] <= dp[i-1], dp[i]=i - position[str[i]-'a'], 
 * 否则 dp[i]=dp[i-1] + 1;
 * 因为只涉及到dp[i],dp[i-1], 可直接使用单个变量计算
 * 
*/
void test_longest_substr() {
    std::string str = "arabcacfr";
    // int result = sword_finger_offer::longest_substr(str);
    int result = sword_finger_offer::longest_substr_v2(str);
    std::cout << "longest substr result: " << result << std::endl;
}

/**
 * 151. 丑数
 * 记录x2, x3, x5的最小丑数，下一个丑数＝min(mult2*2, mult3*3, mult5*5)
 * 记录当前最小的丑数要注意是<=, 而不是<, 如while((*mult2)*2<=curr_num) mult2++;
*/
void test_ugly_number() {
    int result = sword_finger_offer::ugly_number(5); // 1,2,3,4,5
    std::cout << "ugly number result: "<< result << std::endl;
}

/**
 * 153. 第一次只出现一次的数.遍历一遍先求得各个字符出现的次数，然后再遍历原始数组，看map中map[ch]是否存在＝＝1. 
 * 注意第二次确定是否存在１的数，必须遍历原始数组，而不能依次遍历map, 因为map的顺序并不是按照原始数组的先后顺序排列．
 * 另一种方法是滑窗．当map[begin]>=2时　begin++, 一直map[ｉ]++, 则最后map[begin]的字符即为第一个字符．　注意当map[begin]>=2时，不能删除该元素，若删除，　当其出现次数＞２时，这会有问题．
 *
*/
void test_first_one_char() {
    std::string str = "dcbcdbc";
    // char ch = sword_finger_offer::first_one_char(str);
    // char ch = sword_finger_offer::first_one_char_v2(str);
    char ch = sword_finger_offer::first_one_char_v3(str);
    std::cout << "first one char result: " << ch << std::endl;
}

/**
 * 154.　逆序对
*/
void test_count_reverse_pair() {
    std::vector<int> arr = {4, 5, 6, 7};
    int result = sword_finger_offer::count_reverse_pair(arr);
    std::cout << "count reverse pair result: " << result << std::endl;
}

/**
 * 155. 求得两个链表的第一个公共节点
*/
void test_common_node() {
    ListNode* root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    ListNode* root2 = new ListNode(5);
    root2->next = new ListNode(6);
    // root2->next->next = root;
    ListNode* common_node = sword_finger_offer::first_common_node(root, root2);
    if (common_node != nullptr) {
        std::cout << "test common node result: " << common_node->val << std::endl;
    }
    else {
        std::cout << "test common node result: has no common node\n";
    }
}

/**
 * 156 求二叉树中任意两节点的最小公共父节点. dfs求解．　定义 dfs(root, node1, node2), 如果root等于node1或node2,　则返回root, 
 * 依次查找dfs(root->left, node1, node2), dfs(root->right, node1, node2)
 * 如果left存在node1或node2, 且right存在node1或node2,则当前root为parent node, 否则返回left或right
*/
void test_treenode_common_parent() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    TreeNode* parent = sword_finger_offer::lastest_common_parent(root, root->left, root->left->right);
    if (parent != nullptr) {
        std::cout << "test treenode common parent result: " << parent->val << std::endl;
    }
    else {
        std::cout << "test treenode common parent result: has no common node\n";
    }
}

/**
 * 157 排序数组中某个数字的个数. 使用partition方法先找出num数字在数组中第一个，最后一个数字的下标．
 * 注意要考虑num不在数组中的情况，不能直接left==right就返回left, 返回值应该在arr[mid]==num时，才返回．
*/
void test_sorted_arr_count() {
    std::vector<int> arr = {1,1,2,2,2,3,3,5};
    // int result = sword_finger_offer::sorted_arr_count(arr, 5);
    int result = sword_finger_offer::sorted_arr_count_v2(arr, 4);
    std::cout << "test sorted arr count result: " <<  result << std::endl;
}

/**
 * 158 从二叉树中找出第k大的节点. 先序遍历即可．同时记录k.要对k加引用，保证dfs深层修改的k值能被反映到上层中．
 * 因为dfs是自顶向下的，而遍历节点是自底向上的，故底层要反馈信息给上层，需要对k加引用．
*/
void test_kthnode() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    TreeNode* node = sword_finger_offer::kthNode(root, 8);
    if (node != nullptr) {
        std::cout << "test kthnode: " << node->val << std::endl;
    }
    else {
        std::cout << "test kthnode is nullptr\n";
    }
}

/**
 * 159 二叉树的深度
*/
void test_depthofBST() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(3);
    // int depth = sword_finger_offer::depthOfTreeNode(root);
    int depth = sword_finger_offer::depthOfTreeNode_v2(root);
    std::cout << "depth of bst: " << depth << std::endl;
}

/**
 * 160 判断是否为平衡二叉树. 递归判断．递归需要返回两个信息: 1.子数是否为平衡树，2.子树的depth．
 * 可以定义　bool dfs(treenode* root, int& depth); 
 * 也可定义　std::pair<bool, int> dfs(treenode* root);
 * 分别来返回这两个值
*/
void test_balance_tree() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    // root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(3);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(8);

    bool result = sword_finger_offer::check_balance_tree(root);
    std::cout << "balance tree result: " << std::boolalpha << result << std::endl;
}

/**
 * 161 找出数组中唯一出现一次的两个数字. 因为数组中有两个不同的数，故先找出两个不同数最低比特位不同的位置．
 * 根据该位置的０，１数值将数组划分为两类．然后对两类数字分别找出唯一出现一次的数．
 * 注意：符合优先级，＆的优先级低于＝＝，　故划分数组时判断条件为((flag&num)==0), 不可写成(flag&num==0)
*/
void test_appearOnce() {
    std::vector<int> arr = {2,4,3,6,3,2,5,5};
    std::pair<int, int> result = sword_finger_offer::appearOnce(arr);
    std::cout << "appear onece result: " << result.first << ", " << result.second << std::endl;
}

/**
 * 162. 找出数组中唯一出现一次的数字，其他数字出现三次．
 * 思路：记录每个比特位中１出现的次数,最后按位％３,得到出现一次的数字．注意:(int&int)得到的结果还是ｉnt,
 * 判断num&bitmask对应位是否为１的方法不是（num&bitmask）== 1, 其值应该是　(num&bitmask) == bitmask,或写成　(num & bitmask) != 0
 * 2. 基于上一思路，可以直接使用int one, two, three, 分别记录出现１，２，３次的比特．见题９.
 * 注意two的更新要考虑历史two的信息，而three则不能考虑历史信息，如当one=0, two=3, three=2, num=1
 * num=1时，two应该等于two=two|(one&num)=3, 而不是one&num=0, one=one^num=1, three=two&one=1, 而不是three=three|(two&one)=3,
 * three等于３的话会导致更新two, one出错
*/
void test_appearOnce_of_three() {
    std::vector<int> arr = {1,-5,3,1,3,1,3}; //{1,-5,1,1}; //{1,-5,3,1,3,1,3};
    // int result = sword_finger_offer::appearOnce_of_three(arr);
    int result = sword_finger_offer::appearOnce_of_three_v2(arr);
    std::cout << "appear once of three result: " << result << std::endl;
}

/**
 * 163. 找出排序数值中和为s的两个数
*/
void test_sum_of_s() {
    std::vector<int> arr = {1,1,2,4,5,7,7,9};
    int s = 1;
    std::pair<int, int> p = sword_finger_offer::sum_of_s(arr, s);
    std::cout << s << " = " << p.first << " + " << p.second << std::endl;
}

/**
 * 164 找出和为s的所有连续数字序列
*/
void test_sum_of_s_v2() {
    int s = 4;
    std::vector<std::vector<int>> result = sword_finger_offer::sum_of_s_v2(s);
    std::cout << "sum of " << s << std::endl;
    for (int i=0; i<result.size(); i++) {
        for (int j=0; j<result[i].size(); j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * 165 翻转字符串
*/
void test_reverse_str() {
    std::string str = "I"; //"I am a student.";
    std::string result = sword_finger_offer::reverse_str(str);
    std::cout << "reverse str result: " << result << std::endl;
}

/**
 * 166 得到数组中窗口为k的所有最大值. 两种方法：1.使用multipset维护一个最大堆，同时删除前idx-2的数，若使用vector+make_heap或自己实现的heap, 删除操作不太好处理;
 * 2.使用deque，双向队列中只保留windows内最大值的降序排序, 如果当前idx,arr[idx]> dequeue[arr[deque.back()]] deque.pop();
 * 如果deque.front()的下标超出了当前windows范围，则pop front(), 再push_back当前idx, 当前窗口的最大值即为，　deque.front()
 * 
 * 再刷感想：
 * 在当前idx下比较arr[list.back()] <= arr[idx]，　而不是 list.front(), 且使用while而不是if
*/
void test_max_sequence() {
    std::vector<int> arr = {2,3,4,6,2,5,1};
    int windows = 3;
    // std::vector<int> result = sword_finger_offer::max_sequence(arr, windows);
    // std::vector<int> result = sword_finger_offer::max_sequence_v2(arr, windows);
    // std::vector<int> result = sword_finger_offer::max_sequence_v3(arr, windows);
    std::vector<int> result = sword_finger_offer::max_sequence_v4(arr, windows);
    std::cout << "max sequence result:\n";
    for (int i=0; i<result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * 167 n个骰子出现的数字之和的所有概率. dfs生成所有可能的组合．注意使用vector.reverse后，　然后直接使用[i]下标设值，　begin(), end()会有问题．
*/
void test_probability_n() {
    int n = 1;
    std::unordered_map<int, float> result = sword_finger_offer::probability_n(n);
    std::cout << "probability " << n << std::endl;
    for (auto& p : result) {
        std::cout << p.first << ": " << p.second << std::endl;
    }
}

/**
 * 168 扑克牌中的顺子. 先对数字进行升序排序．１．找出０的个数; 2. 对非０个数依次求其间隔．　如果间隔总数小于等于０的个数，则可以是顺子；
 * 注意：1. 求非零数字间隔时要去除第一个非零数字与０的间隔．２．要考虑出现相同数字的情况，即对子
*/
void test_is_continuous() {
    std::vector<int> arr = {2, 4, 7, 0, 0};
    bool result = sword_finger_offer::isContinuous(arr);
    std::cout << "test is continuous result: " << std::boolalpha << result << std::endl;
}

/**
 * 169 圆圈中最后剩下的数字. 两种方法：1. 模拟法，　模拟该过程，　注意最后一个数并不是删除n-1个数的下标+1, 而应该遍历数组，直到找到该数．
 * ２. 数学推到公式：　f(n,m) = (f(n-1, m)+m)%n;
*/
void test_final_number() {
    int n=5;
    int m=3;
    for (n=1; n<=5; n++) {
        // int result = sword_finger_offer::finalNumber(n,m);
        int result = sword_finger_offer::finalNumber_v2(n,m);
        std::cout << "test final number (" << n << ", " << m <<")" << ": " << result << std::endl;
    }   
}

/**
 * 170 最大股票利润
*/
void test_maxprofit() {
    std::vector<int> arr = {9, 8, 5}; //{9, 11, 8, 5, 7, 12, 16, 4};
    int result = sword_finger_offer::maxprofit(arr);
    std::cout << "test max profit: " << result << std::endl;
}

/**
 * 171 求１＋２＋....+n　的方法
*/
void test_nsum() {
    int n = 1;
    int result = sword_finger_offer::nsum(n);
    std::cout << "test sum of n: " << result << std::endl;
}

/**
 * 173 位运算求两数之和. 模拟求和过程．负数也同样适用于
*/
void test_sum_of_bits() {
    int num1 = 5;
    int num2 = -6;
    int result = sword_finger_offer::sum_in_bits(num1, num2);
    std::cout << "test sum of bits: " << result << std::endl;
}

/**
 * 174 不用除法做连乘. 计算A[0...n-1]/A[i]=A[0....i-1] * A[i+1...n-1]
 * 分别求出heads[i]，表示A[0]到A[i]连乘的结果;
 * tails[i]表示A[n-1]到A[i]连乘的结果;
 * 注意: heads[0]应该等于A[0],而不是１，tails[n-1]应该等于A[n-1],而不是１
*/
void test_multipy() {
    std::vector<int> arr = {2,-1,0,-4,3};
    std::vector<int> result = sword_finger_offer::multipy(arr);
    std::cout << "test multipy result: ";
    for (int i=0; i<result.size(); i++) {
        std::cout << result[i] << ", ";
    }
    std::cout << std::endl;
}



int main() {
    //***************sword finger offer ************************

    // test_print1ToNdigits();
    // test_deleteduplictednode();
    // test_regular_match_v2();
    // test_isNumeric();
    // test_reordervec();
    // test_detect_cycle();
    // test_reverse_list();
    // test_merge_two_list();
    // test_issubtree();
    // test_issymmetrical();test_longest_increasing_path
    // test_clockwise_print();
    // test_min_stack();
    // test_is_correct_for_stack();
    // test_z_print();
    // test_reverse();
    // test_check_bst_order();
    // test_sum_path();
    // test_bst2list();
    // test_serialize_deserialize();
    // test_permutation();
    // test_queen_permute();
    // test_morethanhalf();
    // test_topKminus();
    test_median_number();
    // test_heap();
    // test_continuoussum();
    // test_one_counts();
    // test_number_of_digit();
    // test_mincombination();
    // test_number2ascii();
    // test_giftmaxval();
    // test_longest_substr();
    // test_ugly_number();
    // test_first_one_char();
    // test_count_reverse_pair();
    // test_common_node();
    // test_treenode_common_parent();
    // test_sorted_arr_count();
    // test_kthnode();
    // test_depthofBST();
    // test_balance_tree();
    // test_appearOnce();
    // test_appearOnce_of_three();
    // test_sum_of_s();
    // test_sum_of_s_v2();
    // test_reverse_str();
    // test_max_sequence();
    // test_probability_n();
    // test_is_continuous();
    // test_final_number();
    // test_maxprofit();
    // test_nsum();
    // test_sum_of_bits();test_longest_increasing_path
    // test_multipy();
    return 0;
}
