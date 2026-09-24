class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int> n_map;
        while(n>0){
            int digit=n%10;
            n=n/10;
            n_map[digit]++;
        }
        int score=0;
        for(auto& pair : n_map){
            score+= pair.first*pair.second;
        }
        return score;
    }
};
