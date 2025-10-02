#include "iostream"
#include "string"
#include "include/six.h"
using namespace std;

int main(){

    Six arr{"1042"};
    Six arr2(arr);

    Six s = arr + arr2;
    Six s2 = arr.add(arr2);

    s.print(cout);

    cout << (s == s2) << endl;
    return 0;
}