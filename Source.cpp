/*---------------------------------------------------------------------------------------*/
/* Description: Image Steganography. The program decodes and displays hidden messages in 
a bitmap image. It also encodes hidden messages into a bitmap image of the user's choice*/
/*---------------------------------------------------------------------------------------*/


#include <iostream> //For input/output
#include <iomanip> //For output manipulation eg; in tabular format
#include <cmath> //For complex calculations eg: in BinaryToDecimal function
#include <fstream> //Used in BitmapHelper.h, for file-handling
#include "BitmapHelper.h" 
#include "Decoder.h"
#include "Encoder.h"

using namespace std;

int main() {

	cout << "Welcome to the Image Steganography Program\n";

	int x = 1; //Counter for main loop
	char choice; //For selections in the switch statement
	unsigned char*** imageData; //Pixel array
	int imageWidth;
	int imageHeight;
	char fileName[30]; //To store the name of the bitmap image file
	string message; //The secret message input
	int z = 1; //Counter for message validation

	while (x == 1) {

		//MAIN MENU - Prompting the user to choose how the program proceeds
		cout << "\nChoose how the program should proceed\n" << endl;
		cout << "There are three routes:\nEncode a secret message into a bitmap image\n";
		cout << "Decode a secret message from a bitmap image\nOr exit program\n";
		cout << "\nTo\n" << endl;
		cout << left << setw(15) << "Encode:" << setw(15) << "Decode:" << setw(15) << "Exit Program:" << endl;
		cout << left << setw(15) << "Enter A" << setw(15) << "Enter B" << setw(15) << "Enter C\n" << endl;
		cin >> choice;

		switch (choice) { //For execution of commands based on the user's selection
		
		case 'A':

			cout << "Enter the name of the bitmap image file you wish to hide the message in\n";
			cin >> fileName;

			if (!(ReadBitmapImage(fileName, imageData, imageWidth, imageHeight))) { //To read the bitmap image file 
				break; //If the user inputs an invalid file name, go to Exit Display
			}

			cout << "Enter the secret message to be hidden:\n";

			//Validating length of message
			while (z == 1) {
				cin >> message;
				long sizeMessage = message.length() * 8;
				long sizeImage = imageHeight * imageWidth * 3;
				if (sizeMessage >= sizeImage) {
					cout << "The message you entered is too big to be hidden into the image file\n";
					cout << "Please enter a shorter message: \n";
					continue;
				}
				z = 0;
			}
			z = 1; //Re-initializing z


			encodeImage(imageData, imageWidth, imageHeight, message);
			cout << "Message encoded succesfully\n";

			if (!(WriteBitmapImage(fileName, imageData, imageWidth, imageHeight))) {//To write the altered pixel bytes into the image file
				break; //Go to Exit Display
			}

			ReleaseMemory(imageData, imageHeight, imageWidth); //Releasing dynamically allocated memory

			break;

		case 'B':

			cout << "Enter the name of the bitmap image file containing the hidden message\n";
			cin >> fileName;
			cout << "Secret message: " << endl;

			if (!(ReadBitmapImage(fileName, imageData, imageWidth, imageHeight))) { //To read the bitmap image file 
				break; //If the user inputs an invalid file name, go to Exit Display
			} 

			decodeImage(imageData, imageWidth, imageHeight); //Calling the decodeImage function
			cout << endl;

			ReleaseMemory(imageData, imageHeight, imageWidth); //Releasing dynamically allocated memory
			break;

		case 'C':
			cout << "Please confirm your choice\n";
			break;

		default:
			cout << "Error! Invalid  Selection" << endl;

		} 

		//Exit display
		cout << "\nTo " << endl;
		cout << left << setw(35) << "Return to the main menu:" << setw(35) << "Exit the program:" << endl;
		cout << left << setw(35) << "Enter 1" << setw(35) << "Enter 0\n" << endl;

		//Validating counter for the main menu loop
		//To ensure that x can only be 1 or 0

		if (!(cin >> x)) { //To prompt for input of x AND validate an integer input

			//To clear the buffer memory
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\nInvalid selection!\nYou will now be returned to the main menu\n" << endl;
			x = 1;
		}

		if (x != 1 && x != 0) { //To validate input of only 1 or 0
			cout << "\nInvalid selection!\nYou will now be returned to the main menu\n" << endl;
			x = 1;
		}

	}

	return 0;
}
