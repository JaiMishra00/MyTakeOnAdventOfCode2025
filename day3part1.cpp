#include <bits/stdc++.h>
using namespace std;

string arrayParser(string str){
    char max1 = '0', max2 = '0';
    int pos1;
    string num;
    
    for (int i = 0; i < str.length() - 1; i++){
        //max1 = '0';
        if (str[i] > max1){ 
            max1 = str[i];
            pos1 = i;
        }
    }
    
    for (int i = 0; i < str.length(); i++){
        //max2 = '0';
        
        // apparently cpp can't handle running case parameter, it needs to be initialized at compile time bruh 
        // switch(i){
        //     case pos1: continue;
        //     default: 
        //         if (str[i] > max2){ 
        //             max2 = str[i];
        //         }
        // }
        if (i <= pos1) continue;
        else{
            if (str[i] > max2){ 
                     max2 = str[i];
            }
        }
    }
    
    num += max1;
    num += max2;

    return num;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int count = 0;
    string s;
    ifstream file("p1.txt");
    while (getline(file, s)){
        if (!s.empty() && s.back() == '\r')
            s.pop_back();
        
        count += stoi(arrayParser(s));
    }
    cout << count;
    return 0;
}
