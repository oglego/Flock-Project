#ifndef MOTHERDUCK_H
#define MOTHERDUCK_H

#include "duckling.h"
#include <vector>
#include <thread>
#include <mutex>
#include <iostream>

/**
* @brief Represents a central coordinator (mother duck) managing 
* multiple (duckling) instances.
* 
* This class provides a functionality to add ducklings to a list and
* then distribute queries amongst them.
*/
class MotherDuck {
private:
    std::vector<Duckling*> ducklings; // Collection of duckling instances
public:
    /**
    * @brief Adds a duckling instance to the list
    * @param duckling pointer to a duckling object
    */
    void addDuckling(Duckling* duckling);

    /**
    * @brief Distributes a set of queries among the managed ducklings
    * @param queries reference to a vector of strings to be processed
    */
    void distributeQuery(std::vector<std::string> &queries);
};

#endif // MOTHERDUCK_H
