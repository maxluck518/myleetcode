/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode * tos = head->next;
        ListNode * pre = head;
        pre->next = nullptr;
        
        while(tos != nullptr){
            ListNode * next_tos = tos->next;
            tos->next = pre;
            pre = tos;
            tos = next_tos;
        }
        return pre;
    }
};
