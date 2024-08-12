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
#include <sstream>
#include "data_structs/base_struct.h"
#include "huawei_online.h"

using namespace std;

void test_move() {
    std::string s="A10;S20;W10;D30;X;A1A;B10A11;;A10;";
    std::pair<int, int> p(0, 0);
    huawei_online::move_alg(s, p);
    printf("%d,%d\n", p.first, p.second);
    return;
}

void test_error_record() {
    std::vector<std::string> logs = {
        "D:\\zwtymj\\xccb\\ljj\\cqzlyaszjvlsjmkwoqijggmybr 645",
        "E:\\je\\rzuwnjvnuz 633",
        "C:\\km\tgjwpb\\gy\\atl 637",
        "F:\\weioj\\hadd\\connsh\\rwyfvzsopsuiqjnr 647",
        "E:\\ns\\mfwj\\wqkoki\\eez 648",
        "D:\\cfmwafhhgeyawnool 649",
        "E:\\czt\\opwip\\osnll\\c 637",
        "G:\\nt\\f 633",
        "F:\\fop\\ywzqaop 631",
        "F:\\yay\\jc\\ywzqaop 631",
        "D:\\zwtymj\\xccb\\ljj\\cqzlyaszjvlsjmkwoqijggmybr 645"
    };
    std::vector<std::pair<std::string, int>> res;
    huawei_online::error_record(logs, res);
    for (const auto& kv: res) {
        printf("%s %d\n", kv.first.c_str(), kv.second);
    }
}

void test_password_valid() {
    std::string s = "021Abc9000";
    bool res = huawei_online::password_valid(s);
    if (res) {
        printf("OK\n");
    } else {
        printf("NG\n"); 
    }
}

void test_simple_password() {
    std::string s = "YUANzhi1987";
    std::string res = huawei_online::simple_password(s);
    printf("%s\n", res.c_str());
}

void test_delete_least_char() {
    std::string s = "abcdd";
    std::string res = huawei_online::delete_least_char(s);
    printf("%s\n", res.c_str());
}

void test_string_sort() {
    std::string s = "A Famous Saying: Much Ado About Nothing (2012/8).";
    std::string res = huawei_online::sort_string(s);
    printf("%s\n", res.c_str());
}

void test_encrypt_decrypt() {
    std::string s = "abcdefg";
    std::string s2 = "BCDEFGH";
    std::string res = huawei_online::encrypt(s);
    printf("%s\n", res.c_str());
    std::string res2 = huawei_online::decrypt(s2);
    printf("%s\n", res2.c_str());
}

void test_merge_string() {
    std::string s1 = "dec";
    std::string s2 = "fab";
    std::string res = huawei_online::merge_string(s1, s2);
    printf("%s\n", res.c_str());
}

void test_password_cut() {
    std::string s = "021Abc9000";
    int res = huawei_online::password_cut(s);
    printf("%d\n", res);
}

void test_int2ip() {
    uint32_t n = 167969729;
    std::string s="10.0.3.193";
    uint32_t n2 = huawei_online::ip_to_int(s);
    std::string res = huawei_online::int_to_ip(n);
    printf("%u\n", n2);
    printf("%s\n", res.c_str());
}

void test_encrypt_string() {
    std::string key = "nihao";
    std::string s = "ni";
    // std::string res = huawei_online::encrypt_string(key, s);
    std::string res = huawei_online::encrypt_string_v2(key, s);
    printf("%s\n", res.c_str());
}

void test_ip_same_part() {
    std::string mask = "1.255.255.0";
    std::string ip1 = "187.39.235.7";
    std::string ip2 = "219.79.189.231";
    int res = huawei_online::check_same_part(mask, ip1, ip2);
    printf("%d\n", res);
}

void test_weight_count() {
    std::vector<int> weights = {1, 2};
    std::vector<int> nums = {2, 1};
    int res = huawei_online::weight_count(weights, nums);
    printf("%d\n", res);
}

void test_name_beauty() {
    std::string s = "zhangsan";
    int res = huawei_online::name_beauty(s);
    printf("%d\n", res);
}

