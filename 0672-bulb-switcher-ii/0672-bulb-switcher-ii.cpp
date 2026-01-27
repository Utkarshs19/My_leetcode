class Solution {
public:
    int flipLights(int n, int presses) {
        
        n=min(n,6);
        string str(n,'1');

        unordered_set<string> cur,next;

        cur.insert(str);
        while(presses--)
        {
            next.clear();
            
            for(auto s:cur)
            {
                string t=s;
                for(int j=0;j<n;j++)
                {
                    t[j]=(t[j]=='1')?'0':'1';
                }
                next.insert(t);
                
                t=s;

                for(int j=1;j<n;j+=2)
                {
                    t[j]=(t[j]=='1')?'0':'1';
                }
                next.insert(t);
                t=s;
                for(int j=0;j<n;j+=2)
                {
                    t[j]=(t[j]=='1')?'0':'1';
                }
                next.insert(t);
                t=s;
                for(int j=0;j<n;j+=3)
                {
                    t[j]=(t[j]=='1')?'0':'1';
                }
                next.insert(t);
            }

            cur=next;
        }
        return cur.size();
    }
};