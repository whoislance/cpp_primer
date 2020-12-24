#include <bits/stdc++.h>

int main() {
    int a = 0, b = 0, flag = 0;
    std::string s = "";
    std::cin>>s;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '*') {
            flag = 1;
            continue;
        }
        if(flag == 0) {
            a = a * 10 + (s[i] - '0');
        }
        else {
            b = b * 10 + (s[i] - '0');
        }
    }
    std::cout << a * b << std::endl;
    return 0;
}

