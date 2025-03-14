# Flock: A Simple Distributed Query Executor

## Overview
Flock is a simple distributed query execution system that demonstrates parallel query processing using DuckDB. It simulates a principal/agent model, where `MotherDuck` (the coordinator) distributes SQL queries to multiple `Duckling` workers, each running in its own thread.

## Features
- **Parallel Query Execution:** Queries are executed concurrently by multiple `Duckling` instances.
- **DuckDB Integration:** Uses DuckDB as the in-memory database backend.
- **Thread-Safe Query Distribution:** Ensures results are safely aggregated using a mutex.
- **Simple API:** Easily add workers (`Duckling`) and distribute queries using `MotherDuck`.

## Project Structure
```
Flock/
│── include/
│   ├── motherduck.h
│   ├── duckling.h
|   ├── database.h
│── src/
│   ├── motherduck.cpp
│   ├── duckling.cpp
│   ├── main.cpp
|   ├── database.cpp
│── README.md
│── Makefile
```
## Installation
### Prerequisites
- C++17 or later
- [DuckDB](https://duckdb.org/) (included via C++ API)
- A C++ compiler (e.g., `clang`)

### Building the Project
If using a `Makefile`, simply run:
```sh
make
```

## Usage
### Running the Program
After compiling, execute:
```sh
./flock_project
```

### Expected Output
The program initializes an in-memory DuckDB instance, creates a `data` table, and executes the following queries concurrently:
- `SELECT COUNT(*) FROM data;`
- `SELECT SUM(value) FROM data;`
- `SELECT AVG(value) FROM data;`
- `SELECT MIN(value) FROM data;`
- `SELECT MAX(value) FROM data;`

Sample output:
```
Aggregated Results:

Ran query: SELECT COUNT(*) FROM data; Result: 5

Ran query: SELECT SUM(value) FROM data; Result: 1500

Ran query: SELECT AVG(value) FROM data; Result: 300

Ran query: SELECT MIN(value) FROM data; Result: 100

Ran query: SELECT MAX(value) FROM data; Result: 500
```

## How It Works
1. **Initialization:**
   - `main.cpp` creates a `MotherDuck` instance.
   - Five `Duckling` workers are created and registered.
   - An in-memory DuckDB database is initialized.
2. **Query Distribution:**
   - `MotherDuck::distributeQuery()` assigns each query to a separate `Duckling`.
   - Queries are executed concurrently using `std::thread`.
   - A mutex ensures safe aggregation of query results.
3. **Result Aggregation:**
   - After all queries complete, results are printed to the console.


