// binary search
# include<iostream>
# include<vector>
using namespace std;

int binarySearch(vector<int>arr,int target)
{
   int start=0;
   int end=arr.size()-1;
   while(start<=end)
   {
       int mid=strat+(end-start)/2;   // optimized (in worse case mid=(start+end)/2  if there are INT_MAX index it can be overt flow)
       if(arr[mid]>target)
       {
           end=mid-1;
       }
       else if(arr[mid]<target)
       {
           start=mid+1;
       }
       else{
           return mid;
       }
   }
   return -1;
   
}

int main()
{
    vector<int>arr={1,2,3,4,5,6};
    int index=binarySearch(arr,3);
    cout<<index<<endl;
    return 0;
}
