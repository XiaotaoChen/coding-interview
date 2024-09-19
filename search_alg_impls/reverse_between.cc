#include <cstdio>

#include "../search_algs.h"

ListNode* search::reverseBetween(ListNode* head, int m, int n) {
    if (m==n) return head;
    ListNode* pre_m = nullptr;
    ListNode* m_node = nullptr;
    ListNode* tmp_curr = nullptr;
    ListNode* new_head = new ListNode(-1);
    new_head->next = head;
    ListNode* curr = new_head;
    int num = -1;
    while(curr != nullptr) {
        num ++;
        tmp_curr = curr;
        curr = curr->next;
        if (num == m-1) {
            pre_m = tmp_curr;
            m_node = curr;
        }
        // to avoid m == n
        // else if (num == m) {
        //     m_node->next = nullptr;
        // }
        else if (num >m && num <n) {
            tmp_curr->next = pre_m->next;
            pre_m->next = tmp_curr;
        }
        else if (num == n) {
            tmp_curr->next = pre_m->next;
            pre_m->next = tmp_curr;
            m_node->next = curr;
        }
    }
    return new_head->next;
}

ListNode* search::reverseBetweenV2(ListNode* head, int m, int n) {
    if (m == n || head == nullptr) return head;
    ListNode* pre_head = new ListNode(-1);
    pre_head->next = head;
    ListNode* pre = pre_head;
    ListNode* curr = pre_head->next;
    int curr_num = 0;

    ListNode* pre_m_node = nullptr;
    ListNode* m_node = nullptr;

    while(curr != nullptr && curr_num <=n) {
        if (curr_num == m) {
            pre_m_node = pre;
            m_node = curr;
            pre = curr;
            curr = curr->next;
        }
        else if (curr_num >m && curr_num < n) {
            pre = curr;
            curr = curr->next;
            pre->next = pre_m_node->next;
            pre_m_node->next = pre;
        }
        else if (curr_num == n) {
            pre = curr;
            curr = curr->next;
            m_node->next = curr;
            pre->next = pre_m_node->next;
            pre_m_node->next = pre;
        }
        else {
            pre = curr;
            curr = curr->next;
        }
        curr_num++;
    }
    head = pre_head->next;
    delete pre_head;
    return head;
}