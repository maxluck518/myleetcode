/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp{
    bool operator()(const ListNode* l1,const ListNode* l2){
        return l1->val > l2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        ListNode* head = new ListNode(0);
        ListNode* pos = head;
        int k = lists.size();
        for(int i = 0;i<k;i++){
            if(lists[i] != NULL){
                q.push(lists[i]);
            }
        }
        while(!q.empty()){
            pos -> next = q.top();
            pos = pos -> next;
            q.pop();
            if(pos->next != NULL){
                q.push(pos->next);
            }
        }
        return head->next;
        
    }
};
