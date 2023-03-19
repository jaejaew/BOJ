#define MAXN 100100

#include<iostream>
#include<cstring>

using namespace std;

class Stack {
private:
    int a[MAXN];
    char op[2 * MAXN];
    int top;
    int cnt;
public:
    Stack() {
        memset(a, 0, sizeof(a));
        memset(op, 0, sizeof(op));
        top = -1;
        cnt = 0;
    }
    int getTop() {
        if (!empty())
            return a[top];
        else
            return -1;
    }
    void push(int e) {
        a[++top] = e;
        op[cnt++] = '+';
    }
    int pop() {
        if (empty())
            return -1;
        else {
            op[cnt++] = '-';
            return a[top--];
        }
    }
    bool empty() {
        return top == -1;
    }
    void print() {
        for (int i = 0; i < cnt; i++) {
            cout << op[i] << '\n';
        }
    }
} S;

int main(void) {
    int N;
    int tmp, max = 0;
    bool flag = true;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        if (!flag)
            continue;

        while (max < tmp) {
            S.push(++max);
        }
        if (tmp == S.getTop())
            S.pop();
        else
            flag = false;
    }
    if (flag)
        S.print();
    else
        cout << "NO \n";

    return 0;
}   