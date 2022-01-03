#include <iostream>
#include <string>

class Person 
{
    protected:
    std::string imie_nazwisko;

    public:
    Person(std::string imie_nazwisko)
    {
        this->imie_nazwisko = imie_nazwisko;
    }

    virtual std::string to_string() const = 0;

};

class Mr : public Person
{
    public:
    Mr(std::string imie_nazwisko) : Person(imie_nazwisko)
    {

    }

    std::string to_string() const
    {
        return "Mr " + imie_nazwisko;
    }
};

class Mrs : public Person
{
    public:
    Mrs(std::string imie_nazwisko) : Person(imie_nazwisko)
    {

    }

    std::string to_string() const
    {
        return "Mrs " + imie_nazwisko;
    }
};

class King : public Person
{
    public:
    King(std::string imie_nazwisko) : Person(imie_nazwisko)
    {

    }

    std::string to_string() const
    {
        return "King " + imie_nazwisko;
    }
};

class Queen : public Person
{
    public:
    Queen(std::string imie_nazwisko) : Person(imie_nazwisko)
    {

    }

    std::string to_string() const
    {
        return "Queen " + imie_nazwisko;
    }
};

std::string who_is_it(Person const& p)
{
    return p.to_string();
}

class Greeting
{
    public:
    virtual std::string greet(Person const&) = 0;
};

class Hello : public Greeting
{
    public:
    std::string greet(Person const& p)
    {
        return "Hello " + p.to_string();
    }
};

class Good_evening : public Greeting
{
    public:
    std::string greet(Person const& p)
    {
        return "Good evening " + p.to_string();
    }
};

class Farewell : public Greeting
{
    public:
    std::string greet(Person const& p)
    {
        return "Farewell " + p.to_string();
    }
};