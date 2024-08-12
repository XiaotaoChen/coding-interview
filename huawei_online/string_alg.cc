#include "../huawei_online.h"

#include <set>
#include <stack>
#include <unordered_set>
#include <sstream>
#include <queue>

namespace huawei_online
{
// HJ17
bool isNumber(const std::string& s) {
    if (s.empty()) return false;
    for (const auto c: s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

bool move_step(const std::string& s, std::pair<int, int>& p) {
    if (s.empty()) return false;
    std::string s1 = s.substr(1);
    if (isNumber(s1) && s1.length() <= 2) {
        int num = std::stoi(s1);
        switch (s[0])
        {
        case 'A':
            p.first += num;
            break;
        case 'D':
            p.first -= num;
            break;
        case 'W':
            p.second += num;
            break;
        case 'S':
            p.second -= num;
            break;
        default:
            break;
        }
        return true;
    }
    return false;
}

bool move_alg(const std::string& line, std::pair<int, int>& p) {
    std::vector<std::string> items;
    std::string item;
    for (const auto c: line) {
        if (c == ';') {
            items.push_back(item);
            item.clear();
        } else {
            item.push_back(c);
        }
    }
    for (const auto& s: items) {
        move_step(s, p);
    }
    return true;
}

// HJ19
bool error_record(const std::vector<std::string>& logs, std::vector<std::pair<std::string, int>>& res) {
    // split by space
    std::unordered_map<std::string, int> total;
    std::vector<std::string> flags(8, "");
    int curr_cnt = 0;
    for (const auto& log: logs) {
        auto space_pos = log.find_last_of(' ');
        std::string file_name = log.substr(0, space_pos);
        std::string line_num = log.substr(space_pos + 1);
        auto pos = file_name.find_last_of('\\');
        if (pos != std::string::npos) {
            file_name = file_name.substr(pos + 1);
        }
        if (file_name.size() > 16) {
            file_name = file_name.substr(file_name.size() - 16);
        }
        std::string key = file_name + " " + line_num;
        if (total.find(key) == total.end()) {
            total[key] = 1;
            flags[curr_cnt] = key;
            curr_cnt = (curr_cnt + 1) % 8;
        } else {
            total[key]++;
        }
    }
    for (int i = 0; i < 8; i++) {
        if (!flags[curr_cnt].empty()) {
            res.push_back(std::make_pair(flags[curr_cnt], total[flags[curr_cnt]]));
        }
        curr_cnt = (curr_cnt + 1) % 8;
    }
    return true;
}

// HJ20
bool password_valid(const std::string& s) {
    if (s.length() < 8) return false;
    int lower = 0, upper = 0, digit = 0, other = 0;
    for (const auto c: s) {
        if (isdigit(c)) {
            digit = 1;
        }
        else if (c >= 'a' && c <= 'z') {
            lower = 1;
        }
        else if (c >= 'A' && c <= 'Z') {
            upper = 1;
        }
        else {
            other = 1;
        }
    }
    if (lower + upper + digit + other < 3) return false;
    std::set<std::string> substrs;
    for (int i=0; i<s.length()-2; i++) {
        std::string sub = s.substr(i, 3);
        if (substrs.find(sub) != substrs.end()) {
            return false;
        }
        substrs.insert(sub);
    }
    return true;
}

// HJ21
char char2num(const char c) {
    if (c >='a' && c <= 'c') {
        return '2';
    } else if (c >= 'd' && c <= 'f') {
        return '3';
    } else if (c >= 'g' && c <= 'i') {
        return '4';
    } else if (c >= 'j' && c <= 'l') {
        return '5';
    } else if (c >= 'm' && c <= 'o') {
        return '6';
    } else if (c >= 'p' && c <= 's') {
        return '7';
    } else if (c >= 't' && c <= 'v') {
        return '8';
    } else if (c >= 'w' && c <= 'z') {
        return '9';
    }
    return c;
}

std::string simple_password(const std::string& s) {
    if (s.empty()) return "";
    std::string res;
    for (const auto c: s) {
        if (isdigit(c)) {
            res.push_back(c);
        }
        else if (islower(c)) {
            res.push_back(char2num(c));
        }
        else if (isupper(c)) {
            if (c == 'Z') {
                res.push_back('a');
            } else {
                res.push_back(tolower(c) + 1);
            }
        }
    }
    return res;
}

// HJ23
std::string delete_least_char(const std::string& s) {
    if (s.empty()) return "";
    std::unordered_map<char, int> cnt;
    for (const auto c: s) {
        cnt[c]++;
    }
    int min_cnt = s.length();
    for (const auto& kv: cnt) {
        min_cnt = std::min(min_cnt, kv.second);
    }
    std::string res;
    for (const auto c: s) {
        if (cnt[c] != min_cnt) {
            res.push_back(c);
        }
    }
    return res;
}

// HJ26
std::string sort_string(const std::string& s) {
    std::string res;
    std::vector<char> chars;
    for (int i=0; i<26; i++) {
        for (const auto c: s) {
            if (c - 'a' == i || c - 'A' == i) {
                chars.push_back(c);
            }
        }
    }
    for (int i=0,k=0; i<s.length(); i++) {
        if (isalpha(s[i])) {
            res.push_back(chars[k++]);
        } else {
            res.push_back(s[i]);
        }
    }
    return res;
}

// HJ29
std::string encrypt(const std::string& s) {
    std::string res;
    for (const auto c: s) {
        if (isalpha(c)) {
            if (isupper(c)) {
                if (c == 'Z') {
                    res.push_back('a');
                } else {
                    res.push_back(tolower(c) + 1);
                }
            } else {
                if (c == 'z') {
                    res.push_back('A');
                } else {
                    res.push_back(toupper(c) + 1);
                }
            }
        } else if (isdigit(c)) {
            // res.push_back((c - '0' + 1) % 10 + '0');
            if (c == '9') {
                res.push_back('0');
            } else {
                res.push_back(c + 1);
            }
        }
    }
    return res;
}

std::string decrypt(const std::string& s) {
    std::string res;
    for (const auto c: s) {
        if (isalpha(c)) {
            if (isupper(c)) {
                if (c == 'A') {
                    res.push_back('z');
                } else {
                    res.push_back(tolower(c) - 1);
                }
            } else {
                if (c == 'a') {
                    res.push_back('Z');
                } else {
                    res.push_back(toupper(c) - 1);
                }
            }
        }
        else if (isdigit(c)) {
            if (c == '0') {
                res.push_back('9');
            } else {
                res.push_back(c - 1);
            }
        }
    }
    return res;
}

// HJ30
char hexTransform(const char c) {
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')) {
        // transform
        int num = 0;
        if (isdigit(c)) {
            num = c - '0';
        } else if (islower(c)) {
            num = c - 'a' + 10;
        } else {
            num = c - 'A' + 10;
        }
        int rev_num = 0;
        for (int i=0; i<4; i++) {
            rev_num *= 2;
            rev_num += (num & 1);
            num >>= 1;
        }
        if (rev_num < 10) {
            return '0'+ rev_num;
        }
        else {
            return rev_num - 10 + 'A';
        }
    }
    return c;
}

std::string merge_string(const std::string& s1, const std::string& s2) {
    // merge
    std::string res1 = s1 + s2;
    std::string odd_str, even_str;
    for (int i=0; i<res1.length(); i++) {
        if (i % 2 == 0) {
            even_str.push_back(res1[i]);
        } else {
            odd_str.push_back(res1[i]);
        }
    }
    // sort
    std::sort(even_str.begin(), even_str.end());
    std::sort(odd_str.begin(), odd_str.end());
    std::string res2;
    for (int i=0,j=0,k=0; i<res1.length(); i++) {
        if (i % 2 == 0) {
            res2.push_back(even_str[j++]);
        } else {
            res2.push_back(odd_str[k++]);
        }
    }
    // hex transform
    for (int i=0; i<res2.length(); i++) {
        res2[i] = hexTransform(res2[i]);
    }
    return res2;
}

// HJ32
int find_max_len(const std::string& s, int l, int r) {
    while (l >= 0 && r < s.length() && s[l] == s[r]) {
        l--;
        r++;
    }
    return r - l - 1;
}

int password_cut(const std::string& s) {
    if (s.length() < 2) {
        return s.length();
    }
    int max_len = 0;
    for (int i=0; i<s.length(); i++) {
        max_len = std::max(max_len, find_max_len(s, i, i));
        max_len = std::max(max_len, find_max_len(s, i, i+1));
    }
    return max_len;
}

// HJ33
std::string int_to_ip(uint32_t n) {
    std::string res;
    for (int i=0; i<4; i++) {
        int val = (n>>(24-8*i)) & 0xFF;
        std::string val_str = std::to_string(val);
        if (i == 0) {
            res += val_str;
        } else {
            res += "." + val_str;
        }
    }
    return res;
}

uint32_t ip_to_int(const std::string& s) {
    uint32_t res = 0;
    std::string tmp_s = s;
    while(tmp_s.find('.') != std::string::npos) {
        int pos = tmp_s.find('.');
        std::string val_str = tmp_s.substr(0, pos);
        tmp_s = tmp_s.substr(pos + 1);
        int val = std::stoi(val_str);
        res = (res << 8) + val;
    }
    int val = std::stoi(tmp_s);
    res = (res << 8) + val;
    return res;
}

// HJ36
std::string encrypt_string(const std::string& key, const std::string& s) {
    std::string res;
    std::set<char> chars;
    std::vector<char> char_flags(26, '0');
    char curr = 'a';
    for (const auto c: key) {
        if (chars.find(c) == chars.end()) {
            chars.insert(c);
            char_flags[c - 'a'] = curr;
            curr++;
        }
    }
    for (int i=0; i<26; i++) {
        if (char_flags[i] == '0') {
            char_flags[i] = curr++;
        }
    }
    std::vector<char> char_map(26);
    for (int i=0; i<26; i++) {
        char_map[char_flags[i] - 'a'] = i + 'a';
    }

    for (const auto c: s) {
        res.push_back(char_map[c - 'a']);
    }
    return res;
}

std::string encrypt_string_v2(const std::string& key, const std::string& s) {
    std::string res;
    std::vector<char> map_char;
    std::vector<bool> flags(26, false);
    for (const auto c: key) {
        if (!flags[c - 'a']) {
            map_char.push_back(c);
            flags[c - 'a'] = true;
        }
    }
    for (char c='a'; c<='z'; c++) {
        if (!flags[c - 'a']) {
            map_char.push_back(c);
            flags[c - 'a'] = true;
        }
    }
    for (const auto c: s) {
        res.push_back(map_char[c - 'a']);
    }
    return res;
}

// HJ39
bool isIP(const std::string& ip) {
    std::string tmp_ip = ip;
    int right_num =0;
    while(tmp_ip.find_first_of('.') != std::string::npos) {
        auto pos = tmp_ip.find_first_of('.');
        std::string tmp = tmp_ip.substr(0, pos);
        int val = std::stoi(tmp);
        if (val>=0 && val<256) {
            right_num++;
        }
        else {
            return false;
        }
        tmp_ip = tmp_ip.substr(pos+1);
    }
    int val = std::stoi(tmp_ip);
    if (val>=0 && val<256) {
        right_num++;
    }
    else {
        return false;
    }
    if (right_num == 4) return true;
    return false;
}

bool isMask(uint32_t val) {
    if (val == 0) return false;
    int count = 0;
    while((val & 1) == 0) {
        count++;
        val = val >>1;
    }
    while((val & 1) == 1) {
        count++;
        val = val >> 1;
    }
    if (count != 32) return false;
    return val == 0;
}

uint32_t ip2uint32(const std::string& ip) {
    uint32_t res = 0;
    std::string tmp_s = ip;
    while(tmp_s.find('.') != std::string::npos) {
        int pos = tmp_s.find('.');
        std::string val_str = tmp_s.substr(0, pos);
        tmp_s = tmp_s.substr(pos + 1);
        int val = std::stoi(val_str);
        res = (res << 8) + val;
    }
    int val = std::stoi(tmp_s);
    res = (res << 8) + val;
    return res;
}

int check_same_part(const std::string& mask, const std::string& ip1, const std::string& ip2) {
    bool isTrue = isIP(ip1) && isIP(ip2) && isIP(mask);
    if (isTrue == false) return 1;
    uint32_t mask_val = ip2uint32(mask);
    if (!isMask(mask_val)) return 1;
    uint32_t ip1_val = ip2uint32(ip1);
    uint32_t ip2_val = ip2uint32(ip2);
    uint32_t ip1_mask = ip1_val & mask_val;
    uint32_t ip2_mask = ip2_val & mask_val;
    if (ip1_mask == ip2_mask) return 0;
    return 2;
}

// HJ41
int weight_count(const std::vector<int>& weights, const std::vector<int>& nums) {
    int sum = 0;
    for (int i=0; i<weights.size(); i++) {
        sum += weights[i] * nums[i];
    }
    std::vector<bool> sum_flags(sum+1, false);
    sum_flags[0] = true;
    for (int i=0; i<weights.size(); i++) {
        for (int j=0; j<nums[i]; j++) {
            for (int k=sum; k>=weights[i]; k--) {
                if (sum_flags[k-weights[i]]) {
                    sum_flags[k] = true;
                }
            }
        }
    }
    int res = 0;
    for (int i=0; i<sum_flags.size(); i++) {
        if (sum_flags[i]) {
            res++;
        }
    }
    return res;
}

// HJ45
int name_beauty(const std::string& s) {
    std::vector<int> cnt(26, 0);
    for (const auto c: s) {
        int idx = c - 'a';
        cnt[idx]++;
    }
    std::sort(cnt.begin(), cnt.end());
    int res = 0;
    for (int i=25; i>=0&& cnt[i] >0; i--) {
        res += cnt[i] * (i+1);
    }
    return res;
}

// HJ50
int precedence(const char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

std::string infixToPostfix(const std::string& s) {
    std::string res;
    std::stack<char> op_stack;
    for (int i=0; i<s.length(); i++) {
        char c = s[i];
        if (isdigit(c)) {
            res.push_back(c);
        } else if (c == '('|| c == '[' || c == '{') {
            op_stack.push(c);
        } else if (c == ')') {
            while(op_stack.top() != '(') {
                res.push_back(op_stack.top());
                op_stack.pop();
            }
            op_stack.pop();
        } else if (c == ']') {
            while(op_stack.top() != '[') {
                res.push_back(op_stack.top());
                op_stack.pop();
            }
            op_stack.pop();
        } else if (c == '}') {
            while(op_stack.top() != '{') {
                res.push_back(op_stack.top());
                op_stack.pop();
            }
            op_stack.pop();
        } else {
            if (c == '-' &&(i == 0 || s[i-1] == '('|| s[i-1] == '['|| s[i-1] == '{')) { // -1, -4
                res.push_back(c);
            } else {
                while(!op_stack.empty() && precedence(op_stack.top()) >= precedence(c)) {
                    res.push_back(op_stack.top());
                    op_stack.pop();
                }
                op_stack.push(c);
            }
            op_stack.push(c);
        }
    }
    while(!op_stack.empty()) {
        res.push_back(op_stack.top());
        op_stack.pop();
    }
    // // reverse res
    // std::reverse(res.begin(), res.end());
    return res;
}

int compute(const std::string& s, int left, int right) {
    char op = '+';
    int num = 0;
    std::vector<int> st;
    for (int i=left; i<=right; i++) {
        if (isdigit(s[i])) {
            num = num * 10 + s[i] - '0';
        }
        if (s[i]=='{' || s[i] == '[' || s[i] == '(') {
            int layer = 0;
            int j = i;
            while(j<=right) {
                if (s[j]=='{' || s[j] == '[' || s[j] == '(') {
                    layer++;
                } else if (s[j]=='}' || s[j] == ']' || s[j] == ')') {
                    layer--;
                    if (layer == 0) {
                        break;
                    }
                }
                j++;
            }
            num = compute(s, i+1, j-1);
            i = j+1;
        }
        if (!isdigit(s[i]) || i == right) {
            switch (op)
            {
                case '+': st.push_back(num); break;
                case '-': st.push_back(-num); break;
                case '*': st.back() *= num; break;
                case '/': st.back() /= num; break;
            }
            op = s[i];
            num = 0;
        }
    }
    int res = 0;
    for (const auto n: st) {
        res += n;
    }
    return res;
}

// HJ52
int edit_distance(const std::string& s1, const std::string& s2) {
    int n = s1.length();
    int m = s2.length();
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));
    for (int i=0; i<=n; i++) {
        dp[i][0] = i;
    }
    for (int j=0; j<=m; j++) {
        dp[0][j] = j;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = std::min(std::min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            }
        }
    }
    return dp[n][m];
}

