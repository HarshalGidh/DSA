#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool stoneGame(std::vector<int>& piles) {
        //there will always be one way where Alice will win
        //if she gets a chance to pick max piles she will win
        //if she doesn't get a chance to pick max then also there will exist a way where she wins
        // so return true :D
        return true;
    }
};

// Main function
int main() {
    Solution solution;

    // Example 1
    std::vector<int> piles1 = {5, 3, 4, 5};
    std::cout << "Example 1: " << std::boolalpha << solution.stoneGame(piles1) << std::endl;

    // Example 2
    std::vector<int> piles2 = {3, 7, 2, 3};
    std::cout << "Example 2: " << std::boolalpha << solution.stoneGame(piles2) << std::endl;

    return 0;
}
