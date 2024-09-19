#include <map>
#include <vector>
#include <string>
#include "../search_algs.h"

namespace search
{

std::vector<std::vector<std::string>> groupAnagrams_v2(std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> result;

    std::map<std::map<char, int>, std::vector<std::string>> mpps;
    for (int i=0; i<strs.size(); i++) {
        std::map<char, int> mp;
        for (int j=0; j < strs[i].length(); j++) {
            mp[strs[i][j]]++;
        }
        mpps[mp].push_back(strs[i]);
    }
    for (auto& p: mpps) {
        result.push_back(p.second);
    }
    return result;
}

std::vector<std::vector<std::string>> groupAnagrams_v3(std::vector<std::string>& strs) {
    std::unordered_map<std::string, int> map_ids;
    std::vector<std::vector<std::string>> res;
    for (const auto& str: strs) {
        std::string tmp = str;
        std::sort(tmp.begin(), tmp.end());
        if (map_ids.find(tmp) != map_ids.end()) {
            res[map_ids[tmp]].push_back(str);
        }
        else {
            map_ids[tmp] = res.size();
            res.push_back({str});
        }
    }
    return res;
}

} // namespace search
