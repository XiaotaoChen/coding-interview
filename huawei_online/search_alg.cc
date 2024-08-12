#include "../huawei_online.h"
#include <vector>
#include <queue>

namespace huawei_online
{
// search alg
// HJ43
bool dfs(const std::vector<std::vector<int>>& maze, std::vector<std::vector<bool>>& visited, int x, int y, std::vector<std::pair<int,int>>& curr) {
    if (x < 0 || x >= maze.size() || y < 0 || y >= maze[0].size() || visited[x][y] || maze[x][y] == 1) {
        return false;
    }
    visited[x][y] = true;
    curr.push_back(std::make_pair(x, y));
    if (x == maze.size()-1 && y == maze[0].size()-1) {
        return true;
    }
    if (dfs(maze, visited, x+1, y, curr)) return true;
    if (dfs(maze, visited, x-1, y, curr)) return true;
    if (dfs(maze, visited, x, y+1, curr)) return true;
    if (dfs(maze, visited, x, y-1, curr)) return true;
    curr.pop_back();
    visited[x][y] = false;
    return false;
}

bool bfs(const std::vector<std::vector<int>>& maze, std::vector<std::vector<bool>>& visited, std::vector<std::pair<int,int>>& curr) {
    int n = maze.size();
    int m = maze[0].size();
    std::vector<std::vector<std::pair<int,int>>> path_map(n, std::vector<std::pair<int, int>>(m, std::pair<int, int>(-1, -1)));

    std::vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == maze.size()-1 && y == maze[0].size()-1) {
            break;
        }

        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < maze.size() && ny >= 0 && ny < maze[0].size() && !visited[nx][ny] && maze[nx][ny] != 1) {
                q.push({nx, ny});
                path_map[nx][ny] = {x, y};
                visited[nx][ny] = true;
            }
        }
    }

    curr.clear();
    curr.push_back({n-1, m-1});
    while(1) {
        auto [x,y] = curr.back();
        if (x == 0 && y == 0) break;
        curr.push_back({path_map[x][y].first, path_map[x][y].second});
    }
    std::reverse(curr.begin(), curr.end());
    return true;
}

std::vector<std::pair<int,int>> maze_problem(const std::vector<std::vector<int>>& maze) {
    std::vector<std::vector<bool>> visited(maze.size(), std::vector<bool>(maze[0].size(), false));
    std::vector<std::pair<int, int>> curr;
    // bool flag = dfs(maze, visited, 0, 0, curr);
    bool flag = bfs(maze, visited, curr);
    if (!flag) return {};
    return curr;
}

// HJ60 查找组成一个偶数最接近的两个素数

bool is_prime_v2(int n) {
    if (n < 2) return false;
    for(int i=2; i*i<=n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

std::pair<int, int> find_prime_pair(int n) {
    int half = n / 2;
    for(int i=half; i>=2; i--) {
        if (is_prime_v2(i) && is_prime_v2(n-i)) {
            return {i, n-i};
        }
    }
    return {0,0};
}

// HJ85 最长回文子串

int max_length(const std::string& s, int left, int right) {
    while(left <= right) {
        if (s[left] != s[right]) return right - left - 1;
        left--;
        right++;
        if (left <0 || right >= s.length()) return right - left - 1;
    }
    return -1;
}

int longest_palindrome(const std::string& s) {
    int n= s.length();
    if (n < 2) return n;
    int max_len = 1;
    // int start = 0;
    for (int i=1; i<n; i++) {
        int len1 = max_length(s, i, i);
        int len2 = max_length(s, i-1, i);
        if (max_len < len1) {
            max_len = len1;
            // start = i - len1 / 2;
        }
        if (max_len < len2) {
            max_len = len2;
            // start = i - len2 / 2;
        }
    }
    return max_len;
}

// HJ86 求最大连续bit数
int max_continuous_bit(int n) {
    int max_len = 0;
    int curr_len = 0;
    while(n) {
        if (n & 1) {
            curr_len++;
        } else {
            max_len = std::max(max_len, curr_len);
            curr_len = 0;
        }
        n >>= 1;
    }
    max_len = std::max(max_len, curr_len);
    return max_len;
}


} // namespace huawei_online