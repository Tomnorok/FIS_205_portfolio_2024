#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

bool isPalindrome(const string& word) {
    int length = word.length();
    for (int i = 0; i < length / 2; ++i) {
        if (word[i] != word[length - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string word;
    ofstream outputFile("palindrome_results.txt");
    if (!outputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    cout << "Enter a word (type 'exit' to quit): ";
    cin >> word;

    while (word != "exit") {
        string result = isPalindrome(word) ? "is a palindrome" : "is not a palindrome";
        outputFile << "Word: " << word << ", Result: " << result << endl;

        cout << "Enter a word (type 'exit' to quit): ";
        cin >> word;
    }

    outputFile.close();
    cout << "Results have been saved to palindrome_results.txt" << endl;

    return 0;
}
