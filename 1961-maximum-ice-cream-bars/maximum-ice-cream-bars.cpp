class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // Find the maximum price to determine the range for counting sort
        int maxPrice = 0;
        for (int price : costs) {
            maxPrice = max(maxPrice, price);
        }
        
        // Create frequency array for counting sort
        vector<int> frequency(maxPrice + 1, 0);
        
        // Count frequency of each price
        for (int price : costs) {
            frequency[price]++;
        }
        
        int iceCreamCount = 0;
        int remainingCoins = coins;
        
        // Iterate through prices from cheapest to most expensive
        for (int price = 0; price <= maxPrice && remainingCoins >= price; price++) {
            // If this price doesn't exist, skip
            if (frequency[price] == 0) continue;
            
            // Calculate how many we can buy at this price
            int canBuy = min(frequency[price], remainingCoins / price);
            
            // Update count and remaining coins
            iceCreamCount += canBuy;
            remainingCoins -= canBuy * price;
        }
        
        return iceCreamCount;
    }
};