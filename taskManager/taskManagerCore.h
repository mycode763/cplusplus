

#include <iostream>
#include <vector>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <sqlite3.h>

using namespace std;
 struct task
{
    string name;
    string detail;
    string date;
    string repeat;
    
};

class taskManagerCore
{
private:
  
    

public:
    
    void getTaskList();
    bool addTask(task);
    bool deleteTask(int id);
    bool updateTask(int id);

    //  void SetDate(int year, int month, int day);
};