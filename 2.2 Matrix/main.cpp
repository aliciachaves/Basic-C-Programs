#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int l1, l2, c2;
    cin >> l1 >> l2 >> c2;
    int n;
    vector<vector<int>> m1(l1, vector<int>(l2));
    vector<vector<int>> m2(l2, vector<int>(c2));
    vector<vector<int>> m3(l1, vector<int>(c2));

    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < l2; j++) {
            cin >> n;
            m1[i][j] = n;
        }
    }
    for (int i = 0; i < l2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> n;
            m2[i][j] = n;
        }
    }

    for(int i = 0; i < l1; i++) {
        for (int j = 0; j < c2; j++) {
            m3[i][j] = 0;
        }
    }

    for(int i = 0; i < l1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < l2; k++) {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    for(int i = 0; i < l1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << " " << m3[i][j];
            if (j == c2 - 1) {
                cout << "\n";
            }
        }
    }

    return 0;
}
