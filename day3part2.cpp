#include <bits/stdc++.h>
using namespace std;

string arrayParser(string str) {
    string result = "";
    int index = 0; 

    for (int pick = 0; pick < 12; pick++) {
        char best = '0';
        int bestPos = index;

        
        int limit = str.length() - (12 - pick);

        
        for (int i = index; i <= limit; i++) {
            if (str[i] > best) {
                best = str[i];
                bestPos = i;
            }
        }

        result += best;
        index = bestPos + 1;   
    }

    return result;
}





int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long count = 0;
    string s;
    ifstream file("p1.txt");
    while (getline(file, s)){
        if (!s.empty() && s.back() == '\r')
            s.pop_back();
        
        count += stoll(arrayParser(s));
    }
    cout << count;
    return 0;
}
