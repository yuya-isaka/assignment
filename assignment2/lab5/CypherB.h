
#ifndef CYPHERB_H
#define CYPHERB_H

#include "Encrypted.h"
#include <iostream>
#include <string>

using namespace std;

class CypherB : public Encrypted
{
    private:
        char* Cypher2;
    public:
        CypherB(const string, const int);
        ~CypherB();
        void getCypher2();
        void decode();
};

#endif