// HJ57
std::string add(const std::string& s1, const std::string& s2) {
    std::string rev_s1(s1.rbegin(), s1.rend());
    std::string rev_s2(s2.rbegin(), s2.rend());
    int carry = 0;
    std::string res;
    int i = 0, j = 0;
    while(i<rev_s1.length() && j<rev_s2.length()) {
        int sum = rev_s1[i] - '0' + rev_s2[j] - '0' + carry;
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
        i++;
        j++;
    }
    if (i < rev_s1.length()) {
        while(i < rev_s1.length()) {
            int sum = rev_s1[i] - '0' + carry;
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
            i++;
        }
    }
    if (j < rev_s2.length()) {
        while(j < rev_s2.length()) {
            int sum = rev_s2[j] - '0' + carry;
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
            j++;
        }
    }
    if (carry > 0) {
        res.push_back(carry + '0');
    }
    return std::string(res.rbegin(), res.rend());
}

// HJ59
bool find_first_unique_char(const std::string& s, char& res) {
    std::vector<int> cnt;
    std::vector<char> chars;
    for (int i=0; i<s.length(); i++) {
        if (std::find(chars.begin(), chars.end(), s[i]) == chars.end()) {
            chars.push_back(s[i]);
            cnt.push_back(1);
        }
        else {
            int idx = std::find(chars.begin(), chars.end(), s[i]) - chars.begin();
            cnt[idx]++;
        }
    }
    for (int i=0; i<cnt.size(); i++) {
        if (cnt[i] == 1) {
            res = chars[i];
            return true;
        }
    }
    return false;
}

