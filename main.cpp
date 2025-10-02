#include "iostream"
#include "string"
#include "include/six.h"
using namespace std;

int main(){

    Six arr{"1042"};
    Six arr2(arr);
    arr.print(cout);
    arr2.print(cout);
    cout << (arr == arr2) << endl;
    return 0;
}