#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i < 10; i += 2)
    {
        cout << i + 1 << ", ";
    }
    cout << "who do we appreciate?"
         << endl;
    
    return 0;
}

// memory:
// i 	11

/* output:
2, 4, 6, 8, 10, who do we appreciate?
_
*/
