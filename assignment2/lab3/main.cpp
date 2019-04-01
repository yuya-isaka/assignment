#include <iostream>
#include "Question.h"
#include <string>
using namespace std;

int main()
{
    const int SIZE = 10;
    Question Q[SIZE] = 
    {
        Question("テニスの神様と言われている選手は誰ですか？", "1.ナダル", "2.フェデラー", "3.錦織", "4.ジョコビッチ", 2),
        Question("テニスラケットで世界で一番シェアされているブランドはなんでしょう？", "1.バボラ", "2.ウィルソン", "3.ヘッド", "4.プリンス", 3),
        Question("錦織圭のガットのテンションはいくつでしょう？", "1.54", "2.48", "3.40", "4.38", 4),
        Question("ジョコビッチのガットのテンションはいくつでしょう？", "1.55", "2.63", "3.58", "4.50", 2),
        Question("テニスコートの種類は何個あるでしょうか？", "1.3", "2.4", "3.5", "4.6", 3),
        Question("井阪ゆうやの身長は？", "1.172", "2.170", "3.168", "4.165", 1),
        Question("井阪ゆうやの血液型は？", "1.A", "2.B", "3.O", "4.AB", 3),
        Question("井阪ゆうやの体重は？", "1.60", "2.62", "3.58", "4.65", 2),
        Question("井阪ゆうやの使ってるテニスラケットは？", "1.バボラ", "2.ウィルソン", "3.ヘッド", "4.プリンス", 3),
        Question("井阪ゆうやの履いているくるのメーカーは？", "1.nike", "2.adidas", "3.reebok", "4.vans", 1)
    };

    for(int i = 0; i < SIZE; i++){
        int useranser;
        cout << "質問" << endl;
        cout << Q[i].getQuestion() << endl;
        cout << Q[i].getAnswer1() << " " << Q[i].getAnswer2() << " " << Q[i].getAnswer3() << " " << Q[i].getAnswer4() << endl;
        cout << "選んでください。 :";
        cin >> useranser;
        while(cin.fail() || !(useranser == 1 || useranser == 2 || useranser == 3 || useranser == 4)){
            cout << "入力を間違えています。もう一度入力してください。 :";
            cin.clear();
            cin.ignore(1024, '\n');
            cin >> useranser;
        }
        if(useranser == Q[i].getCorrectAnswer()){
            cout << "正解です。次の問題に行きます。" << endl << endl;
        }
        else{
            cout << "不正解です。"<< endl; 
            cout << "正解は" << Q[i].getCorrectAnswer() << "です。次の問題に行きます。" << endl << endl;
        }
    }
    cout << "あっ問題が終わってしまいました。問題は以上です。お疲れ様でした。" << endl;

    return 0;
}

