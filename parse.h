#ifndef PROLOGUE

#define PROLOGUE

#include <iostream>
#include <stack>
#include <string>
#include <climits>

using std::stack;
using std::string;
using std::cin;
using std::cout;
using std::endl;

const int INF = -1;
const int ERROR = -2;
const int NOTHING = -3;


#endif

#ifndef REGULAR_PARSE_PARSE_H

#define REGULAR_PARSE_PARSE_H

class IntInf {
public:
    IntInf(int x) : val(x) {}
    IntInf operator+(const IntInf& other) const;
    bool operator<(const IntInf& other) const;
    bool operator>(const int other) const;
    bool operator==(const IntInf& other);
    void operator=(const IntInf& other);
    int return_val();
private:
    int val;
};

struct Duo {
    Duo (int l, int w) : max_k_word(w), max_k_len(l) {}
    Duo (IntInf l, IntInf w) : max_k_word(w), max_k_len(l) {}
    IntInf max_k_len;
    IntInf max_k_word;
};

int parse(string& polish_str, char k);

#endif //REGULAR_PARSE_PARSE_H
