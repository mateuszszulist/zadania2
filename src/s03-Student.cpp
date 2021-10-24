#include <iostream>
#include <string>
#include <sstream>
#include "Student.h"

Student::Student(std::string imie, std::string nazwisko, int numer_indeksu, int aktualny_semestr, double srednia_ocen)
{
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->numer_indeksu = numer_indeksu;
    this->aktualny_semestr = aktualny_semestr;
    this->srednia_ocen = srednia_ocen;
}

std::string Student::to_string() const
{
    std::stringstream student;

    student << imie << " " << nazwisko << " (" << numer_indeksu << "), semestr " << aktualny_semestr << ": " << srednia_ocen;
    return student.str();
}

auto main() -> int
{
    auto const student = Student
    {
        "Mateusz"
        , "Szulist"
        , 24718
        , 1
        , 4.12
    };

    std::cout << student.to_string() << std::endl;
    return 0;
}
