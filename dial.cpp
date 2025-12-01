#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

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
      cout << "subtracting: " << sub << endl;
      dial -= sub;
      cout << "dial was subtracted to: " << dial << endl;
      if (dial < 0) {

        while(dial < 0){
          dial = ((dial % 100) + 100) % 100;
        }

      }

    }
    else if(str[0] == 'R') {
      int add = stoi(str.substr(1));
      dial += add;
      if (dial > 99) {
        while(dial > 99) {
          dial = dial % 100;
        }
      }
    }

      if (dial == 0){
        ctr++;
      }
  } 
    cout << "the final count is: " << ctr << endl;
}
