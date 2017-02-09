#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

#include <boost/algorithm/string.hpp>

class Device {

private:
	string device_name;

public:
	virtual void open_device() = 0;
	virtual void read_device() = 0;
	virtual void write_device() = 0;
	virtual void close_device() = 0;
	void set_device_name(string name)
	{
		device_name = name;
	}

	virtual ~Device()
	{
		cout << "Device is deleted \n";
	};
};


class Sensor1 : public Device
{
public:

	Sensor1()
	{
		set_device_name("Sensor 1")
	}

	virtual void open_device()
	{
		cout << "Sensor 1 is opened \n";
	}
	virtual void read_device()
	{
		cout << "Sensor 1 is read \n";
	}
	virtual void write_device()
	{
		cout << "Sensor 1 is written \n";
	}
	virtual void close_device()
	{
		cout << "Sensor 1 is closed \n";
	}

	virtual ~Sensor1 ()
	{
		cout << "Sensor 1 is deleted \n";
	}
};

class Sensor2 : public Device
{

public:
	Sensor2()
	{
		set_device_name("Sensor 2")
	}


	virtual void open_device()
	{
		cout << "Sensor 2 is opened \n";
	}
	virtual void read_device()
	{
		cout << "Sensor 2 is read \n";
	}
	virtual void write_device()
	{
		cout << "Sensor 2 is written \n";
	}
	virtual void close_device()
	{
		cout << "Sensor 2 is closed \n";
	}

	virtual ~Sensor2 ()
	{
		cout << "Sensor 2 is deleted \n";
	}
};


class DeviceFactory
{
public:

	static Device * get_device(string device_name)
	{
		if (device_name == "sensor 1")
		{
			return new Sensor1();
		}
		else if (device_name == "sensor 2")
		{
			return new Sensor2();
		}
		return NULL;
	}
};


int main()
{
	Device* dev1 = DeviceFactory::get_device("sensor 1");
	Device* dev2 = DeviceFactory::get_device("sensor 2");

	dev1->open_device();
	dev2->open_device();

	dev1->close_device();
	dev2->close_device();

	delete dev1;
	delete dev2;

	return 0;
}
