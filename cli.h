#pragma once

#include "db.h"

class CLI {
public:
    CLI(DB& db);
    void execute();

private:
    void processCommand(const std::string& input);
    DB& database_;
};