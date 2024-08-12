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
#include "huawei_online.h"

using namespace std;

void test_move() {
    std::string s="A10;S20;W10;D30;X;A1A;B10A11;;A10;";
    std::pair<int, int> p(0, 0);
    huawei_online::move_alg(s, p);
    printf("%d,%d\n", p.first, p.second);
    return;
}


int main() {
    test_move();
    return 0;
}
