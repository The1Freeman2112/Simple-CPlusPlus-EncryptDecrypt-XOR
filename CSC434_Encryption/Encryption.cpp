#include "Encryption.h"

using namespace std;
int main(int argc, char *argv[]) {
	RunMainMenu();
}

void RunMainMenu() {
	/* 1.Encrypt
	2. Decrypt
	3. Exit   */
	int choice = 0;
	while (choice != 3) {
		cout << "1. Encrypt" << endl;
		cout << "2. Decrypt" << endl;
		cout << "3. Exit" << endl;
		cin >> choice;
		if (choice < 1 || choice>3) {
			cout << "Enter valid choice" << endl;
			cin >> choice;
		}
		RunChoice(choice);
	}
} //RunMainMenu function end

void RunChoice(int choice) {

	ifstream input;
	string testerText, encryptedFile, key;
	ofstream output;

	switch (choice) {
	case 1:
		OpenFile();
		break;
	case 2:
		OpenFile();
		break;
	case 3:
		cout << "Exiting the program" << endl;
		system("PAUSE");
		exit(0);
	}
}//RunChoice function end

void OpenFile() {

	ifstream input;
	string testerText, encryptedFile;

	cout << "Enter the name of the file\n";
	cin >> testerText;
	//write file name
	input.open(testerText.c_str(), ios::in | ios::binary);
	//opens file for read in

	string textToEncrypt((istreambuf_iterator<char>(input)), istreambuf_iterator<char>());

	input.close();
	TextEncrypt(textToEncrypt);
}

void TextEncrypt(string textToEncrypt) {

	string key, encryptedFile;
	ofstream output;

	bool good = 0;
	while (good != true) {
		cout << "Enter the encryption key\n";
		getline(cin, key); //any key works...i think?
						   //cin.ignore();
		for (int i = 0; i < key.size(); i++) {
			if (key[i] == ' ') {
				cout << "Please no spaces" << endl;
				good = 0;
				break;
			}
			else {
				good = 1;
			}
		}
	}

	cout << "Enter the name of the outgoing file\n";
	cin >> encryptedFile;
	//output file for writing
	output.open(encryptedFile.c_str(), ios::out | ios::binary); //Opens the file for writing

	int s = key.size();
	//finds key size

	for (int i = 0; i <= textToEncrypt.size() - 1; i++) {	//loop for size of string
		output << char(textToEncrypt[i] ^ key[i%s]);		//XOR encryption  
	}

	output.close();

}//end function TextEncrypt