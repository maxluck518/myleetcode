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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head ->next == nullptr)
            return head;
        ListNode * fast = head->next;
        ListNode * slow = head;
        ListNode * head2;
        while(fast->next != nullptr && fast->next->next !=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        head2 = slow->next;
        slow->next = nullptr;
        return merge(sortList(head),sortList(head2));
    }
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode *ret = new ListNode(0);
        ListNode *tos = ret;
        while(head2 != nullptr || head1 != nullptr)
        {
            if(head1 == nullptr && head2 != nullptr){
                tos->next = head2;
                head2 = nullptr;
            }
            else if(head2 == nullptr && head1 != nullptr){
                tos->next = head1;
                head1 = nullptr;
            }
            else if(head2->val >= head1->val){
                tos ->next = head1;
                tos = head1;
                head1 = head1->next;
            }
            else{
                tos ->next = head2;
                tos = head2;
                head2 = head2->next;
            }
        }
        return ret->next;
    }
};
