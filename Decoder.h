#pragma once

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

void decodeImage(unsigned char*** imageData, int imageWidth, int imageHeight) {

	int LSBarray[8]; //Array to hold the LSB of pixel bytes (dynamically allocated memory)
	int LSBsize = 0;

	for (int row = 0; row < imageHeight; row++)
	{
		for (int col = 0; col < imageWidth; col++)
		{
			for (int j = 0; j < 3; j++) {

				LSBarray[LSBsize] = (imageData[row][col][j] & 1);
				LSBsize++;

				if (LSBsize == 8) {

					LSBsize = 0;
					char n = '0';
					for (int i = 0; i < 8; i++) {
						if (LSBarray[i] == 1) {
							n |= 1UL << i; //Set i-th bit to 1
						}
						if (LSBarray[i] == 0) {
							n &= ~(1UL << i); //Set i-th bit to 0
						}
					}

					if (n == '\0') {
						row = imageHeight;
						col = imageWidth;
						j = 4;
						break;
					}

					cout << n; 
				}
			}
		}
	}
}


