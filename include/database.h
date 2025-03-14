#ifndef DATABASE_H
#define DATABASE_H

#include "duckdb.hpp"
#include <memory>

// Import DuckDB symbols into the current namespace
using namespace duckdb;

/**
 * @brief Initializes the DuckDB database.
 * 
 * This function is responsible for setting up the DuckDB instance and 
 * establishing a connection. It should be called before executing any queries.
 */
void InitializeDatabase();

/**
 * @brief Global database instance.
 * 
 * This unique pointer holds the DuckDB database instance, which manages
 * storage and execution of queries.
 */
extern std::unique_ptr<DuckDB> db;

/**
 * @brief Global database connection.
 * 
 * This unique pointer represents a connection to the DuckDB database,
 * allowing execution of SQL queries.
 */
extern std::unique_ptr<Connection> conn;

#endif // DATABASE_H
