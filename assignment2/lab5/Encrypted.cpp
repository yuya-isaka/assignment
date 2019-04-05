#include "Encrypted.h"
#include "CypherA.h"
#include "CypherB.h"
#include <iostream>
#include <string> 
#include <fstream>

using namespace std;


Encrypted::Encrypted(const string filename, const int max){
    Encode = new char[max];
    ifstream inputfile;
    inputfile.open(filename);
    if(!inputfile){
        cout << "ファイルを開けませんでした。" << endl;
        exit(1);
    }else{
        inputfile.getline(Encode, max);
        if(Encode[max - 1] != '\0'){
            Encode[max - 1] = '\0';
            cout << "////////警告////////" << endl;
        }
    }
    size = strlen(Encode);
    decodetxt = "";
}

Encrypted::~Encrypted(){
    delete [] Encode;
}

void Encrypted::getDecode() const{
    cout << decodetxt << " ";
}

const char Encrypted::alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; //アルファベットの初期化
const char Encrypted::changealphabet[26] = {'i','z','t','o','h','n','d','b','e','q','r','k','g','l','m','a','c','s','v','w','f','u','y','p','j','x'}; //デコードするためのアルファベットを初期化



CypherA::CypherA(string filename, int max) : Encrypted(filename, max){};


void CypherA::decode(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 26; j++){
            if(Encode[i] == alphabet[j]){
                Encode[i] = changealphabet[j];
                break;
            }
        }
    }
    decodetxt = Encode;
}


CypherB::CypherB(const string filename, const int max){
    Cypher2 = new char[max];
    ifstream inputfile;
    inputfile.open(filename);
    if(!inputfile){
        cout << "ファイルを開けませんでした。" << endl;
        exit(1);
    }else{
        inputfile.getline(Cypher2, max);
        if(Cypher2[max - 1] != '\0'){
            Cypher2[max - 1] = '\0';
            cout << "////////警告////////" << endl;
        }
    }
    size = strlen(Cypher2);
    decodetxt = "";
}

CypherB::~CypherB(){
    delete [] Cypher2;
}

void CypherB::getCypher2(){
    cout << Cypher2 << " ";
}

void CypherB::decode(){
    for(int i = 0; i < size; i++){
        if(Cypher2[i] != '\0'){
            for(int j = 0; j < 26; j++){
                if(Cypher2[i] == alphabet[j]){
                    if(Cypher2[i] >= 'e' && Cypher2[i] <= 'z'){
                        Cypher2[i] = alphabet[j - 4];
                        break;
                    }
                    else if(Cypher2[i] >= 'E' && Cypher2[i] <= 'Z'){
                        Cypher2[i] =  alphabet[j - 4];
                        break;
                    }
                    else{
                        Cypher2[i] = alphabet[j + 22];
                        break;
                    }

                }
            }
        }
    }
    decodetxt = Cypher2;
}
