#include <iostream>
using namespace std;

int main()
{
    auto result = (10 <=> 20) > 0; // Explicitly check ordering
    cout << result << endl; // Outputs 0 (false), as 10 is less than 20
    return 0;
}
