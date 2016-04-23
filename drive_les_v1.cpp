// Para compilar: g++ -Wall -pedantic drive_les_v1.cpp les_v1.cpp -o drive_les_v1


#include <iostream>
using std::cout;
#include "les_v1.h"

int main ( void ) {
    SNPtr pHead = NULL;
	int aux;

	std::cout << ">>> Teste length..." << std::endl; 
    std::cout << length(pHead) << std::endl; 
    std::cout << ">>> Teste clear..." << std::endl;
    	clear(pHead);   

    std::cout << ">>> Teste pushFront..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
    	pushFront( pHead, i ) == true ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
    }

    std::cout << ">>> Teste pushBack..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
    	pushBack( pHead, i ) == true ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
    }

    std::cout << ">>> Teste empty..." << std::endl;    
       	empty( pHead) == true ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

    std::cout << ">>> Teste popFront..." << std::endl;
    	popFront(pHead, aux);
    std::cout << ">>> Teste popBack..." << std::endl;    	
    	popBack(pHead, aux);

    std::cout << ">>> Teste front..." << std::endl;    
       	front(pHead, aux) == true ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
    std::cout << ">>> Teste back..." << std::endl;    
       	back(pHead, aux) == true ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
   
    std::cout << ">>> Teste insert..." << std::endl;        	
    	insert(pHead, pHead->mpNext, aux) == true ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;    
    std::cout << ">>> Teste remove..." << std::endl;        	
    	remove(pHead, pHead->mpNext, aux) == true ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;



	print(pHead);

    cout << "\n\n>>> Normal exiting...\n";
    return EXIT_SUCCESS;
}
