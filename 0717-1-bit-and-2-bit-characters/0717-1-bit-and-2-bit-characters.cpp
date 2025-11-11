class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        for(int i=0;i<bits.size();i++)
        {
            if(bits[i]==1)
            {
                if(i+1==bits.size()-1)return false;
                i+=1;
            }
        }

        return true;

    }
};