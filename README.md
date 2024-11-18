
# MemDBLite

**MemDBLite** is a lightweight, in-memory key-value database built in C++. It offers a simple command-line interface (CLI) to manage key-value pairs efficiently. It supports storing, retrieving, updating, deleting, and listing entries. The database also features persistence capabilities, allowing users to save the database state to a file and reload it when needed.

---

## 🚀 Features
- **In-Memory Storage**: Fast data access using an in-memory key-value store.
- **Approximate LRU Eviction**: Uses the Clock algorithm for efficient memory management.
- **Command-Line Interface (CLI)**: Easy-to-use CLI for database management.
- **Persistence Support**: Save and load the database state to/from a file.

---

## 🛠️ Getting Started

### Prerequisites
- A C++ compiler (`g++` recommended, with support for C++11 or later)
- `make` (to build the project)

### 📦 Building the Project
```bash
# Clone the repository
git clone https://github.com/prasanthmanda/MemDBLite.git
cd MemDBLite

# Build the project
make
```

### 🚀 Running the Database
```bash
# Run the CLI application
./memdblite
```

---

## 📝 Commands and Usage

### 1. `SET key value`
Store a key-value pair in the database.
```plaintext
> SET username alice
Key set: username = alice
```

### 2. `GET key`
Retrieve the value associated with a key.
```plaintext
> GET username
username: alice
```

### 3. `DELETE key`
Remove a key-value pair from the database.
```plaintext
> DELETE username
Key deleted: username
```

### 4. `UPDATE key value`
Update the value of an existing key.
```plaintext
> UPDATE username bob
Key updated: username = bob
```

### 5. `LIST`
List all stored key-value pairs.
```plaintext
> LIST
username = bob
email = bob@example.com
```

### 6. `CLEAR`
Clear all entries in the database.
```plaintext
> CLEAR
All keys cleared
```

### 7. `SAVE filename`
Save the current database state to a file.
```plaintext
> SAVE database.txt
Database saved to database.txt
```

### 8. `LOAD filename`
Load the database state from a file.
```plaintext
> LOAD database.txt
Database loaded from database.txt
```

### 9. `EXIT`
Exit the CLI application.
```plaintext
> EXIT
Exiting MemDBLite... Goodbye!
```



## 🛠️ Future Milestones
- **Write-Ahead Logging (WAL)**: Add durability and crash recovery.
- **TCP/IP Interface**: Allow remote database access over a network.
- **I/O Multiplexing**: Handle multiple connections using a single-threaded event loop.
- **Support for Multiple Data Types**: Extend to support integers, floats, and binary data.

---

## 🤝 Contributing
Contributions are welcome! Feel free to open issues or submit pull requests.

### Building for Development
```bash
make clean
make
```

### Running Tests
```bash
make test
./tests
```

---

## 📄 License
This project is licensed under the MIT License.
