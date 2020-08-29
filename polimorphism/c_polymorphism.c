#include "c_polymorphism_defs.h"
#include <stdlib.h>


void doPrePostFixer()
{
	PrePostFixer angleBrackets;
    printf("\n--- start doPrePostFixer() ---\n\n");

    PrePostFixer_ctor(&angleBrackets, "<<< ", " >>>");
    PrePostFixer_print_c_c(&angleBrackets, "Hello World!");
    PrePostFixer_print_c_lc(&angleBrackets, -777, '\0');
    PrePostFixer_print_c_lc(&angleBrackets, 350, '#');
    PrePostFixer_print_c_lc(&angleBrackets, (long int)(3.14), '\0');

    printf("\n--- end doPrePostFixer() ---\n\n");
    PrePostFixer_dtor(&angleBrackets);
}


void doPrePostDollarFixer()
{
	PrePostDollarFixer asterisks;
    printf("\n--- start doPrePostDollarFixer() ---\n\n");

    PrePostDollarFixer_ctor(&asterisks, "***** ", " *****");
    PrePostDollarFixer_print_c_ic(&asterisks, -777, '$');
    PrePostDollarFixer_print_c_ic(&asterisks, 350, '#');
    PrePostDollarFixer_print_c_dc(&asterisks, 3.14f, '$');

    printf("\n--- end doPrePostDollarFixer() ---\n\n");
    PrePostDollarFixer_dtor(&asterisks);
}


void doPrePostChecker()
{
	PrePostChecker check;
    printf("\n--- start doPrePostChecker() ---\n\n");

    
    PrePostChecker_ctor(&check);
    PrePostChecker_printThisSymbolUsingFunc(&check);
    PrePostChecker_printThisSymbolDirectly(&check);
    PrePostChecker_printDollarSymbolByCastDirectly(&check);
    PrePostChecker_printDollarSymbolByScopeDirectly(&check);
    PrePostChecker_printDollarSymbolByCastUsingFunc(&check);
    PrePostChecker_printDollarSymbolByScopeUsingFunc(&check);

    printf("\n--- end doPrePostChecker() ---\n\n");
    PrePostChecker_dtor(&check);
}


void doPrePostFloatDollarFixer()
{
	PrePostFloatDollarFixer hashes;
	PrePostDollarFixer hashes2;
    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    PrePostFloatDollarFixer_ctor(&hashes, "### ", " ###");
    PrePostFloatDollarFixer_print_c_f(&hashes, -777);
    PrePostFloatDollarFixer_print_c_fc(&hashes, 350, '#');
    PrePostFloatDollarFixer_print_c_f(&hashes, 3.14f);

    PrePostDollarFixer_cpyCtor(&hashes2, (PrePostDollarFixer*)&hashes);
    PrePostDollarFixer_print_c_dc(&hashes2, 7.5, '$');
    PrePostDollarFixer_print_c_ic(&hashes2, 100, '$');

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
	PrePostDollarFixer_dtor(&hashes2);
	PrePostFloatDollarFixer_dtor(&hashes);
}


void runAsPrePostFixerRef(const PrePostFixer* const pp)
{
    printf("\n--- start runAsPrePostFixerRef() ---\n\n");
	pp -> defaultTextFormatter.textFormatter.vptr[2](pp, 123, '\0');
	printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}


void runAsPrePostDollarFixerRef(const PrePostDollarFixer* const pp)
{
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");
	PrePostDollarFixer_print_c_ic(pp, 123, '$');
    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}


void runAsPrePostDollarFixerObj(const PrePostDollarFixer* const pp)
{
	PrePostDollarFixer tmp;
	PrePostDollarFixer_cpyCtor(&tmp, pp);
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");
	PrePostDollarFixer_print_c_ic(&tmp, 123, '$');
	printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
	PrePostDollarFixer_dtor(&tmp);
}


void runAsPrePostHashFixerRef(const PrePostHashFixer* const pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");
    PrePostHashFixer_print_c_ic(pp, 123, '#');
	printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}


