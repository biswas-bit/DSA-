# include<iostream>
# include<vector>
# include <climits>
using namespace std;

bool isPossible(vector<int>arr, int n, int m, int maximumallowedTime)
{
    int painters=1,times=0;
    for(int i=0; i<arr.size();i++)
    {
        if(arr[i]>maximumallowedTime)
        {
            return false;
        }
        if(times+arr[i]<=maximumallowedTime)
        {
            times+=arr[i];
        }
        else{
            painters++;
            times=arr[i];
        }
    }
    return painters <=m;
}
int minTimeToPaint(vector<int> &arr, int n, int m)
{
   int num=arr.size();
   int sum =0, maxVal=INT_MIN;
   for(int i=0;i<num;i++)
   {
       sum+=arr[i];
       maxVal=max(arr[i],maxVal);
   }
   int start=maxVal, end=sum, ans=-1;
   while(start<=end)
   {
       int mid=start+(end-start)/2;
       if (isPossible(arr,n,m,mid))
       {
           ans=mid;
           end=mid-1;
       }
       else{
           start=mid+1;
       }
   }
   return ans;
}
int main()
{
    vector<int>arr={40,30,10,20};
    int n=4,m=2;
    cout<<minTimeToPaint(arr,n,m)<<endl;
    return 0;
}
