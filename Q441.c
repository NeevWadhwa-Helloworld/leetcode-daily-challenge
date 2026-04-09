int arrangeCoins(int n) {
    long left = 0, right = n;
    long k, current_sum;
    
    while (left <= right) {
        k = left + (right - left) / 2;
        current_sum = k * (k + 1) / 2;

        if (current_sum == n) {
            return (int)k;
        }

        if (n < current_sum) {
            right = k - 1;
        } else {
            left = k + 1;
        }
    }
    return (int)right;
}
