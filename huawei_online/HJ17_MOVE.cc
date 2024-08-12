#include "../huawei_online.h"

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

} // namespace huawei_online
