#include <iostream>
using namespace std;
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        //initialise pick time for each trucks
        int pickP = 0;
        int pickM = 0;
        int pickG = 0;
        //Travel time
        int travelP = 0;
        int travelM = 0;
        int travelG = 0;
        //last travel house (i)
        int lastP = 0;
        int lastM = 0;
        int lastG = 0;

        //calculate pick time and last house to travel of a truck :
        for(int i =0;i<garbage.size();i++){
            //counting no. of garbage present in a house
            string curr = garbage[i];
            for(int j = 0;j < curr.size();j++){
                char ch = curr[j];
                if(ch == 'P'){
                    pickP++;
                    lastP = i;    //lastP = i because we need the last index to travel till
                }
                else if(ch == 'M'){
                    pickM++;
                    lastM = i;
                }
                else if(ch == 'G'){
                    pickG++;
                    lastG = i;
                }
            }
        }
        //calculating travel time :
        for(int i =0;i < lastP; i++){
            travelP += travel[i];
        }
        for(int i =0;i < lastM; i++){
            travelM += travel[i];
        }
        for(int i =0;i < lastG; i++){
            travelG += travel[i];
        }
        //adding Pick Time and Travel Time :
        int totalTime = pickP + pickG + pickM + travelP + travelM + travelG ;
        return totalTime ; 
    }
};
int main() {
  cout << "Hello world!" << endl;
  return 0;
}