class Solution {
public:
    int solve(vector<int>& nums , int size ,int index){
        //Base Case
        if(index >= size){
            return 0;
        }
        //checking 1 case
        //ghar chori ki 
        int option1 = nums[index] + solve(nums,size,index + 2);//curr house pe chori ki
        //index + 2 as next house cant be robbed
        //ghar chori nahi ki
        int option2 = 0+ solve(nums,size,index + 1); //chori nahi ki so 0 + solve
        //index + 1 as next house can be robbed
        //taking max of both 
        int finalAns = max(option1 , option2) ;
        return finalAns;
    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        int index = 0; //start index
        int ans = solve(nums,size,index) ; //Function Call
        return ans ;
    }
};