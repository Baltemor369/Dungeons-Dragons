#include <iostream>
#include <vector>
#include <map>

#include "Tile.h"

class Map
{
private:
    std::vector<Tile*> tiles_;
public:
    Map();
    ~Map();
    Tile* getTile(int x, int y);
    void addTile(Tile* tile);
    void playerMove(Character* player, std::string direction);

};