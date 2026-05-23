/**
 * Definition for doubly-linked list.
 * class Node {
 *     int val;
 *     Node* prev;
 *     Node* next;
 *     Node() : val(0), next(nullptr), prev(nullptr) {}
 *     Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *     Node(int x, Node *prev, Node *next) : val(x), next(next), prev(prev) {}
 * };
 */
class Solution {
public:
	vector<int> toArray(Node *node){

        vector<int> ans;
        Node* n=node;
        while(n)
        {
            ans.push_back(n->val);
            n=n->prev;
        }
        reverse(ans.begin(),ans.end());
        node=node->next;
        while(node)
        {
            ans.push_back(node->val);
            node=node->next;
        }

        return ans;
        
    }
};