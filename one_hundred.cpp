/**
 * This program return the number as its word representation
 * From (0 to 10000)
 *  Eg: 
 *    I/P : 1234 
 *    O/P : one thousand two hundred thirty fourteen
**/

#include<bits/stdc++.h>
using namespace std;

vector<string> check1 = {"hundred", "thousand"};
vector<string> check2 = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "ninteen"};
vector<string> check3 = {"ten","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
vector<string> check4 = {"zero","one", "two", "three", "four", "five", "six", "seven", "eight","nine"};
int x;

string forOne(char num) {
  int x = num - '0'; 
  return check4[x];
}

string forTwo(string num) {
  int x = num[0] - '0';
  if(x == 0 && num[1] - '0' == 0) return "";
  if(x == 0 && num[1] - '0' != 0) return forOne(num[1]);
  if(num[1] == '0') return check3[x] + " ";
  if(x==1) return check2[(num[1] - '0')-1] + " "; 
  else return check3[x-1]+ " " + check4[(num[1]-'0')];
}

string forThree(string num) {
  int x = num[0] - '0';
  if(x == 0) return "" + forTwo(num.substr(1));
  return check4[x] + " " + check1[0] + " " + forTwo(num.substr(1));
}

string oneHundred(string num) {
  int len = num.length();
  int i;
  switch(len) {
    case 0: return "None";
            break;
    case 1: 
            return forOne(num[0]);
            break;
    case 2:
            return forTwo(num);
            break;
    case 3: 
            return forThree(num);
            break;
    case 4:
            x = num[0] - '0';
            return forOne(num[0]) + " " + check1[1] + " " + forThree(num.substr(1));
            break;
    case 5:
            if(num[0] == '1' && num.substr(1) == "0000")
              return check3[0] + " " + check1[1];
            else return "Not programmed for that...";
  }
}

int main() {
  string num;
  cin>> num;
  cout<<oneHundred(num)<<endl;
}