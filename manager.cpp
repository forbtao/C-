#include "manager.h"

Manager::Manager(): Person(){}
Manager::Manager(string name, string surname): Person(name, surname){}
Manager::~Manager(){}

void Manager::giveTask(){
    int ts = tasks.size();
    for(int i = 0; i < masters.size() && i < ts; i++){
        cout << tasks[i] << endl;
        masters[i]+tasks[ts-i-1];
        tasks.pop_back();
    }
}

void Manager::checkTasks(){
    cout << "Задания исполнителей: " << endl;
    for(int i = 0; i < masters.size(); i++){
        cout << masters[i];
        masters[i].checkTask();
    } 
}

void Manager::deleteMaster(){
    if(masters.size() == 0){ cout << "Добавьте исполнителей!" << endl; return;}
    int n;
    for(int i = 0; i < masters.size(); i++) cout << i+1 << ": " << masters[i];
    cout << "Какого исполнителя удалить: ";
    cin >> n;
    if(n > 0 && n <= masters.size()) masters.erase(masters.begin()+n-1);
}

void Manager::deleteTask(){
    if(tasks.size() == 0){ cout << "Добавьте задачу!" << endl; return;}
    int n;
    for(int i = 0; i < tasks.size(); i++) cout << i+1 << ": " << tasks[i];
    cout << "Какую задачу удалить: ";
    cin >> n;
    if(n > 0 && n <= tasks.size()) tasks.erase(tasks.begin()+n-1);
}

void Manager::operator+(Task& t){
    tasks.push_back(t);
}

void Manager::operator+(Master& m){
    masters.push_back(m);
}

ostream& operator<< (std::ostream &out, const Manager &m){
    out << "Менеджер: " << endl << "Имя: " << m.name << endl << "Фамилия: " << m.surname << endl;
    if(m.tasks.size() != 0) out << "Заказы: " << endl;
    for(int i = 0; i < m.tasks.size(); i++){
        out << m.tasks[i] << endl;
    }
    
    if(m.masters.size() != 0) out << "Исполнители: " << endl;
    for(int i = 0; i < m.masters.size(); i++){
        out << m.masters[i] << endl;
    }

    return out;
}
istream& operator>> (std::istream &in, Manager &m){
    cout << "Имя: ";
    in >> m.name;
    cout << "Фамилия: ";
    in >> m.surname;
    return in;
}

ofstream& operator<< (std::ofstream &out, const Manager &m){
    cout << m;
    out << "." << endl << m.name << endl <<  m.surname << endl;
    out  << m.tasks.size() << endl;
    for(int i = 0; i < m.tasks.size(); i++){
        out << m.tasks[i];
    }
    
    out << m.masters.size() << endl;
    for(int i = 0; i < m.masters.size(); i++){
        out << m.masters[i];
        if(i != m.masters.size()-1) out << endl;
    }

    return out;
}
ifstream& operator>> (std::ifstream &in, Manager &m){
    
    in >> m.name;
    in >> m.surname;

    int n;
    in >> n;
    for(int i = 0; i < n; i++){
        Task t;
        in >> t;
        m.tasks.push_back(t);
    }

    in >> n;
    for(int i = 0; i < n; i++){
        Master master;
        in >> master;
        m.masters.push_back(master);
    }
    return in;
}