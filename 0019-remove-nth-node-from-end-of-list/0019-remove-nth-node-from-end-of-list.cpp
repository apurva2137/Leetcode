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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return nullptr;

        ListNode* temp = head;
        int len = 0;

        while(temp){
            len++;
            temp = temp->next;
        }
        temp = head;
        if(len == n)
        {
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }

        int diff = len - n;

        if(diff < 0) return head;

        int count = 1;

        while(count < diff){
            temp = temp->next;
            count++;
        }
        ListNode* todel = temp->next;
        temp->next = temp->next->next;
        delete todel;
        return head;
    }
};