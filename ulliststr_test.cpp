/* Write your test code for the ULListStr in this file */

#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
ULListStr dat;
    dat.push_back("hello");
    dat.push_front("welcome");
    dat.push_back("to");
    dat.push_front("cs104");
    dat.pop_front();

    cout << dat.get(0) << "this is rimi and " << dat.get(1) << dat.get(2) << dat.get(3) << endl;
    

  return 0;
}
