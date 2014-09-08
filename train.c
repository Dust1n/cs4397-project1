#include <taskLib.h>
#include <logLib.h>
#include <ioLib.h>
#include <msgQLib.h>
#include <stdio.h>

unsigned char SerBuf[3], x;
int ser_fd;
int dir;

// Function Declarations
void SendCommand();

// Global Data Structures
#define ENGINE_ADDRESS 1

void init(void)
{
	// Open Serial Port
	ser_fd =  open("/tyCo/1",O_WRONLY, 0);
	printf("\n train id %d",ENGINE_ADDRESS);
	if( ser_fd == -1)
			printf("\nSerial Port Not Open, error\n",ser_fd,0,0,0,0,0);
	else
			printf("\nSerial Port Open, fd = %d \n",ser_fd,0,0,0,0,0);
	
}

// TODO: Add main()

// Sends data to the train via the serial connection
void SendCommand()
{
	int numByteWritten = 0;
	SerBuf[0] = (unsigned char)254;
	SerBuf[1] = (unsigned char)0;
	numByteWritten = write(ser_fd, SerBuf, 3);
} 

// Instructs the train to blow its horn
void blowTrainHorn()
{
	SerBuf[2] = 0x9c;

	/*
		Your values replace 0x9c for other commands. Enter a hexadecimal value depending on the manual. Read
		pages 36-37 of the Trainmaster manual and place the values in the 'Engine Commands' format. Set the
		train address as 1 and the C and D bits as per the command list on page 37 for the 3rd byte. The
		8th bit (MSB) for the 3rd byte should be 1, so fill only the 3rd byte. The 2nd byte is a 0.
	*/

	x = SerBuf[2];

	SendCommand();
}
