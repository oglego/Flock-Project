#ifndef DUCKLING_H
#define DUCKLING_H

#include "database.h"
#include <string>

/**
 * @brief Represents a Duckling entity that interacts with the database.
 * 
 * This class provides a simple interface for executing SQL queries
 * using the global DuckDB connection.
 */
class Duckling {
private:
    int id;  ///< Unique identifier for the Duckling instance.
public:
    /**
     * @brief Constructs a Duckling with a given ID.
     * 
     * @param id The unique identifier for the Duckling.
     */
    explicit Duckling(int id);

    /**
     * @brief Executes an SQL query using the global database connection.
     * 
     * @param query The SQL query to be executed.
     * @return The result of the query as a string.
     */
    std::string executeQuery(const std::string &query);
};

#endif // DUCKLING_H
