#include "OpsTest.h"
#include "SpriteTests.h"

int main(int argc, char *argv[])
{
	double total = 0;
	double opsCount = OpsRunAll();
	std::cout << "Ops: " << opsCount * 100 << "%" << std::endl;
	total += opsCount;
	double spriteCount = SpriteRunAll();
	std::cout << "Sprite tests: " << spriteCount * 100 << "%" << std::endl;
	total += spriteCount;
	//total /= 2;
	//std::cout << "Total: " << total * 100 << "%" << std::endl;
	system("pause");
	return 0;
}