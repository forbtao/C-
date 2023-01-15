#include "task.h"

Task::Task(): title(""), price(0){}
Task::Task(string title, int price): title(title), price(price){}
Task::~Task(){}

void Task::operator=(const Task& t){
    title = t.title;
    price = t.price;
}

ostream& operator<< (std::ostream &out, const Task &o){
    out << "Название: " << o.title << endl << "Цена: " << o.price << endl;
    return out;
}
istream& operator>> (std::istream &in, Task &o){
    cout << "Название: ";
    in >> o.title;
    cout << "Цена: ";
    in >> o.price;
    return in;
}

ofstream& operator<< (std::ofstream &out, const Task &o){
    out << o.title << endl << o.price << endl;
    return out;
}

ifstream& operator>> (std::ifstream &in, Task &o){
    in >> o.title;
    in >> o.price;
    return in;
}