class Solution {
public:

    set<string> st;

    void helper(int i,string &str)
    {
        if(i==str.length())
        {
            st.insert(str);
            return;
        }

        for(int j=i;j<str.length();j++)
        {
            swap(str[j],str[i]);
            helper(i+1,str);
            swap(str[j],str[i]);
        }
    }

    void subsets(int i,string &tiles,string str)
    {
        if(i==tiles.length())
        {
            if(str=="")return;
            
            helper(0,str);
            return;
        }

        str+=tiles[i];
        subsets(i+1,tiles,str);
        str.pop_back();
        subsets(i+1,tiles,str);
    }

    int numTilePossibilities(string tiles) {
        
        subsets(0,tiles,"");

        return st.size();
    }
};