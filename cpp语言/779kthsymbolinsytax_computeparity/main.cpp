class Solution {
public:
    int kthGrammar(int N, int K) {
       return computeparity(--K);
    }

    int computeparity(int i)//针对int类型的基于乘法的偶检验位求解
    {
        i^=i>>1;
        i^=i>>2;
        i=(i&0x11111111U)*0x11111111U;
        return (i>>28)&1;
    }
};
