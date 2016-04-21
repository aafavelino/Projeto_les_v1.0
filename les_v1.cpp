// This is a stub code (or skeleton code) just to allow the first compilation
#include <iostream>
#include "les_v1.h"

using namespace std;

//! Prints the list.
/*! This a debugging function that prints the list content.
 *  @param _pAIL Pointer to the head of the list. It NULL, list is empty.
 */
void print( SNPtr _pAIL )
{	
	if (_pAIL == nullptr)
		std::cout << "Lista { }" << std::endl;

	while(_pAIL != nullptr)
	{
		std::cout << _pAIL -> miData << std::endl;
		_pAIL = _pAIL -> mpNext;
	}
}

//! Length of the list.
/*! Calculates and return the length of the list. Length is zero, if list is empty.
 *  @param _pAIL Pointer to the head of the list. It NULL, list is empty.
 *  @return The length.
 */
int length( SNPtr _pAIL )
{
	int slave = 0;
	if (_pAIL == nullptr)
    	return 0;
    else
    	while(_pAIL != nullptr)
    	{
    		slave++;
    	}
    return slave;
}


bool empty( SNPtr _pAIL )
{
	if (_pAIL == nullptr)
    	return true;
    else
    	return false;
}


void clear( SNPtr & _pAIL )
{	
	SNPtr slave;
	slave = _pAIL;

	while(_pAIL != nullptr)
	{
		_pAIL = nullptr;
		_pAIL = slave -> mpNext;
	}
	delete[] _pAIL;
	_pAIL = nullptr;
}


bool front( SNPtr _pAIL, int & _retrievedVal )
{	
	if (_pAIL == nullptr)
	{
		_retrievedVal = 0;
    	return false;
	}
	else
	{
		_retrievedVal = _pAIL -> miData;
		return true;
	}

}


bool back( SNPtr _pAIL, int & _retrievedVal )
{
	if (_pAIL == nullptr)
	{
		_retrievedVal = 0;
    	return false;
	}
	else
	{
		while(_pAIL != nullptr)
			_pAIL = _pAIL -> mpNext;

		_retrievedVal = _pAIL -> miData;
		return true;
	}

}


bool pushFront( SNPtr & _pAIL, int _newVal )
{
	SLLNode *slave;
	try 
	{
        slave = new SLLNode;
    } 
    catch (const std::bad_alloc &e) 
    {
        return false;
    }

	slave -> miData = _newVal;
	slave -> mpNext = _pAIL;
	_pAIL = slave;
    	return true;
}


bool pushBack( SNPtr & _pAIL, int _newVal )
{
    if (_pAIL == NULL) 
    {
        pushFront(_pAIL, _newVal);
    } 
    else 
    {
        SNPtr slave = _pAIL;
        while (_pAIL->mpNext != NULL)
            _pAIL = _pAIL->mpNext;
        if (pushFront(_pAIL->mpNext, _newVal))
            _pAIL = slave;
        else
            return false;
    }

    return true;
}


bool popFront( SNPtr & _pAIL, int & _retrievedVal )
{
	if (front(_pAIL,_retrievedVal))
	{
		SNPtr slave = _pAIL;
		delete _pAIL;
		_pAIL = slave->mpNext;
		return true;
	}
    	return false;
}


bool popBack( SNPtr & _pAIL, int & _retrievedVal )
{
	if (_pAIL != NULL)
	{
		SNPtr slave = _pAIL;
		SNPtr slave2 = NULL;
		while(_pAIL->mpNext!= NULL)
		{
			slave2 = _pAIL;
			_pAIL = _pAIL->mpNext;
		}
			_retrievedVal = _pAIL->miData;
			delete _pAIL;
			slave2 -> mpNext = NULL;
			_pAIL = slave;

			return true;
	}
	return false;
}


SNPtr find( SNPtr _pAIL, int _targetVal )
{
	while(_pAIL != NULL and _pAIL->mpNext != NULL){
		if(_pAIL->mpNext->miData == _targetVal)
			return _pAIL;
		_pAIL = _pAIL->mpNext;
	}
    return NULL;
}


bool insert( SNPtr & _pAIL, SNPtr _pAnte, int _newVal )
{
    return true;
}


bool remove( SNPtr & _pAIL, SNPtr _pAnte, int & _retrievedVal )
{
    return true;
}


//**** ===================[ End of les_v1.cpp ]=================== ****// 