#include "c_encapsulation_defs.h"
#include <stdio.h>


/* Box */ 

void _ZN3BoxC1Ed(Box *this, double dim)
{
	this -> length = dim;
	this -> width = dim;
	this -> height = dim;
    _ZNK3Box5printEv(this);
}


void _ZN3BoxC2Ed(Box *this)
{
	this -> length = 1;
	this -> width = 1;
	this -> height = 1;
	_ZNK3Box5printEv(this);
}


void _ZN3BoxC1Eddd(Box *this, double l, double w, double h) 
{ 
	this -> length = l;
	this -> width = w;
	this -> height = h;
    _ZNK3Box5printEv(this); 
}


void _ZN3BoxD1Ev(Box *this)
{
    printf("Box destructor, %f x %f x %f\n", this -> width, this -> height, this -> length);
}


void _ZN3BoxmLEd(Box *this, double mult)
{
    this -> width *= mult;
    this -> height *= mult;
    this -> length *= mult;
}


void _ZNK3Box5printEv(Box* const this)
{
    printf("Box: %f x %f x %f\n", this -> length, this -> width, this -> height); 
}


/* Shelf */

const char* const _ZN5Shelf7DEF_MSGE = "The total volume held on the shelf is";
const char* _ZN5Shelf7messageE = "The total volume held on the shelf is";


void _ZN5Shelf6setBoxEiRK3Box(Shelf* this, int index, Box* const dims)
{
    this -> boxes[index] = *dims;
}


double _ZNK5Shelf9getVolumeEv(Shelf* const this)
{
    double vol = 0;
    size_t i;
    for(i = 0; i < 3; ++i)
    {
        vol += this -> boxes[i].height * this -> boxes[i].width * this -> boxes[i].length;
    }

	return vol;
}


void _ZNK5Shelf5printEv(Shelf* const this)
{
    printf("%s %f\n", _ZN5Shelf7messageE, _ZNK5Shelf9getVolumeEv(this));
}





