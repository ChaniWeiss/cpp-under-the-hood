#include <stdio.h>
#include "c_encapsulation_defs.h"

static Box _ZL8largeBox;
extern const char* const  _ZN5Shelf7DEF_MSGE;
extern const char*_ZN5Shelf7messageE;
static Box _ZGVZ8thisFuncvE5box99;
static Box _ZGVZ8thisFuncvE5box88;


void _Z8thisFuncv()
{
	
	static int count = 0;
		
    printf("\n--- thisFunc() ---\n\n");
    if(count == 0)
    	_ZN3BoxC1Eddd(&_ZGVZ8thisFuncvE5box99, 99, 99, 99);
    _ZN3BoxmLEd(&_ZGVZ8thisFuncvE5box99, 10);
    count++;
}


void _Z8thatFuncv()
{
	static int count = 0;
    printf("\n--- thatFunc() ---\n\n"); 
    if(count == 0)
    	_ZN3BoxC1Eddd(&_ZGVZ8thisFuncvE5box88, 88, 88, 88);
    _ZN3BoxmLEd(&_ZGVZ8thisFuncvE5box88, 10);
    count++;
}


void _Z7doBoxesv()
{
	Box b1;
	Box b2;
	Box b3;
	Box b4;
	
    printf("\n--- Start doBoxes() ---\n\n");

    
    _ZN3BoxC1Ed(&b1, 3);
    _ZN3BoxC1Eddd(&b2, 4, 5, 6);
    
    printf("b1 volume: %f\n", b1.height * b1.width * b1.length);
    printf("b2 volume: %f\n", b2.height * b2.width * b2.length);

    _ZN3BoxmLEd(&b1, 1.5);
    _ZN3BoxmLEd(&b2, 0.5);

    printf("b1 volume: %f\n", b1.height * b1.width * b1.length);
    printf("b2 volume: %f\n", b2.height * b2.width * b2.length);

    b3 = b2;
    b4 = b2;
    _ZN3BoxmLEd(&b4, 3);
    
    printf("b3 %s b4\n", b3.width == b4.width && b3.height == b4.height && b3.length == b4.length ? "equals" : "does not equal");

    _ZN3BoxmLEd(&b3, 1.5);
    _ZN3BoxmLEd(&b4, 0.5);
    printf("Now, b3 %s b4\n", b3.width == b4.width && b3.height == b4.height && b3.length == b4.length ? "equals" : "does not equal");

    printf("\n--- End _Z7doBoxesv() ---\n\n");
    
    _ZN3BoxD1Ev(&b4);
    _ZN3BoxD1Ev(&b3);
    _ZN3BoxD1Ev(&b2);
    _ZN3BoxD1Ev(&b1);
}


void _Z9doShelvesv()
{
	Box tmp;
	Box aBox;
	Shelf aShelf;
	Box tmp1;
	Box tmp2;
	size_t i;

    printf("\n--- start _Z9doShelvesv() ---\n\n");

	
	_ZN3BoxC1Ed(&tmp, 5);
    aBox = tmp;

   	for(i = 0; i < 3; ++i)
   	{
   		_ZN3BoxC1Ed(&aShelf.boxes[i], 1.0);
   	}
   	
   	_ZNK5Shelf5printEv(&aShelf);
   	
   	_ZN5Shelf6setBoxEiRK3Box(&aShelf, 1, &_ZL8largeBox);
   	_ZN5Shelf6setBoxEiRK3Box(&aShelf, 0, &aBox);

    _ZNK5Shelf5printEv(&aShelf);
    _ZN5Shelf7messageE = "This is the total volume on the shelf:";
    _ZNK5Shelf5printEv(&aShelf);
    _ZN5Shelf7messageE = "Shelf's volume:";
    _ZNK5Shelf5printEv(&aShelf);

	_ZN3BoxC1Eddd(&tmp1, 2, 4, 6);
	_ZN5Shelf6setBoxEiRK3Box(&aShelf, 1, &tmp1);
	_ZN3BoxD1Ev(&tmp1);

	_ZN3BoxC1Ed(&tmp2, 2);
    _ZN5Shelf6setBoxEiRK3Box(&aShelf, 2, &tmp2);
    _ZN3BoxD1Ev(&tmp2);
    _ZNK5Shelf5printEv(&aShelf);

    printf("\n--- end _Z9doShelvesv() ---\n\n");
    for(i = 0; i < 3; ++i)
    	_ZN3BoxD1Ev(&aShelf.boxes[3 - i - 1]);
    _ZN3BoxD1Ev(&tmp);
}

int main()
{
	_ZN3BoxC1Eddd(&_ZL8largeBox, 10, 20, 30);
    printf("\n--- Start main() ---\n\n");

    _Z7doBoxesv();

    _Z8thisFuncv();
    _Z8thisFuncv();
    _Z8thisFuncv();
    _Z8thatFuncv();
    _Z8thatFuncv();

    _Z9doShelvesv();
        
    printf("\n--- End main() ---\n\n");
    
    _ZN3BoxD1Ev(&_ZGVZ8thisFuncvE5box88);
    _ZN3BoxD1Ev(&_ZGVZ8thisFuncvE5box99);
    _ZN3BoxD1Ev(&_ZL8largeBox);
    return 0;
}

