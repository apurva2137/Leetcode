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

        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* node = dummy ;

        while(temp != nullptr){
            if(temp->val == val) 
                temp = temp->next;
            else{
                ListNode* newnode = new ListNode(temp->val);
                node->next = newnode;
                node = node->next;
                temp = temp->next;
                
            }
        }
        return dummy->next;
    }
};