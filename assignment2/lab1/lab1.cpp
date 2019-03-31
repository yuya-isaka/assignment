#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int advantageDevice(vector<int> advantage, int advantageSize);

int medianDevice1(vector<int> advantage, int advantageSize);

tuple<int, int> medianDevice2(vector<int> advantage, int advantageSize);

int main(){
    string filename;
    char check;
    int box,
        count = 0,
        totalScore = 0,
        advantageOfClass,
        advantageSize,
        medianOfClass1,
        medianOfClass2;
    static const int testOfNumber = 10;
    vector<int> advantage;

    cout << "ファイルから数値を配列に書き込みます。" << endl;
    while(1){
        cout << "ファイル名を入力してください。 :";
        cin >> filename;
        while(cin.fail()){
            cout << "入力を間違えています。もう一度入力してください。" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "入力してください。 :";
            cin >> filename;
        }
        cout << "ファイル名は" << filename << "で間違い無いですか？ Y or N でお答えください。 :";
        cin.clear();
        cin.ignore(1024, '\n');
        cin >> check;
        while(cin.fail() || !(check == 'Y' || check == 'y' || check == 'N' || check == 'n')){
            cout << "入力を間違えています。もう一度入力してください。" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "入力してください。 :";
            cin >> check;
        }
        if(check == 'Y' || check == 'y'){
            cout << "わかりました。" << endl;
            //ファイルを開きます。
            ifstream inputfile;
            inputfile.open(filename);
            if(!inputfile){
                cout << "ファイルを開くことができませんでした。　ファイル名を間違えている可能性があります。　もう一度入力してください。" << endl;
            }
            else{

                cout << "ファイルを入力します。" << endl;
                while(inputfile >> box){
                    totalScore += box;
                    count++;
                    if(count == testOfNumber){
                        int advantageScore;
                        advantageScore = totalScore/testOfNumber;
                        advantage.push_back(advantageScore);
                        totalScore = 0;
                        count = 0;
                    }
                }
                break;

            }
        }
        else{
            cout << "それではもう一度入力してください。" << endl;
        }
    }

    advantageSize = advantage.size();

    cout << "ソートして並び替えた平均値と、クラスの平均値とクラスの中央値がこちらです。" << endl;
    sort(advantage.begin(), advantage.end());

    cout << "それぞれの平均値は" << endl;
    for(int i = 0; i < advantageSize; i++){
        cout << advantage[i] << endl;
    }

    cout << "クラスの平均値は" << endl;
    advantageOfClass = advantageDevice(advantage,advantageSize);
    cout << advantageOfClass << "です。" << endl;

    cout << "クラスの中央値は" << endl;
    if(advantageSize % 2 == 0){
        tie(medianOfClass1, medianOfClass2) = medianDevice2(advantage, advantageSize);
        cout << medianOfClass1 << "と" << medianOfClass2 << "です。" << endl;
    }
    else{
        medianOfClass1 = medianDevice1(advantage, advantageSize);
        cout << medianOfClass1 << "です。" << endl;
    }

}


int advantageDevice(vector<int> advantage, int advantageSize){
    int totalOfScore = 0,
        advantageOfScore = 0;

    for(int i = 0; i < advantageSize; i++){
        totalOfScore += advantage[i];
    }
    advantageOfScore = totalOfScore/advantageSize;

    return advantageOfScore;
}

int medianDevice1(vector<int> advantage, int advantageSize){
    int medianScore = (advantageSize - 1) / 2;

    return advantage[medianScore];
}

tuple<int, int> medianDevice2(vector<int> advantage, int advantageSize){
    int medianScore = (advantageSize - 1) / 2;

    return forward_as_tuple(advantage[medianScore], advantage[medianScore+1]);
}
