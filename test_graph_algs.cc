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
#include "graph_algs.h"

using namespace std;


/*
55. 克隆图，类似8.
*/
void test_clone_graph2() {
    graphNode* head = new graphNode(1);
    graphNode* node2 = new graphNode(2);
    graphNode* node3 = new graphNode(3);
    graphNode* node4 = new graphNode(4);
     
    head->neighbors.push_back(node2);
    head->neighbors.push_back(node4);
    node2->neighbors.push_back(head);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(head);
    node4->neighbors.push_back(node3);

    graphNode* copy_head = graph::cloneGraph(head);
    
    std::set<int> visited;
    std::queue<graphNode*> q;
    graphNode* curr = copy_head;
    q.push(curr);
    while(!q.empty()) {
        curr = q.front();
        q.pop();
        if (visited.find(curr->val) != visited.end()) continue;
        visited.insert(curr->val);
        printf("%d: ", curr->val);
        for (int i=0; i<curr->neighbors.size(); i++) {
            printf("%d ", curr->neighbors[i]->val);
            if (visited.find(curr->neighbors[i]->val) == visited.end()) q.push(curr->neighbors[i]);
        }
        printf("\n");
    }
}

/*
56. 判断课程之间的依赖关系，是否可以正常完成课程。即判断拓扑结构中不存在环
队列中保存入度为0的节点，直到遍历完所有节点。
*/
void test_can_finish() {
    std::vector<std::vector<int>>  data = {{0,1}, {0,2}, {1,2}};
    bool result = graph::canFinish(3, data);
    printf("result:%d\n", result);
}

/*
57. 类似56, 保留visit顺序
*/
void test_find_order() {
    std::vector<std::vector<int>>  data = {{0,1}, {0,2}, {1,2}};
    std::vector<int> result = graph::findOrder(3, data);
    for (int i=0; i<result.size(); i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

/*
58. 将graph转化为树，使其高度最低。
记录每个点的出入度，依次遍历degree=1的点，直到剩下最后1或2个。
*/
void test_find_highest_node() {
    std::vector<std::vector<int>> edges={{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}}; //{{1,0},{1,2},{1,3}};
    std::vector<int> result = graph::findMinHeightTrees(6, edges);
    for (int i=0; i<result.size(); i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}



int main() {
    test_clone_graph2();
    // test_can_finish();
    // test_find_order();
    // test_find_highest_node();
    return 0;
}
