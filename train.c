#include <taskLib.h>
#include <logLib.h>
#include <ioLib.h>
#include <msgQLib.h>
#include <stdio.h>

// Global data structures
#define ENGINE_ADDRESS 1

unsigned char SerBuf[3], x;
int ser_fd;
int dir;

// Function declarations
void init(void);
void sendCommand(void);
void blowHorn(void);

int main(int argc, const char* argv[])
{
	printf("CS 4397.001 Project 1: Trainmaster Train System\n\n");
	printf("Select from the menu below:\n");
	printf("A. Ring the train's bell\n");
	printf("B. Start the train's engine\n");
	printf("C. Stop the train's engine\n");
	printf("D. Exit");

	// TODO: Get and process user input
}

// Initializes the serial connection.
void init(void)
{
	// Open serial port
	ser_fd = open("/tyCo/1", O_WRONLY, 0);
	printf("\nTrain ID: %d", ENGINE_ADDRESS);

	if (ser_fd == -1)
	{
		printf("[ERROR] Unable to open serial port.\n");
	}
	else
	{
		printf("Successfully opened serial port; fd = %d\n", ser_fd);
	}
}

// Sends data to the train via the serial connection.
void sendCommand(void)
{
	int numByteWritten = 0;
	SerBuf[0] = (unsigned char)254;
	SerBuf[1] = (unsigned char)0;
	numByteWritten = write(ser_fd, SerBuf, 3);
}

// Instructs the train to blow its horn.
void blowHorn(void)
{
	SerBuf[2] = 0x9c;

	/*
		Your values replace 0x9c for other commands. Enter a hexadecimal value depending on the manual. Read
		pages 36-37 of the Trainmaster manual and place the values in the 'Engine Commands' format. Set the
		train address as 1 and the C and D bits as per the command list on page 37 for the 3rd byte. The
		8th bit (MSB) for the 3rd byte should be 1, so fill only the 3rd byte. The 2nd byte is a 0.
	*/

	x = SerBuf[2];

	sendCommand();
}
