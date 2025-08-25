class Solution {
public:
    int minimumChairs(string s) {
        
        int count=0;
        int person=0;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='E')
            {
                person++;
                if(count<person)
                count++;
            }
            if(s[i]=='L')
            {
                person--;
            }
        }
        return count;

    }
};