#ifndef __C_INHERITANCE_DEFS_H__
#define __C_INHERITANCE_DEFS_H__

#include <stdio.h>
#include "c_encapsulation_defs.h"

/* Materials */

typedef enum Types
{
	PLASTIC,
	METAL,
	WOOD,
	PAPER,
	OTHER
}Types;


typedef struct Materials
{
	char padding;
}Materials;



typedef struct Material_t
{
    Types material;
}Material_t;


/* PhysicalBox */

typedef struct PhysicalBox
{
	Box box;
    Material_t material;
    
}PhysicalBox;

void _ZN11PhysicalBoxC1Eddd(PhysicalBox* const, double l, double w, double h);

void _ZN11PhysicalBoxC1EdddN9Materials5TypesE(PhysicalBox* const, double l, double w, double h, Types t);

void _ZN11PhysicalBoxC1EN9Materials5TypesE(PhysicalBox* const, Types t);

void _ZN11PhysicalBoxD1Ev(PhysicalBox* const);

void printp(const PhysicalBox* const);


/* WeightBox */

typedef struct WeightBox
{
	Box box;
    double weight;

}WeightBox;


void _ZN9WeightBoxC1Edddd(WeightBox* const, double l, double w, double h, double wgt);

void _ZN9WeightBoxC1ERKS_(WeightBox* const, const WeightBox* const other);

void _ZN9WeightBoxD1Ev(WeightBox* const);

WeightBox _ZN9WeightBoxaSERKS_(WeightBox* const, const WeightBox* const other);

void _ZNK9WeightBox6printwEv(WeightBox* const);

#endif 

