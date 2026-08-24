int maxProfit(int* prices, int pricesSize) {
    int least=prices[0];
    int profit=0;
    for(int i=0;i<pricesSize;i++){
        if(prices[i]<least){
            least=prices[i];
        }
        else if((prices[i]-least)>profit){
            profit=prices[i]-least;
        }
    }
    return profit;
}