void test_four_arithmetic() {
    std::string s = "3+2*{1+2*[-4/(8-6)+7]}"; // 3+2*{1+2*[-4/(8-6)+7]}
    // std::string res = huawei_online::infixToPostfix(s);
    // printf("%s\n", res.c_str());
    // int res2 = huawei_online::calculate(res);
    // printf("%d\n", res2);
    int res = huawei_online::compute(s, 0, s.size()-1);
    printf("%d\n", res);
}

void test_edit_distance() {
    std::string s1 = "abcdefg";
    std::string s2 = "abcdef";
    int res = huawei_online::edit_distance(s1, s2);
    printf("%d\n", res);
}

void test_add() {
    std::string s1="9876543210";
    std::string s2="1234567890";
    std::string res = huawei_online::add(s1, s2);
    printf("%s\n", res.c_str());
}

void test_find_first_unique_char() {
    std::string s = "asdfasdfo";
    char res;
    bool flag = huawei_online::find_first_unique_char(s, res);
    if (flag) {
        printf("%c\n", res);
    } else {
        printf("-1\n");
    }
}

void test_dna_sequence() {
    std::string s = "AACTGTGCACGACCTGA";
    int n = 5;
    std::string res = huawei_online::dna_sequence(s, n);
    printf("%s\n", res.c_str());
}

void test_longest_common_substring() {
    std::string s1 = "abcdefghijklmnop"; // abcdefghijklmnop
    std::string s2 = "afjklmnopqrstuvw"; // afjklmnopqrstuvw
    std::string res = huawei_online::longest_common_substring(s1, s2);
    printf("%s\n", res.c_str());
}

void test_matrix_multiply() {
    std::vector<std::pair<int, int>> matrix = {
        {50, 10},
        {10, 20},
        {20, 5}
        };
    std::string s = "(A(BC))";
    int res = huawei_online::matrix_multiply(matrix, s);
    printf("%d\n", res);
}

void test_wildcard_match() {
    std::string patten = "?*Bc*?";
    std::string words = "abcd";
    bool res = huawei_online::wildcard_match(patten, words);
    if (res) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}

void test_parse_args() {
    std::string s = "xcopy /s c:\\ d:\\e";
    std::vector<std::string> res = huawei_online::parse_args(s);
    printf("%d\n", res.size());
    for (const auto& ss: res) {
        printf("%s\n", ss.c_str());
    }
}

void test_longest_common_substring_v2() {
    std::string s1 = "asdfas";
    std::string s2 = "werasdfaswer";
    int res = huawei_online::longest_common_substring_v2(s1, s2);
    printf("%d\n", res);
}

void test_puke_compare() {
    std::string s1 = "4 4 4 4";
    std::string s2 = "joker JOKER";
    std::string res = huawei_online::puke_compare(s1, s2);
    printf("%s\n", res.c_str());
}

void test_twenty_four_arithmetic() {
    std::string s = "A 2 J 3";
    std::string res = huawei_online::twenty_four_arithmetic(s);
    printf("%s\n", res.c_str());
}

void test_longest_number_string() {
    std::string s = "a8a72a6a5yy98y65ee1r2";
    std::vector<std::string> res = huawei_online::longest_number_string(s);
    for (const auto& ss: res) {
        printf("%s", ss.c_str());
    }
    printf(",%d\n", res[0].length());
}

void test_group_array() {
    std::vector<int> nums = {1, 5, -5, 1};
    bool res = huawei_online::group_array(nums);
    if (res) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}

void test_vending_machine() {
    std::string s = "r 22-18-21-21-7-20 3-23-10-6;c;q0;p 1;b A6;c;b A5;b A1;c;q1;p 5;";
    std::vector<int> goods, coins;
    int balance;
    
    std::istringstream iss(s);
    std::string tmp;
    while(getline(iss, tmp, ';')) {
        std::string res = huawei_online::vending_machine(tmp, goods, coins, balance);
        printf("%s\n", res.c_str());
    }
}

// test array alg
void test_distinct_random() {
    std::vector<int> nums = {1, 2, 2};
    std::vector<int> res = huawei_online::distinct_random(nums);
    for (const auto& n: res) {
        printf("%d ", n);
    }
    printf("\n");
}

