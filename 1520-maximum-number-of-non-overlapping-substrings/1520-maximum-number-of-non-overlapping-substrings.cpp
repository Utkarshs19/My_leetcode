class Solution {
public:
    vector<int> start,end;
    vector<bool> isValid;

     vector<string> maxNumOfSubstrings(string s) {

        vector<string> ans;
        int n=s.length();
        start.resize(26,-1);
        end.resize(26,-1);
        isValid.resize(26,true);

        for(int i=0;i<n;i++)
        {
            if(start[s[i]-'a']==-1)
            {
                start[s[i]-'a']=i;
            }
            end[s[i]-'a']=i;
        }

        for(int c=0;c<26;c++)
        {
            if(start[c]==-1)continue;

            for(int i=start[c];i<=end[c];i++)
            {
                if(start[s[i]-'a']<start[c]){
                    isValid[c]=false;
                    break;
                }
                end[c]=max(end[c],end[s[i]-'a']);
            }
        }
        
        int last=INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
            int idx=s[i]-'a';
            if(!isValid[idx])continue;

            if(start[idx]==i && end[idx]<last)
            {
                ans.push_back(s.substr(start[idx],end[idx]-start[idx]+1));
                last=start[idx];
            }
        }
        
        return ans;
        
    }
};