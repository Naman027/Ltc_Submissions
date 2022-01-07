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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    vector<int> ar;
    Solution(ListNode* head) {
        ListNode* root=head;
        while(root!=nullptr){
            ar.push_back(root->val);
            root=root->next;
        }
        
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int n=ar.size();
        int ind=rand()%n;
        return ar[ind];
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */