#include "Header.h"

std::ofstream WaveEquation::out;

int main()
{
	WaveEquation exmp(ExFirstF, ExFirstG, ExFirstFi, ExFirstPsi, "Poryadok1");
	//WaveEquation exmp(ExSecondF, ExSecondG, ExSecondFi, ExSecondPsi, "example2");
	//WaveEquation exmp(NineF, NineG, NineFi, NinePsi, "varNine");
	//WaveEquation exmp(TaskOneF, TaskOneG, TaskOneFi, TaskOnePsi, "TaskOneDif01");
	//WaveEquation exmp(TaskOneF, TaskOneG, TaskOneFi, TaskOnePsi, "TaskOneExact1");
	exmp.Scheme();
}
