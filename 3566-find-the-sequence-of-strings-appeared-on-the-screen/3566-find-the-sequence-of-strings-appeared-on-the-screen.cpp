class Solution {
public:
    vector<string> stringSequence(string target) {

        vector<string> ans;
        
        string s="";
        char c='a';
        int i=0;
        while(s!=target)
        {
            s+=c;
            if(c==target[i])
            {
                ans.push_back(s);
                c='a';
                i++;
                continue;

            }
            ans.push_back(s);
           s.pop_back();
            c++;
        }
        return ans;
        
    }
};