
#ifndef CYPHERA_H
#define CYPHERA_H

#include "Encrypted.h"
#include <iostream>
#include <string>

using namespace std;

class CypherA : public Encrypted
{
    public:
        CypherA(string filename, int max);
        ~CypherA(){};
        void decode(); //ファイルをデコードするメンバ関数
};

#endif
