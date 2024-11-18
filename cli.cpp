#include "cli.h"
#include <iostream>
#include <sstream>

// Constructor initializes the CLI with the database instance
CLI::CLI(DB& db) : database_(db) {}

// Method to run the command-line interface
void CLI::execute() {
    std::cout << "====================================" << std::endl;
    std::cout << "Welcome to MemDBLite CLI!" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "Commands: SET, GET, DELETE, UPDATE, LIST, CLEAR, SAVE, LOAD, EXIT" << std::endl;
    std::cout << std::endl;

    std::string input;
    // Loop to continuously accept user input
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);
        processCommand(input);
    }
}

// Method to process user commands
void CLI::processCommand(const std::string& input) {
    std::istringstream stream(input);
    std::string cmd, key, value, filename;
    stream >> cmd;

    // Convert command to uppercase for case-insensitive matching
    for (auto &c : cmd) c = toupper(c);

    if (cmd == "SET") {
        stream >> key >> value;
        if (key.empty() || value.empty()) {
            std::cerr << "Error: SET command requires both a key and a value." << std::endl;
        } else {
            database_.set(key, value);
        }
    } 
    else if (cmd == "GET") {
        stream >> key;
        if (key.empty()) {
            std::cerr << "Error: GET command requires a key." << std::endl;
        } else {
            database_.get(key);
        }
    } 
    else if (cmd == "DELETE") {
        stream >> key;
        if (key.empty()) {
            std::cerr << "Error: DELETE command requires a key." << std::endl;
        } else {
            database_.del(key);
        }
    } 
    else if (cmd == "UPDATE") {
        stream >> key >> value;
        if (key.empty() || value.empty()) {
            std::cerr << "Error: UPDATE command requires both a key and a value." << std::endl;
        } else {
            database_.update(key, value);
        }
    } 
    else if (cmd == "LIST") {
        database_.listAll();
    } 
    else if (cmd == "CLEAR") {
        database_.clear();
        std::cout << "Database cleared." << std::endl;
    } 
    else if (cmd == "SAVE") {
        stream >> filename;
        if (filename.empty()) {
            std::cerr << "Error: SAVE command requires a filename." << std::endl;
        } else {
            database_.saveToFile(filename);
        }
    } 
    else if (cmd == "LOAD") {
        stream >> filename;
        if (filename.empty()) {
            std::cerr << "Error: LOAD command requires a filename." << std::endl;
        } else {
            database_.loadFromFile(filename);
        }
    } 
    else if (cmd == "EXIT") {
        std::cout << "Exiting MemDBLite... Goodbye!" << std::endl;
        exit(0);
    } 
    else {
        std::cerr << "Invalid command. Type a valid command." << std::endl;
    }
}
