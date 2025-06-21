#include "logicfunctions.h"
void exclusive(bool x, bool y, bool& ans){ans=x^y;}
void implies(bool x, bool y, bool& ans){ans=y>=x;}
void equivalence(bool x, bool y, bool& ans){ans=x==y;}