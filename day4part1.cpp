#include <bits/stdc++.h>
using namespace std;

int access(string top, string mid, string bot){
    int finalcount = 0;
    
    for (int i = 0; i < mid.length(); i++){
        int count = 0;
        if (mid[i] == '@'){ //checking if mid is actually a roll first
        if (i == 0){
            count += (top[i] == '@') + (top[i+1] == '@');
            count += (mid[i+1]   == '@');
            count += (bot[i] == '@') + (bot[i+1] == '@');
        }
        else if (i == mid.length() - 1){
            count += (top[i] == '@') + (top[i-1] == '@');
            count += (mid[i-1]   == '@');
            count += (bot[i] == '@') + (bot[i-1] == '@');
        }
        else{
            count += (top[i] == '@') + (top[i+1] == '@') + (top[i-1] == '@') ;
            count += (mid[i+1]   == '@') + (mid[i-1]   == '@');
            count += (bot[i+1]   == '@') + (bot[i]   == '@') + (bot[i-1]   == '@');
        }
        
        if (count < 4){
            finalcount += 1;
        }
        
    }
    }
    return finalcount;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string mid, bot;
    string top(139, '.');
    string finalbot(139, '.');
    
    int accessRolls = 0;
    
    ifstream file("p1.txt");
    // getline(file, top);
    // if (!top.empty() && top.back() == '\r')
    //         top.pop_back();
    getline(file, mid);
    if (!mid.empty() && mid.back() == '\r')
             mid.pop_back();
            
    while (getline(file, bot)){
        if (!bot.empty() && bot.back() == '\r')
            bot.pop_back();
        
        accessRolls += (access(top, mid, bot));
        top.swap(mid); 
        mid.swap(bot);
    }
    accessRolls += access(top, mid, finalbot);
    cout << accessRolls;
    return 0;
}
