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
bool isDetonated(Bomb& bomb1,Bomb& bomb2)
{
    int squaredDist = (bomb1.x - bomb2.x)*(bomb1.x - bomb2.x) + (bomb1.y - bomb2.y)*(bomb1.y - bomb2.y);
    if(squaredDist <= bomb1.r * bomb1.r)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Bomb bomb1(2,1,3);
    Bomb bomb2(6,1,4);

    if(isDetonated(bomb1,bomb2))
        std::cout <<"true";
    else
        std::cout <<"true";
}
