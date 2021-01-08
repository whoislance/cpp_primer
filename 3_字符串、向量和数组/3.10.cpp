#include <bits/stdc++.h>
using namespace std;

int main() {
  std::string s = "jfsd,sdflsje,234,2*(^,sdjfh)!#$@%#^$&*(dljeijjjjjjjj)";
  for(auto& c : s) {
    if(!ispunct(c)) {
      std::cout << c;
    }
  }
  return 0;
}

