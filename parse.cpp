#include "parse.h"

Duo::Duo (int l, int w) {
    max_k_word = w;
    max_k_len = l;
}

Duo parse(string& polish_str, char k) {
    stack<Duo> st;
    if (k != 'a' && k != 'b' && k != 'c')
        return Duo(-2, -1);
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
            else return Duo(-2, -1);
        }
        else if (sym == '.') {
            if (st.size() > 1) {
                Duo second_arg = st.top();
                st.pop();
                Duo first_arg = st.top();
                if (first_arg.max_k_word + second_arg.max_k_len > first_arg.max_k_len)
                    second_arg.max_k_len += first_arg.max_k_word;
                else
                    second_arg.max_k_len = first_arg.max_k_len;

                if (first_arg.max_k_word != -1 && second_arg.max_k_word != -1)
                    second_arg.max_k_word = first_arg.max_k_word + second_arg.max_k_word;
                else
                    second_arg.max_k_word = -1;
                st.pop();
                st.push(Duo(second_arg.max_k_len, second_arg.max_k_word));
            }
            else return Duo(-2, -1);
        }
        else if (sym == '*') {
            if (!st.empty()) {
                Duo arg = st.top();
                if (arg.max_k_word > 0)
                    return Duo(-1, -1);
                else
                    arg.max_k_word = 0;
                st.pop();
                st.push(Duo(arg.max_k_len, arg.max_k_word));
            }
            else return Duo(-2, -1);
        }
        else if (sym == '1') {
            st.push(Duo(0, 0));
        } else {
            if (sym != 'a' && sym != 'b' && sym != 'c')
                return Duo(-2, -1);
            int new_k_len = 0;
            int new_k_word = -1;
            if (sym == k) {
                new_k_len = 1;
                new_k_word = 1;
            }
            st.push(Duo(new_k_len, new_k_word));
        }
    }
    if (st.size() > 1 || st.empty()) return Duo(-2, -1);
    return st.top();
}
