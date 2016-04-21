// Para compilar: g++ -Wall -pedantic drive_les_v1.cpp les_v1.cpp -o drive_les_v1


#include <iostream>
using std::cout;
#include "les_v1.h"

int main ( void ) {
    SNPtr pHead = NULL;// nullptr;
    for (int i = 0; i < 10; ++i)
    {
    	pushFront( pHead, i );
    }
    for (int i = 0; i < 10; ++i)
    {
    	//pushBack( pHead, i );
    }
    	int j;
    	popFront(pHead, j);
    	popBack(pHead, j);




	print(pHead);

    cout << "\n\n>>> Normal exiting...\n";
    return EXIT_SUCCESS;
}
