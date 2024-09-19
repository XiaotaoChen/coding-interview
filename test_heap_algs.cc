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
#include "heap_algs.h"

using namespace std;


/*
70. 求第k大的数： 维护一个大小为k的最小堆，或使用快排找mid_indx是否为k，进而调整left，right
1. 构建最小堆，
2. 遍历k->n的数据，如果nums[i]>nums[0]则交换两者，并对堆进行调整
3. 调整堆： while(son<=end) {
    if (son+1<=end && nums[son]>nums[son+1]) son++;
    if (nums[dad]<nums[son]) return;
    swap(nums[dad], nums[son]);
    dad = son;
    son = 2 * dad + 1;
}
*/
void test_find_k_largest() {
    std::vector<int> nums = {3,2,1,5,6,4};; // {7,6,5,4,3,2,1}; //{3,2,1,5,6,4};
    int k = 5; //5; //2;
    // int result = heap::findKthLargest(nums, k);
    int result = heap::findKthLargest_v2(nums, k);
    printf("result:%d\n", result);
}


/*
71. 合并k个list.
递归合并list.
mergelists(vector_list, 0, k)
*/
void test_merge_k_list() {
    std::vector<ListNode*> lists;
    ListNode* root1 = new ListNode(1);
    root1->next = new ListNode(4);
    root1->next->next = new ListNode(5);
    ListNode* root2 = new ListNode(1);
    root2->next = new ListNode(3);
    root2->next->next = new ListNode(4);
    ListNode* root3 = new ListNode(2);
    root3->next = new ListNode(6);
    lists.push_back(root1);
    lists.push_back(root2);
    lists.push_back(root3);
    ListNode* root = heap::mergeKLists(lists);
    while(root!=nullptr) {
        printf("%d ", root->val);
        root = root->next;
    }
    printf("\n");
}


int main() {
    test_find_k_largest();
    // test_merge_k_list();
    return 0;
}
