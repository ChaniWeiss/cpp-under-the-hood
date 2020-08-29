#ifndef __C_POLYMORPHISM_DEFS_H__
#define __C_POLYMORPHISM_DEFS_H__

#include <stdio.h>


typedef void(*func_ptr)();


typedef struct TextFormatter
{
	func_ptr* vptr;
}TextFormatter;


void TextFormatter_dtor(TextFormatter* const this);
void TextFormatter_print(const TextFormatter* const this, const char* text);

/* DefaultTextFormatter */

typedef struct DefaultTextFormatter
{
	TextFormatter textFormatter;
	int id;

}DefaultTextFormatter;


void DefaultTextFormatter_ctor(DefaultTextFormatter* const this);
void DefaultTextFormatter_cpyCtor(DefaultTextFormatter* const this, const DefaultTextFormatter* const);
DefaultTextFormatter assOp(DefaultTextFormatter* const this,const DefaultTextFormatter* const);
/*virtual*/void DefaultTextFormatter_dtor(DefaultTextFormatter* const this);
/*virtual*/void DefaultTextFormatter_print_c(const DefaultTextFormatter* const this, const char* text);


typedef struct Ider
{
	char buffer;
}Ider;

int next_id;

/* inline static int getId() { return next_id++; } */
   

DefaultTextFormatter* generateFormatterArray();


/* PrePostFixer */

typedef struct PrePostFixer
{
	DefaultTextFormatter defaultTextFormatter;
	const char* pre;
    const char* post;
}PrePostFixer;


/* PrePostFixer Defs */

void PrePostFixer_ctor(PrePostFixer* const, const char* prefix, const char* postfix);
/*virtual*/ void PrePostFixer_dtor(PrePostFixer* const);
/*virtual*/ void PrePostFixer_print_c_c(const PrePostFixer* const, const char* text);
/*virtual*/ void PrePostFixer_print_c_lc(const PrePostFixer* const, long num, char symbol);
/*virtual*/ char PrePostFixer_getDefaultSymbol(const PrePostFixer* const);



/* PrePostDollarFixer */

typedef struct PrePostDollarFixer
{
	PrePostFixer prePostFixer;
}PrePostDollarFixer;

/* PrePostDollarFixer Defs */

void PrePostDollarFixer_ctor(PrePostDollarFixer* const this, const char* prefix, const char* postfix);
void PrePostDollarFixer_cpyCtor(PrePostDollarFixer* const this, const PrePostDollarFixer* const other);
/*virtual*/void PrePostDollarFixer_dtor(PrePostDollarFixer* const this);
void PrePostDollarFixer_print_c_ic(const PrePostDollarFixer* const this, int num, char symbol);
/*virtual*/void PrePostDollarFixer_print_c_lc(const PrePostDollarFixer* const this, long num, char symbol);
void PrePostDollarFixer_print_c_dc(const PrePostDollarFixer* const this, double num, char symbol);
/*virtual*/char PrePostDollarFixer_getDefaultSymbol(const PrePostDollarFixer* const this);



/* PrePostHashFixer */

typedef struct PrePostHashFixer
{
	PrePostDollarFixer prePostDollarFixer;
    int precision;
}PrePostHashFixer;


/* PrePostHashFixer Defs */

void PrePostHashFixer_ctor(PrePostHashFixer* const this, int prc/* = 4*/);
/*virtual*/void PrePostHashFixer_dtor(PrePostHashFixer* const this);

void PrePostHashFixer_print_c_ic(const PrePostHashFixer* const this, int num, char symbol);
/*virtual*/void PrePostHashFixer_print_c_lc(const PrePostHashFixer* const this, long num, char symbol);
void PrePostHashFixer_print_c_dc(const PrePostHashFixer* const this, double num, char symbol);
/*virtual*/char PrePostHashFixer_getDefaultSymbol(const PrePostHashFixer* const this);


/* PrePostFloatDollarFixer */

typedef struct PrePostFloatDollarFixer
{
	PrePostDollarFixer prePostDollarFixer;
}PrePostFloatDollarFixer;


/* PrePostFloatDollarFixer Defs */

void PrePostFloatDollarFixer_ctor(PrePostFloatDollarFixer* const this, const char* prefix, const char* postfix);
/*virtual*/void PrePostFloatDollarFixer_dtor(PrePostFloatDollarFixer* const this);
void PrePostFloatDollarFixer_print_c_f(const PrePostFloatDollarFixer* const this, float num);
void PrePostFloatDollarFixer_print_c_fc(const PrePostFloatDollarFixer* const this, float num, char symbol);
/*virtual*/char PrePostFloatDollarFixer_getDefaultSymbol(const PrePostFloatDollarFixer* const this);



/* PrePostChecker */

typedef struct PrePostChecker
{
	PrePostFloatDollarFixer prePostFloatDollarFixer;    
}PrePostChecker;

void PrePostChecker_ctor(PrePostChecker* const this);
/*virtual*/void PrePostChecker_dtor(PrePostChecker* const this);

void PrePostChecker_printThisSymbolUsingFunc(const PrePostChecker* const this);
void PrePostChecker_printThisSymbolDirectly(const PrePostChecker* const this);    
void PrePostChecker_printDollarSymbolByCastUsingFunc(const PrePostChecker* const this); 
void PrePostChecker_printDollarSymbolByScopeUsingFunc(const PrePostChecker* const this); 
void PrePostChecker_printDollarSymbolByCastDirectly(const PrePostChecker* const this); 
void PrePostChecker_printDollarSymbolByScopeDirectly(const PrePostChecker* const this); 


/* Multiplier */

typedef struct Multiplier
{
	DefaultTextFormatter defaultTextFormatter;
    int times;
}Multiplier; 


/* Multiplier Defs */

/*virtual*/void Multiplier_dtor(Multiplier* const this);
void Multiplier_print_c_c(const Multiplier* const this, const char*);
/*
inline int Multiplier::getTimes() const
{
    return times;
}
inline void Multiplier::setTimes(int t)
{
    times = t;
}



inline Multiplier::Multiplier(int t)
:   times(t)
{
    printf("--- Multiplier CTOR: times = %d\n", times);
}
*/
 






#endif

