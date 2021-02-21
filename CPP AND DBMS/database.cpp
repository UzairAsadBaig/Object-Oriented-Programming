/**
 * @(#)database.cpp   1.0.0
 *
 * Copyright 2004 Vijay Mathew Pandyalakal. All rights reserved.
 *
 * Change history:
 * Created on July 26, 2004
 * Last Modified on January 11, 2007
 *
 */

#include <algorithm>
#include <iterator>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include "database.h"

/**
 * This file defines C++ abtractions to provide a JDBC style interface to SQLite.
 * @author Vijay Mathew Pandyalakal
 * @since 1.0.0
 */

// class SqlException

/**
 * Creates an exception with the given code
 * @param code error code
 * @since 1.0.0
 */	
SQLException::SQLException(int code)
  : m_nCode(code)
{
  setMessageFromCode();
}

/**
 * Creates an exception with the given message
 * @param msg Error message
 * @since 1.0.0
 */
SQLException::SQLException(std::string msg) 
  : m_nCode(0), m_strMsg(msg)
{
}

SQLException::~SQLException(){ }

const char*
SQLException::what() const
{
  std::ostringstream oss;
  oss << m_nCode << ": " << m_strMsg;
  return oss.str().c_str();
}

/**
 * Returns the error code
 * @return int
 * @since 1.0.0
 */
int 
SQLException::getCode() 
{
  return m_nCode;
}

/**
 * Returns the error message
 * @return string
 * @since 1.0.0
 */
std::string 
SQLException::getMessage() 
{
  return m_strMsg;
}

/**
 * Creates a message from the current error code
 * @since 1.0.0
 */	
void 
SQLException::setMessageFromCode() 
{
  if (m_nCode == SQLITE_ERROR) m_strMsg = "SQL error or missing database";
  else if(m_nCode == SQLITE_INTERNAL) m_strMsg = "An internal logic error in the database";
  else if(m_nCode == SQLITE_PERM) m_strMsg = "Access permission denied";
  else if(m_nCode == SQLITE_ABORT) m_strMsg = "Callback routine requested an abort";
  else if(m_nCode == SQLITE_BUSY) m_strMsg = "The database file is locked";
  else if(m_nCode == SQLITE_LOCKED) m_strMsg = "A table in the database is locked";
  else if(m_nCode == SQLITE_NOMEM) m_strMsg = "A memory allocation failed in the database";
  else if(m_nCode == SQLITE_READONLY) m_strMsg = "Attempt to write a readonly database";
  else if(m_nCode == SQLITE_INTERRUPT) m_strMsg = "Operation terminated by a database interrupt";
  else if(m_nCode == SQLITE_IOERR) m_strMsg = "Some kind of disk I/O error occurred";
  else if(m_nCode == SQLITE_CORRUPT) m_strMsg = "The database disk image is malformed";
  else if(m_nCode == SQLITE_NOTFOUND) m_strMsg = "Table or record not found";
  else if(m_nCode == SQLITE_FULL) m_strMsg = "Insertion failed because database is full";
  else if(m_nCode == SQLITE_CANTOPEN) m_strMsg = "Unable to open the database file";
  else if(m_nCode == SQLITE_PROTOCOL) m_strMsg = "Database lock protocol error";
  else if(m_nCode == SQLITE_EMPTY) m_strMsg = "Database table is empty";
  else if(m_nCode == SQLITE_SCHEMA) m_strMsg = "The database schema changed";
  else if(m_nCode == SQLITE_TOOBIG) m_strMsg = "Too much data for one row of a table";
  else if(m_nCode == SQLITE_CONSTRAINT) m_strMsg = "Abort due to contraint violation";
  else if(m_nCode == SQLITE_MISMATCH) m_strMsg = "Data type mismatch";
  else if(m_nCode == SQLITE_MISUSE) m_strMsg = "Library used incorrectly";
  else if(m_nCode == SQLITE_NOLFS) m_strMsg = "Uses OS features not supported on host";
  else if(m_nCode == SQLITE_AUTH) m_strMsg = "Authorization denied";
  else m_strMsg = "Unknown database error";
}
	
	
// class Connection

