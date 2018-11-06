#include "parse.h"

int main() {
    string polish_string;
    cin >> polish_string;
    char k;
    cin >> k;
    Duo ans = parse(polish_string, k);
    if (ans.max_k_len == -2)
        cout << "ERROR" << endl;
    else if (ans.max_k_len == -1)
        cout << "INF" << endl;
    else
        cout << ans.max_k_len << endl;
    return 0;
}