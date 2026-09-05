class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return -1;
        vector<int> pref_max(n);
        pref_max[0]=nums[0];
        for(int i=1;i<n;i++){
            pref_max[i]=max(pref_max[i-1],nums[i]);
        }
        vector<int> suff_min(n);
        suff_min[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff_min[i]=min(suff_min[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            if(pref_max[i]-suff_min[i]<=k){
                return i;
            }
        }
        return -1;
    }
};
