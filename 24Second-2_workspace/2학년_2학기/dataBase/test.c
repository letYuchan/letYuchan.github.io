#include <stdio.h>
#include <sqlite3.h>
int main(int argc, char* argv[]) {
    sqlite3* db;
    char* zErrMsg = 0;
    int rc;
    rc = sqlite3_open("test.db", &db);
    if (rc) {
            fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
            return(0);
        }
    else {
        fprintf(stderr, "Opened database successfully\n");
        }
    char* sql;
    sql = "CREATE TABLE COMPANY( NAME TEXT NOT NULL);";
    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    sqlite3_close(db);
}