/**
 * Constructor
 * @since 1.0.0
 */
Connection::Connection()
  : m_sqlite(0), m_stmt(0), m_dbMtdt(0)
{
}

/**
 * Destructor
 * @since 1.0.0
 */
Connection::~Connection() 
{
  close();
}

/**
 * Opens a database. The database is created, if not found.
 * @param db_name database name
 * @since 1.0.0
 */
void 
Connection::open(const char* db_name) 
  
{
  close();
  int ret = sqlite3_open(db_name,&m_sqlite);
  if (ret != SQLITE_OK) 
    {		
      close();
      throw SQLException(ret);
    }
  m_dbMtdt = NULL;

  // fills in the DatabaseMetaData
  refreshMetaData();
}

/**
 * Creates and returns a statement object
 * @return Statement*
 * @since 1.0.0
 */
Statement* 
Connection::createStatement() 
{
  delete m_stmt;
  m_stmt = new Statement(m_sqlite);
  return m_stmt;
}

/**
 * Returns meta data of the entire database
 * @return DatabaseMetaData*
 * @since 1.0.0
 */
DatabaseMetaData* 
Connection::getDatabaseMetaData() 
{	
  return m_dbMtdt;
}

/**
 * Refreshes the meta data
 * @since 1.0.0
 */
void 
Connection::refreshMetaData()
{
  sqlite3_stmt *stmt;
  std::string sql = "select type,name,sql from sqlite_master";
  int ret = sqlite3_prepare(m_sqlite,sql.c_str(),sql.length(),&stmt,NULL);	
  if (ret != SQLITE_OK)
    throw SQLException(ret);
  int res = sqlite3_step(stmt);
  std::vector<DatabaseObject> vct;
  while (true) 
    {
      if (res != SQLITE_ROW && res != SQLITE_OK && res != SQLITE_DONE)
	throw SQLException(res);
      if (res != SQLITE_ROW) break;		
      DatabaseObject dobj;
      dobj.type_ = (const char*)sqlite3_column_text(stmt,0);
      dobj.name_ = (const char*)sqlite3_column_text(stmt,1);
      dobj.sql_ = (const char*)sqlite3_column_text(stmt,2);
      vct.push_back(dobj);
      res = sqlite3_step(stmt);
    }	
  sqlite3_finalize(stmt);
  delete m_dbMtdt;
  m_dbMtdt = new DatabaseMetaData(vct);
}

/**
 * Closes the database and releases all resources
 * @since 1.0.0
 */
void 
Connection::close() 
{
  delete m_stmt;
  m_stmt = NULL;
  delete m_dbMtdt;
  m_dbMtdt = NULL;
  if (m_sqlite != NULL) 
    {
      sqlite3_close(m_sqlite);
      m_sqlite = NULL;
    }
}
	

// class Statement

/**
 * Constructor
 * @param pS Handle to the core database
 * @since 1.0.0	
 */
Statement::Statement(sqlite3* pS) 
  : m_sqlite(pS), m_rslt(0)
{
}

/**
 * Destructor
 * @since 1.0.0
 */
Statement::~Statement() 
{
  delete m_rslt;
}

/**
 * Executes an sql and returns the number of rows affected
 * @param sql SQL to execute
 * @since 1.0.0
 */
int 
Statement::execute(const char* sql) 
{
  int ret = sqlite3_exec(m_sqlite,sql,0,0,0);
  if (ret != SQLITE_OK)
    throw SQLException(ret);  
  return sqlite3_changes(m_sqlite);
}

/**
 * Executes an sql and returns a pointer to the resultset
 * @param sql SQL query
 * @since 1.0.0
 */
ResultSet* 
Statement::executeQuery(const char* sql) 
  
{
  sqlite3_stmt *stmt;
  int ret = sqlite3_prepare(m_sqlite,sql,strlen(sql),&stmt,NULL);
  if (ret != SQLITE_OK) throw SQLException(ret);
  delete m_rslt;
  m_rslt = new ResultSet(stmt);
  return m_rslt;
}


// class ResultSet
		