// test snake matrix
void test_snake_matrix() {
    int n = 4;
    std::vector<std::vector<int>> res = huawei_online::snake_matrix(n);
    for (const auto& v: res) {
        for (const auto& n: v) {
            printf("%d ", n);
        }
        printf("\n");
    }
}

void test_mp3_move() {
    std::string s = "UUUU";
    int n = 10;
    std::pair<std::vector<int>, int> res = huawei_online::move(s, n);
    for (const auto& n: res.first) {
        printf("%d ", n);
    }
    printf("\n");
    printf("%d\n", res.second);
}

void test_matrix_multiply_hj69() {
    std::vector<std::vector<int>> m1 = {
        {1, 2, 3},
        {3, 2, 1}
    };
    std::vector<std::vector<int>> m2 = {
        {1, 2},
        {2, 1},
        {3, 3}
    };
    std::vector<std::vector<int>> res = huawei_online::matrix_multiply(m1, m2);
    for (const auto& v: res) {
        for (const auto& n: v) {
            printf("%d ", n);
        }
        printf("\n");
    }
}

void test_shopping_list() {
    int money = 50;
    int n = 5;
    std::vector<std::tuple<int, int, int>> inputs = {
        {20, 3, 5},
        {20, 3, 5},
        {10, 3, 0},
        {10, 2, 0},
        {10, 1, 0}
    };
    std::vector<std::vector<std::pair<int, int>>> goods(n+1);
    for (int i = 1; i < n+1; ++i) {
        int a, b, c;
        std::tie(a, b, c) = inputs[i-1];
        if (c == 0) {
            goods[i].insert(goods[i].begin(), {a, b*a});
        }
        else {
            goods[c].push_back({a, b*a});
        }
    }
    std::vector<std::vector<std::pair<int, int>>> final_goods;
    for (int i = 1; i < n+1; ++i) {
        if (!goods[i].empty()) {
            final_goods.push_back(goods[i]);
        }
    }
    int res = huawei_online::shopping_list(final_goods, money);
    printf("%d\n", res);
}

void test_chorus_team() {
    std::vector<int> nums = {186, 186, 150, 200, 160, 130, 197, 200};
    int res = huawei_online::chorus_team(nums);
    printf("%d\n", res);
}

void test_apple_count() {
    int m = 7;
    int n = 3;
    int res = huawei_online::apple_count(m, n);
    printf("%d\n", res);
}

void test_ball_distance() {
    int n = 1;
    std::pair<float, float> res = huawei_online::ball_distance(n);
    printf("%f %f\n", res.first, res.second);
}

void test_prime_factor() {
    int n = 180;
    std::vector<int> res = huawei_online::prime_factor(n);
    for (const auto& r: res) {
        printf("%d ", r);
    }
    printf("\n");
}

void test_prime_partner() {
    std::vector<int> nums = {2, 5, 6, 13};
    int res = huawei_online::prime_partner(nums);
    printf("%d\n", res);
}

void test_sort_score() {
    std::vector<std::pair<std::string, int>> scores = {
        {"fang", 90},
        {"yang", 50},
        {"ning", 70}
    };
    bool is_asc = false;
    // std::vector<std::pair<std::string, int>> res = huawei_online::sort_score(scores, is_asc);
    std::vector<std::pair<std::string, int>> res = huawei_online::sort_score_v2(scores, is_asc);
    for (const auto& r: res) {
        printf("%s %d\n", r.first.c_str(), r.second);
    }
}

void test_redraiment_walk() {
    std::vector<int> nums = {237, 153, 196, 160, 154, 91, 195, 250, 129, 219, 14, 29, 209}; // {2, 5, 1, 5, 4, 5};
    int res = huawei_online::redraiment_walk(nums);
    printf("%d\n", res);
}

void test_maze_problem() {
    std::vector<std::vector<int>> maze = {
         {0, 1, 0, 0, 0},
         {0, 1, 1, 1, 0},
         {0, 0, 0, 0, 0},
         {0, 1, 1, 1, 0},
         {0, 0, 0, 1, 0}
    };
    std::vector<std::pair<int, int>> res = huawei_online::maze_problem(maze);
    for (const auto& r: res) {
        printf("(%d,%d)\n", r.first, r.second);
    }
}

