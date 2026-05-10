class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {

        int score=0,counter=0;

        for(int i=0;i<events.size();i++)
        {
            if(counter>=10)break;
            if(events[i]=="0" || events[i]=="1" || events[i]=="2" || events[i]=="3" || events[i]=="4" || events[i]=="6")
            score+=(stoi(events[i]));

            if(events[i]=="W")counter++;
            if(events[i]=="WD" || events[i]=="NB")score++;
        }


        return {score,counter};
        
    }
};