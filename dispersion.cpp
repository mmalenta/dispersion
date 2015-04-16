/* ##############################################
	Simple tool for providing dispersion
	delay for given DM and frequency range,
	as well as smearing for given bandwidth.
	Nothing really fancy or revolutionary.
############################################## */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

struct properties
{
	int nchans;
	double band;
	double topchn;
	double dm;
};

void disperse(double delays[], const properties prop)
{

	int nchans = prop.nchans;

	for (int chan = 0; chan < nchans; chan++)
	{
	}
}

int main(int argc, char* argv[])
{

	properties prop;

	// set default values

	prop.dm = 100.0;
	prop.nchans = 1024;
	prop.topchn = 1500.0;
	prop.band = -0.032;


	for (int arg = 1; arg < argc; arg++)
	{
		if (string(argv[arg]) == "-d")
		{
			arg++;
			prop.dm = atof(argv[arg]);
		} else if (string(argv[arg]) == "-n")
		{
			arg++;
			prop.nchans = atoi(argv[arg]);
		} else if (string(argv[arg]) == "-t")
		{
			arg++;
			prop.topchn = atof(argv[arg]);
		} else if (string(argv[arg]) == "-b")
		{
			arg++;
			prop.band = atof(argv[arg]);
		}


	}

	// make sure bandwidth is negative

	cout << "Options: " << endl;
	cout << "\tDM: " << prop.dm << endl;
	cout << "\tNumber of channels: " << prop.nchans << endl;
	cout << "\tFrequency of the top channel: " << prop.topchn << " MHz" << endl;
	cout << "\tBandwidth: " << prop.band << " MHz" << endl;

	int nchans = 0;

	double *delays = new double[nchans];


	disperse(delays, prop);

	return 0;
}
