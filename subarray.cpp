//subarray=n(n+1)/2;
//ex: [1,2,3,4,5]
/*sun array is:1,12,123,1234,12345
               2,23,234,2345
               3,34,345
               4,45
               5             it is the number of array you can create form  one single array */

# include<iostream>
# include<vector>
using namespace std;
void subarray(vector<int>& vec)
{
  for(int i=0;i<vec.size();i++)
    {
    for(int j=i;j<vec.size();j++)
      {
        for(int k=i;k<=j;k++)
          {
            cout<<vec[k];
          }
        cout<<" ";
      }
      cout<<endl;
    }
}
// broot force approch to calculate maximum sub array sum 
int subarraymaxsum(vectro<int>& vec)
{
  int maxSum=0;
  for(int i=0;i<vec.size();i++)
    {
      int currentSum=0;
      for(int j=i;j<vec.size(); j++)
        {
          currentSum+=vec[j];
          maxSum=max(currentSum, maxSum);
        }
    }
  return maxSum;
}
int main()
{
  vector<int>arr={1,2,3,4,5};
  subarray(arr);
  cout<<suarraymaxsum(arr)<<endl;
  return 0;
}
