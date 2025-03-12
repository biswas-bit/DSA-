# include<iostream>
# include<vector>
using namespace std;
void  maxsumarray(vector<int> vec)
{
  int maxSum=INT_MIN;
  int currentSum=0;
  for(int i=0; i<vec.size(); i++)
    {
      currentSum+=vec[i];
      maxSum=max(currentSum, maxSum);
      if(currentSum<0)
      {
        currentSum=0;
      }
    }
  cout<<maxSum<<endl;
  
}
int main()
{
   vector<int> arr={3,-4,5,4,-1,7,-8};
    maxsumarray(arr);
    return 0;
}
