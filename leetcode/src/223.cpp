class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int A1 = max(A, E);
        int B1 = max(B, F);
        int C1 = min(C, G);
        int D1 = min(D, H);
        int s = (C - A) * (D - B) + (G - E) * (H - F);
        if (A1 >= C1 || B1 >= D1)
            return s;
        else
            return s - (C1 - A1) * (D1 - B1);
    }
};