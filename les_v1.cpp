// This is a stub code (or skeleton code) just to allow the first compilation
#include <iostream>
#include "les_v1.h"

using namespace std;

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

int length( SNPtr _pAIL )
{
	int slave = 0;
	if (_pAIL == NULL)
    	return 0;
    else
    	while(_pAIL != NULL)
    	{
    		slave++;
    	}
    return slave;
}


bool empty( SNPtr _pAIL )
{
	if (_pAIL == NULL)
    	return true;
    else
    	return false;
}


void clear( SNPtr & _pAIL )
{	
	SNPtr slave;
	slave = _pAIL;

	while(_pAIL != NULL)
	{
		_pAIL = NULL;
		_pAIL = slave -> mpNext;
	}
	delete[] _pAIL;
	_pAIL = NULL;
}


bool front( SNPtr _pAIL, int & _retrievedVal )
{	
	if (_pAIL == NULL)
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
	if (_pAIL == NULL)
	{
    	return false;
	}
	else
	{
		while(_pAIL->mpNext != NULL){
			_pAIL = _pAIL -> mpNext;
		}
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
	if (_pAIL == NULL and _pAnte == NULL)
	{
		return pushFront(_pAIL, _newVal);
	}
	SNPtr slave = _pAnte;
	if (pushFront(_pAnte, _newVal))
	{
		SNPtr slave2 = _pAIL;
		while(_pAIL -> mpNext != slave)
		{
			_pAIL = _pAIL->mpNext;
		}
		_pAIL->mpNext = _pAnte;
		_pAIL = slave2;
		return true;
	}
    return false;
}


bool remove( SNPtr & _pAIL, SNPtr _pAnte, int & _retrievedVal )
{	
	_pAIL = _pAIL->mpNext;
	_pAnte = _pAIL;

	if (_pAIL == NULL)
		return true;

	if (_pAnte == NULL)
	{
		_retrievedVal = _pAIL->miData;
		SNPtr slave = _pAIL->mpNext;
		delete _pAIL;
		_pAIL = slave;
	}

	while(_pAnte != _pAIL and _pAIL != NULL)
	{
		_pAnte = _pAIL;
		_pAIL = _pAIL->mpNext;
	}

	if (_pAIL == NULL)
		return false;

	_pAnte->mpNext = _pAIL->mpNext;
	delete _pAIL->mpNext;
    return true;
}


//**** ===================[ End of les_v1.cpp ]=================== ****// 
