#include <string>
#include <iostream>

class Creature
{
    public:
    std::string name;
    int hp;
    Creature (std::string name, int hp)
    {
        this->name = name;
        this->hp = hp;
        std::cout << this->name << " " << this->hp << std::endl;
    }
};

class Item
{
    public:
    virtual void use_on(Creature &) = 0;
    virtual int strength() const = 0;
};

class Weapon : public Item
{
    public:
    void use_on(Creature& c)
    {
        c.hp -= strength();
        std::cout << c.name << " " << c.hp << std::endl;
    }
};

class Potion : public Item
{
    public:
    void use_on(Creature& c)
    {
        c.hp += strength();
        std::cout << c.name << " " << c.hp << std::endl;
    }
};

class Sword : public Weapon
{
    public:
    int strength() const
    {
        return 5;
    }
};

class Bow : public Weapon
{
    public:
    int strength() const
    {
        return 3;
    }
};

class Axe : public Weapon
{
    public:
    int strength() const
    {
        return 9;
    }
};

class Health_potion : public Potion
{
    public:

    int count = 0;

    void use_on(Creature& c)
    {
        count++;
        if (count <= 2)
        {
            Potion::use_on(c);
        }
        else
        {
            std::cout << c.name << " " << c.hp << std::endl;
        }
    }

    int strength() const
    {
        return 10;
    }
};