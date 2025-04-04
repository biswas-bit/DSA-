// quick sort
# include<iostream>
# include<vector>
using namespace std;

int partation(vector<int>&arr,int st,int end)
{
    int idx=st-1,pvt=arr[end];
    for(int j=st;j<end;j++)
    {
        if(arr[j]<=pvt)
        {
            idx++;
            swap(arr[j],arr[idx]);   
        }
    }
    idx ++;
    swap(arr[end],arr[idx]);
    return idx;
}
void quickSort(vector<int>&arr,int st, int end)
{
    if(st<end){
        int pvtIdx=partation(arr, st, end);
        // left
        quickSort(arr,st,pvtIdx-1);
        // right
        quickSort(arr,pvtIdx+1,end);
    }
}
int main()
{
    vector<int>arr={5,1,6,3};
    
    quickSort(arr,0,arr.size()-1);
    for(int value : arr)
    {
        cout<<value<<" ";
    }
    cout<<endl;
    return 0;
}
