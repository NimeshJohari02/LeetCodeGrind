class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int x = jug1Capacity;
        int y = jug2Capacity;
        int t = targetCapacity;
     return t == 0 || t <= (long long)x + y && t % __gcd(x, y) == 0;
    }
};