// Thinking C++ Practice programming / Template Function

//: C05:MinTest.cpp
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string>

using std::strcmp;
using std::cout;
using std::endl;

template <typename T> void f(T s = 10) { cout << s * 2 << endl; }
template<int T> void f() { cout << "general template" << endl; }
template<> void f<0>() { cout << "special tempalte" << endl; }

template <typename T> const T &min(const T &a, const T &b) {
  return (a < b) ? a : b;
}
const char *min(const char *a, const char *b) {
  return (strcmp(a, b) < 0) ? a : b;
}
double min(double x, double y) { return (x < y) ? x : y; }

// void pointer
void increase(void *data, int type) {
  {
    switch (type) {
    case sizeof(char):
      (*((char *)data))++;
      break;
    case sizeof(short):
      (*((short *)data))++;
      break;
    case sizeof(long):
      (*((long *)data))++;
      break;
    case sizeof(float):
      (*((float *)data))++;
      break;
    default:
      break;
    }
  }
}
template <class T> const T increase(T s) { return s + 1; }

int main() {
  const char *s2 = "say \"Ni-!\"", *s1 = "knights who";
  cout << min(1, 2) << endl;     // 1: 1 (template)
  cout << min(1.0, 2.0) << endl; // 2: 1 (double)
  cout << min(1, 2.0) << endl;   // 3: 1 (double)
  cout << min(s1, s2) << endl;   // 4: knights who (const
  // char*)
  cout << min<>(s1, s2) << endl; // 5: say "Ni-!"

  f<int>(11);
  f<float>(11.1);
  f<float>();
  f(111.5);
//  f(); fail
  f<1>(); //general template
  f<0>(); //special template

  // ( end template)
  char a = 5;
  short b = 9;
  long c = 12;
  float d = 12.12;
  increase(&a, sizeof(a));
  increase(&b, sizeof(b));
  increase(&c, sizeof(c));
  increase(&d, sizeof(d));
  char *bb = &a;
  printf("%d\n", *bb);
  cout << (int)a << " " << b << " " << c << " " << d << endl;
  cout << (int)increase<char>(a) << " " << increase<short>(b) << " "
       << increase<short>(c) << " " << increase<float>(d) << endl;


  std::string s("Hello");
  std::string str = "Hello world";
  cout << str.size() << endl;


} ///:~
