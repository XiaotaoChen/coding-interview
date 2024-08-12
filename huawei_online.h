#ifndef HUAWEI_ONLINE_IMPLS
#define HUAWEI_ONLINE_IMPLS

#include <vector>
#include <string>
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


} // namespace huawei_online


#endif