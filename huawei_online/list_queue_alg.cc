#include "../huawei_online.h"
#include <vector>
#include <stack>

namespace huawei_online
{
// sort alg
// HJ48
ListNode* add_node(ListNode* head, int val, int parent_val) {
    ListNode* node = new ListNode(val);
    ListNode* p = head;
    while (p) {
        if (p->val == parent_val) {
            node->next = p->next;
            p->next = node;
            break;
        }
        p = p->next;
    }
    return head;
}

ListNode* construct_and_delete(std::vector<std::pair<int, int>> inputs, int head_val, int val) {
    ListNode* head = new ListNode(head_val);
    for (const auto& input: inputs) {
        head = add_node(head, input.first, input.second);
    }
    ListNode* p = head;
    ListNode* prev = nullptr;
    while (p) {
        if (p->val == val) {
            if (prev) {
                prev->next = p->next;
            } else {
                head = p->next;
            }
            delete p;
            break;
        }
        prev = p;
        p = p->next;
    }
    return head;
}


bool add_node(ListNodeV2* root, int val, int prev_val) {
    ListNodeV2* curr = root->next;
    while(curr!=nullptr) {
        if (curr->val == prev_val) {
            ListNodeV2* tmp = curr->next;
            curr->next = new ListNodeV2(val);
            curr->next->next = tmp;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool delete_node(ListNodeV2* root, int del_val) {
    if (root->next == nullptr) return false;
    ListNodeV2* pre = root;
    ListNodeV2* curr = pre->next;
    while(curr != nullptr) {
        if (curr->val == del_val) {
            pre->next = curr->next;
            delete curr;
            curr = pre->next;
        }
        else {
            pre = curr;
            curr = curr->next;
        }
    }
    return true;
}

ListNodeV2* construct_and_delete_v2(const std::vector<std::pair<int, int>> node_infos, int head_val, int delete_val) {
    ListNodeV2* root = new ListNodeV2(-1);
    root->next = new ListNodeV2(head_val);
    for (int i=0; i<node_infos.size(); i++) {
        add_node(root, node_infos[i].first, node_infos[i].second);
    }
    // delete
    delete_node(root, delete_val);
    return root->next;
}



// HJ51
int find_kth_node(const std::vector<int>& inputs, int k) {
    ListNode* root = new ListNode(-1);
    ListNode* p = root;
    for(int i=0; i<inputs.size(); i++) {
        p->next = new ListNode(inputs[i]);
        p = p->next;
    }

    ListNode* fast = root;
    ListNode* slow = root;
    for (int i=0; i<k; i++) {
        if (fast) {
            fast = fast->next;
        } else {
            return -1;
        }
    }
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    int val = slow->val;
    p = root;
    while(p) {
        ListNode* tmp = p;
        p = p->next;
        delete tmp;
    }
    return val;
}

// HJ77 火车进站
void dfs(const std::vector<int>& nums, int idx, std::stack<int>& st, std::vector<int>& out_order, std::vector<std::vector<int>>& res) {
    if (idx >= nums.size() && st.empty() == true) {
        res.push_back(out_order);
        return;
    }
    if (idx < nums.size()) {
        st.push(nums[idx]);
        dfs(nums, idx+1, st, out_order, res);
        st.pop();
    }
    if (!st.empty()) {
        out_order.push_back(st.top());
        int tmp = st.top();
        st.pop();
        dfs(nums, idx, st, out_order, res);
        st.push(tmp);
        out_order.pop_back();
    }
    return;
}

std::vector<std::vector<int>> train_in_out(const std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::stack<int> simulate_station;
    std::vector<int> out_order;
    dfs(nums, 0, simulate_station, out_order, res);
    std::sort(res.begin(), res.end());
    return res;
}

} // namespace huawei_online