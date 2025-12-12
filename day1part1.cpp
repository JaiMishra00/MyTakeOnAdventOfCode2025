#include <bits/stdc++.h>
using namespace std;

int current_num = 50;

int str2num(string str) {
    int a, b, c;
    
    // remove Windows CR character if present
    if (!str.empty() && str.back() == '\r')
        str.pop_back();

    if (str.size() == 3) {
        a = 0;
        b = str[2] - '0';
        c = str[1] - '0';
        return c * 10 + b;
    }
    else if (str.size() == 4) {
        a = str[3] - '0';
        b = str[2] - '0';
        c = str[1] - '0';
        return c * 100 + b * 10 + a;
    }
    else {
        a = 0;
        b = 0;
        c = str[1] - '0';
        return c;
    }
}

bool check0(string str) {
    int the_num = str2num(str) % 100;

    switch (str[0]) {

        case 'L':
            current_num = current_num - the_num;
            if (current_num < 0)
                current_num += 100;
            break;

        case 'R':
            current_num = current_num + the_num;
            if (current_num > 99)
                current_num -= 100;
            break;

        default:
            cout << "error\n";
    }

    return (current_num == 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("p1.txt");
    int count = 0;

    string s;
    while (getline(file, s)) {

        if (!s.empty() && s.back() == '\r')
            s.pop_back();

        if (check0(s)) {
            count++;
        }
    }

    cout << count << "\n";
}