// HJ63
std::string dna_sequence(const std::string& s, int n) {
    if (s.length() < n) return "";
    if (s.length() == n) return s;
    std::string res;
    int final_l = 0;
    int final_r = n-1;
    int max_cnt = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == 'G' || s[i] == 'C') {
            max_cnt++;
        }
    }
    int curr_cnt = max_cnt;
    for (int i=n; i<s.length(); i++) {
        if (s[i] == 'G' || s[i] == 'C') {
            curr_cnt++;
        }
        if (s[i-n] == 'G' || s[i-n] == 'C') {
            curr_cnt--;
        }
        if (curr_cnt > max_cnt) {
            max_cnt = curr_cnt;
            final_l = i - n + 1;
            final_r = i;
        }
    }
    return s.substr(final_l, n);
}

// HJ65
std::string longest_common_substring(const std::string& s1, const std::string& s2) {
    std::string s_short, s_long;
    if (s1.length() < s2.length()) {
        s_short = s1;
        s_long = s2;
    } else {
        s_short = s2;
        s_long = s1;
    }
    int max_len = 0;
    std::string res;
    for (int i=0; i<s_short.length(); i++) {
        for (int j=i; j<s_short.length(); j++) {
            std::string sub = s_short.substr(i, j-i+1);
            if (s_long.find(sub) != std::string::npos) {
                if (sub.length() > max_len) {
                    max_len = sub.length();
                    res = sub;
                }
            }
        }
    }
    return res;
}

