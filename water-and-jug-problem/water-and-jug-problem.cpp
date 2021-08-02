class Solution {
public:
    bool canMeasureWater(int a, int b, int z) {
        if(a+b<z) return 0;
        if(a==z || b==z) return 1;
        int g = __gcd(a,b);
        return (z%g==0);
    }
};