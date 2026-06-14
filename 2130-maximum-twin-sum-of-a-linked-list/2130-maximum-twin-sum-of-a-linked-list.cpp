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

    ListNode* reverse_list(ListNode *head)
    {
        // cout<<head->val<<"  "<<head->next->val<<endl;
        ListNode *d=nullptr;
        ListNode *n=nullptr;
        while(head){
        n=head->next;
        head->next=d;
        d=head;
        head=n;
        }

        ListNode *p=d;
        while(p)
        {
            cout<<p->val<<" ";
            p=p->next;
        }

        return d;
    }

    int pairSum(ListNode* head) {

        ListNode *slow=head;
        ListNode *fast=head;

        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow=reverse_list(slow);
        int maxi=INT_MIN;
        while(slow)
        {
            if(maxi<(slow->val+head->val))
            maxi=slow->val+head->val;
            slow=slow->next;
            head=head->next;

        }

        return maxi;

        
        
    }
};