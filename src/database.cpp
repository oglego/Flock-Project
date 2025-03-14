#include "../include/database.h"

// Define global database objects
std::unique_ptr<DuckDB> db;
std::unique_ptr<Connection> conn;

/**
* @brief Initializes an in-memory DuckDB database and creates a sample table
* 
* This function checks if the database instance (`db`) is unitialized - if it is
* then it will create an in-memory DuckDB instance and create a connection to it.
*
* It will then create a `data` table with two columns (id, value) and then inserts
* sample records in for demonstration purposes.
*
*/
void InitializeDatabase() {
    // Check if database is already initialized
    if (!db) {
        db = std::make_unique<DuckDB>(nullptr); // In-memory database
        conn = std::make_unique<Connection>(*db); // Establish a connection

        // Create table and insert sample data
        conn->Query("CREATE TABLE data(id INTEGER, value INTEGER);");
        conn->Query("INSERT INTO data VALUES (1, 100), (2, 200), (3, 300), (4, 400), (5, 500);");
    }
}