/**
 * Constructor
 * @param ps Pointer to sqlite statement object
 * since 1.0.0
 */
ResultSet::ResultSet(sqlite3_stmt* ps) 
  
{
  if (ps == NULL) throw SQLException("NULL statement object");	
  m_stmt = ps;
  m_nRes = sqlite3_step(m_stmt);
  if (m_nRes != SQLITE_OK && m_nRes != SQLITE_ROW && m_nRes != SQLITE_DONE)
    throw SQLException(m_nRes);
  m_bSecondStep = true;
  std::vector<Column> vct;
  int col_count = sqlite3_column_count(m_stmt);
  for (int i=0;i<col_count;i++) 
    {
      Column col;
      col.name_ = sqlite3_column_name(m_stmt,i);
      try 
	{
	  const char* type = sqlite3_column_decltype(m_stmt,i);
	  if (type)
	    col.type_ = type;
	  else
	    col.type_ = "VARIANT"; // is this selection good?
	}
      catch(...) 
	{
	  col.type_ = "VARIANT";
	}
      vct.push_back(col);
    }
  m_rsltMtdt = new ResultSetMetaData(vct);
}

/**
 * Destructor
 * @since 1.0.0
 */
ResultSet::~ResultSet() 
{
  if (m_stmt != NULL)  
    {
      sqlite3_finalize(m_stmt);		
      m_stmt = NULL;
    }
  delete m_rsltMtdt; 
}

/**
 * Moves to the next row of the resultset
 * @return bool
 * @since 1.0.0
 */
bool 
ResultSet::next() 
{
  if (m_nRes != SQLITE_ROW) return false;
  if (m_bSecondStep) 
    { 
      m_bSecondStep = false; 
      return true; 
    }
  m_nRes = sqlite3_step(m_stmt);
  if (m_nRes != SQLITE_OK && m_nRes != SQLITE_ROW && m_nRes != SQLITE_DONE)
    throw SQLException(m_nRes);	
  if (m_nRes == SQLITE_DONE) return false;
  return true;
}

/**
 * Returns true if the given column has a null value
 * @return bool
 * @since 1.0.0
 */
bool 
ResultSet::isNull(int colNum) 
{
  // as of now we don't support null
  return false;
}

/**
 * Returns data of column as a string
 * @param colNum Column number, starting at 1
 * @return const char*
 * @since 1.0.0
 */
std::string 
ResultSet::getString(int colNum) 
{
  int i = colNum-1;
  if (i < 0) throw SQLException("Invalid column number");
  std::string ret = (const char*)sqlite3_column_text(m_stmt,(i));
  return ret;
}

/**
 * Returns data of column as an int
 * @param colNum Column number, starting at 1
 * @return int
 * @since 1.0.0
 */
int 
ResultSet::getInt(int colNum) 
{
  return atoi(getString(colNum).c_str());
}

/**
 * Returns data of column as a Long
 * @param colNum Column number, starting at 1
 * @return long
 * @since 1.0.0
 */
long 
ResultSet::getLong(int colNum) 
{
  return atol(getString(colNum).c_str());
}

/**
 * Returns data of column as an unsiged int
 * @param colNum Column number, starting at 1
 * @return unsigned int
 * @since 1.0.0
 */
unsigned int 
ResultSet::getUInt(int colNum) 
{
  return (unsigned int)atoi(getString(colNum).c_str());
}

/**
 * Returns data of column as a unsigned long
 * @param colNum Column number, starting at 1
 * @return unsigned long
 * @since 1.0.0
 */
unsigned long 
ResultSet::getULong(int colNum) 
{
  return (unsigned long)atol(getString(colNum).c_str());
}

/**
 * Returns data of column as a float
 * @param colNum Column number, starting at 1
 * @return float
 * @since 1.0.0
 */
float 
ResultSet::getFloat(int colNum) 
{
  return atof(getString(colNum).c_str());
}

/**
 * Returns data of column as a double
 * @param colNum Column number, starting at 1
 * @return double
 * @since 1.0.0
 */
double 
ResultSet::getDouble(int colNum) 
{
  return (double)atof(getString(colNum).c_str());
}

