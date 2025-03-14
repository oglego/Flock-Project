#include "../include/motherduck.h"

std::mutex result_mutex; ///< Mutex to ensure thread-safe access to shared resources

/**
* @brief Add a duckling instance to the list
*
* This method will register a new duckling by appending it to the `ducklings` vector.
*
* @param duckling Pointer to the duckling instance added
*/
void MotherDuck::addDuckling(Duckling* duckling) {
    ducklings.push_back(duckling);
}

/**
* @brief Distributes a set of queries among available ducklings for parallel execution
*
* This method creates a separate thread for each query, assigns it to a duckling, and then
* executes the queries concurrently.  The results are collected and the printed out.
*
* @param queries A reference to a vector of sql query strings to be executed 
*/
void MotherDuck::distributeQuery(std::vector<std::string> &queries) {
    std::vector<std::thread> threads; ///< Vector to manage worker threads (ducklings)
    std::vector<std::string> results; ///< Vector to store query results

    // Iterate over the ducklings and queries assigning each a query to execute
    for (int i = 0; i < ducklings.size() && i < queries.size(); i++) {
        threads.emplace_back([&, i]() {
            // Execute the query using the assigned duckling
            std::string result = ducklings[i]->executeQuery(queries[i]);

            // Ensure thread-safe access when storing the result
            std::lock_guard<std::mutex> lock(result_mutex);
            results.push_back(result);
        });
    }

    // Wait for all the threads to complete execution
    for (auto &t : threads) {
        t.join();
    }

    // Print all query results
    std::cout << "\nAggregated Results:\n\n";
    for (const auto &res : results) {
        std::cout << res << std::endl;
    }
}
