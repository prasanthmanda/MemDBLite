#include "db.h"
#include "db_impl.h"

DB::DB(size_t max_size) : implementation_(new DBImpl(max_size)) {}
DB::~DB() { delete implementation_; }

void DB::set(const std::string& key, const std::string& value) { implementation_->set(key, value); }
void DB::get(const std::string& key) const { implementation_->get(key); }
void DB::del(const std::string& key) { implementation_->del(key); }
void DB::update(const std::string& key, const std::string& value) { implementation_->update(key, value); }
void DB::listAll() const { implementation_->listAll(); }
void DB::clear() { implementation_->clear(); }
void DB::saveToFile(const std::string& filename) const { implementation_->saveToFile(filename); }
void DB::loadFromFile(const std::string& filename) { implementation_->loadFromFile(filename); }
