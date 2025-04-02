# include<iostream>
# include<vector>
using namespace std;                       
void bubbleSort(vector<int>arr)                 // time cop of this algorithem is O(n2) but we have more optimized malgorithem
{
  for(int i=0;i<arr.size();i++)
    {
      for(int j=0;j<arr.size()-i-1;j++)
        {
          if(arr[j]>arr[j+1])
          {
            swap(arr[j],arr[j+1]);
          }
        }
    }
}
int main()
{
  vector<int>arr={4,1,5,2,3};
  bubbleSort(arr);
  for(int value : arr)
    {
      cout<<value<<"";
    }
  cout<<endl;
}
