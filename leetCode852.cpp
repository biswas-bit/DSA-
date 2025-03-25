//pick index in mountain array
# include<iostream>
# include<vector>
using namespace std;
int pickIndex(vector<int>& arr)
{
    int n=arr.size();
     int start=1;
     int end=n-2;
     while(start<=end)
     {
         int mid=start+(end-start)/2;
         if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1])
         {
             return mid;
         }
         else if(arr[mid-1]<arr[mid])
         {
             start=mid+1;
         }
         else
         {
             end=mid-1;
         }
     }
     return -1;
}
int main()
{
    vector<int>arr={0,3,8,9,5,2};
    int maxIndex=pickIndex(arr);
    cout<<maxIndex<<endl;
    return 0;
}
