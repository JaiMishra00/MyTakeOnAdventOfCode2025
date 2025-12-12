#include <bits/stdc++.h>
using namespace std;


//take input separated with - and commas, then run a for loop for every series
pair<long long,long long> inputTaker(string str) {
    long long i = 1;
    while (!(str[i] == '-')){
        i++;
    }
    
    long long num1 = stoll(str.substr(0, i));
    long long num2 = stoll(str.substr(i+1));
    
    return {num1, num2};
}

//split the number in middle if even and check if left and right side are same and different logic for odd now
long long logicHandler(long long a, long long b) {
    long long count = 0;
    
    for (long long i = a; i <= b; i++){
        string num = to_string(i);
        long long len = num.length();
        
        for(long long k = 1; k <= len-1; k++){
        string sub = num.substr(0, k);
        string app;
                
        if (len%sub.length() == 0){
            for(long long j = 0; j < (len/sub.length()); j++){
                app.append(sub);
            }
            if (app == num){
                count = count + i;
                break;
            }
            else continue;
            }
            else continue;
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
	    if (s.empty()) continue; // skip empty tokens
		
		if (!s.empty() && s.back() == '\r')
            s.pop_back();
		auto [a, b] = inputTaker(s);
		final_count += logicHandler(a, b);
	}
	
	cout << final_count;
	
}
