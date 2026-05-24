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
    ListNode* sortLinkedList(ListNode* head) {

        vector<int> v;

        ListNode* t=head;

        while(t)
        {
            if(t->val<0)v.push_back(t->val);
            t=t->next;
        }

        reverse(v.begin(),v.end());

        ListNode* ans=new ListNode(-1);
        ListNode* cur=ans;

        for(int i=0;i<v.size();i++)
        {
            ListNode* temp=new ListNode(v[i]);
            cur->next=temp;
            cur=cur->next;
        }

        t=head;
        while(t)
        {
            if(t->val>=0)
            {
                ListNode* temp=new ListNode(t->val);
                cur->next=temp;
                cur=cur->next;
            }
            t=t->next;
        }

        return ans->next;
        
    }
};