#ifndef __C_ENCAPSULATION_DEFS_H__
#define __C_ENCAPSULATION_DEFS_H__



typedef struct Box
{
	double length;
    double width;
    double height;	
}Box;


void _ZN3BoxC1Ed(Box*, double dim);

void _ZN3BoxC1Eddd(Box*, double l, double w, double h);

void _ZN3BoxD1Ev(Box*);

void _ZN3BoxmLEd(Box*, double mult);

void _ZNK3Box5printEv(Box* const);


typedef struct Shelf
{
    Box boxes[3];
}Shelf;


void _ZN5Shelf6setBoxEiRK3Box(Shelf*, int index, Box* const dims);


double _ZNK5Shelf9getVolumeEv(Shelf* const);


void _ZNK5Shelf5printEv(Shelf* const);


#endif

