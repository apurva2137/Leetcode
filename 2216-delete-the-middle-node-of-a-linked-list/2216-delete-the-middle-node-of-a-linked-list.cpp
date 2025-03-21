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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL) return NULL;
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        int node=n/2;
        if(node==1 && head->next==NULL) {
            delete head->next;
            return head;
        }
        temp=head;
        for(int i=0;i<node-1;i++){
            temp=temp->next;
        }
        ListNode* t=temp->next;
        temp->next=temp->next->next;
        delete t;
        return head;
    }
};