#include "database.h"
#include <iostream>
#include <fstream>

using namespace std;

void verifyDB(const string &dbname)
{
	ifstream db(dbname.c_str(), ios::binary);
	if(!db)
	{
		Connection conn;
		conn.open(dbname.c_str()); // the argument is the database name.
		Statement* stmt = conn.createStatement();
		stmt->execute("create table albums(title,artist)"); // creates a table
	}
	else
	{
		db.close();
	}
}

int main() {
	
	string dbname = "mydb.db";
	verifyDB(dbname);
	
	Connection conn;
	conn.open(dbname.c_str()); // the argument is the database name.
	Statement* stmt = conn.createStatement();

   // remove old data
	cout << endl << stmt->execute("delete from albums");
   // insert some data
	cout << endl << stmt->execute("insert into albums values('Chandni ratain','Noor Jahan')");
	cout << endl << stmt->execute("insert into albums values('Dil dil Pakistan','JJ')");
	cout << endl << stmt->execute("insert into albums values('Gai gi dunya','Noor Jahan')");
	cout << endl << stmt->execute("insert into albums values('Aey putter hattann','Noor Jahan')");
	cout << endl << stmt->execute("insert into albums values('Hum kyun chalenn','JJ')");
	cout << endl << endl;
	
	string ttl = "JJ";
	string sql = "select * from albums where artist=\'" + ttl + "\'"; ;
	cout << endl << sql << endl;
	
	ResultSet* rslt = stmt->executeQuery(sql.c_str());
	ResultSetMetaData* r_mtdt = rslt->getMetaData();
	int cols = r_mtdt->getColumnCount();
	/*
	while(rslt->next()) {
	  	for(int i=1;i<=cols;i++) {
				cout << r_mtdt->getColumnName(i);
				cout << "(";
				cout << r_mtdt->getColumnType(i);
				cout << ",";
				cout << rslt->getString(i);
				cout << ")";
				cout << endl;
	  	}
	  	cout << endl;
	}
	*/
	for(int i=1;i<=cols;i++) {
		cout << r_mtdt->getColumnName(i) << "\t|\t";
	}
  	cout << endl;
	while(rslt->next()) {
		cout << rslt->getString(1);
		cout << "\t|\t";
		cout << rslt->getString(2);
	  	cout << endl;
	}
	conn.close();
}


