#include "OpsTest.h"

int main(int argc, char *argv[])
{
	double opsCount = OpsRunAll();
	std::cout << "Ops: " << opsCount * 100 << "%" << std::endl;
	system("pause");
	return 0;
}