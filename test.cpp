#include <iostream>
#include "maybe.hpp"

using namespace std;
using namespace maybe;

int main() {
  auto a = Maybe<int>::present(14);
  auto b = Maybe<int>::absent();

  cout << "Test 1:" << endl;

  for (auto absent : a.forAbsent())
    cout << "a is absent" << endl;
  for (auto present : a.forPresent())
    cout << "a is present: " << present << endl;
  for (auto absent : b.forAbsent())
    cout << "b is absent" << endl;
  for (auto present : b.forPresent())
    cout << "b is present: " << present << endl;

  cout << "Test 2:" << endl;

  a.ifPresent([] (int value) {
    cout << "a is present: " << value << endl;
  }).ifAbsent([] {
    cout << "a is absent" << endl;
  });
  b.ifPresent([] (int value) {
    cout << "b is present: " << value << endl;
  }).ifAbsent([] {
    cout << "b is absent" << endl;
  });

  return 0;
}
