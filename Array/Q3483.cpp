class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
        int count[10] = {0};
        for (int d : digits) {
            count[d]++;
        }

        int total_valid = 0;
        for (int num = 100; num <= 998; num += 2) {
            int d1 = num / 100;
            int d2 = (num / 10) % 10;
            int d3 = num % 10;       
            int req[10] = {0};
            req[d1]++;
            req[d2]++;
            req[d3]++;

            if (req[d1] <= count[d1] && req[d2] <= count[d2] && req[d3] <= count[d3]) {
                total_valid++;
            }
        }

        return total_valid;
    }
};
