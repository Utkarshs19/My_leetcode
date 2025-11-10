class Solution {
public:
    bool checkYear(int n) {
  
   // Check if n is divisible by 4
   if (n % 4 == 0) {
     
      // If it's divisible by 100, it should also be 
      // divisible by 400 to be a leap year
      if (n % 100 == 0) {
         return n % 400 == 0;
      }
      return true;
   }
   return false;
}
    string dayOfTheWeek(int day, int month, int year) {

        int d=0;

        for(int i=1971;i<year;i++)
        {
            if(checkYear(i))
            d+=366;
            else
            d+=365;
        }

            for(int i=0;i<month-1;i++)
            {
                if(i==0)d+=31;
                if(i==1){
                    if(checkYear(year))
                    d+=29;}
                else
                d+=28;
                if(i==2)d+=31;
                if(i==3)d+=30;
                if(i==4)d+=31;
                if(i==5)d+=30;
                if(i==6)d+=31;
                if(i==7)d+=31;
                if(i==8)d+=30;
                if(i==9)d+=31;
                if(i==10)d+=30;
                if(i==11)d+=31;
            }

            d+=day-1;

            d=d%7;

            if(d==0)return "Friday";
            if(d==1)return "Saturday";
            if(d==2)return "Sunday";
            if(d==3)return "Monday";
            if(d==4)return "Tuesday";
            if(d==5)return "Wednesday";
            if(d==6)return "Thursday";     

            return "0"; 
        
    }
};