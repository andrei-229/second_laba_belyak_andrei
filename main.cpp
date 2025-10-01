#include "iostream"
#include "string"
#include "include/six.h"
using namespace std;

int main(){

    Six arr("13");
    // arr.print(cout);
    Six arr2{"55"};
    // Six copy_arr(move(arr));
    arr.print(cout);
    arr2.print(cout);
    // unsigned char *x = arr.sum(arr2);
    // copy_arr.print(cout);
    Six a = arr.add(arr2);
    Six x = arr2 + arr;
    // cout << x << endl;
    a.print(cout);
    // cout << a << endl;
    return 0;
}