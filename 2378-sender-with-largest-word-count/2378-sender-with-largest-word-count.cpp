class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {

        map<string,int> m;
        int maxi=INT_MIN;

        for(int i=0;i<senders.size();i++)
        {
            string str=messages[i];
            str+=' ';
            int k=0;
            string s="";
            while(k<str.length())
            {
                if(str[k]==' ')
                {
                    m[senders[i]]++;
                    s="";
                }
                else
                {
                    s+=str[k];
                }
                k++;
            }

            maxi=max(maxi,m[senders[i]]);
        }
        

        for(auto it=m.rbegin();it!=m.rend();++it)
        {
            if(it->second==maxi)
            return it->first;
        }

        return "";


    }
};