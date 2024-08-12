#ifndef HUAWEI_ONLINE_IMPLS
#define HUAWEI_ONLINE_IMPLS

#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include "./data_structs/base_struct.h"

namespace huawei_online
{

/*
    字符串
    数组
    动态规划
    模拟
    排序
    广度搜索,递归
    链表,队列，哈希
    基础数学，位运算，穷举
*/

// 字符串
// HJ17 坐标移动 https://www.nowcoder.com/share/jump/2303985301723476519759
bool move_step(const std::string& s, std::pair<int, int>& p);
bool move_alg(const std::string& line, std::pair<int, int>& p);

// HJ18 识别有效的IP地址和掩码并进行分类统计 https://www.nowcoder.com/share/jump/2303985301723476579734

// HJ19 简单错误记录 https://www.nowcoder.com/share/jump/2303985301723476579735
bool error_record(const std::vector<std::string>& logs, std::vector<std::pair<std::string, int>>& res);

// HJ20 密码验证合格程序 https://www.nowcoder.com/share/jump/2303985301723476579736
bool password_valid(const std::string& s);

// HJ21 简单密码
std::string simple_password(const std::string& s);

// HJ23 删除字符串中出现次数最少的字符
std::string delete_least_char(const std::string& s);

// HJ26 字符串排序
std::string sort_string(const std::string& s);

//HJ29 字符串加解密
std::string encrypt(const std::string& s);
std::string decrypt(const std::string& s);

// HJ30 字符串合并处理
std::string merge_string(const std::string& s1, const std::string& s2);

// HJ32 密码截取
int password_cut(const std::string& s);

// HJ33 整数与IP地址间的转换
std::string int_to_ip(uint32_t n);
uint32_t ip_to_int(const std::string& s);

// HJ36 字符串加密
std::string encrypt_string(const std::string& key, const std::string& s);
std::string encrypt_string_v2(const std::string& key, const std::string& s);

// HJ39 判断两个IP是否属于同一网段
int check_same_part(const std::string& mask, const std::string& ip1, const std::string& ip2);

// HJ41 称砝码
int weight_count(const std::vector<int>& weights, const std::vector<int>& nums);

// HJ45 名字的漂亮度
int name_beauty(const std::string& s);

// HJ50 四则运算
std::string infixToPostfix(const std::string& s);
int compute(const std::string& s, int left, int right);

// HJ52 计算字符串的编辑距离
int edit_distance(const std::string& s1, const std::string& s2);

// HJ57 高精度加法
std::string add(const std::string& s1, const std::string& s2);

// HJ59 找出字符串中第一个只出现一次的字符
bool find_first_unique_char(const std::string& s, char& res);

// HJ63 DNA序列
std::string dna_sequence(const std::string& s, int n);

// HJ65 查找两个字符串a,b中的最长公共子串
std::string longest_common_substring(const std::string& s1, const std::string& s2);

// HJ70 矩阵乘法计算量估算
int matrix_multiply(const std::vector<std::pair<int, int>>& matrix, const std::string& s);

// HJ71 字符串通配符
bool wildcard_match(const std::string& patten, const std::string& words);

// HJ74 参数解析
std::vector<std::string> parse_args(const std::string& s);

// HJ75 公共子串计算
int longest_common_substring_v2(const std::string& s1, const std::string& s2);

// HJ88 扑克牌大小
std::string puke_compare(const std::string& s1, const std::string& s2);

// HJ89 24点运算
std::string twenty_four_arithmetic(const std::string& s);

// HJ92 在字符串中找出连续最长的数字串
std::vector<std::string> longest_number_string(const std::string& s);

// HJ93 数组分组
bool group_array(const std::vector<int>& nums);

// HJ98 自动售货系统
// goods: a1~a6, coins: 1,2,5,10
std::string vending_machine(const std::string& s, std::vector<int>& goods, std::vector<int>& coins, int& balance);

// array alg
// HJ3 明明的随机数
std::vector<int> distinct_random(const std::vector<int>& nums);

// HJ35 蛇形矩阵
std::vector<std::vector<int>> snake_matrix(int n);

// HJ64 MP3光标位置
std::pair<std::vector<int>, int> move(const std::string& s, int n);

// HJ69 矩阵乘法
std::vector<std::vector<int>> matrix_multiply(const std::vector<std::vector<int>>& m1, const std::vector<std::vector<int>>& m2);

// dp alg
// HJ16 购物单
int shopping_list(const std::vector<std::vector<std::pair<int, int>>>& goods, int money);

// HJ24 合唱队
int chorus_team(const std::vector<int>& nums);

// HJ61 放苹果
int apple_count(int m, int n);

// HJ38 求小球落地5次后所经历的路程和第5次反弹的高度
std::pair<float, float> ball_distance(int n);

// sort alg
// HJ6 质数因子
std::vector<int> prime_factor(int n);

// HJ28 素数伴侣
int prime_partner(const std::vector<int>& nums);

// HJ68 成绩排序
std::vector<std::pair<std::string, int>> sort_score(const std::vector<std::pair<std::string, int>>& scores, const bool is_asc);
std::vector<std::pair<std::string, int>> sort_score_v2(const std::vector<std::pair<std::string, int>>& scores, const bool is_asc);

// HJ103 Redraiment的走法
int redraiment_walk(const std::vector<int>& nums);

// bfs, dfs alg
// HJ43 迷宫问题
std::vector<std::pair<int,int>> maze_problem(const std::vector<std::vector<int>>& maze);

// list, queue, hash, stack alg
// HJ48 从单向链表中删除指定值的节点
ListNode* construct_and_delete(std::vector<std::pair<int, int>> inputs, int head_val, int val);
struct ListNodeV2 {
    int val;
    ListNodeV2* next;
    ListNodeV2(int val_):val(val_),next(nullptr){};
};
ListNodeV2* construct_and_delete_v2(const std::vector<std::pair<int, int>> node_infos, int head_val, int delete_val);


// HJ51 输出单向链表中倒数第k个结点
int find_kth_node(const std::vector<int>& inputs, int k);

// HJ77 火车进站
std::vector<std::vector<int>> train_in_out(const std::vector<int>& nums);

// base math alg
// HJ44 Sudoku
bool sudoku(std::vector<std::vector<int>>& matrix);

// HJ55 挑7
int pick_seven(int n);

// HJ56 完全数计算
int perfect_number(int n);

// HJ107 求解立方根
double cube_root(double n);

// HJ60 查找组成一个偶数最接近的两个素数
std::pair<int, int> find_prime_pair(int n);

// HJ85 最长回文子串
int longest_palindrome(const std::string& s);

// HJ86 求最大连续bit数
int max_continuous_bit(int n);

} // namespace huawei_online


#endif