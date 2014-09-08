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
int init(void);
int dispose(void);
void sendCommand(void);
void ringBell(void);
void startEngine(void);
void stopEngine(void);
void blowHorn(void);

int main(int argc, const char* argv[])
{
	printf("CS 4397.001 Project 1: Trainmaster Train System\n");
	printf("===============================================\n\n");

	while(true)
	{
		printf("Select from the menu below:\n");
		printf("1. Ring the train's bell\n");
		printf("2. Start the train's engine\n");
		printf("3. Stop the train's engine\n");
		printf("4. Exit\n\n");

		int choice = 0;
		bool valid = false;

		// Get menu choice:
		do
		{
			printf("Enter selection: ");
			valid = scanf("%d", &choice) && choice <= 4 && choice >= 1;

			if (!valid)
				fflush(stdin);
		} while (!valid);

		// Process input:
		switch (choice)
		{
			case 1:
				printf("TODO: Ring train's bell\n");
				ringBell();
				break;
			case 2:
				printf("TODO: Start train's engine\n");
				startEngine();
				break;
			case 3:
				printf("TODO: Stop train's engine\n");
				stopEngine();
				break;
			case 4:
				dispose();
				exit(0);
				break;
			default:
				printf("Input was invalid. Please try again.\n");
				break;
		}
	}
}

// Initializes the serial connection.
// Returns: 1 if connection was successfully opened, -1 otherwise.
int init(void)
{
	// Open serial port
	ser_fd = open("/tyCo/1", O_WRONLY, 0);
	printf("\nTrain ID: %d", ENGINE_ADDRESS);

	if (ser_fd == -1)
	{
		printf("[ERROR] Unable to open serial port.\n");
		return -1;
	}
	else
	{
		printf("Successfully opened serial port; fd = %d\n", ser_fd);
		reutrn 1;
	}
}

// Closes the serial connection.
// Returns: 0 if connection was successfully closed, -1 otherwise.
int dispose(void)
{
	if (ser_fd > 0)
	{
		return close(ser_fd);
	}

	return -1;
}

// Sends data to the train via the serial connection.
void sendCommand(void)
{
	int numByteWritten = 0;
	SerBuf[0] = (unsigned char)254;
	SerBuf[1] = (unsigned char)0;
	numByteWritten = write(ser_fd, SerBuf, 3);
}

// Instructs the train to start its engine.
void startEngine(void)
{
	// TODO
}

// Instructs the train to stop its engine.
void stopEngine(void)
{
	// TODO
}

// Instructs the train to ring its bell.
void ringBell(void)
{
	// TODO
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
