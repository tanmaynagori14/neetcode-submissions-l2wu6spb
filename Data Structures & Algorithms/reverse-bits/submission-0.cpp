class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t newno = 0; 
        for(int i=0 ; i<32 ; i++) {
            uint32_t lastbit = n & 1;
            lastbit = lastbit << (31 - i);
            newno |= lastbit;
            n = n>>1;
        }

        return newno;
    }
};
