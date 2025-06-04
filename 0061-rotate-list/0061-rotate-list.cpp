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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0) return head;
        ListNode* temp = head;
        int n = 1;
        while(temp->next !=NULL){
            temp = temp->next;
            n++;
        }

        k = k % n;
        int shift = n - k;
        if(shift!=0 ) temp->next = head;
        temp = head;
        shift--;
        while(shift){
            temp = temp->next;
            shift--;
        }
        ListNode* nextnode = temp->next;
        temp->next = NULL;
        head = nextnode;
        return head;
    }
};