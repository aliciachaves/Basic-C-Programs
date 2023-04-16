#include <iostream>
using namespace std;

int main() {
    string word;
    cin >> word;
    int i = word.length();
    int j = 0;
    int na = 0;
    int ne = 0;
    int ni = 0;
    int no = 0;
    int nu = 0;

    for(i>=0; i--; j++){
        if(word[j] == 'a'){
            na++;
        }
        if(word[j] == 'e'){
            ne++;
        }
        if(word[j] == 'i'){
            ni++;
        }
        if(word[j] == 'o'){
            no++;
        }
        if(word[j] == 'u'){
            nu++;
        }
    }

    if(na!=0){
        cout << "a " << na << endl;
    }
    if(ne!=0){
        cout << "e " << ne << endl;
    }
    if(ni!=0){
        cout << "i " << ni << endl;
    }
    if(no!=0){
        cout << "o " << no << endl;
    }
    if(nu!=0){
        cout << "u " << nu << endl;
    }

    return 0;
}
