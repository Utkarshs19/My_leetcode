class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        char x;
        int mini=INT_MAX;

        for(int i=0;i<letters.size();i++)
        {
            if(target==letters[i])continue;

            if(letters[i]>target)
            {
               if(mini> (letters[i]-target))
               {
                 mini=letters[i]-target;
                 x=letters[i];
               }
            }
        }

        return mini==INT_MAX?letters[0]:x;
        
    }
};