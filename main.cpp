#include "manager.h"
#include <fstream>
#include <string>

int main(){
    vector<Manager> managers;
    ifstream fin("save");
    string line;
    bool f;
    while (getline(fin,line))
    {
        if(line != ".") break;
        Manager m;
        fin >> m;
        managers.push_back(m);
    }
    fin.close();
    for(int i = 0; i < managers.size(); i++) cout << managers[i];
    ofstream fout("save");
    Manager m("Ivan", "Kazak");
    Master master("Anton", "Rozhkov");
    Task t;

    cin >> t;
    m+t;
    cin >> t;
    m+t;
    cin >> t;
    m+t;

    cin >> master;
    m+master;
    cin >> master;
    m+master;
    cin >> master;
    m+master;

    // cout << m << endl;
    // m.giveTask();
    // cout << m << endl;
    // m.checkTasks();

    // m.deleteMaster();
    // cout << m << endl;
    // m.deleteTask();
    // cout << m << endl;

    managers.push_back(m);

    for(int i = 0; i < managers.size(); i++){
        fout << managers[i];
        if(i != managers.size()-1) fout << endl;
    }
    fout.close();
    return 0;
}