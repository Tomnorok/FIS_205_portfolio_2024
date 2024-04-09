#include <iostream>

void towers_of_hanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        std::cout << "Move disk 1 from " << source << " to " << target << std::endl;
        return;
    }
    towers_of_hanoi(n-1, source, auxiliary, target);
    std::cout << "Move disk " << n << " from " << source << " to " << target << std::endl;
    towers_of_hanoi(n-1, auxiliary, target, source);
}

int main() {
    int n_disks = 3;
    char source_peg = 'A';
    char target_peg = 'C';
    char auxiliary_peg = 'B';

    std::cout << "Solving Towers of Hanoi with " << n_disks << " disks:" << std::endl;
    towers_of_hanoi(n_disks, source_peg, target_peg, auxiliary_peg);

    return 0;
}