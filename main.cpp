#include <iostream>
#include "cli.h"
#include "db.h"

int main() {
    DB db(100);
    CLI cli(db);
    cli.execute();
    return 0;
}