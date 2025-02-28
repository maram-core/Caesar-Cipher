#include <iostream>
using namespace std;

// Function to encrypt text using Caesar cipher
string encrypt(string text, int shift) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) { // Check if character is a letter
            char base = islower(c) ? 'a' : 'A'; 
            result += char(int(c + shift - base) % 26 + base);
        } else {
            result += c; // Keep non-alphabetic characters unchanged
        }
    }
    return result;
}

// Function to decrypt text (reverse of encryption)
string decrypt(string text, int shift) {
    return encrypt(text, 26 - shift);
}

int main() {
    string text;
    int shift, choice;
    
    cout << "Choose an operation (1: Encrypt - 2: Decrypt): ";
    cin >> choice;
    cin.ignore(); // Ignore newline character after input
    
    cout << "Enter the text: ";
    getline(cin, text);
    
    cout << "Enter the shift value: ";
    cin >> shift;

    if (choice == 1)
        cout << "Encrypted text: " << encrypt(text, shift) << endl;
    else
        cout << "Decrypted text: " << decrypt(text, shift) << endl;

    return 0;
}
