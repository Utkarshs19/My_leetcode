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
        
        set<int> s;

        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }

        ListNode *first=head;
        ListNode *p=nullptr;
        ListNode *ans=first;

        while(first)
        {
            if(s.find(first->val)!=s.end()&&p==nullptr)
            {
                first=first->next;
                ans=ans->next;
            }
            else if(s.find(first->val)!=s.end()&&p!=nullptr)
            {
                p->next=first->next;
                first=first->next;
            }
            else {
                p=first;
                first=first->next;
                }
        }
        return ans;
    }
};