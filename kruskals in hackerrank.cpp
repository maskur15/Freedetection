#include<bits/stdc++.h>
using namespace std;
class Node
{
    public :
    int u , v, value;
      bool operator < (const Node& cmp) const{
          if(value==cmp.value)
            return (u+v+value)<(cmp.u+cmp.v+cmp.value);
          else
          return value <cmp.value;   ///here is the comparison
    }

};
int fathers[3100];
int find(int x)
{
    if(fathers[x]==x)
    {
        return x;
    }
    return find(fathers[x]);
}
void unite(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    fathers[fx]=fy;
}
int main()
{
     for(int i=0;i<3100;i++)
    {
        fathers[i]=i;
    }
     int n,i=0, m,u1,v1,val;
     cin >> n >>  m;
     Node x[m];
     for(i=0;i<m;i++)
     {
          cin>> u1 >> v1 >> val;
          x[i].u=u1; x[i].v=v1;
          x[i].value=val;
     }
     sort(x,x+m); i=0;
    long  int sum=0,medge=0;
    for(i=0;i<m;i++)
     {   if(find(x[i].u)!=find(x[i].v))
         {
             unite(x[i].u,x[i].v);
             sum+=x[i].value;
         }
     }
     cout << sum << endl;

}
