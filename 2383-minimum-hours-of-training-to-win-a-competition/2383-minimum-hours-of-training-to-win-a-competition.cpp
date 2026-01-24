class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {

        int ans=0;

        for(int i=0;i<energy.size();i++)
        {
            if(initialEnergy<=energy[i] && initialExperience<=experience[i])
            {
                ans+=(1+energy[i]-initialEnergy);
                initialEnergy+=(1+energy[i]-initialEnergy);
                ans+=(1+experience[i]-initialExperience);
                initialExperience+=(1+experience[i]-initialExperience);
            }
            else if(initialEnergy<=energy[i])
            {
                ans+=(1+(energy[i]-initialEnergy));
                initialEnergy+=(1+energy[i]-initialEnergy);

            }
            else if(initialExperience<=experience[i])
            {
                ans+=(1+experience[i]-initialExperience);
                initialExperience+=(1+experience[i]-initialExperience);
            }
            initialEnergy-=energy[i];
            initialExperience+=experience[i];

        }

        return ans;
        
    }
};