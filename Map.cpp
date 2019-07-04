#include "Map.h"



void Map::InitMap()
{
   int Nsize=initmap.size();
   for(int i=0;i<Nsize;i++)
   {
       initmap[i].PrintSqar();
   }
}
