#include "task.h"
#include "person.h"
#include <fstream>

class Master : public Person
{
private:
    Task task;
public:
    Master();
    Master(string name, string surname);
    ~Master();

    void checkTask();

    void operator+(Task& t);

    friend ostream& operator<< (std::ostream &out, const Master &m);
    friend istream& operator>> (std::istream &in, Master &m);

    friend std::ofstream& operator<< (std::ofstream &out, const Master &m);
    friend std::ifstream& operator>> (std::ifstream &in, Master &m);
};
