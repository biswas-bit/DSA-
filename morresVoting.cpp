// majority element
# include<iostream>
# include<vector>
using namespace std;

int majoritySum(vector<int>arr)
{
   int freq=0;
   int ans=0;
   for(int i=0;i<arr.size();i++)
   {
       if(freq==0)
       {
           ans=arr[i];
       }
       if(ans==arr[i])
       {
           freq++;
       }
       else
       {
           freq--;
       }
   }
   return ans;
}
int main()
{
    vector<int>nums={2,2,1,1,1,2,2};
    cout<<majoritySum(nums);
    return 0;
}
