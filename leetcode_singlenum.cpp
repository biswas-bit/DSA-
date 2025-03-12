# include<iostream>
# include<vectro>
using namespace std;
class solution
{
public:
int singeNumber(vector<int>& nums)
{
  ans=0;
  for(int value: nums)
    {
      ans=ans^value;      // Note xor of the elemente gives unique single number from the pair of numbers in the list
    }
  return ans;
}
};
int main()
{
  vector<int> list={4,1,2,1,2};
  solution obj;
  int uniquenum=obj.singleNumber(list);
  cout<<uniquenum<<endl;
  return 0;
}
