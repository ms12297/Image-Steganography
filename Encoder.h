#pragma once

#include <iostream>
#include <cmath>

using namespace std;

void encodeImage(unsigned char*** imageData, int imageWidth, int imageHeight, string message) {

	int size = message.length();

	//Copying contents of message to a char array
	char* keys = &message[0];

	int BIT = 0;
	int counter = 0; //To compare with size of message

	for (int row = 0; row < imageHeight; row++)
	{
		for (int col = 0; col < imageWidth; col++)
		{
			for (int j = 0; j < 3; j++) {

				char a = imageData[row][col][j];
				char b = keys[counter];
				int LSB = ((b >> BIT) & 1); //Get the bit value of b at the BIT-th bit

				if ((a & 1) != LSB) { //If LSB of a is not already equal to int LSB
					a = a & 0xFE | LSB; //Set LSB of a as int LSB
					imageData[row][col][j] = a;
				}

				BIT++;

				if (BIT == 8) { //Completion of one character
					counter++;
					BIT = 0;
				}

				if (counter == (size + 1)) { //End encoding
					row = imageHeight;
					col = imageWidth;
					j = 4;
					break;
				}

			}
		}
	}

}

