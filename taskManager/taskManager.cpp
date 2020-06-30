// my second program in C++

#include "taskManagerCore.h"

#include <iostream>
#include <sqlite3.h>

using namespace std;

int main ()
{

task ts;
ts.name="ben45";
ts.detail="deta11il";
ts.date="29.06.2020";
ts.repeat="1.0.0";
taskManagerCore cr;
cr.addTask(ts);

int id=2;

cr.deleteTask(id);
  cout << "Hello World! ";
  return 0;
}