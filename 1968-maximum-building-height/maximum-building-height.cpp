class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // Add implicit restrictions for building 1 (height must be 0)
        restrictions.push_back({1, 0});
        
        // Sort restrictions by building id
        sort(restrictions.begin(), restrictions.end());
        
        // Forward pass: ensure restrictions are feasible from left to right
        for (int i = 1; i < restrictions.size(); i++) {
            int id1 = restrictions[i-1][0];
            int h1 = restrictions[i-1][1];
            int id2 = restrictions[i][0];
            int h2 = restrictions[i][1];
            
            // The maximum possible height at id2 given the restriction at id1
            // is h1 + (id2 - id1)
            restrictions[i][1] = min(h2, h1 + (id2 - id1));
        }
        
        // Backward pass: ensure restrictions are feasible from right to left
        for (int i = restrictions.size() - 2; i >= 0; i--) {
            int id1 = restrictions[i][0];
            int h1 = restrictions[i][1];
            int id2 = restrictions[i+1][0];
            int h2 = restrictions[i+1][1];
            
            // The maximum possible height at id1 given the restriction at id2
            restrictions[i][1] = min(h1, h2 + (id2 - id1));
        }
        
        int maxHeight = 0;
        
        // Check between restrictions and also at the end
        for (int i = 0; i < restrictions.size(); i++) {
            int id = restrictions[i][0];
            int h = restrictions[i][1];
            
            // Check from building 1 to first restriction
            if (i == 0) {
                maxHeight = max(maxHeight, h + (id - 1));
            }
            
            // Check between restrictions
            if (i > 0) {
                int prevId = restrictions[i-1][0];
                int prevH = restrictions[i-1][1];
                
                // The maximum height between two restrictions occurs in the middle
                int dist = id - prevId;
                int maxPossible = max(prevH, h) + (dist - abs(prevH - h)) / 2;
                maxHeight = max(maxHeight, maxPossible);
            }
            
            // Check after the last restriction to building n
            if (i == restrictions.size() - 1) {
                maxHeight = max(maxHeight, h + (n - id));
            }
        }
        
        return maxHeight;
    }
};