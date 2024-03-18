#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>
#include<limits.h>
using namespace std;


int main(){
    //inputs :
    int row = 8;
    int col = 15 ;
    int tower = 3;

    // create a vector to store the coordinates:
    vector<pair<int,int>>loc ;
    loc.push_back({3,8}) ;
    loc.push_back({11,2});
    loc.push_back({8,6});

    //store the x dimensions 
    vector<int>xdim;
    //push dummy towers :
    xdim.push_back(0);
    xdim.push_back(col + 1);
    //store all the x dimensions of the towers :
    for (int  i = 0; i < loc.size(); i++)
    {
        xdim.push_back(loc[i].first) ;
    }
    //sort all the x dims to get the difference which will be unsafe x dimensions
    sort(xdim.begin(),xdim.end()) ;

    //store the y dimensions 
    vector<int>ydim;
    //push dummy towers :
    ydim.push_back(0);
    ydim.push_back(row + 1);
    //store all the y dimensions of the towers :
    for (int  i = 0; i < loc.size(); i++)
    {
        ydim.push_back(loc[i].second) ;
    }
    //sort all the y dims to get the difference which will be unsafe y dimensions
    sort(ydim.begin(),ydim.end()) ;

    //Now push back all the xdiff :
    vector<int>xans ;
    for (int i = 1; i < xdim.size(); i++)
    {
        int diff = xdim[i] - xdim[i-1] - 1;
        xans.push_back(diff) ;
    }

     //Now push back all the ydiff :
    vector<int>yans ;
    for (int i = 1; i < ydim.size(); i++)
    {
        int diff = ydim[i] - ydim[i-1] - 1;
        yans.push_back(diff) ;
    }

    int maxi = -1;
    for (int i = 0; i < xans.size(); i++)
    {
        for(int j = 0;j<yans.size();j++){
            int prod = xans[i] *yans[j] ;
            maxi = max(prod,maxi) ;
        }
    }
    

    cout<<"Maximum number of unsafe blocks are "<<maxi;
    


    return 0;
}