#include <string>

struct Student
{
    std::string imie;
    std::string nazwisko;
    int numer_indeksu;
    int aktualny_semestr;
    double srednia_ocen;

    std::string to_string() const;
    Student(std::string imie, std::string nazwisko, int numer_indeksu, int aktualny_semestr, double srednia_ocen);
};