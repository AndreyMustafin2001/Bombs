#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

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
//Checking if bomb2 is in bomb1 explosion area
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
//Calculating how many bombs exploded
int dfs(int start,std::vector<std::vector<int> >& NeighbourBombs,std::vector<bool>& isbabah)
{
    int koll = 1;//koll stores number of exploded bombs

    for(int i = 0;i < (int)NeighbourBombs[start].size();i++)//Iterating over all neighbour bombs
    {
        int next = NeighbourBombs[start][i];
        if(isbabah[next] == false)
        {
            isbabah[next] = true;
            koll += dfs(next,NeighbourBombs,isbabah);//Recursion
        }
    }
    return koll;
}
//Orcestrates solution process
std::pair<Bomb, int> solve(std::string file)
{
    int x,y,r;
    std::vector<Bomb> bombs;
    std::ifstream in(file);
    while (in >> x >> y >> r)
    {
        Bomb b(x,y,r);
        bombs.push_back(b);
    }
    in.close();
    //Iterating over all pairs of bombs establishing vector of neighbours for each bomb
    std::vector<std::vector<int> > NeighbourBombs((int)bombs.size());
    for(int i = 0;i < (int)bombs.size();i++)
    {
        for(int j = 0;j < (int)bombs.size();j++)
        {
            if(i==j)continue;//Exclude checking with itself
            if(isDetonated(bombs[i],bombs[j]) == true)
            {
                NeighbourBombs[i].push_back(j);
            }
        }
    }
    //Stores state of each bomb (detonated or not)
    std::vector<bool> isbabah(bombs.size());
    int ans = 0;
    int bestbombindex = 0;
    //Iterating over each bomb and saving number of the most explosions
    for(int i = 0;i < (int)bombs.size();i++)
    {
        for(int j = 0;j < (int)bombs.size();j++)
        {
            isbabah[j] = false;
        }
        isbabah[i] = true;
        int k = dfs(i,NeighbourBombs,isbabah);
        if(k > ans)
        {
            ans = k;
            bestbombindex = i;
        }
    }

 std::cout <<"Kolichestvo vzorvanix = " << ans << std::endl;
 std::cout <<"Bestbomb = " << bombs[bestbombindex].x << " "<< bombs[bestbombindex].y << " "<< bombs[bestbombindex].r << " " << std::endl;
 std::ofstream out("output.txt");

 out <<"Kolichestvo vzorvanix = " << ans << std::endl;
 out <<"Bestbomb = " << bombs[bestbombindex].x << " "<< bombs[bestbombindex].y << " "<< bombs[bestbombindex].r << " " << std::endl;
 out.close();

 return {bombs[bestbombindex],ans};
}


