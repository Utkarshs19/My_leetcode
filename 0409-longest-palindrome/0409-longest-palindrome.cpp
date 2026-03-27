class Solution {
public:
    int longestPalindrome(string s) {
     int ans=0;

     int maxi=0;

     map<char,int> m;

     for(auto i:s)
     m[i]++;

    int cnt=0;
     for(auto i:m)
     {
        if(i.second%2==0)
        ans+=i.second;
        else{
            cnt++;
        ans+=i.second-1;}
     }   

     return cnt==0?ans:ans+1;
    }
};