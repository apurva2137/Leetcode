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
    ListNode* findkth(ListNode* head, int k){
        ListNode* temp = head;
        k--;
        while(temp && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp=next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
       
        while(temp){

        ListNode* kthnode = findkth(temp , k);
        if(kthnode == NULL) {
            prev->next = temp;
            break;
        } 
        ListNode* nextnode = kthnode->next ;
        kthnode->next = nullptr;
        reverse(temp);
        if(head == temp){
            head = kthnode;
        }
        else{
            prev->next = kthnode;
        }
        prev = temp;
        temp = nextnode;
        }
        return head;
    }
};