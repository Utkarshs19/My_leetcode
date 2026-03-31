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
    ListNode* rev(ListNode* head)
    {
        ListNode* prev=nullptr;
        ListNode* cur=head;

        while(cur)
        {
            ListNode* temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }

        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {

        head=rev(head);

        stack<int> st;

        vector<int> ans;

        while(head)
        {
            while(!st.empty() && head->val>=st.top())
            {
                st.pop();
            }
            if(st.empty())ans.push_back(0);
            else
            ans.push_back(st.top());
            st.push(head->val);
            head=head->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};