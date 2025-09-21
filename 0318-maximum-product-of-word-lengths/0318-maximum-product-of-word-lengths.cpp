class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int maxi=0;


        for(int i=0;i<words.size();i++)
        {
            set<char> st;
            for(auto k:words[i])
            st.insert(k);
            for(int j=i+1;j<words.size();j++)
            {
                bool flag=true;

                for(auto k:words[j]){
                    if(st.find(k)!=st.end())
                    {
                        flag=false;
                        break;
                    }
                }

                if(flag==true)
                maxi=max(maxi,(int)(words[i].length()*words[j].length()));
            }
        }

        return maxi;

    }
};