#include <iostream>
#include <vector>

using namespace std;

    struct Ingr {
        string name;
        int num;
        char symbol;
    };
int main() {
    size_t h,w = 0;
    cin >> h >> w;
    cin.ignore(1);
    vector<string> cup(h);
    for (int i = --h;i >= 0; --i){
        string s;
        getline(cin,s);
        cup[i] = s;
    }
    int ingr;
    cin >> ingr;
    vector<Ingr> v;
    while (ingr){
        string name;
        cin >> name;
        int num;
        cin >> num;
        char c;
        cin >> c;
        v.push_back({name,num,c});
        --ingr;
    }
    int current_string = 1;
        for(auto& j : v){
            for (int i = current_string; i < current_string + j.num; ++i){
                for (char& c : cup[i]){
                    if (c == ' '){
                        c = j.symbol;
                    }
                }
            }
        current_string +=j.num;
        }

    for (int i = h;i >= 0; --i){
        cout << cup[i] << endl;
    }

  return 0;
}
