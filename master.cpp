#include "master.h"

Master::Master(): Person(){}
Master::Master(string name, string surname): Person(name, surname){}
Master::~Master(){}

void Master::checkTask(){
    cout << "Задача: " << endl;
    cout << task << endl;
}

void Master::operator+(Task& t){
    task = t;
}

ostream& operator<< (std::ostream &out, const Master &m){
    out << "Имя: " << m.name << endl << "Фамилия: " << m.surname << endl;

    
    return out;
}

istream& operator>> (std::istream &in, Master &m){
    cout << "Имя: ";
    in >> m.name;
    cout << "Фамилия: ";
    in >> m.surname;
    return in;
}

ofstream& operator<< (std::ofstream &out, const Master &m){
    out << m.name << endl << m.surname;
    return out;
}

ifstream& operator>> (std::ifstream &in, Master &m){
    in >> m.name;
    in >> m.surname;
    return in;
}