#include <iostream>
#include <cstring>

#define MAXLEN 1001

using namespace std;



int main(void) {
    freopen("../input", "r", stdin);
    int lcs[MAXLEN][MAXLEN];
    char str1[MAXLEN], str2[MAXLEN];

    cin >> str1 >> str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for (int i=0; i<len1; i++) {
        for (int j=0; j<len2; j++) {
            if (str1[i] == str2[j])
                lcs[i + 1][j + 1] = lcs[i][j] + 1;
            else
                lcs[i + 1][j + 1] = max(lcs[i][j + 1], lcs[i + 1][j]);
        }
    }

    cout << lcs[len1][len2] << '\n';
    return 0;
}