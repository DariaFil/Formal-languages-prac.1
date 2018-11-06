#ifndef PROLOGUE

#define PROLOGUE

#include <iostream>
#include <stack>
#include <string>

using std::stack;
using std::string;
using std::cin;
using std::cout;
using std::endl;

#endif

#ifndef REGULAR_PARSE_PARSE_H

#define REGULAR_PARSE_PARSE_H

struct Duo {
    Duo (int l, int w);
    int max_k_len;
    int max_k_word;
};

Duo parse(string& polish_str, char k);

#endif //REGULAR_PARSE_PARSE_H
