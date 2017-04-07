#include "ArduinoSerial.h"

ArduinoSerial::ArduinoSerial()
{

}

ArduinoSerial::~ArduinoSerial()
{
    delete SP;
}

bool ArduinoSerial::setComPort(int comport)
{
    printf("Initializing connection to Arduino..");

    //Convert port number to const char
    std::string portStr = "COM" + std::to_string(comport);
    std::cout << portStr << std::endl;
    const char *port = portStr.c_str();
    //catch error here
    SP = new Serial(port); //use the comport variable here

    if (SP->IsConnected())
    {
        printf("We are connected!");
        return true;
    }
    return false;
}

bool ArduinoSerial::startPump()
{
	if (SP->IsConnected())
	{
		SP->WriteData("s", 1);
        //Sleep(500);
		return true;
	}
	return false;
}

bool ArduinoSerial::stopPump()
{
	if (SP->IsConnected())
	{
		SP->WriteData("p", 1);
        //Sleep(500);
		return true;
	}
	return false;
}

bool ArduinoSerial::openLiquid1()
{
	if (SP->IsConnected())
	{
		SP->WriteData("o", 1);
        //Sleep(500);
		return true;
	}
	return false;
}

bool ArduinoSerial::openLiquid2()
{
	if (SP->IsConnected())
	{
		SP->WriteData("c", 1);
        //Sleep(500);
		return true;
	}
	return false;
}
