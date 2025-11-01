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

    ListNode* removeElements(ListNode* head, const unordered_set<int>& nums_set) {
    ListNode* dummy = new ListNode(); 
    dummy->next = head;       
    ListNode* prev = dummy;
    ListNode* curr = head;

    while (curr != nullptr) {
        if (nums_set.find(curr->val) != nums_set.end()) {
            prev->next = curr->next;
            delete curr;
        } else {
            prev = curr; 
        }
        curr = prev->next; 
    }

    head = dummy->next;
    delete dummy;
    return head;
}
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> nums_set(nums.begin(), nums.end());        
        return removeElements(head,nums_set);
    }
};