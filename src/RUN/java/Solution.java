package RUN.java;

class Solution {
    //内联调用: 1.003 ms
    public static void main(String[] args) {
        long start = System.nanoTime();
        int n = 1;
        int ans = 0;
        for (int i = 0; i < 10000; i++) {
            for (int i1 = 0; i1 < 10; i1++) {
                n <<= 1;
            }
            ans += n;
        }
        long end = System.nanoTime();
        System.out.println("内联调用: " + (end - start) / 1000000.0 + " ms");
    }
}
