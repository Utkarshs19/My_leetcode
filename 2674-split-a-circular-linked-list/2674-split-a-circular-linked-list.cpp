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
    vector<ListNode*> splitCircularLinkedList(ListNode* list) {

        vector<ListNode*> ans;
        int len=0;
        ListNode* cur=list;
        while(cur)
        {
            len++;
            if(cur->next==list)break;
            cur=cur->next;
        }
        int x;
        if(len%2==1)
        {
            x=(len+1)/2;
        }
        else
        x=len/2;
        
        len=len-x;
        ListNode* first=list;
       
        ListNode* prev=nullptr;

        while(x>0)
        {
            prev=first;
            first=first->next;
            x--;
        }

        
        prev->next=list;

        ans.push_back(list);

        ListNode* t=first;
        prev=nullptr;
        while(len>0)
        {
            len--;
            prev=first;
            first=first->next;
        }

        prev->next=t;

        ans.push_back(t);



        

        return ans;
        
    }
};