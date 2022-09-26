# Image-Steganography: A Computer Engineering Case Study


## Programming aspects learned and implemented:
* The use of multidimensional arrays and pointers.
* Dynamic memory allocation and deallocation.

## Background

A watermark adds information to a document or image by placing a logo or seal in plain sight. The watermark protects the owner’s rights by showing ownership. TV broadcasters commonly do this by placing their logo in a corner of the broadcast picture. A watermark can be hidden in an image. Hiding the watermark does not change the appearance of the image. This protects the owner’s rights, without disturbing the image.

Steganography is a technique of hiding the data (file, text, image, etc.) within another data file (file, text, image, etc.). In this project, I implement a solution for digital image steganography. I develop a software solution to encode a secret text message inside a Bitmap image and decode the secret message by extracting the embedded message from the encoded image. More information about steganography can be found in the following Wikipedia article (https://en.wikipedia.org/wiki/Steganography).

## Implementation

For this project, I assume an image is represented as a three-dimensional array (M-by-N-by-3 array) where M is the number of pixels in the vertical direction (rows) and N is the number of pixels in the horizontal direction (cols), while each 3-vector corresponds to the blue, green, and red intensities of each pixel. The pixel values are 1-byte characters and are between 0 and 255.

I use a “BitmapHelper” header script provided by a Professor at NYUAD to read Bitmap images (.bmp) into a 3D image array and to write Bitmap image (.bmp) to an image file. A bitmap file BGR pixel data can be read in an unsigned char*** array using BitmapHelper.h. 

The program reads from the user the secret message to hide from the standard input. The Least Significant Bit (LSB) image steganography is implemented where message bits are hidden in the least significant bit of image bytes to have minimal visible effect so it is not recognizable for a common viewer. 

At the end of the secret message a delimiter character ‘\0’ is embedded to pixel bytes so the message can be extracted back in the decode process. Thus, the relevant functions (Encode and Decode found within their respective .h files and ReleaseMemory found within the BitmapHelper.h file) are implemented in the program.


## The Software

The software provides the user with options to encode and decode images. It presents the user with a main menu, with options to encode a message, decode a message, and exit the program. When the user selects the encode option, he/she is prompted to enter the secret message and the name of the bitmap file where the secret message must be encoded in. When the user selects the decode option, the program prompts the user for the encoded bitmap image name, extracts the secret test message, and display it on the output screen. When the user selects the exit option, a message confirming exit is printed on the screen and the program is terminated.
