#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;
int main() {

  ifstream file("input.txt");
  string str;
  int dial = 50;
  int ctr = 0;

  while (getline(file,str)) {

    cout << "dial is: " << dial << endl;
    cout << "instruction is: " << str << endl;
    if(str[0] == 'L') {
      int sub = stoi(str.substr(1));
       int prev = dial;
      dial -= sub;
      if (dial <= 0) {
        ctr += dial / -100 + 1;
        if (prev == 0) {
          ctr--;
        }

          dial = ((dial % 100) + 100) % 100;
        }

      }

    else if(str[0] == 'R') {
      int add = stoi(str.substr(1));
      dial += add;
      if (dial >= 100) {
          ctr += dial / 100;
        }
      }
    

    dial = dial % 100;

  } 
    cout << "the final count is: " << ctr << endl;
}
