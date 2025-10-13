class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {

        vector<string> ans;

        ans.push_back(words[0]);


        for(int i=1;i<words.size();i++)
        {
            string x=ans.back();
            string y=words[i];

            sort(x.begin(),x.end());
            sort(y.begin(),y.end());

            if(x!=y)
            ans.push_back(words[i]);
        }
        
        return ans;
    }
};