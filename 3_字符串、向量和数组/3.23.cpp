#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v;
  for(decltype(v.size()) i = 0; i < 10; ++i) {
    v.push_back(i);
    cout<<v[i]<<" "; 
  }
  cout<<std::endl;
  for(auto it = v.begin(); it != v.end(); ++it) {
    (*it) = (*it) * 2;
  }
  for(auto it = v.begin(); it != v.end(); ++it) {
    cout<<(*it)<<" ";
  }
 return 0;
}

