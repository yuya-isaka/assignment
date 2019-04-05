#include "Encrypted.h"
#include "CypherA.h"
#include "CypherB.h"
#include <iostream>
#include <string> 

using namespace std;

int main(){
    int maxsize = 3000;
    Encrypted *Object[2];
    Object[0] = new CypherA("Encrypted.txt", maxsize);
    Object[1] = new CypherB("EncryptedB.txt", maxsize);

    cout << "ファイルをデコードします。" << endl << endl;

    for(int i = 0; i < 2; i++){
        Object[i]->decode();
        cout << "デコードしたファイルを表示します。" << endl;
        Object[i]->getDecode();
        cout << endl;
    }
    delete Object[0];
    delete Object[1];

    return 0;
}
