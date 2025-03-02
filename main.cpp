
#include <iostream>
using namespace std;

int moveCount = 0; 

void hanoi(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        moveCount++;
        cout << "Крок " << moveCount << ": Перемістити диск 1 з " << source << " на " << target << endl;
        return;
    }
    hanoi(n - 1, source, target, auxiliary);
    moveCount++;
    cout << "Крок " << moveCount << ": Перемістити диск " << n << " з " << source << " на " << target << endl;
    hanoi(n - 1, auxiliary, source, target);
}

int main() {
    int n;
    cout << "Введіть кількість дисків: ";
    cin >> n;
    
    cout << "Послідовність ходів для " << n << " дисків:" << endl;
    hanoi(n, 'A', 'B', 'C'); 
    
    cout << "Загальна кількість переміщень: " << moveCount << endl;
    return 0;
}