// HJ70
int matrix_multiply(const std::vector<std::pair<int, int>>& matrix, const std::string& s) {
    int res = 0;
    int matrix_idx = 0;
    std::stack<std::pair<int, int>> st;
    for (int i=0; i<s.length(); i++) {
        if (s[i] == '(') {
            continue;
        } else if (s[i] == ')') {
            // A * B
            auto B = st.top(); // B
            st.pop();
            auto A = st.top(); // A
            st.pop();
            if (A.second != B.first) {
                return -1;
            }
            res += A.first * A.second * B.second;
            st.push(std::make_pair(A.first, B.second));
        }
        else {
            st.push(std::make_pair(matrix[matrix_idx].first, matrix[matrix_idx].second));
            matrix_idx++;
        }
    }
    return res;
}

// HJ72
bool wildcard_match(const std::string& patten, const std::string& words) {
    int n = patten.length();
    int m = words.length();
    std::vector<std::vector<bool>> dp(n+1, std::vector<bool>(m+1, false));
    dp[0][0] = true;
    for (int i=1; i<=n; i++) {
        char ch1 = patten[i-1];
        dp[i][0] = dp[i-1][0] && ch1 == '*';
        for (int j=1; j<=m; j++) {
            if (patten[i-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            } else {
                char ch2 = words[j-1];
                if (isalpha(ch2)) {
                    dp[i][j] = dp[i-1][j-1] && (ch1 == '?' || ch1 == ch2 || (ch1 == (ch2 - 'a' + 'A')) || (ch1 == (ch2 - 'A' + 'a')));
                }
                else if (isdigit(ch2)) {
                    dp[i][j] = dp[i-1][j-1] && (ch1 == '?' || ch1 == ch2);
                }
                else {
                    dp[i][j] = dp[i-1][j-1] && ch1 == ch2;
                }
            }
        }
    }
    return dp[n][m];
}

// HJ74
std::vector<std::string> parse_args(const std::string& s) {
    if (s.length() == 0) return {};
    std::vector<std::string> res;
    int begin = 0;
    int end = 0;
    bool find_quote = false;
    for (int i=0; i<s.length(); i++) {
        if (s[i] == ' ' && !find_quote) {
            end = i;
            res.push_back(s.substr(begin, end - begin));
            begin = i + 1;
        }
        else if (s[i] == '"') {
            if (find_quote) {
                end = i;
                res.push_back(s.substr(begin, end - begin));
                begin = i + 2;
                i++;
                find_quote = false;
            } else {
                begin = i + 1;
                find_quote = true;
            }
        }
    }
    if (begin < s.length()) {
        res.push_back(s.substr(begin));
    }
    return res;
}

// HJ75
int longest_common_substring_v2(const std::string& s1, const std::string& s2) {
    std::string s_short, s_long;
    if (s1.length() < s2.length()) {
        s_short = s1;
        s_long = s2;
    } else {
        s_short = s2;
        s_long = s1;
    }
    for (int i=s_short.length(); i>0; i--) {
        for (int j=0; j<=s_short.length()-i; j++) {
            std::string sub = s_short.substr(j, i);
            if (s_long.find(sub) != std::string::npos) {
                return i;
            }
        }
    }
    return 0;
}

// HJ88
int pukeType(const std::vector<std::string>& vecs) {
    if (vecs.size() == 1) return 1; // single
    if (vecs.size() == 2) {
        if (vecs[0] == vecs[1]) return 2; // double
        if ((vecs[0] == "joker" && vecs[1] == "JOKER") 
            || (vecs[1] == "joker" && vecs[0] == "JOKER")) return 6; // joker
        return -1;
    }
    if (vecs.size() ==  3) return 3; // three
    if (vecs.size() == 4) return 4; // bomb
    if (vecs.size() == 5) return 5; // serial
    return -1;
}

int diffTypeComp(int type1, int type2) {
    if (type1 == 6) return 0;
    if (type2 == 6) return 1;
    if (type1 == 4) return 0;
    if (type2 == 4) return 1;
    return -1;
}

std::vector<std::string> split_str(const std::string& str) {
    std::vector<std::string> res;
    int idx = 0;
    for (int i=0; i<str.length(); i++) {
        if (str[i] == ' ' && i > idx) {
            res.push_back(str.substr(idx, i-idx));
            idx = i + 1;
        }
    }
    if (idx < str.length()) {
        res.push_back(str.substr(idx));
    }
    return res;
}

std::string puke_compare(const std::string& s1, const std::string& s2) {
    std::unordered_map<std::string, int> puke_map = {
        {"3", 0}, {"4", 1}, {"5", 2}, {"6", 3}, {"7", 4}, {"8", 5}, {"9", 6}, {"10", 7},
        {"J", 8}, {"Q", 9}, {"K", 10}, {"A", 11}, {"2", 12}, {"joker", 13}, {"JOKER", 14}
    };
    std::vector<std::string> vecs1 = split_str(s1);
    std::vector<std::string> vecs2 = split_str(s2);
    int type1 = pukeType(vecs1);
    int type2 = pukeType(vecs2);
    if (type1 == -1 || type2 == -1) return "ERROR";
    if (type1 == type2) {
        return puke_map[vecs1[0]] > puke_map[vecs2[0]] ? s1 : s2;
    }
    int ret = diffTypeComp(type1, type2);
    if (ret == 0) return s1;
    if (ret == 1) return s2;
    return "ERROR";
}

// HJ89
bool is24(const std::vector<int>& nums, const std::vector<int>& ops) {
    std::vector<int> nums_copy = nums;
    for (int i=0; i<3; i++) {
        if (ops[i] == 0) {
            nums_copy[i+1] += nums_copy[i];
        } else if (ops[i] == 1) {
            nums_copy[i+1] = nums_copy[i] - nums_copy[i+1];
        } else if (ops[i] == 2) {
            nums_copy[i+1] *= nums_copy[i];
        } else if (ops[i] == 3) {
            nums_copy[i+1] = nums_copy[i] / nums_copy[i+1];
        }
    }
    return nums_copy[3] == 24;
}

std::string twenty_four_arithmetic(const std::string& s) {
    std::vector<std::string> items = split_str(s);
    for (const auto& item: items) {
        if (item == "joker" || item == "JOKER") {
            return "ERROR";
        }
    }
    std::vector<int> nums;
    std::unordered_map<std::string, int> puke2num = {
        {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10},
        {"J", 11}, {"Q", 12}, {"K", 13}, {"A", 1}, {"2", 2}
    };
    std::unordered_map<int, std::string> num2puke = {
        {3, "3"}, {4, "4"}, {5, "5"}, {6, "6"}, {7, "7"}, {8, "8"}, {9, "9"}, {10, "10"},
        {11, "J"}, {12, "Q"}, {13, "K"}, {1, "A"}, {2, "2"}
    };

    std::unordered_map<int, std::string> num2op = {
        {0, "+"}, {1, "-"}, {2, "*"}, {3, "/"}
    };

    for (const auto& item: items) {
        nums.push_back(puke2num[item]);
    }
    std::sort(nums.begin(), nums.end());
    bool flag;
    std::vector<int> ops(3, -1);
    do {

        // if (nums[0] == 1 && nums[1] == 13 && nums[2] == 2 && nums[3] == 4) {
        //     printf("debug\n");
        // }

        for (int i=0; i<4&& !flag; i++) {
            ops[0] = i;
            for (int j=0; j<4&&!flag; j++) {
                ops[1] = j;
                for (int k=0; k<4&&!flag; k++) {
                    ops[2] = k;
                    // if (ops[0] == 0 && ops[1] == 2 && ops[2] == 1) {
                    //     printf("debug\n");
                    // }
                    if(is24(nums, ops)) {
                        flag = true;
                        std::string res = num2puke[nums[0]] + num2op[ops[0]] + \
                                          num2puke[nums[1]] + num2op[ops[1]] + \
                                          num2puke[nums[2]] + num2op[ops[2]] + num2puke[nums[3]];
                        return res;
                    }
                }
            }
        }
    } while (std::next_permutation(nums.begin(), nums.end()));
    return "NONE";
}

// HJ92
std::vector<std::string> longest_number_string(const std::string& s) {
    std::vector<std::string> res;
    if (s.length() == 0) return res;
    int max_len = 0;
    int begin = 0;
    int end = 0;
    int curr_idx = 0;
    while(curr_idx < s.length()) {
        // begin stage
        if (isdigit(s[curr_idx]) && (curr_idx ==0 || !isdigit(s[curr_idx-1]))) {
            begin = curr_idx;
            end = curr_idx;
        }
        else if(isdigit(s[curr_idx])) {
            end++;
        }
        
        if ((!isdigit(s[curr_idx]) || curr_idx == s.length()-1)&& isdigit(s[curr_idx-1])) { // end stage
            if (end - begin+1 > max_len) {
                max_len = end - begin+1;
                res.clear();
                res.push_back(s.substr(begin, end-begin+1));
            }
            else if (end - begin +1 ==  max_len) {
                res.push_back(s.substr(begin, end-begin+1));
            }
        }
        curr_idx++;
    }
    return res;
}

// HJ93
bool group_array(const std::vector<int>& nums) {
    int sum3 = 0;
    int sum5 = 0;
    int res = 0;
    int sum = 0;
    std::vector<int> arr;
    for (const auto num: nums) {
        if (num % 5 == 0) {
            sum5 += num;
        } else if (num % 3 == 0) {
            sum3 += num;
        } else {
            arr.push_back(num);
            res += num;
        }
        sum += num;
    }
    if (sum % 2 != 0) return false;
    // enumerate
    std::unordered_set<int> sum_set;
    sum_set.insert(0);
    for (int i=0; i<arr.size(); i++) {
        std::unordered_set<int> tmp_set = sum_set;
        for (const auto s: tmp_set) {
            sum_set.insert(s + arr[i]);
        }
    }
    for (const auto s: sum_set) {
        if (s + sum5 == sum3 + res - s) return true;
    }
    return false;
}

// HJ98
std::string init_vending_machine(const std::string& s, std::vector<int>& goods, std::vector<int>& coins, int& balance) {
    goods.resize(7, 0);
    coins.resize(11, 0);
    std::istringstream iss(s);
    char tmp;
    iss >> goods[1] >> tmp >> goods[2] >> tmp >> goods[3] >> tmp >> goods[4] >> tmp >> goods[5] >> tmp >> goods[6];
    iss >> coins[1] >> tmp >> coins[2] >> tmp >> coins[5] >> tmp >> coins[10];
    balance = 0;
    return "S001:Initialization is successful";
}

std::string purchase(const std::string& s, std::vector<int>& goods, std::vector<int>& coins, int& balance) {
    int money = std::stoi(s);
    if (money != 1 && money != 2 && money != 5 && money != 10) {
        return "E002:Denomination error";
    }
    if ((money != 1 && money != 2) && coins[1] + coins[2] * 2 < money) {
        return "E003:Change is not enough, pay fail";
    }
    if (goods[1] + goods[2] + goods[3] + goods[4] + goods[5] + goods[6] == 0) {
        return "E005:All the goods sold out";
    }
    balance += money;
    coins[money]++;
    return "S002:Pay success,balance=" + std::to_string(balance);
}

std::string buy(const std::string& s, std::vector<int>& goods, std::vector<int>& coins, int& balance) {
    static std::vector<int> good_prices = {0,2,3,4,5,8,6};
    if (s[0] != 'A') {
        return "E006:Goods does not exist";
    }
    int good_idx = std::stoi(s.substr(1));
    if (good_idx < 1 || good_idx > 6) {
        return "E006:Goods does not exist";
    }
    if (goods[good_idx] == 0) {
        return "E007:The goods sold out";
    }
    if (balance < good_prices[good_idx]) {
        return "E008:Lack of balance";
    }
    balance -= good_prices[good_idx];
    goods[good_idx]--;
    return "S003:Buy success,balance=" + std::to_string(balance);
}

std::string change(std::vector<int>& coins, int& balance) {
    if (balance == 0) {
        return "E009:Work failure";
    }
    std::vector<int> coin_values = {10, 5, 2, 1};
    std::vector<int> coin_nums(4, 0);
    for (int i=0; i<4; i++) {
        int coin = coin_values[i];
        while(balance >= coin && coins[coin] > 0) {
            balance -= coin;
            coin_nums[i]++;
            coins[coin]--;
        }
    }
    return "1 yuan coin number=" + std::to_string(coin_nums[3]) + \
           "\n2 yuan coin number=" + std::to_string(coin_nums[2]) + \
           "\n5 yuan coin number=" + std::to_string(coin_nums[1]) + \
           "\n10 yuan coin number=" + std::to_string(coin_nums[0]);
}

std::string query(const std::string& s, std::vector<int>& goods, std::vector<int>& coins, int& balance) {
    if (s[0] != '0' && s[0] != '1') {
        return "E010:Parameter error";
    }
    if (s[0] == '1') {
        return "1 yuan coin number=" + std::to_string(coins[1]) + \
               "\n2 yuan coin number=" + std::to_string(coins[2]) + \
               "\n5 yuan coin number=" + std::to_string(coins[5]) + \
               "\n10 yuan coin number=" + std::to_string(coins[10]);
    }
    else {
        std::vector<std::pair<int, int>> goods_info = {
            {1, goods[1]}, {2, goods[2]}, {3, goods[3]}, {4, goods[4]}, {5, goods[5]}, {6, goods[6]}
        };
        std::sort(goods_info.begin(), goods_info.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        });

        static std::vector<int> good_prices = {0,2,3,4,5,8,6};
        return "A" + std::to_string(goods_info[0].first) + " " + std::to_string(good_prices[goods_info[0].first]) + " " + std::to_string(goods_info[0].second) + \
               "\nA" + std::to_string(goods_info[1].first) + " " + std::to_string(good_prices[goods_info[1].first]) + " " + std::to_string(goods_info[1].second) + \
               "\nA" + std::to_string(goods_info[2].first) + " " + std::to_string(good_prices[goods_info[2].first]) + " " + std::to_string(goods_info[2].second) + \
                "\nA" + std::to_string(goods_info[3].first) + " " + std::to_string(good_prices[goods_info[3].first]) + " " + std::to_string(goods_info[3].second) + \
                "\nA" + std::to_string(goods_info[4].first) + " " + std::to_string(good_prices[goods_info[4].first]) + " " + std::to_string(goods_info[4].second) + \
                "\nA" + std::to_string(goods_info[5].first) + " " + std::to_string(good_prices[goods_info[5].first]) + " " + std::to_string(goods_info[5].second);
    }
}

std::string vending_machine(const std::string& s, std::vector<int>& goods, std::vector<int>& coins, int& balance) {
    char op = s[0];
    if (op == 'r') {
        return init_vending_machine(s.substr(2), goods, coins, balance);
    } else if (op == 'p') {
        return purchase(s.substr(2), goods, coins, balance);
    } else if (op == 'b') {
        return buy(s.substr(2), goods, coins, balance);
    } else if (op == 'c') {
        return change(coins, balance);
    } else if (op == 'q') {
        return query(s.substr(2), goods, coins, balance);
    }
    return "";
}

} // namespace huawei_online
