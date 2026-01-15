class Solution {
public:
    bool canBeValid(string s, string locked) {

        stack<int> lock;
        stack<int> unlock;

        for(int i=0;i<s.length();i++)
        {
            if(locked[i]=='0')
            unlock.push(i);
            else if(s[i]=='(')
            {
                lock.push(i);
            }
            else if(s[i]==')')
            {
                if(!lock.empty())lock.pop();
                else if(!unlock.empty())unlock.pop();
                else return false;
            }
        }    

        while(!lock.empty() && !unlock.empty())
        {
            if(lock.top()>unlock.top())return false;
            lock.pop();
            unlock.pop();
        }

        if(unlock.size()%2==1)return false;

        return lock.empty() ;
        
    }
};