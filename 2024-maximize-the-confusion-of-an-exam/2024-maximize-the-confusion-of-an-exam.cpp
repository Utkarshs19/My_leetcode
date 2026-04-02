class Solution {
public:

    int helper(string answerKey,char ch,int k)
    {
        int i=0,j=0;
        int ans=0;
        int cnt=0;

        while(j<answerKey.length())
        {
            if(answerKey[j]==ch)cnt++;

            while(cnt>k)
            {
                if(answerKey[i]==ch)cnt--;
                i++;
            }

            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        
        return max(helper(answerKey,'T',k),helper(answerKey,'F',k));

    }
};