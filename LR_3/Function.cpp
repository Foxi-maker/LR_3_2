//#include "Function.h"
#include "Header.h"

//Example 1
double ExFirstF(double xx)
{
	return sin(PI*xx);
}

double ExFirstG(double xx)
{
	return 0.0;
}

double ExFirstFi(double tt)
{
	return 0.0;
}

double ExFirstPsi(double tt)
{
	return 0.0;
}

//Example 2
double ExSecondF(double xx)
{
	return xx * (1 - xx);
}

double ExSecondG(double xx)
{
	return 0.0;
}

double ExSecondFi(double tt)
{
	return 0.0;
}

double ExSecondPsi(double tt)
{
	return 0.0;
}

//Variant 9
double NineF(double xx)
{
	return xx * (2 * xx - 0.5);
}

double NineG(double xx)
{
	return cos(2 * xx);
}

double NineFi(double tt)
{
	return tt * tt;
}

double NinePsi(double tt)
{
	return 1.5;
}

double TaskOneF(double xx)
{
	if (xx<1. / 3 && xx>-1. / 3)
		return 1.;
	else
		return 0.;
}

double TaskOneG(double)
{
	return 0.0;
}

double TaskOneFi(double)
{
	return 0.0;
}

double TaskOnePsi(double)
{
	return 0.0;
}
