#include "iostream"
#include "string"
#include "include/six.h"
using namespace std;

int main(){

    Six arr{"15"};
    arr.print(cout);

    Six copy_arr(move(arr));
    arr.print(cout);
    copy_arr.print(cout);
    return 0;
}