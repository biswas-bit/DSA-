// product of Arry except it self
# include<iostream>
# include<vector>
using namespace std;
// using brootforce approch
vector<int> productExceptItself(vector<int>& nums)
{
  vector<int>ansArray(nums.size(),1);
  for(int i=0;i<nums.size();i++)
    {
      int product=1;
      for(int j=0;j=nums.size();j++)
        {
          if(i!=j)
          {
            product*=nums[i];
          }
        }
      ansArray[i]=product;
    }
  return ansArray;
}

int main()
{
  vector<int>nums={1,2,3,4,5};
  vector<int>product=productExceptItSelf(nums);
  for(int value : product)
    {
      cout<<value<<" ";
    }
  cout<<endl;
  return 0;
}
