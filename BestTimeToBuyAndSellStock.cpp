# include<iostream>
# include<vector>
using namespace std;

int SellStock(vector<int>prices){
  int maxProfit=0;
  int bestDay=prices[0];
  for(int i=1;i<prices.size();i++)
    {
      if(prices[i]>bestDay)
      {
        maxProfit=max(maxProfit,prices[i]-bestDay);
      }
      bestDay=min(bestDay,prices[i]);
    }
  return maxProfit;
}
