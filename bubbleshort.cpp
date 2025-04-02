# include<iostream>
# include<vector>
using namespace std;                       
void bubbleSort(vector<int>arr)                 // time cop of this algorithem is O(n2) but we have more optimized malgorithem
{
 
  for(int i=0;i<arr.size();i++)
    {
       bool isSwaped=false;                                   // this algo still runs n-1 times even if the array is sorted to avoid we checked that the arr is swapping in the loop or not
      for(int j=0;j<arr.size()-i-1;j++)
        {
          if(arr[j]>arr[j+1])
          {
            swap(arr[j],arr[j+1]);
            isSwaped=true;
          }
        }
      if(!isSwaped)                  // if elements are not swapping the return 
      {
        return;
      }
    }
}

void selectionSort(vector<int>arr)
{
 for(int i=0;i<arr.size()-1;i++)
  {
   int startingIdx=i;
   for(int j=i+1;j<arr.size(); j++)
    {
     if(arr[j]<arr[startingIdx])
     {
       startingIdx=j;
     }
    }
   swap(arr[i],arr[startingIdx]);
  }
}

int main()
{
  vector<int>arr={4,1,5,2,3};
  selectionSort(arr);
  bubbleSort(arr);
  for(int value : arr)
    {
      cout<<value<<"";
    }
  cout<<endl;
}
