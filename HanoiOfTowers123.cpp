#include <iostream>

using namespace std;


static void HanoiOfTowers(int disks, int first, int third, int second, int* counter, int** massiv, int &size) {
	if (disks != 0) {
		HanoiOfTowers(disks - 1, first, second, third, counter, massiv, size);
		massiv[*counter][0] = first;
		massiv[*counter][1] = third;
		(*counter)++;
		if (*counter == size + 1) {
			massiv = (int**)realloc(massiv, (size + 10) * sizeof(int));
			size = size + 10;
			for (int i = size - 10 ; i != size ; ++i) {
				massiv[i] = (int*)malloc(sizeof(int) * 2);
			}
		}

		HanoiOfTowers(disks - 1, second, third, first, counter, massiv, size);
		
	}
}
int main()
{
	int size = 10;
	int counter = 0;
	int** massiv = (int**)malloc(sizeof(int) * size);
	
	for (int i = 0; i != size; ++i) {
		massiv[i] = (int*)malloc (sizeof(int) * 2);
	}
	
	int disks;
	cin >> disks;
	const int peg1 = 1, peg2 = 2, peg3 = 3;
	HanoiOfTowers(disks, peg1, peg3, peg2, &counter, massiv, size);
	cout << counter << endl;
	for (int i = 0; i != counter; ++i) {
		cout << massiv[i][0] << " " << massiv[i][1] << endl;
	}

	return 0;
}