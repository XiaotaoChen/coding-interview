#include <vector>
#include "../search_algs.h"

namespace search
{

int maxProfit_v4(std::vector<int>& prices) {
    if (prices.size()<2) return 0;
    int res = 0;
    int result = 0;
    for (int i=1; i<prices.size(); i++) {
        if (res <0) res = prices[i] - prices[i-1];
        else res += prices[i] - prices[i-1];
        result  = result > res ? result : res;
    }
    return result;
}

int maxProfit_v5(std::vector<int>& prices) {
    if (prices.size() <2)return 0;
    int min_val = prices[0];
    int res = 0;
    for (int i=1; i<prices.size(); i++) {
        res = std::max(res, prices[i]-min_val);
        min_val = std::min(min_val, prices[i]);
    }
    return res;
}

} // namespace search
