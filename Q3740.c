#define MAX_VAL 100001

int minimumDistance(int* nums, int numsSize) {
    int first[MAX_VAL];
    int second[MAX_VAL];
    for (int i = 0; i < MAX_VAL; i++) {
        first[i] = -1;
        second[i] = -1;
    }

    int min_dist = INT_MAX;
    bool found = false;

    for (int k = 0; k < numsSize; k++) {
        int val = nums[k];
        if (first[val] != -1) {
            int i = first[val];
            int current_dist = 2 * (k - i);
            if (current_dist < min_dist) {
                min_dist = current_dist;
            }
            found = true;
        }
        first[val] = second[val];
        second[val] = k;
    }

    return found ? min_dist : -1;
}
