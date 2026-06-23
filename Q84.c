#define MAX(a, b) ((a) > (b) ? (a) : (b))

int largestRectangleArea(int* heights, int heightsSize) {
    int* stack = (int*)malloc(sizeof(int) * (heightsSize + 1));
    int top = -1;
    int max_area = 0;
    int i = 0;

    while (i < heightsSize) {
        if (top == -1 || heights[i] >= heights[stack[top]]) {
            stack[++top] = i;
            i++;
        } else {
            int tp = stack[top--];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = heights[tp] * width;
            max_area = MAX(max_area, area);
        }
    }
    while (top != -1) {
        int tp = stack[top--];
        int width = (top == -1) ? i : i - stack[top] - 1;
        int area = heights[tp] * width;
        max_area = MAX(max_area, area);
    }
    free(stack);
    return max_area;
}
