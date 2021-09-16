#include <iostream>
#include "func.h"

using namespace func;

int main() {
    struct Line *ln = nullptr;
    int m;

    ln = input(m);
    if(!ln){
        std::cout << "incorrect data" << std::endl;
        return 1;
    }

    output("Sourced matrix", ln, m);
    ln = sort(ln);
    output("Sorted matrix", ln, m);
    erase(ln, m);
    return 0;
}
