class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {

        string s1="",s2="",s3="";

        long long sum1=0;
        long long sum2=0;

        long long sum3=0;

        for(int i=0;i<firstWord.length();i++)
        {
            s1+=to_string(firstWord[i]-'a');
        }

        for(int i=0;i<secondWord.length();i++)
        {
            s2+=to_string(secondWord[i]-'a');
        }

        for(int i=0;i<targetWord.length();i++)
        {
            s3+=to_string(targetWord[i]-'a');
        }

        sum1=stoi(s1);
        sum2=stoi(s2);
        sum3=stoi(s3);

        return sum1+sum2==sum3;

        
    }
};