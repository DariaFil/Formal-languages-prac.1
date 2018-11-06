#include "parse.h"
#include "tests.h"

string error_tests() {
    char letter = 'a';
    string str;
    if (parse(str, letter) != ERROR) return "ERROR TEST 1";
    str = "2";
    if (parse(str, letter) != ERROR) return "ERROR TEST 2";
    str = "abs.+";
    if (parse(str, letter) != ERROR) return "ERROR TEST 3";
    str = "ab.+";
    if (parse(str, letter) != ERROR) return "ERROR TEST 4";
    str = "*";
    if (parse(str, letter) != ERROR) return "ERROR TEST 5";
    str = "abc.";
    if (parse(str, letter) != ERROR) return "ERROR TEST 6";
    str = "ab/";
    if (parse(str, letter) != ERROR) return "ERROR TEST 7";
    if (parse(str, '1') != ERROR) return "ERROR TEST 8";
    if (parse(str, 'd') != ERROR) return "ERROR TEST 9";
    if (parse(str, '+') != ERROR) return "ERROR TEST 10";
    return "ALL ERROR TESTS PASSED";
}

string regular_tests() {
    char letter = 'a';
    string str = "ab.";
    if (parse(str, letter) != 1) return "REGULAR TEST 1";
    str = "ab+";
    if (parse(str, letter) != 1) return "REGULAR TEST 2";
    str = "ba+";
    if (parse(str, letter) != 1) return "REGULAR TEST 3";
    str = "ba.";
    if (parse(str, letter) != 0) return "REGULAR TEST 4";
    str = "b";
    if (parse(str, letter) != 0) return "REGULAR TEST 5";
    str = "abc.+";
    if (parse(str, letter) != 1) return "REGULAR TEST 6";
    str = "abc+.";
    if (parse(str, letter) != 1) return "REGULAR TEST 7";
    str = "a*";
    if (parse(str, letter) != INF) return "REGULAR TEST 8";
    str = "ab+*";
    if (parse(str, letter) != INF) return "REGULAR TEST 9";
    str = "ab.*";
    if (parse(str, letter) != 1) return "REGULAR TEST 10";
    str = "ba.*";
    if (parse(str, letter) != 0) return "REGULAR TEST 11";
    str = "aba.*.a.";
    if (parse(str, letter) != 2) return "REGULAR TEST 12";
    str = "acb..bab.c.*.ab.ba.+.+*a.";
    if (parse(str, letter) != 1) return "REGULAR TEST 13";
    str = "ba*.";
    if (parse(str, letter) != 0) return "REGULAR TEST 14";
    str = "abc+.";
    if (parse(str, letter) != 1) return "REGULAR TEST 15";
    return "ALL REGULAR TESTS PASSED";
}

void run_all_tests() {
    cout << error_tests() << endl;
    cout << regular_tests() << endl;
}