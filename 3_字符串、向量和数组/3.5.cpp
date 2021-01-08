#include <bits/stdc++.h>
using namespace std;

int main() {
  string s = "", res = "";
  while(std::cin >> s) {
    if(res == "")
      res += s;
    else
    {
      res += (" " + s);
    }
    
    std::cout << res << std::endl;
  }
  std::cout << res;
  return 0;
}

