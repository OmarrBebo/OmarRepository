#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to encrypt the message
void encryptMessage();
// Function to decrypt the message
void decryptMessage();

int main() {
    int choice;

    // Menu to make the user choose encrypt or decrypt the message or exit the progran
    do {
        cout << "Welcome in Rail-fence cipher program" << endl;
        cout << "Choose an option:" << endl;
        cout << "1) Encrypt the message" << endl;
        cout << "2) Decrypt the message" << endl;
        cout << "3) Exit the program" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                encryptMessage(); //if user choise is 1 calling the function that encrypt the message
                break;
            case 2:
                decryptMessage();//if user choise is 2 calling the function that decrypt the message
                break;
            case 3:
                cout << "Exiting the program" << endl;//if user choise is 3 exit the program
                break;
            default:
                cout << "Invalid choice. Please enter again." << endl; //if the user doesn't enter 1,2,3 display invalid

        }
    } while (choice != 3);
    return 0;


}
//The function of encrypting the message
void encryptMessage() {
    int keyValue=3, nRows,nColumns , direction;
    string message;

    cout << "Enter the message to encrypt" << endl;
    cin.ignore(); // Clear input buffer
    getline(cin, message); // Allowing spaces in the message to remove it

    //convert all letters to small letters
    for (char &chr:message){
        chr= tolower(chr);
    }

    // Initialize a 2D vector named matrix
    vector<vector<char>> matrix(keyValue, vector<char>(message.size(), ' '));
    nColumns= 0;
    direction = 0;

    // Filling the matrix with the message
    for(nRows = 0; nRows < message.size(); nRows++) {
        if(message[nRows] != ' ') { // Skip spaces
            matrix[nColumns][nRows] = message[nRows];

            // Changing direction when reaching the top or bottom nRows
            if(nColumns == keyValue- 1) {
                direction = 1;
            }
            else if(nColumns == 0) {
                direction = 0;
            }

            // Moving up or down based on direction
            if(direction== 0) {
                nColumns++;
            } else {
                nColumns--;
            }
        }
    }

    // Printing the encrypted message
    cout << "The encrypted message: ";
    for(nRows = 0; nRows < keyValue; nRows++) {
        for(nColumns = 0; nColumns < message.size(); nColumns++) {
            if(matrix[nRows][nColumns] != ' ') {
                cout << matrix[nRows][nColumns];
            }
        }
    }
    cout << endl;
}

//The function of decrypting the message
void decryptMessage() {
    int keyLength=3; //Fixed key = 3
    int nRows, nColumns, index, flag;
    string encryptedMessage;

    cout << "Enter the message to decrypt" << endl;
    cin.ignore(); // Clear input buffer
    getline(cin, encryptedMessage);

    //convert all letters to small letters
    for (char &chr:encryptedMessage){
        chr= tolower(chr);
    }


// Initialize a 2D vector to store the decrypted message. Each nRows corresponds to a character in the key,
//and each umn corresponds to a character in the encrypted message.
    vector<vector<char>> decryptionMatrix(keyLength, vector<char>(encryptedMessage.size(), ' '));

    // Initialize variables for tracking the current umn and a flag for controlling program flow.
    nColumns = 0;
    flag = 0;


    // Filling the decryption matrix
    for(nRows = 0; nRows < encryptedMessage.size(); nRows++) {
        decryptionMatrix[nColumns][nRows] = '0'; // Marking the positions in the matrix with '0'
        if(nColumns == keyLength - 1) {
            flag = 1;
        }
        else if(nColumns == 0) {
            flag = 0;
        }
        if(flag == 0) {
            nColumns++;
        }
        else {
            nColumns--;
        }
    }

    index = 0;

    // Filling the decryption matrix with the encrypted message
    for(nRows = 0; nRows < keyLength; nRows++) {
        for(nColumns = 0; nColumns < encryptedMessage.size(); nColumns++) {
            if(decryptionMatrix[nRows][nColumns] == '0') {
                decryptionMatrix[nRows][nColumns] = encryptedMessage[index++];
            }
        }
    }

    flag = 0;
    nColumns = 0;

    // Printing the decrypted message
    cout << "Decrypted message: ";
    for(nRows = 0; nRows < encryptedMessage.size(); nRows++) {
        cout << decryptionMatrix[nColumns][nRows];
        if(nColumns == keyLength - 1) {
            flag = 1;
        }
        else if(nColumns == 0) {
            flag = 0;
        }
        if(flag == 0) {
            nColumns++;
        }
        else {
            nColumns--;
        }
    }
    cout << endl;
}