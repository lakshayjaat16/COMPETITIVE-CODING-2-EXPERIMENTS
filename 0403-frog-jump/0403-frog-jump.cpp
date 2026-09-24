#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        
        // Quick check: Pehle step par 0 se 1 hi jump leni padegi
        if (stones[1] != 1) return false;

        // dp[stone] -> Un saare last jump sizes (k) ka set jo is stone tak pahunchne me lage
        unordered_map<int, unordered_set<int>> dp;
        
        for (int stone : stones) {
            dp[stone] = unordered_set<int>();
        }
        
        // Initial state: Stone 0 par jump size 0 thi
        dp[0].insert(0);

        for (int i = 0; i < n; i++) {
            int currentStone = stones[i];
            
            for (int k : dp[currentStone]) {
                // Next potential jumps are k-1, k, k+1
                for (int step = k - 1; step <= k + 1; step++) {
                    if (step > 0 && dp.count(currentStone + step)) {
                        dp[currentStone + step].insert(step);
                    }
                }
            }
        }

        // Agar last stone par koi bhi reachable jump value mili, toh true
        return !dp[stones.back()].empty();
    }
};