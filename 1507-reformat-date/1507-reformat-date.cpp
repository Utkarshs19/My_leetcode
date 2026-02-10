class Solution {
public:
    string reformatDate(string date) {

        string day;
        string month;
        string year;

        int i=0;

        while(i<date.length())
        {
            while(i<date.length() && date[i]!=' ')
            {
                if(isdigit(date[i]))
                day+=date[i];
                i++;
            }
            if(day.length()==1)
            {
                day+='0';
                reverse(day.begin(),day.end());
            }
            i++;
            while(i<date.length() && date[i]!=' ')
            {

                month+=date[i];
                i++;
            }
            i++;
            while(i<date.length())
            {
                year+=date[i];
                i++;
            }
        }

        string ans;
        ans+=year;
        ans+='-';
        
        if(month=="Jan")ans+="01-";
        if(month=="Feb")ans+="02-";
        if(month=="Mar")ans+="03-";
        if(month=="Apr")ans+="04-";
        if(month=="May")ans+="05-";
        if(month=="Jun")ans+="06-";
        if(month=="Jul")ans+="07-";
        if(month=="Aug")ans+="08-";
        if(month=="Sep")ans+="09-";
        if(month=="Oct")ans+="10-";
        if(month=="Nov")ans+="11-";
        if(month=="Dec")ans+="12-";


      ans+=day;



        return ans;
    }
};