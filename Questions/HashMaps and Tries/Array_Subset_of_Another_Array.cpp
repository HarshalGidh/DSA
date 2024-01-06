//M1 two nested Loops 
//M2 sort two arrays then apply binary search
//M3 map :
string isSubset(int a1[], int a2[], int n, int m) {
    string ans ="Yes";
    //Create a Hash Map for all a1
    unordered_map<int,int>map;
    //store the occurence and count of elements of a1 in map:
    for(int i = 0;i<n;i++){
        map[a1[i]]++;
    }
    //Process a2:
    //check if elements of a2 is presnt in a1 :
    for(int i = 0;i<m;i++){
        if(map.find(a2[i]) == map.end()){
            //element ofa2 not found in a1
            //hence not a subset
            ans = "No";
            return ans;
        }
        else{
            //element is present :
            //check if element of a2 has less or equal occurences to that of a1
            if(map[a2[i]]){
                map[a2[i]]--; //decreamenting the count if found
            }
            else{
                ans = "No";
                return ans;
            }
        }
    }
    return ans;
    
}