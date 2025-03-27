# include<iostream>
# include<vector>
using namespace std;
int singleNonDuplicate(vector<int>& arr)
{
    int n=arr.size();
    int start=0;
    int end=n-1;
    if(n==1 ) return arr[0];
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(mid==0 && arr[0]!=arr[1]) return arr[mid];
        if(mid ==n-1 && arr[n-1]!=arr[n-2]) return arr[mid];
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])
        {
            return arr[mid];
        }
        else if(mid%2==0)
        {
            if(arr[mid-1]==arr[mid])
            {
                end=mid-1;
                
            }
            else
            {
                start=mid+1;
            }
        }
        else if(mid%2!=0)
        {
            if(arr[mid-1]==arr[mid])
            {
                start=mid+1;
            }
            else 
            {
                end=mid-1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int>arr={1,1,2,3,3,4,4,8,8};
    int single=singleNonDuplicate(arr);
    cout<<single<<endl;
    return 0;
}
