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

//optimizing time complex
vector<int>exceptSelf(vector<int>arr)   // O(n) 
{
    int n=arr.size();
    vector<int>prefix(n,1);
    vector<int>sufix(n,1);
    vector<int>ans(n,1);
    //prefix
    for(int i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]*arr[i-1];
    }
    
    //sufix
    for(int i=n-2;i>=0;i--)
    {
        sufix[i]=sufix[i+1]*arr[i+1];
    }
    
    //calculate
    for(int i=0;i<n;i++)
    {
        ans[i]=prefix[i]*sufix[i];
    }
    return ans;
}

//optimizing space also
vector<int>spaeOptimized(vector<int>& nums)
{
  int n=nums.size();
  vector<int>ans(n,1);

  //prefix
  for(int i=0;i<n;i++)   //optimization
    {
      ans[i]=ans[i-1]+nums[i-1];
    }

  int sufix=1;
for(int i-n-2;i>=0;i++)                         //optimization
  {
  sufix*=nums[i+1];
  ans[i]*=sufix;
  }
  return ans;
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