void doMultiplier()
{
	Multiplier m1;
	Multiplier m2;
	Multiplier m3;
	Multiplier m4;
	
    printf("\n--- start doMultiplier() ---\n\n");

	DefaultTextFormatter_ctor(&(m1.defaultTextFormatter));
	m1.times = 3;
	printf("--- Multiplier CTOR: times = %d\n", m1.times);
    
    DefaultTextFormatter_ctor(&(m2.defaultTextFormatter));
    m2.times = 5;
    printf("--- Multiplier CTOR: times = %d\n", m2.times);
    
    DefaultTextFormatter_cpyCtor(&(m3.defaultTextFormatter), &(m1.defaultTextFormatter));
    m3.times = m1.times;
    
    DefaultTextFormatter_cpyCtor(&(m4.defaultTextFormatter), &(m2.defaultTextFormatter));
    m4.times = m2.times;
    

    Multiplier_print_c_c(&m1, "abc ");
    Multiplier_print_c_c(&m2, "abc ");
    Multiplier_print_c_c(&m3, "abc ");
    Multiplier_print_c_c(&m4, "abc ");
    

    printf("\n--- start doMultiplier() ---\n\n");
    Multiplier_dtor(&m4);
    Multiplier_dtor(&m3);
    Multiplier_dtor(&m2);
    Multiplier_dtor(&m1);
}


extern func_ptr multiplier_vptr[2];
void doFormatterArray(){
    PrePostDollarFixer prePostDollarFixer;
    Multiplier multiplier;
    PrePostChecker prePostChecker;
    DefaultTextFormatter formatters[3];
    int i;

    printf("\n--- start doFormatterArray() ---\n\n");

    PrePostDollarFixer_ctor(&prePostDollarFixer, "!!! ", " !!!");
    DefaultTextFormatter_cpyCtor(&formatters[0], (DefaultTextFormatter*)&prePostDollarFixer);
    PrePostDollarFixer_dtor(&prePostDollarFixer);

    DefaultTextFormatter_ctor((DefaultTextFormatter*)&multiplier);
    multiplier.defaultTextFormatter.textFormatter.vptr = multiplier_vptr;
    multiplier.times = 4;
    printf("--- Multiplier CTOR: times = %d\n", 4);

    DefaultTextFormatter_cpyCtor(&formatters[1], (DefaultTextFormatter*)&multiplier);
    Multiplier_dtor(&multiplier);

    PrePostChecker_ctor(&prePostChecker);
    DefaultTextFormatter_cpyCtor(&formatters[2], (DefaultTextFormatter*)&prePostChecker);
    PrePostChecker_dtor(&prePostChecker);

    for (i = 0; i < 3; ++i)
        DefaultTextFormatter_print_c(&formatters[i], "Hello World!");

    printf("\n--- end doFormatterArray() ---\n\n");

    for (i = 2; i >= 0; --i) {
        DefaultTextFormatter_dtor(&formatters[i]);
    }
}



void doFormatterPtrs()
{
    DefaultTextFormatter* pfmt[3];
    int i;

    printf("\n--- start doFormatterPtrs() ---\n\n");

    pfmt[0] = malloc(sizeof(PrePostDollarFixer));
    PrePostDollarFixer_ctor((PrePostDollarFixer*)pfmt[0], "!!! ", " !!!");

    pfmt[1] = malloc(sizeof(Multiplier));
    DefaultTextFormatter_ctor((DefaultTextFormatter*)pfmt[1]);
    ((Multiplier*)pfmt[1]) -> defaultTextFormatter.textFormatter.vptr = multiplier_vptr;
    ((Multiplier*)pfmt[1]) -> times = 4;
    printf("--- Multiplier CTOR: times = %d\n", 4);

    pfmt[2] = malloc(sizeof(PrePostChecker));
    PrePostChecker_ctor((PrePostChecker*)pfmt[2]);

    for (i = 0; i < 3; ++i)
        pfmt[i]->textFormatter.vptr[1](pfmt[i], "Hello World!");

    for (i = 2; i >= 0; --i) {
        pfmt[i]->textFormatter.vptr[0](pfmt[i]);
        free(pfmt[i]);
    }

    printf("\n--- end doFormatterPtrs() ---\n\n");
}


int main()
{
	PrePostHashFixer hfix;
    printf("\n--- Start main() ---\n\n");

    doPrePostFixer();
    doPrePostDollarFixer();
    doPrePostFloatDollarFixer();
    doPrePostChecker();

	PrePostHashFixer_ctor(&hfix, 4);
    runAsPrePostFixerRef(&(hfix.prePostDollarFixer.prePostFixer));
    runAsPrePostDollarFixerRef(&(hfix.prePostDollarFixer));
    runAsPrePostDollarFixerObj(&(hfix.prePostDollarFixer));
    runAsPrePostHashFixerRef(&hfix);

    doMultiplier();

    doFormatterArray();
    doFormatterPtrs();
    /*doFormatterDynamicArray();*/

    printf("\n--- End main() ---\n\n");

    return 0;
}





