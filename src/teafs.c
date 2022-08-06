// Include the required standard libraries.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *buf = 0;

int TFSFreeBuf() {
	free(buf);

	return 0;
}

// Define a function called "TFSWriteData" which takes in two character arrays and a boolean. This function will append the second parameter (writeData) to a file specified in the first parameter (writePath). The third characer specifies whether there should be a new line or not.
int TFSWriteData(char writePath[], char writeData[], int writeMode) {
	// File pointer to hold the reference to the file.
	FILE *filePtr;

	// Check the right mode and open the file in the appropriate way, report an error if it is not a valid
	if (writeMode == 0) {
		// Open the file in write mode.
		filePtr = fopen(writePath, "w");
	} else if (writeMode == 1) {
		// Open the file in append mode.
		filePtr = fopen(writePath, "a");
	} else {
		// Report error.
		printf("Failed, %d is not a correct mode. Available modes are:\n    * 0 - Write\n    * 1 - Append\n", writeMode);
		return -1;
	}

	// If NULL was returned it failed to create or write to file, return -1 to show error.
	if (filePtr == NULL) {
		printf("Debug:\n");
		printf("	Path: %s\n", writePath);
		printf("	Data: %s\n", writeData);

		printf("\nUnable to create or write to the file.\n");
		return -1;
	}

	// Write the data to the file.
	fputs(writeData, filePtr);

	// Close the file to save the data.
	fclose(filePtr);

	// Show success with message and return value of 0.
	printf("\"%s\" wrote to \"%s\"\n", writeData, writePath);
	return 0;
}

// Define a function called "TFSReadData" which takes in one character array. This function will read to contents of a file specified by the first parameter (readPath). Will need you to run `TFSFreeBuf();` after to put the memory used back to the heap`
char * TFSReadData(char readPath[]) {

	// Define a long to contain the amoun of memory the file needs.
	long length;

	// File pointer to hold the reference to the file
	FILE *filePtr;

	// Open the file in read mode.
	filePtr = fopen(readPath, "r");

	// Error check opening the file and return "Error" if there is an issue.
	if (filePtr == NULL) {
		printf("Debug:\n");
		printf("	Path: %s\n", readPath);

		printf("\nUnable to open the file.\n");
		return "Error";
	}

	// Put the cursor at the end of the file.
	fseek(filePtr, 0, SEEK_END);

	// Get the cursors position and assign it to length
	length = ftell(filePtr);

	// Put the cursor back at the start of the file.
	fseek(filePtr, 0, SEEK_SET);

	// Allocate memory from the heap to buf, using length as the amount.
	buf = malloc(length);

	// Check if the memory allocation was succesful, if so then read the contents of the file into the buf variable. If it was not succesful, then return "Error"
	if (buf) {
		fread(buf, 1, length, filePtr);
	} else {
		return "Error";
	}

	// Close the file.
	fclose(filePtr);

	// Return buf (now contains the contents of the file)
	return buf;
}

// Define a function that takes in a character array. The first parameter defines which file should be deleted.
int TFSRemoveFile(char filePath[]) {
	// If the file was removed successfully, it will return a 0, otherwise return a -1 to indicate error.
	if (remove(filePath) == 0) {
		return 0;
	} else {
		return -1;
	}
}
