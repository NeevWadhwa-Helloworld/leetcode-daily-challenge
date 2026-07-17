/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* gcdValues(int* nums, int numsSize, long long* queries, int queriesSize, int* returnSize) {
    int max_num = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max_num) {
            max_num = nums[i];
        }
    }

    int* freq = (int*)calloc(max_num + 1, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }

    long long* countGcdPair = (long long*)calloc(max_num + 1, sizeof(long long));

    for (int gcd = max_num; gcd >= 1; gcd--) {
        long long multiples_count = 0;
        
        for (int larger = gcd; larger <= max_num; larger += gcd) {
            multiples_count += freq[larger];
        }

        long long total_pairs = (multiples_count * (multiples_count - 1)) / 2;

        for (int largerGcd = 2 * gcd; largerGcd <= max_num; largerGcd += gcd) {
            total_pairs -= countGcdPair[largerGcd];
        }

        countGcdPair[gcd] = total_pairs;
    }

    long long* prefixCountGcdPair = (long long*)calloc(max_num + 1, sizeof(long long));
    for (int gcd = 1; gcd <= max_num; gcd++) {
        prefixCountGcdPair[gcd] = prefixCountGcdPair[gcd - 1] + countGcdPair[gcd];
    }

    int* ans = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; i++) {
        long long target = queries[i];
        
        int low = 1, high = max_num;
        int result_gcd = max_num;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (prefixCountGcdPair[mid] > target) {
                result_gcd = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans[i] = result_gcd;
    }

    free(freq);
    free(countGcdPair);
    free(prefixCountGcdPair);

    return ans;
}
