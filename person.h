#include <iostream>

using namespace std;

class Person
{
protected:
    string name, surname;
public:
    Person();
    Person(string name, string surname);
    ~Person();

    friend std::ostream& operator<< (std::ostream &out, const Person &p);
    friend std::istream& operator>> (std::istream &in, Person &p);
};