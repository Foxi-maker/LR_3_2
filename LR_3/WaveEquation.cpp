#include "WaveEquation.h"

WaveEquation::WaveEquation()
{
}

WaveEquation::WaveEquation(std::function<double(double)> funcF, std::function<double(double)> funcG, std::function<double(double)> funcFi, std::function<double(double)> funcPsi, std::string na)
{
	F = funcF;
	G = funcG;
	Fi = funcFi;
	Psi = funcPsi;

	out.open("OUTPUT\\" + na + ".txt");
	if (!out.is_open())
	{
		std::cout << "Error! File for writing was not open!";
		exit(1);
	}
}

void WaveEquation::Scheme()
{
	double tau = 0.01, h = 0.1;
	//double tau = 0.075, h = 0.1;
	//double tau = 0.05, h = 0.1;
	//double tau = 0.01, h = 0.1;

	int Nx = L / h + 1;
	int Nt = T / tau + 1;

	//Сетка по положению и времени
	std::vector<std::vector<double>> grid(3, std::vector<double>(Nx));

	//Заполение значениями начальных и краевых условий
	double tau_DIVIDE_h = tau * tau / (h*h);
	double x = -2.;
	for (int pIter = 0; pIter < Nx; pIter++)
	{
		grid[0][pIter] = F(x);
		grid[1][pIter] = grid[0][pIter] + tau * G(x) + 1. / 2 * tau_DIVIDE_h*(F(x + h) - 2 * F(x) + F(x - h));
		//grid[1][pIter] = grid[0][pIter];															//Для задачи 1
		//grid[1][pIter] = grid[0][pIter] + tau * G(x) + tau * tau / 2 * (-PI * PI*sin(PI*x));		//TODO: вторая произвводная
		x += h;
	}
	//for (const auto gx : grid[0])
	//	out << gx << " ";
	//out << "\n";
	//for (const auto gx : grid[1])
	//	out << gx << " ";
	//out << "\n";

	double time = 0.;
	//Разностная схема крест
	for (int tIter = 1; tIter < Nt - 1; tIter++)
	{
		//Краевые условия
		time += tau;
		grid[1].front() = Fi(time);
		grid[1].back() = Psi(time);
		grid[2].front() = Fi(time);
		grid[2].back() = Psi(time);

		for (int pIter = 1; pIter < Nx - 1; pIter++)
		{
			grid[2][pIter] = tau_DIVIDE_h * (grid[1][pIter + 1] - 2. * grid[1][pIter] + grid[1][pIter - 1]) + 2. * grid[1][pIter] - grid[0][pIter];
		}

		//for (const auto gx : grid[2])
		//	out << gx << " ";
		//out << "\n";

		grid[0] = grid[1];
		grid[1] = grid[2];
	}
	for (const auto gx : grid[2])
		out << gx << " ";
	out << "\n";
}

WaveEquation::~WaveEquation()
{
}
