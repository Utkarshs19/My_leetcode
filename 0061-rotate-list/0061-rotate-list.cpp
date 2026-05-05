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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr)return head;
        int size=0;
        ListNode* cur=head;
        while(cur)
        {
            size++;
            cur=cur->next;
        }

        int x=k%size;

        while(x>0)
        {
            ListNode* first=head;
            ListNode* second=head->next;

            while(second->next)
            {
                first=first->next;
                second=second->next;
            }
            first->next=nullptr;
            second->next=head;
            head=second;
            x--;
        }

        return head;

        
    }
};