#include <iostream>

struct Bomb{
 int x;
 int y;
 int r;

 Bomb(int a,int b,int c)
 {
  x=a;
  y=b;
  r=c;
 }
};

int main()
{

 Bomb bomb1(2,1,3);

 return 0;
}

