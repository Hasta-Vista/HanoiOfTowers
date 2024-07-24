#include <iostream>
#include <vector>

using namespace std;

static void HanoiOfTowers(int disks, int first, int third, int second, int* counter, vector<pair<int, int>>& moves) {
    if (disks != 0) {
        HanoiOfTowers(disks - 1, first, second, third, counter, moves);
        moves.push_back({ first, third });
        (*counter)++;
        HanoiOfTowers(disks - 1, second, third, first, counter, moves);
    }
}

int main()
{
    int counter = 0;
    vector<pair<int, int>> moves;

    int disks;
    cin >> disks;
    const int peg1 = 1, peg2 = 2, peg3 = 3;
    HanoiOfTowers(disks, peg1, peg3, peg2, &counter, moves);

    cout << counter << endl;
    for (const auto& move : moves) {
        cout << move.first << " " << move.second << endl;
    }

    return 0;
}