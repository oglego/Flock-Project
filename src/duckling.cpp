#include "../include/duckling.h"

/**
* @brief constructs a duckling instance with a given id
*
* This constructor initializes a duckling object by setting its ID
* and calling `InitializeDatabase()` to ensure that a database connection
* is established before queries are executed.
*
* @param id The unique identifier for this duckling instance
*/

Duckling::Duckling(int id) : id(id) {
    InitializeDatabase();
}

/**
* @brief Executes a given sql query on the DuckDB database.
*
* This method will run the provided sql query using the database connection - if the
* query executes successfully and returns results, it will created a formatted output
* containing the query and the results.  If an error occurs, it will capture the
* error and return it.
*
* @param query the sql query to be executed
* @return A formatted string containing the result or an error message
*/
std::string Duckling::executeQuery(const std::string &query) {
    // Execute the query and store the result
    auto result = conn->Query(query);
    std::string output;

    // Check if the query executed successfully and return the results
    if (!result->HasError() && result->RowCount() > 0) {
        for (size_t row = 0; row < result->RowCount(); row++) {
            // Output to show what query ran the result set returned by the statement
            output += "Ran query: " + query + " Result: " + std::to_string(result->GetValue<int64_t>(0, row)) + "\n";
        }
    } 
    // Handle errors
    else if (result->HasError()) {
        output = "Error: " + result->GetError() + "\n";
    }
    return output;
}
