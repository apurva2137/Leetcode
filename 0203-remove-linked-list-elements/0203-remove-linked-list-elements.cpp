/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr || head->next==nullptr && head->val == val)
         return nullptr;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy ; 
        ListNode* temp = head;
        while(temp){
            if(temp->val == val) 
                prev->next = temp->next;
            else
               prev = prev->next;
            
           temp = temp->next;
        }
        return dummy->next;
    }
};