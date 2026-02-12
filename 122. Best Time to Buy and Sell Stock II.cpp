class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int currBuy,currNotBuy,aheadBuy,aheadNotBuy;
        aheadBuy=0;aheadNotBuy=0;
        for(int i=n-1;i>=0;i--){
            currNotBuy=max(prices[i]+aheadBuy,aheadNotBuy);
            currBuy=max(-prices[i]+aheadNotBuy,aheadBuy);
            aheadBuy=currBuy;
            aheadNotBuy=currNotBuy;
        }
        return aheadBuy;
    }
};
