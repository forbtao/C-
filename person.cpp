#include "person.h"

Person::Person(){}
Person::Person(string name, string surname): name(name), surname(surname){}

Person::~Person(){}

ostream& operator<< (std::ostream &out, const Person &p){
    out << "Имя: " << p.name << endl << "Фамилия: " << p.surname << endl;;
    return out;
}
istream& operator>> (std::istream &in, Person &p){
    cout << "Имя: ";
    in >> p.name;
    cout << "Фамилия: ";
    in >> p.surname;
    return in;
}