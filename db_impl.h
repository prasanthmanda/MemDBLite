#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>

class DBImpl {
public:
    DBImpl(size_t max_size);

    void set(const std::string& key, const std::string& value);
    void get(const std::string& key) const; // Marked as const
    void del(const std::string& key);
    void update(const std::string& key, const std::string& value);
    void listAll() const;
    void clear();
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    void evictIfNeeded();

    std::unordered_map<std::string, std::string> storage_;
    mutable std::unordered_map<std::string, bool> reference_bits_; // Mutable to allow modification
    std::vector<std::string> keys_;
    size_t max_size_;
    size_t clock_hand_;
};
