#include "master.h"
#include <vector>
#include <fstream>

class Manager : public Person
{
private:
    vector<Task> tasks;
    vector<Master> masters; 
public:
    Manager();
    Manager(string name, string surname);
    ~Manager();

    void giveTask();
    void checkTasks();
    void deleteTask();
    void deleteMaster();


    void operator+ (Task& t);
    void operator+ (Master& m);

    friend std::ostream& operator<< (std::ostream &out, const Manager &m);
    friend std::istream& operator>> (std::istream &in, Manager &m);

    friend std::ofstream& operator<< (std::ofstream &out, const Manager &m);
    friend std::ifstream& operator>> (std::ifstream &in, Manager &m);
};


