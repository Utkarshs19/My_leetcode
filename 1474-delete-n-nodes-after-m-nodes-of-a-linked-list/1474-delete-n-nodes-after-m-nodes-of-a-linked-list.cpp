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
    ListNode* deleteNodes(ListNode* head, int m, int n) {

        bool flag=true;
        ListNode* cur=head;
        ListNode* prev;
        int x=m,y=n;
        while(cur)
        {
            x=m,y=n;
            if(flag)
            {
                while(cur && x>0)
                {
                    prev=cur;
                    cur=cur->next;
                    x--;
                }
                flag=!flag;
            }
            else
            {
                while(cur && y>0)
                {
                    cur=cur->next;
                    y--;
                }
                prev->next=cur;
                flag=!flag;
            }
        }

        return head;
        
    }
};