/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int** image, int imageSize, int* imageColSize, int r, int c, int originalColor, int color) {
    if (r < 0 || r >= imageSize || c < 0 || c >= imageColSize[r] || image[r][c] != originalColor) {
        return;
    }
    image[r][c] = color;
    dfs(image, imageSize, imageColSize, r + 1, c, originalColor, color);
    dfs(image, imageSize, imageColSize, r - 1, c, originalColor, color);
    dfs(image, imageSize, imageColSize, r, c + 1, originalColor, color);
    dfs(image, imageSize, imageColSize, r, c - 1, originalColor, color);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int originalColor = image[sr][sc];
    if (originalColor != color) {
        dfs(image, imageSize, imageColSize, sr, sc, originalColor, color);
    }
    *returnSize = imageSize;
    *returnColumnSizes = (int*)malloc(imageSize * sizeof(int));
    for (int i = 0; i < imageSize; i++) {
        (*returnColumnSizes)[i] = imageColSize[i];
    }
    
    return image;
}
