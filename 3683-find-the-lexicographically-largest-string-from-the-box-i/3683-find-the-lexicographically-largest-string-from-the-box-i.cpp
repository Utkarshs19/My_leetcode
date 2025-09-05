class Solution {
public:
    string answerString(string word, int numFriends) {
        
        if(numFriends==1)return word;
        priority_queue<string> pq;

        int n=word.length();

        for(int i=0;i<n;i++)
        {
            pq.push(word.substr(i,n-numFriends+1));
        }

        return pq.top();
        
    }
};