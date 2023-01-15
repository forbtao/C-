#include <iostream>
#include <fstream>

using namespace std;

class Task
{
private:
    string title;
    int price;
public:
    Task();
    Task(string title, int price);
    ~Task();

    void operator=(const Task& t);

    friend std::ostream& operator<< (std::ostream &out, const Task &o);
    friend std::istream& operator>> (std::istream &in, Task &o);

    friend std::ofstream& operator<< (std::ofstream &out, const Task &t);
    friend std::ifstream& operator>> (std::ifstream &in, Task &t);
};


