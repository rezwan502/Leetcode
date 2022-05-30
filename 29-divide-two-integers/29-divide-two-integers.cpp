class Solution {
public:
    int divide(int dividend, int divisor) {
        return (int)((dividend == INT_MIN) && divisor == -1) ? INT_MAX : dividend / divisor;
    }
};