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
    
    ListNode* reverse(ListNode* root)
    {
        if(!root)return nullptr;
        ListNode* cur=root;
        ListNode* prev=nullptr;
        
        while(cur)
        {
            ListNode* temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        ListNode* ans=new ListNode(-1);
        ListNode* cur=ans;
        int carry=0;
        
        while(l1 && l2)
        {
            ListNode* temp=new ListNode((l1->val+l2->val+carry)%10);
            carry=(l1->val+l2->val+carry)/10;
            cur->next=temp;
            cur=cur->next;
            l1=l1->next;
            l2=l2->next;
        }
        
        
        while(l1)
        {
            ListNode* temp=new ListNode((l1->val+carry)%10);
            carry=(l1->val+carry)/10;
            cur->next=temp;
            cur=cur->next;
            l1=l1->next;
        }
        
        while(l2)
        {
            ListNode* temp=new ListNode((l2->val+carry)%10);
            carry=(l2->val+carry)/10;
            cur->next=temp;
            cur=cur->next;
            l2=l2->next;
        }
        
        if(carry)
        {
            ListNode* temp=new ListNode(carry);
            cur->next=temp;
        }
        
        return ans->next;        
        
    }
};