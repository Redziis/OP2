#include <iostream>

using namespace std;

int main(){
  int skaicius;
  cout << "Iveskite trizenkli skaiciu: ";
  cin >> skaicius;

  int s1 = skaicius / 100;
  int s2 = (skaicius / 10) % 10;
  int s3 = skaicius % 10;

  cout << s1 << endl;
  cout << s2 << endl;
  cout << s3 << endl;

  int kubu_suma = s1*s1*s1 + s2*s2*s2 + s3*s3*s3;

  bool armstrong = {kubu_suma == skaicius};

  cout<<"armstrong = " << armstrong << endl;



}
