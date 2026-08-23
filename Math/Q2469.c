/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* convertTemperature(double celsius, int* returnSize) {
    double k=celsius+273.15;
    double f=celsius * 1.80 +32.00;
    double* l = (double*)malloc(2*sizeof(double));
    l[0]=k;
    l[1]=f;
    *returnSize=2;
    return l;
}
