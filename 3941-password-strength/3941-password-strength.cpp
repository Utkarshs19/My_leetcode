class Solution {
public:
    int passwordStrength(string password) {

        int ans=0;  
        set<char> st;

        for(int i=0;i<password.length();i++)
        {
            if(st.count(password[i]))continue;
            if(isalpha(password[i]) && islower(password[i]))ans+=1;
            else if(isalpha(password[i]) && isupper(password[i]))ans+=2;
            else if(isdigit(password[i]))ans+=3;
            else
            ans+=5;
            st.insert(password[i]);
        }
        return ans;
        
    }
};