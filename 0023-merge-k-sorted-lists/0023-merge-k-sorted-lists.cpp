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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* ans=new ListNode(-1);
        ListNode* cur=ans;

        while(true)
        {
            int mini=INT_MAX;
            int idx=-1;

            for(int i=0;i<lists.size();i++)
            {
                if(lists[i])
                {
                    if(mini>lists[i]->val)
                    {
                        mini=lists[i]->val;
                        idx=i;
                    }
                }
            }

            if(idx==-1)break;

            cur->next=lists[idx];
            cur=cur->next;
            lists[idx]=lists[idx]->next;
        }
        
        return ans->next;
    }
};