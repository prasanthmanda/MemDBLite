#pragma once

#include <string>

class DBImpl;

class DB {
public:
    DB(size_t max_size);
    ~DB();

    void set(const std::string& key, const std::string& value);
    void get(const std::string& key) const; // Marked as const again
    void del(const std::string& key);
    void update(const std::string& key, const std::string& value);
    void listAll() const;
    void clear();
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    DBImpl* implementation_;
};
