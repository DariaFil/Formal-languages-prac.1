#include "parse.h"

IntInf IntInf::operator+(const IntInf& other) const {
    if (val == INF)
        return INF;
    else if (val == NOTHING) {
        return NOTHING;
    } else
        return val + other.val;
}

bool IntInf::operator<(const IntInf& other) const {
    if (val == INF || other.val == NOTHING)
        return false;
    else if (val == NOTHING || other.val == INF)
        return true;
    else
        return (val < other.val);
}

bool IntInf::operator>(const int other) const {
    if (val == INF || other == NOTHING)
        return true;
    else if (val == NOTHING || other == INF)
        return false;
    else
        return (val > other);
}

bool IntInf::operator==(const IntInf& other) {
    return (val == other.val);
}

void IntInf::operator=(const IntInf& other) {
    val = other.val;
}

int IntInf::return_val(){
    return val;
}

int parse(string& polish_str, char k) {
    stack<Duo> st;
    if (k != 'a' && k != 'b' && k != 'c')
        return ERROR;
    for (char sym : polish_str) {
        if (sym == '+') {
            if (st.size() > 1) {
                Duo second_arg = st.top();
                st.pop();
                second_arg.max_k_len = std::max(second_arg.max_k_len, st.top().max_k_len);
                second_arg.max_k_word = std::max(second_arg.max_k_word, st.top().max_k_word);
                st.pop();
                st.push(Duo(second_arg.max_k_len, second_arg.max_k_word));
            }
            else return ERROR;
        }
        else if (sym == '.') {
            if (st.size() > 1) {
                Duo second_arg = st.top();
                st.pop();
                Duo first_arg = st.top();
                if (first_arg.max_k_len < first_arg.max_k_word + second_arg.max_k_len)
                    second_arg.max_k_len = first_arg.max_k_word + second_arg.max_k_len;
                else
                    second_arg.max_k_len = first_arg.max_k_len;

                second_arg.max_k_word = first_arg.max_k_word + second_arg.max_k_word;
                st.pop();
                st.push(Duo(second_arg.max_k_len, second_arg.max_k_word));
            }
            else return ERROR;
        }
        else if (sym == '*') {
            if (!st.empty()) {
                Duo arg = st.top();
                if (arg.max_k_word > 0)
                    arg.max_k_len = INF;
                else
                    arg.max_k_word = 0;
                st.pop();
                st.push(Duo(arg.max_k_len, arg.max_k_word));
            }
            else return ERROR;
        }
        else if (sym == '1') {
            st.push(Duo(0, 0));
        } else {
            if (sym != 'a' && sym != 'b' && sym != 'c')
                return ERROR;
            int new_k_len = 0;
            int new_k_word = NOTHING;
            if (sym == k) {
                new_k_len = 1;
                new_k_word = 1;
            }
            st.push(Duo(new_k_len, new_k_word));
        }
    }
    if (st.size() > 1 || st.empty()) return ERROR;
    return st.top().max_k_len.return_val();
}
