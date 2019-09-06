#include "OpsTest.h"
#include "SpriteTests.h"

int main(int argc, char *argv[])
{
	double total = 0;
	double opsCount = OpsRunAll();
	total += opsCount;
	opsCount /= OpsSize();
	std::cout << "Ops: " << opsCount * 100 << "%" << std::endl;

	double spriteCount = SpriteRunAll();
	total += spriteCount;
	spriteCount /= SpriteTestsSize();
	std::cout << "Sprite tests: " << spriteCount * 100 << "%" << std::endl;

	total /= OpsSize() + SpriteTestsSize();
	std::cout << "Total: " << total * 100 << "%" << std::endl;
	system("pause");
	return 0;
}