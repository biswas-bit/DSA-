# include<iostream>
# include<vector>
using namespace std;

// brootforce approch
int maxArea(vector<int>height)
{
  int maxWater=0;
  for(int i=0;i<height.size();i++)
    {
      for(int j=i+1;j<height.size();j++)
        {
           int width=j-i;
          int height=min(height[i],height[j]);
          int area=width*height;
          maxArea=max(area,maxArea);
        }
    }
  return maxWater;  
}

int optimized(vector<int>& vec)
{
  int lp=0;
  int rp=vec.size()-1;
  int maxWater=0;
  while(lp<rp)
    {
      int wd=rp-lp;
      int ht=min(vec[lp],vec[rp]);
      int area=wd*ht;
      maxWater=max(maxWater,area);
      if(vec[lp]<vec[rp])
      {
        lp++;
      }
      else{
        rp--;
      }
    }
    return maxWater;
}
