#include "Item.h"

int main()
{
    Creature c("Ogr", 25);
    Sword s;
    Bow b;
    Axe a;
    Health_potion h;
    s.use_on(c);
    b.use_on(c);
    a.use_on(c);
    h.use_on(c);
    s.use_on(c);
    b.use_on(c);
    a.use_on(c);
    h.use_on(c);
    s.use_on(c);
    h.use_on(c);
}