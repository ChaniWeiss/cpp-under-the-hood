#include <stdio.h>
#include "c_inheritance_defs.h"


/*physical box*/
void _ZN11PhysicalBoxC1Eddd(PhysicalBox* const this, double l, double w, double h)
{
	_ZN3BoxC1Eddd(&(this -> box), l, w, h);
	this -> material.material = OTHER;
	printf("Material created, set to %s\n", "Other");
	printp(this);
}


void _ZN11PhysicalBoxC1EdddN9Materials5TypesE(PhysicalBox* const this, double l, double w, double h, Types t)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	_ZN3BoxC1Eddd(&(this -> box), l, w, h);
	this -> material.material = t;
	printf("Material created, set to %s\n", names[this -> material.material]);
	printp(this);
}


void _ZN11PhysicalBoxC1EN9Materials5TypesE(PhysicalBox* const this, Types t)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other"};
	_ZN3BoxC1Ed(&(this -> box), 1);
	this -> material.material = t;
	printf("Material created, set to %s\n", names[this -> material.material]);
	printp(this);
}


void _ZN11PhysicalBoxD1Ev(PhysicalBox* const this)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other"};
	printf("PhysicalBox dtor, %f x %f x %f, %s; ", this -> box.length, this -> box.width, this -> box.height, names[this -> material.material]);
	_ZN3BoxD1Ev(&(this -> box));
}


void printp(const PhysicalBox* const this)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other"};
    printf("PhysicalBox, made of %s; ", names[this -> material.material]);
    _ZNK3Box5printEv((Box*)this); 
}



/*Weight Box*/
void _ZN9WeightBoxC1Edddd(WeightBox* const this, double l, double w, double h, double wgt)
{
	_ZN3BoxC1Eddd(&(this -> box), l, w, h);
	this -> weight = wgt;
	_ZNK9WeightBox6printwEv(this);
}


void _ZN9WeightBoxC1ERKS_(WeightBox* const this, const WeightBox* const other)
{
	_ZN3BoxC1Ed(&(this -> box), 1);
	this -> weight = other -> weight;
	_ZNK9WeightBox6printwEv(this);
}


void _ZN9WeightBoxD1Ev(WeightBox* const this)
{
	printf("Destructing WeightBox; ");
    _ZNK9WeightBox6printwEv(this);
    _ZN3BoxD1Ev(&(this -> box));
}


WeightBox _ZN9WeightBoxaSERKS_(WeightBox* const this, const WeightBox* const other)
{
	this -> weight = other -> weight;
	return *this;
}

void _ZNK9WeightBox6printwEv(WeightBox* const this)
{
	printf("WeightBox, weight: %f; ", this -> weight);
	_ZNK3Box5printEv(&(this -> box));
}


