class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        
        map<string,int> m;

        for(int k=0;k<cpdomains.size();k++)
        {
            string s=cpdomains[k];

            int i=0,j=s.length()-1;

            while(i<j && isdigit(s[i]))
            {
                i++;
            }

            int x=stoi(s.substr(0,i));


            while(j>=i)
            {
                if(s[j]=='.' || j==i)
                {
                    m[s.substr(j+1)]+=x;
                }
                j--;
            }
        }

        vector<string> ans;


        for(auto i:m)
        {
            ans.push_back(to_string(i.second)+" "+i.first);
        }


        return ans;

    }
};