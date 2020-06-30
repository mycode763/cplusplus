
#include "taskManagerCore.h"
#include <string.h>

using namespace std;

void taskManagerCore::getTaskList()
{
}

string quotesql(const string &s){
   return
    string("'") + s + std::string("'");
}
static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
   int i;
   for (i = 0; i < argc; i++)
   {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

bool taskManagerCore::addTask(task _task)
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("taskManager.db", &db);

   if (rc)
   {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return (0);
   }
   else
   {
      fprintf(stderr, "Opened database successfully\n");
   }

   // string sql="INSERT INTO PERSON VALUES(1, 'STEVE', 'GATES', 30, 'PALO ALTO', 1000.0);"

   string sqlstatement =
       "INSERT INTO task (name,detail, date, repeat) VALUES (" + quotesql(_task.name) + "," + quotesql(_task.detail) + "," + quotesql(_task.date) + "," + quotesql(_task.repeat) + ");";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sqlstatement.c_str(), callback, 0, &zErrMsg);

   if (rc != SQLITE_OK)
   {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }
   else
   {
      fprintf(stdout, "Records created successfully\n");
   }
   sqlite3_close(db);

   return true;
}
bool taskManagerCore::deleteTask(int id)
{

   sqlite3 *db;
   int rc;
   rc = sqlite3_open("taskManager.db", &db);
   char *zErrMsg = 0;
   if (rc)
   {
      cout << "Hata" << sqlite3_errmsg(db);
      return false;
   }
   else
   {
      cout << "db is open" << endl;
      string idd = to_string(id);
      string sql = "DELETE FROM task WHERE id='" + idd + "';";
      /* Execute SQL statement */
      rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
      if (rc == SQLITE_OK)
      {
         cout << "success" << endl;
         return true;
      }
      else
      {
         cout << "Hata" << zErrMsg;
         sqlite3_free(zErrMsg);
         return false;
      }
   }
}
bool updateTask(int id)
{
   return false;
}

/* CREATE TABLE "task" (
	"id"	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
	"name"	TEXT NOT NULL,
	"detail"	TEXT,
	"date"	TEXT NOT NULL,
	"repeat"	TEXT
); */