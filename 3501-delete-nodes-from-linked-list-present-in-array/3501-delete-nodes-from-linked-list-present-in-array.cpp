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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
         unordered_set<int> numSet(nums.begin(), nums.end());
         ListNode* temp = head;
         ListNode* dummy = new ListNode(-1);
         ListNode* y = dummy;
         while(temp){
            int val = temp->val;
            if(numSet.find(val) == numSet.end()){
                y->next = new ListNode(val);
                y = y->next;
            }
            temp = temp->next;
         }
        return dummy->next;
    }
};