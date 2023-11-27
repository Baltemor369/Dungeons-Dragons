#include "Character.h"

int main()
{
    Character villain("Joker", 120, Weapon("Massue",5,1),Armor(),10,10,1);
    Character hero("Batman", 70, Weapon("dagg",8,4),Armor("Iron",10),0,0,1);
    
    villain.info();
    hero.info();

    for (int i = 0; i < 5; i++)
    {
        hero.move("down");
    }

    villain.attack(&hero);
    hero.attack(&villain);

    villain.info();
    hero.info();
    
    return 0;
}