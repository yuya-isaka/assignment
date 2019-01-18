#include <iostream>
using namespace std;

int main()
{
    int number;
      
    //input

    cout << "ここにコミュニティカレッジの情報が書かれています。あなたの興味のある分野の番号を'1--8'の中から選択してください。" << endl;

    cout << "1. Date winter quarter begins " << endl;
    
    cout << "2. Website address for schedule of classes " << endl;

    cout << "3. Phone number for admissions and records" << endl;

    cout << "4. Address of the college " << endl;

    cout << "5. List of division offices " << endl;

    cout << "6. Information about US voter requirements " << endl;

    cout << "7. How to contact a counselor " << endl;

    cout << "8. College health office hours " << endl;

    cout << " こちらに入力してください >>>";
    cin >> number;

    //process_and_output


    switch(number){
    case 1:
        cout << "Fri. Jan. 11: Last Day of Fall Semester / 4th Quarter " << endl;
        break;
    case 2:
        cout << "https://global.kwansei.ac.jp/academics/attached/0000131586.pdf" << endl;
        break;
    case 3:
        cout << "090-1234_5678" << endl;
        break;
    case 4:
        cout << "兵庫県西宮市上ケ原一番町１−１５５" << endl;
        break;
    case 5:
        cout << "11学部（神、文、社会、法、経済、商、人間福祉、国際、教育、総合政策、理工）" << endl;
        break;
    case 6:
        cout << "https://en.wikipedia.org/wiki/Voter_registration_in_the_United_States" << endl;
        break;
    case 7:
        cout << "各キャンパスの学生支援相談室にて、相談の申し込みをしてください。" << endl;
        break;
    case 8:
        cout << "保健館では、学生や教職員の皆さんの健康生活を支援すると共に、病気治療のために診療もおこなっています。健康に関するあらゆる相談に応じていますのでお気軽にご利用下さい。" << endl; 
        break;
    default:
        cout << "入力した番号が間違っているよ" << endl;

   }

return 0;

}
