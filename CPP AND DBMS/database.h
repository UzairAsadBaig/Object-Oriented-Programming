/**
 * @(#)database.h   1.0.0
 *
 * Copyright 2004 Vijay Mathew Pandyalakal. All rights reserved.
 *
 * Change history:
 * Created on July 26, 2004
 * Last Modified on January 01, 2007
 *
 */

#ifndef DSQLXPREZ_2_H
#define DSQLXPREZ_2_H

#include <string>
#include <vector>
#include <exception>
#include "sqlite3.h"





  class Statement;
  class DatabaseMetaData;
  class ResultSet;
  class ResultSetMetaData;

  /**
   * class SQLException
   * Thrown by DsqlXprez classes accesing the database
   * @since 1.0.0
   */
  class SQLException : std::exception
  {
  public:
    SQLException(int code); /// Creates an exception with the given code
    SQLException(std::string msg); /// Creates an exception with the given message
    ~SQLException();
    int getCode(); /// Returns the error code
    std::string getMessage(); /// Returns the error message
    const char* what() const;
  private:
    void setMessageFromCode(); /// Creates a message from the current error code
  private:
    int m_nCode; /// Error code
    std::string m_strMsg; /// Error message
    
  };

  /**
   * class Connection
   * Interface with the low-level database
   * @since 1.0.0
   */
  class Connection 
  {
  public:
    Connection(); /// Constructor
    ~Connection(); /// Destructor
    void open(const char* db_name); /// opens a database
    Statement* createStatement(); /// Creates and returns a statement object
    DatabaseMetaData* getDatabaseMetaData(); /// Returns meta data of the entire database
    void refreshMetaData(); /// Refreshes the meta data
    void close(); /// closes the database and releases all resources
  private:
    sqlite3 *m_sqlite; /// Handle to the database engine
    Statement* m_stmt; /// Handle to the object to execute sql commands
    DatabaseMetaData* m_dbMtdt; /// Database metadata
  };

  /**
   * class Statement
   * Class to execute SQL commands
   * @since 1.0.0
   */
  class Statement 
  {
  public:
    Statement(sqlite3 *pSqlite); /// Constructor
    ~Statement(); /// Destructor
    int execute(const char* sql); /// Executes an sql and returns the number of rows affected
    ResultSet* executeQuery(const char* sql); /// Executes an sql and returns a pointer to the resultset
  private:
    sqlite3 *m_sqlite;
    ResultSet* m_rslt;
  };

  /**
   * class ResultSet
   * Wraps up the result of a SELECT
   * @since 1.0.0
   */
  class ResultSet 
  {
  public:
    ResultSet(sqlite3_stmt *ps); /// Constructor
    ~ResultSet(); /// Destructor
    bool next(); /// Moves to the next row of the resultset
    bool isNull(int colNum); /// Returns true if the given column has a null value
    std::string getString(int colNum); /// Returns data of column as a string
    int getInt(int colNum); ///  Returns data of column as an int
    long getLong(int colNum); ///  Returns data of column as a Long
    unsigned int getUInt(int colNum); ///  Returns data of column as an unsiged int
    unsigned long getULong(int colNum); ///  Returns data of column as a unsigned long
    float getFloat(int colNum); ///  Returns data of column as a float
    double getDouble(int colNum); ///  Returns data of column as a double
    bool getBoolean(int colNum); ///  Returns data of column as a bool

    ResultSetMetaData* getMetaData(); /// Returns meta data of the resultset
  private:
    sqlite3_stmt *m_stmt;
    ResultSetMetaData *m_rsltMtdt;
    int m_nRes;
    bool m_bSecondStep;
  };

  /**
   * struct Column
   * Represents a single column in a resultset
   * @since 1.0.0
   */
  struct Column 
  {
    std::string name_; /// Column name
    std::string type_; /// Data type
  };

  /**
   * class ResultSetMetaData
   * reprrsents meta data of a resultset
   * @since 1.0.0
   */
  class ResultSetMetaData 
  {
  public:
    ResultSetMetaData(std::vector<Column> vct); /// Constructor
    int getColumnCount(); /// Returns number of columns in the resultset
    std::string getColumnName(int colNum); /// Returns the name of the column
    std::string getColumnType(int colNum); /// Returns the datatype of the column
  private:
    std::vector<Column> m_vctColumns;
  };

  /**
   * struct DatabaseObject
   * Represents an object (like a table,index..) in the database
   * @since 1.0.0
   */
  struct DatabaseObject 
  {
    std::string name_; /// Object name
    std::string type_; /// Object type
    std::string sql_; /// Object sql
  };

  /**
   * class DatabaseMetaData 
   * Wraps up the meta data of the entire database
   * @since 1.0.0
   */
  class DatabaseMetaData 
  {
  public:
    DatabaseMetaData(std::vector<DatabaseObject> vct); /// Constructor
    int getNumObjects(); /// Returns the number of objects in the database
    std::string getName(int colNum); /// Returns the name of the object at the given position
    std::string getType(int colNum); /// Returns the type of the object at the given position
    std::string getSql(int colNum); /// Returns the sql that created the object at the given position
    bool doesObjectExist(const char* name_,const char* type); /// Checks if the given object exists in the database
  private:
    std::vector<DatabaseObject> m_vctObjects;
  };


#endif
