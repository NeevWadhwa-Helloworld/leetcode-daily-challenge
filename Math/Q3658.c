long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int gcdOfOddEvenSums(int n) {
    long long sumOdd = 0;
    long long sumEven = 0;
    
    for (int i = 1; i <= n; i++) {
        sumOdd += (2 * i - 1);
        sumEven += (2 * i);
    }
    
    return (int)gcd(sumOdd, sumEven);
}
