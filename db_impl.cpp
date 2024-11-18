#include "db_impl.h"
#include <iostream>
#include <algorithm>
#include <fstream>

DBImpl::DBImpl(size_t max_size) : max_size_(max_size), clock_hand_(0) {}

void DBImpl::set(const std::string& key, const std::string& value) {
    if (storage_.size() >= max_size_) {
        evictIfNeeded();
    }

    if (storage_.find(key) == storage_.end()) {
        keys_.push_back(key);
    }

    storage_[key] = value;
    reference_bits_[key] = true;
    std::cout << "Key set: " << key << " = " << value << "\n";
}

void DBImpl::get(const std::string& key) const {
    auto it = storage_.find(key);
    if (it != storage_.end()) {
        std::cout << key << ": " << it->second << "\n";
        reference_bits_[key] = true; // Mark as recently used
    } else {
        std::cerr << "Error: Key '" << key << "' not found\n";
    }
}

void DBImpl::del(const std::string& key) {
    if (storage_.erase(key)) {
        reference_bits_.erase(key);
        keys_.erase(std::remove(keys_.begin(), keys_.end(), key), keys_.end());
        std::cout << "Key deleted: " << key << "\n";
    } else {
        std::cerr << "Error: Key '" << key << "' not found\n";
    }
}

void DBImpl::update(const std::string& key, const std::string& value) {
    auto it = storage_.find(key);
    if (it != storage_.end()) {
        it->second = value;
        reference_bits_[key] = true;
        std::cout << "Key updated: " << key << " = " << value << "\n";
    } else {
        std::cerr << "Error: Key '" << key << "' not found\n";
    }
}

void DBImpl::listAll() const {
    if (storage_.empty()) {
        std::cout << "Database is empty\n";
    } else {
        for (const auto& key : keys_) {
            std::cout << key << " = " << storage_.at(key) << "\n";
        }
    }
}

void DBImpl::clear() {
    storage_.clear();
    reference_bits_.clear();
    keys_.clear();
    std::cout << "All keys cleared\n";
}

void DBImpl::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& key : keys_) {
            file << key << " " << storage_.at(key) << "\n";
        }
        file.close();
        std::cout << "Database saved to " << filename << "\n";
    } else {
        std::cerr << "Error: Unable to open file " << filename << "\n";
    }
}

void DBImpl::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        storage_.clear();
        reference_bits_.clear();
        keys_.clear();
        std::string key, value;
        while (file >> key >> value) {
            storage_[key] = value;
            reference_bits_[key] = true;
            keys_.push_back(key);
        }
        file.close();
        std::cout << "Database loaded from " << filename << "\n";
    } else {
        std::cerr << "Error: Unable to open file " << filename << "\n";
    }
}

void DBImpl::evictIfNeeded() {
    while (true) {
        const std::string& key = keys_[clock_hand_];
        if (!reference_bits_[key]) {
            storage_.erase(key);
            reference_bits_.erase(key);
            keys_.erase(keys_.begin() + clock_hand_);
            std::cout << "Evicted key: " << key << "\n";
            return;
        } else {
            reference_bits_[key] = false;
        }
        clock_hand_ = (clock_hand_ + 1) % keys_.size();
    }
}
