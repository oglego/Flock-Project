#include "../include/motherduck.h"

int main() {
    // Create the main coordinator (Mother Duck)
    MotherDuck md;

    // Create ducklings (workers)
    Duckling duckling1(1), duckling2(2), duckling3(3), duckling4(4), duckling5(5);
    md.addDuckling(&duckling1);
    md.addDuckling(&duckling2);
    md.addDuckling(&duckling3);
    md.addDuckling(&duckling4);
    md.addDuckling(&duckling5);

    // Different queries for each worker (ducklings)
    std::vector<std::string> queries = {
        "SELECT COUNT(*) FROM data;",
        "SELECT SUM(value) FROM data;",
        "SELECT AVG(value) FROM data;",
        "SELECT MIN(value) FROM data;",
        "SELECT MAX(value) FROM data;"
    };

    // Distribute the queries amongst the ducklings for parallel execution
    md.distributeQuery(queries);

    return 0; 
}