void test_construct_and_delete() {
    std::vector<std::pair<int, int>> inputs = {
        {3, 2},
        {4, 3},
        {5, 2},
        {1, 4}
    };
    int head_val = 2;
    int val = 3;
    // ListNode* head = huawei_online::construct_and_delete(inputs, head_val, val);
    // ListNode* p = head;
    huawei_online::ListNodeV2* head = huawei_online::construct_and_delete_v2(inputs, head_val, val);
    huawei_online::ListNodeV2* p = head;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

void test_find_kth_node() {
    std::vector<int> inputs = {1, 2, 3, 4, 5};
    int k = 2;
    int res = huawei_online::find_kth_node(inputs, k);
    printf("%d\n", res);
}

void test_train_in_out() {
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> res = huawei_online::train_in_out(nums);
    for (const auto& v: res) {
        for (const auto& n: v) {
            printf("%d ", n);
        }
        printf("\n");
    }
}

void test_sudoku() {
    std::vector<std::vector<int>> matrix = {
        {0, 9, 2, 4, 8, 1, 7, 6, 3},
        {4, 1, 3, 7, 6, 2, 9, 8, 5},
        {8, 6, 7, 3, 5, 9, 4, 1, 2},
        {6, 2, 4, 1, 9, 5, 3, 7, 8},
        {7, 5, 9, 8, 4, 3, 1, 2, 6},
        {1, 3, 8, 6, 2, 7, 5, 9, 4},
        {2, 7, 1, 5, 3, 8, 6, 4, 9},
        {3, 8, 6, 9, 1, 4, 2, 5, 7},
        {0, 4, 5, 2, 7, 6, 8, 3, 1}
    };
    bool res = huawei_online::sudoku(matrix);
    if (res) {
        for (const auto& v: matrix) {
            for (const auto& n: v) {
                printf("%d ", n);
            }
            printf("\n");
        }
    }
}

void test_pick_seven() {
    int n = 198;
    int res = huawei_online::pick_seven(n);
    printf("%d\n", res);
}

void test_perfect_number() {
    int n = 1000;
    int res = huawei_online::perfect_number(n);
    printf("%d\n", res);
}

void test_cube_root() {
    double n = 19.9;
    float res = (float)huawei_online::cube_root(n);
    printf("%.1f\n", res);
}

void test_find_prime_pair() {
    int n = 100;
    std::pair<int, int> res = huawei_online::find_prime_pair(n);
    printf("%d\n%d\n", res.first, res.second);
}

void test_longest_palindrome() {
    std::string s = "cdabbacc";
    int res = huawei_online::longest_palindrome(s);
    printf("%d\n", res);
}

void test_max_continuous_bit() {
    int n = 200;
    int res = huawei_online::max_continuous_bit(n);
    printf("%d\n", res);
}

int main() {
    // test_max_continuous_bit();
    // test_longest_palindrome();
    // test_find_prime_pair();
    // test_cube_root();
    // test_perfect_number();
    // test_pick_seven();
    // test_sudoku();
    // test_train_in_out();
    // test_find_kth_node();
    test_construct_and_delete();
    // test_maze_problem();
    // test_redraiment_walk();
    // test_sort_score();
    // test_prime_partner();
    // test_prime_factor();
    // test_ball_distance();
    // test_apple_count();
    // test_chorus_team();
    // test_shopping_list();
    // test_matrix_multiply_hj69();
    // test_mp3_move();
    // test_snake_matrix();
    // test_distinct_random();
    // test_vending_machine();
    // test_group_array();
    // test_longest_number_string();
    // test_twenty_four_arithmetic();
    // test_puke_compare();
    // test_longest_common_substring_v2();
    // test_parse_args();
    // test_move();
    // test_error_record();
    // test_password_valid();
    // test_simple_password();
    // test_delete_least_char();
    // test_string_sort();
    // test_encrypt_decrypt();
    // test_merge_string();
    // test_password_cut();
    // test_int2ip();
    // test_encrypt_string();
    // test_ip_same_part();
    // test_weight_count();
    // test_name_beauty();
    // test_four_arithmetic();
    // test_edit_distance();
    // test_add();
    // test_find_first_unique_char();
    // test_dna_sequence();
    // test_longest_common_substring();
    // test_matrix_multiply();
    // test_wildcard_match();
    return 0;
}
