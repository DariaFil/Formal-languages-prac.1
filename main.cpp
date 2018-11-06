#include "parse.h"
#include "tests.h"

int main() {
    run_all_tests();
    string polish_string;
    cin >> polish_string;
    char k;
    cin >> k;
    int ans = parse(polish_string, k);
    if (ans == ERROR)
        cout << "ERROR" << endl;
    else if (ans == INF)
        cout << "INF" << endl;
    else
        cout << ans << endl;
    return 0;
}