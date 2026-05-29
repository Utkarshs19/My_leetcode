/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    map<int,int> m;
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        
        PolyNode* p1=poly1;
        PolyNode* p2=poly2;
        while(p1)
        {
            m[p1->power]+=p1->coefficient;
            p1=p1->next;
        }

        while(p2)
        {
            m[p2->power]+=p2->coefficient;
            p2=p2->next;
        }

        vector<pair<int,int>> v;

        for(auto i:m)
        {
            if(i.second!=0)
            v.push_back({i.first,i.second});
        }

        sort(v.rbegin(),v.rend());

        PolyNode* ans=new PolyNode();
        PolyNode* cur=ans;

        for(int i=0;i<v.size();i++)
        {
            PolyNode* p=new PolyNode(v[i].second,v[i].first);
            cur->next=p;
            cur=cur->next;
        }

        return ans->next;
    }
};