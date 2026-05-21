class Solution {
public:
    bool canPermutePalindrome(string s) {

        map<char,int> m;

        for(auto i:s)
        {
            m[i]++;
        }

        int odd=0;

        for(auto i:m)
        {
            if(i.second%2==1)odd++;
        }

        return odd<=1;
        
    }
};