/*--- Start main() ---


--- start doPrePostFixer() ---

--- DefaultTextFormatter Default CTOR
########## C 0 ##########
--- PrePostFixer CTOR: "<<< "..." >>>"
[PrePostFixer::print(const char*)]                           | <<< Hello World! >>>
[PrePostFixer::print(long, char)]                            | -->
[PrePostFixer::print_num(long)]                              | <<< -777 >>>
[PrePostFixer::print(long, char)]                            | -->
[PrePostFixer::print_num(long, char)]                        | <<< #350 >>>
[PrePostFixer::print(long, char)]                            | -->
[PrePostFixer::print_num(long)]                              | <<< 3 >>>

--- end doPrePostFixer() ---

--- PrePostFixer DTOR: "<<< "..." >>>"
--- DefaultTextFormatter DTOR
########## D 0 ##########

--- start doPrePostDollarFixer() ---

--- DefaultTextFormatter Default CTOR
########## C 1 ##########
--- PrePostFixer CTOR: "***** "..." *****"
--- PrePostDollarFixer CTOR: "***** "..." *****"
[PrePostDollarFixer::print(int, char)]                       | -->
[PrePostDollarFixer::print(long, char)]                      | -->
[PrePostFixer::print(long, char)]                            | -->
[PrePostFixer::print_num(long, char)]                        | ***** $-777 *****
[PrePostDollarFixer::print(int, char)]                       | -->
[PrePostDollarFixer::print(long, char)]                      | -->
[PrePostFixer::print(long, char)]                            | -->
[PrePostFixer::print_num(long, char)]                        | ***** #350 *****
[PrePostDollarFixer::print(double, char)]                    | ***** $3.140000 *****

--- end doPrePostDollarFixer() ---

--- PrePostDollarFixer DTOR: "***** "..." *****"
--- PrePostFixer DTOR: "***** "..." *****"
--- DefaultTextFormatter DTOR
########## D 1 ##########

--- start doPrePostFloatDollarFixer() ---

--- DefaultTextFormatter Default CTOR
########## C 2 ##########
--- PrePostFixer CTOR: "### "..." ###"
--- PrePostDollarFixer CTOR: "### "..." ###"
--- PrePostFloatDollarFixer CTOR: "### "..." ###"
[PrePostFloatDollarFixer::print(float)]                      | -->
[PrePostFloatDollarFixer::print(float, char)]                | ### @-777.00 ###
[PrePostFloatDollarFixer::print(float, char)]                | ### #350.00 ###
[PrePostFloatDollarFixer::print(float)]                      | -->
[PrePostFloatDollarFixer::print(float, char)]                | ### @3.14 ###
--- DefaultTextFormatter Copy CTOR, from id: 2
########## C 3 ##########
--- PrePostDollarFixer Copy CTOR: "### "..." ###"
[PrePostDollarFixer::print(double, char)]                    | ### $7.500000 ###
[PrePostDollarFixer::print(int, char)]                       | -->
[PrePostDollarFixer::print(long, char)]                      | -->
[PrePostFixer::print(long, char)]                            | -->
[PrePostFixer::print_num(long, char)]                        | ### $100 ###

--- start doPrePostFloatDollarFixer() ---

--- PrePostDollarFixer DTOR: "### "..." ###"
--- PrePostFixer DTOR: "### "..." ###"
--- DefaultTextFormatter DTOR
########## D 3 ##########
--- PrePostFloatDollarFixer DTOR: "### "..." ###"
--- PrePostDollarFixer DTOR: "### "..." ###"
--- PrePostFixer DTOR: "### "..." ###"
--- DefaultTextFormatter DTOR
########## D 2 ##########

--- start doPrePostChecker() ---

--- DefaultTextFormatter Default CTOR
########## C 4 ##########
--- PrePostFixer CTOR: "[[[[ "..." ]]]]"
--- PrePostDollarFixer CTOR: "[[[[ "..." ]]]]"
--- PrePostFloatDollarFixer CTOR: "[[[[ "..." ]]]]"
--- PrePostChecker CTOR: "[[[[ "..." ]]]]"
[PrePostChecker::printThisSymbolUsingFunc()]                 | Default symbol is @
[PrePostChecker::printThisSymbolDirectly()]                  | Default symbol is @
[PrePostChecker::printDollarSymbolByCastDirectly()]          | Default symbol is $
[PrePostChecker::printDollarSymbolByScopeDirectly()]         | Default symbol is $
[PrePostChecker::printDollarSymbolByCastUsingFunc()]         | Default symbol is @
[PrePostChecker::printDollarSymbolByScopeUsingFunc()]        | Default symbol is $

--- end doPrePostChecker() ---

--- PrePostChecker CTOR: "[[[[ "..." ]]]]"
--- PrePostFloatDollarFixer DTOR: "[[[[ "..." ]]]]"
--- PrePostDollarFixer DTOR: "[[[[ "..." ]]]]"
--- PrePostFixer DTOR: "[[[[ "..." ]]]]"
--- DefaultTextFormatter DTOR
########## D 4 ##########
--- DefaultTextFormatter Default CTOR
########## C 5 ##########
--- PrePostFixer CTOR: "===> "..." <==="
--- PrePostDollarFixer CTOR: "===> "..." <==="
--- PrePostHashFixer CTOR: "===> "..." <===", precision: 4
[PrePostHashFixer::print(double, char)]                      | ===> [#9999.9999] <===

--- start runAsPrePostFixerRef() ---

[PrePostHashFixer::print(long, char)]                        | -->
[PrePostHashFixer::print(double, char)]                      | ===> [123.0000] <===

--- end runAsPrePostFixerRef() ---


--- start runAsPrePostDollarFixerRef() ---

[PrePostDollarFixer::print(int, char)]                       | -->
[PrePostHashFixer::print(long, char)]                        | -->
[PrePostHashFixer::print(double, char)]                      | ===> [$123.0000] <===

--- end runAsPrePostDollarFixerRef() ---

--- DefaultTextFormatter Copy CTOR, from id: 5
########## C 6 ##########
--- PrePostDollarFixer Copy CTOR: "===> "..." <==="

--- start runAsPrePostDollarFixerObj() ---

[PrePostDollarFixer::print(int, char)]                       | -->
[PrePostDollarFixer::print(long, char)]                      | -->
[PrePostFixer::print(long, char)]                            | -->
[PrePostFixer::print_num(long, char)]                        | ===> $123 <===

--- end runAsPrePostDollarFixerObj() ---

--- PrePostDollarFixer DTOR: "===> "..." <==="
--- PrePostFixer DTOR: "===> "..." <==="
--- DefaultTextFormatter DTOR
########## D 6 ##########

--- start runAsPrePostHashFixerRef() ---

[PrePostHashFixer::print(int, char)]                         | -->
[PrePostHashFixer::print(double, char)]                      | ===> [#123.0000] <===

--- end runAsPrePostHashFixerRef() ---


--- start doMultiplier() ---

--- DefaultTextFormatter Default CTOR
########## C 7 ##########
--- Multiplier CTOR: times = 3
--- DefaultTextFormatter Default CTOR
########## C 8 ##########
--- Multiplier CTOR: times = 5
--- DefaultTextFormatter Copy CTOR, from id: 7
########## C 9 ##########
--- DefaultTextFormatter Copy CTOR, from id: 8
########## C 10 ##########
[Multiplier::print(const char*)]                             | abc abc abc 
[Multiplier::print(const char*)]                             | abc abc abc abc abc 
[Multiplier::print(const char*)]                             | abc abc abc 
[Multiplier::print(const char*)]                             | abc abc abc abc abc 

--- start doMultiplier() ---

--- Multiplier DTOR: times = 5
--- DefaultTextFormatter DTOR
########## D 10 ##########
--- Multiplier DTOR: times = 3
--- DefaultTextFormatter DTOR
########## D 9 ##########
--- Multiplier DTOR: times = 5
--- DefaultTextFormatter DTOR
########## D 8 ##########
--- Multiplier DTOR: times = 3
--- DefaultTextFormatter DTOR
########## D 7 ##########

--- start doFormatterArray() ---

--- DefaultTextFormatter Default CTOR
########## C 11 ##########
--- PrePostFixer CTOR: "!!! "..." !!!"
--- PrePostDollarFixer CTOR: "!!! "..." !!!"
--- DefaultTextFormatter Copy CTOR, from id: 11
########## C 12 ##########
--- PrePostDollarFixer DTOR: "!!! "..." !!!"
--- PrePostFixer DTOR: "!!! "..." !!!"
--- DefaultTextFormatter DTOR
########## D 11 ##########
--- DefaultTextFormatter Default CTOR
########## C 13 ##########
--- Multiplier CTOR: times = 4
--- DefaultTextFormatter Copy CTOR, from id: 13
########## C 14 ##########
--- Multiplier DTOR: times = 4
--- DefaultTextFormatter DTOR
########## D 13 ##########
--- DefaultTextFormatter Default CTOR
########## C 15 ##########
--- PrePostFixer CTOR: "[[[[ "..." ]]]]"
--- PrePostDollarFixer CTOR: "[[[[ "..." ]]]]"
--- PrePostFloatDollarFixer CTOR: "[[[[ "..." ]]]]"
--- PrePostChecker CTOR: "[[[[ "..." ]]]]"
--- DefaultTextFormatter Copy CTOR, from id: 15
########## C 16 ##########
--- PrePostChecker CTOR: "[[[[ "..." ]]]]"
--- PrePostFloatDollarFixer DTOR: "[[[[ "..." ]]]]"
--- PrePostDollarFixer DTOR: "[[[[ "..." ]]]]"
--- PrePostFixer DTOR: "[[[[ "..." ]]]]"
--- DefaultTextFormatter DTOR
########## D 15 ##########
[DefaultTextFormatter::print(const char*)]                   | Hello World!
[DefaultTextFormatter::print(const char*)]                   | Hello World!
[DefaultTextFormatter::print(const char*)]                   | Hello World!

--- end doFormatterArray() ---

--- DefaultTextFormatter DTOR
########## D 16 ##########
--- DefaultTextFormatter DTOR
########## D 14 ##########
--- DefaultTextFormatter DTOR
########## D 12 ##########

--- start doFormatterPtrs() ---

--- DefaultTextFormatter Default CTOR
########## C 17 ##########
--- PrePostFixer CTOR: "!!! "..." !!!"
--- PrePostDollarFixer CTOR: "!!! "..." !!!"
--- DefaultTextFormatter Default CTOR
########## C 18 ##########
--- Multiplier CTOR: times = 4
--- DefaultTextFormatter Default CTOR
########## C 19 ##########
--- PrePostFixer CTOR: "[[[[ "..." ]]]]"
--- PrePostDollarFixer CTOR: "[[[[ "..." ]]]]"
--- PrePostFloatDollarFixer CTOR: "[[[[ "..." ]]]]"
--- PrePostChecker CTOR: "[[[[ "..." ]]]]"
[PrePostFixer::print(const char*)]                           | !!! Hello World! !!!
[Multiplier::print(const char*)]                             | Hello World!Hello World!Hello World!Hello World!
[PrePostFixer::print(const char*)]                           | [[[[ Hello World! ]]]]
--- PrePostChecker CTOR: "[[[[ "..." ]]]]"
--- PrePostFloatDollarFixer DTOR: "[[[[ "..." ]]]]"
--- PrePostDollarFixer DTOR: "[[[[ "..." ]]]]"
--- PrePostFixer DTOR: "[[[[ "..." ]]]]"
--- DefaultTextFormatter DTOR
########## D 19 ##########
--- Multiplier DTOR: times = 4
--- DefaultTextFormatter DTOR
########## D 18 ##########
--- PrePostDollarFixer DTOR: "!!! "..." !!!"
--- PrePostFixer DTOR: "!!! "..." !!!"
--- DefaultTextFormatter DTOR
########## D 17 ##########

--- end doFormatterPtrs() ---


--- start doFormatterDynamicArray() ---

--- DefaultTextFormatter Default CTOR
########## C 20 ##########
--- DefaultTextFormatter Default CTOR
########## C 21 ##########
--- DefaultTextFormatter Default CTOR
########## C 22 ##########
[DefaultTextFormatter::print(const char*)]                   | Hello World!
[DefaultTextFormatter::print(const char*)]                   | Hello World!
[DefaultTextFormatter::print(const char*)]                   | Hello World!
--- DefaultTextFormatter DTOR
########## D 22 ##########
--- DefaultTextFormatter DTOR
########## D 21 ##########
--- DefaultTextFormatter DTOR
########## D 20 ##########

--- start doFormatterDynamicArray() ---


--- End main() ---

--- PrePostHashFixer DTOR: "===> "..." <==="
--- PrePostDollarFixer DTOR: "===> "..." <==="
--- PrePostFixer DTOR: "===> "..." <==="
--- DefaultTextFormatter DTOR
########## D 5 ##########
*/

