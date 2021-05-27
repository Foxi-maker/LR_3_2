#pragma once
#include "Header.h"

class WaveEquation
{
	double L = 1.;
	double T = 5.;

	std::function<double(double)> F;
	std::function<double(double)> G;
	std::function<double(double)> Fi;
	std::function<double(double)> Psi;

	//Поток для вывода данных
	static std::ofstream out;

public:
	WaveEquation();
	WaveEquation(std::function<double(double)>, std::function<double(double)>, std::function<double(double)>, std::function<double(double)>, std::string);

	void Scheme();

	~WaveEquation();
};

