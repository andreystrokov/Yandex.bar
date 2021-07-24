#include <iostream>
#include <vector>

using namespace std;

struct TCup {
    vector<string> Levels;
    int CurrentLevel;

    void Read() {
        size_t height, width = 0;
        cin >> height >> width;
        cin.ignore(1);
        Levels.resize(height);
        string level;
        for (int i = 0; i < height; ++i) {
            getline(cin, level);
            Levels[i] = level;
        }
        CurrentLevel = height - 1;
    }

    void Fill(char symbol) {
        auto& level = Levels[--CurrentLevel];

        int start = level.find(' ');
        if (start == string::npos) {
            return;
        }
        int finish = level.rfind(' ');
        for (int i = start; i <= finish; ++i) {
            level[i] = symbol;
        }
    }

    void Draw() {
        for (const auto& level : Levels) {
            cout << level << endl;
        }
    }
};

struct TIngredient {
    string Name;
    int LayersCount;
    char Symbol;

    void Read() {
        cin >> Name;
        cin >> LayersCount;
        cin >> Symbol;
    }

    void Fill(TCup& cup) {
        for (int i = 0; i < LayersCount; ++i) {
            cup.Fill(Symbol);
        }
    }
};

int main() {
    TCup cup;
    cup.Read();

    int ingredientsCount;
    cin >> ingredientsCount;
    
    TIngredient ingredient;
    for (int i = 0; i < ingredientsCount; ++i) {
        ingredient.Read();
        ingredient.Fill(cup);
    }
    cup.Draw();
    return 0;
}