namespace 
{
  const std::string to_lower(const std::string& s) 
  {
    std::string res;
    std::transform(s.begin(), s.end(), std::back_inserter(res), tolower);
    return res;
  }
}

/**
 * Returns data of column as a bool
 * @param colNum Column number, starting at 1
 * @return double
 * @since 1.0.0
 */
bool 
ResultSet::getBoolean(int colNum) 
{
  std::string str = to_lower(getString(colNum));
  return (str == "true" || str == "1");
}

/**
 * Returns meta data of the resultset
 * @return ResultSetMetaData*
 * @since 1.0.0
 */
ResultSetMetaData* 
ResultSet::getMetaData() 
{
  return m_rsltMtdt;
}

// class ResultSetMetaData

/**
 * Constructor
 * @param vct Vector of columns
 * @since 1.0.0
 */
ResultSetMetaData::ResultSetMetaData(std::vector<Column> vct)
  : m_vctColumns(vct)
{  
}

/**
 * Returns number of columns in the resultset
 * @return int
 * @since 1.0.0
 */
int 
ResultSetMetaData::getColumnCount() 
{
  return m_vctColumns.size();
}

/**
 * Returns the name of the column
 * @param colNum Number of column, starting at 1
 * @return string
 * @since 1.0.0
 */
std::string 
ResultSetMetaData::getColumnName(int colNum) 
  
{
  int i = colNum-1;
  if (i < 0 || i >= m_vctColumns.size())
    throw SQLException("Invalid column number");
  return m_vctColumns[i].name_;
}

/**
 * Returns the datatype of the column
 * @param colNum Number of column, starting at 1
 * @return string
 * @since 1.0.0
 */
std::string 
ResultSetMetaData::getColumnType(int colNum) 
  
{
  int i = colNum-1;
  if (i < 0 || i >= m_vctColumns.size())
    throw SQLException("Invalid column number");
  return m_vctColumns[i].type_;
}
	

// class DatabaseMetaData 

/**
 * Constructor
 * @param Vector of database objects
 * @since 1.0.0
 */
DatabaseMetaData::DatabaseMetaData(std::vector<DatabaseObject> vct) 
  : m_vctObjects(vct)
{  
}

/**
 * Returns the number of objects in the database
 * @return int
 * @since 1.0.0
 */
int 
DatabaseMetaData::getNumObjects() 
{
  return m_vctObjects.size();
}

/**
 * Returns the name of the object at the given position
 * @param colNum Column number,starts at 1
 * @return string
 * @since 1.0.0
 */
std::string 
DatabaseMetaData::getName(int colNum)
{
  int i = colNum - 1;
  if (i < 0 || i >= m_vctObjects.size()) 
    throw SQLException("Invalid column number");
  return m_vctObjects[i].name_;
}

/**
 * Returns the type of the object at the given position
 * @param colNum Column number,starts at 1
 * @return string
 * @since 1.0.0
 */
std::string 
DatabaseMetaData::getType(int colNum)
{
  int i = colNum - 1;
  if (i < 0 || i >= m_vctObjects.size()) 
    throw SQLException("Invalid column number");
  return m_vctObjects[i].type_;
}

/**
 * Returns the sql that created the object at the given position
 * @param colNum Column number,starts at 1
 * @return string
 * @since 1.0.0
 */
std::string 
DatabaseMetaData::getSql(int colNum) 
{
  int i = colNum - 1;
  if (i < 0 || i >= m_vctObjects.size()) 
    throw SQLException("Invalid column number");
  return m_vctObjects[i].sql_;
}

/**
 * Checks if the given object exists in the database
 * @param name_ Name of the object
 * @param type_ Type of the object (table,index)
 * @return bool
 * @since 1.0.0
 */
bool 
DatabaseMetaData::doesObjectExist(const char* name_, 
					     const char* type_)
{
  int sz = m_vctObjects.size();
  for (int i=0;i<sz;i++) 
    {
      if ((to_lower(m_vctObjects[i].name_) == to_lower(name_))
	  && (to_lower(m_vctObjects[i].type_) == to_lower(type_)))
	return true;
    }
  return false;
}
