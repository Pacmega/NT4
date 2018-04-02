#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// char* fileNameRequest()
// {
// 	char UserInput[50];

// 	cout << "What is the full name of the file to use?" << endl;
// 	cout << "Reminder: having spaces in your file names is NOT allowed." << endl;
// 	cin >> UserInput;
// 	cout << "File name inserted: " << UserInput << endl;

// 	return UserInput;
// }

// string passwordRequest()
// {
// 	char UserInput[50];

// 	cout << "What is the password that should be used?" << endl;
// 	cout << "Reminder: having spaces in your password is NOT allowed." << endl;
// 	cin >> UserInput;
// 	cout << "Password given: " << UserInput << endl;

// 	return UserInput;
// }

int main()
{
	char n = '0';
	char fileName[50] = "";

	char readChar = '\0';
	int stringPos = 0;

	char password[50] = "";
	ifstream inputFile;
	ofstream outputFile;

	while (n != '3')
	{
		cout << endl;
		cout << "-----------------------------------" << endl;
		cout << "           NT4 - Security          " << endl;
		cout << "Encryption & decryption application" << endl;
		cout << "-----------------------------------" << endl;
		cout << "\nWarning: having spaces in your file names & passwords is NOT allowed.\n" << endl;
		cout << "1. Encrypt an existing file using your own password" << endl;
		cout << "2. Decrypt an previously encrypted file using the password" << endl;
		cout << "3. Close the application" << endl; 
		cin >> n;

		switch(n)
		{
			case '1':
				cout << "\nFile encryption selected." << endl;
				
				// File
				cout << "What is the full name of the file to use?" << endl;
				cout << "Reminder: having spaces in your file names is NOT allowed." << endl;
				cin >> fileName;
				cout << "File name inserted: " << fileName << endl;
				
				// Password
				cout << "What is the password that should be used?" << endl;
				cout << "Reminder: having spaces in your password is NOT allowed." << endl;
				cin >> password;
				cout << "Password given: " << password << endl;
				
				inputFile.open(fileName);
				if (inputFile.is_open())
				{
					outputFile.open("encrypted.txt");
					if (outputFile.is_open())
					{
						// Both files opened, get to work.
						
						while (inputFile >> noskipws >> readChar)
						{
							if (password[stringPos] != '\0')
							{
								outputFile << (unsigned char)(readChar ^ password[stringPos]);
								stringPos++;
							}
							else
							{
								stringPos = 0;
								outputFile << (unsigned char)(readChar ^ password[stringPos]);
							}
						}

						// Done encrypting.
						inputFile.close();
						outputFile.close();
						stringPos = 0;
					}
					else
					{
						cout << "Unable to open output file." << endl;
					}
				}
				else
				{
					cout << "Unable to open file to encrypt." << endl;
				}
				break;
			case '2':
				cout << "\nFile decryption selected." << endl;
				
				// File
				cout << "What is the full name of the file to use?" << endl;
				cout << "Reminder: having spaces in your file names is NOT allowed." << endl;
				cin >> fileName;
				cout << "File name inserted: " << fileName << endl;
				
				// Password
				cout << "What is the password that should be used?" << endl;
				cout << "Reminder: having spaces in your password is NOT allowed." << endl;
				cin >> password;
				cout << "Password given: " << password << endl;
				
				inputFile.open(fileName, ios::in);
				if (inputFile.is_open())
				{
					outputFile.open("decrypted.txt");
					if (outputFile.is_open())
					{
						// Both files opened, get to work.
						
						while (inputFile >> noskipws >> readChar)
						{
							if (password[stringPos] != '\0')
							{
								outputFile << (unsigned char)(readChar ^ password[stringPos]);
								stringPos++;
							}
							else
							{
								stringPos = 0;
								outputFile << (unsigned char)(readChar ^ password[stringPos]);
							}
						}

						// Done encrypting.
						inputFile.close();
						outputFile.close();
						stringPos = 0;
					}
					else
					{
						cout << "Unable to open output file." << endl;
					}
				}
				else
				{
					cout << "Unable to open file to decrypt." << endl;
				}
				break;
			case '3':
				cout << "Exit signal received." << endl;
				break;
			default:
				cout << "Invalid input." << endl;
				break;
		}
	}

	cout << "Shutting down." << endl;

	return 0;
}
