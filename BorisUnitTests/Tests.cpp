#include "Tests.h"

double RunTests(StrTestMap tests)
{
	if (tests.size() > 0)
	{
		double count = 0;
		for (StrTestMap::iterator i = tests.begin(); i != tests.end(); i++)
		{
			bool r;
			try
			{
				r = i->second();
			}
			catch(std::exception err)
			{
				r = false;
				std::cout << "Error: \"" << err.what() << "\"" << std::endl;
			}
			count += r;
			std::cout << i->first << ": " << BorisOperations::BoolToString(r) << ";" << std::endl;
		}
		return count;
	}
	return (double)tests.size();
}