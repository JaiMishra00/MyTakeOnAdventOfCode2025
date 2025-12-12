#include <bits/stdc++.h>
using namespace std;

// take input separated with - and commas, then run a for loop for every series
pair<long long,long long> inputTaker(string str) {
    long long i = 1;
    while (!(str[i] == '-')) {
        i++;
    }
    
    long long num1 = stoll(str.substr(0, i));
    long long num2 = stoll(str.substr(i+1));
    
    return {num1, num2};
}

// number is invalid only if len is even AND left half == right half
long long logicHandler(long long a, long long b) {
    long long count = 0;
    
    for (long long i = a; i <= b; i++) {
        string num = to_string(i);
        long long len = num.length();
        
        if (len % 2 == 0) {
            if (num.substr(0, len/2) == num.substr(len/2, len/2)) {
                count += i;
            }
        }
    }
    
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file("p1.txt");
    long long final_count = 0;
    string s;
    
    while (getline(file, s, ',')) {
        if (s.empty()) continue;
        
        if (!s.empty() && s.back() == '\r')
            s.pop_back();  // remove Windows CR character
        
        auto [a, b] = inputTaker(s);
        final_count += logicHandler(a, b);
    }
    
    cout << final_count;
}
