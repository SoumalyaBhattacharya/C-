#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;

    for (int i = n; i >= 1; --i) {
        int coef = 1;
        for (int space = 0; space < n - i; ++space)
            cout << "  ";

        for (int j = 0; j < i; ++j) {
            if (j == 0 || i == 0)
                coef = 1;
            else
                coef = coef * (i - j) / j;

            cout << coef << "   ";
        }
        cout << endl;
    }

    return 0;
}

