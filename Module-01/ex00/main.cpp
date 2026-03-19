#include <iostream>

#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Worker.hpp"
#include "Workshop.hpp"

int main () {
	std::cout << std::endl << "========== IV.1 COMPOSITION ==========" << std::endl;
	Worker bob("Bob");
	Worker alex("Alex");

	std::cout << std::endl << "========== IV.2 AGGREGATION ==========" << std::endl;
	Shovel shov;
	bob.giveTool(&shov);
	bob.takeTool(&shov);

	std::cout << std::endl << "Transfer shovel from Bob to Alex" << std::endl;
	alex.giveTool(&shov);
	bob.takeTool(&shov);
	alex.takeTool(&shov);

	std::cout << std::endl << "Worker deletion must not delete shovel" << std::endl;
	{
		Worker temp("Temp");
		temp.giveTool(&shov);
		temp.takeTool(&shov);
	}
	alex.giveTool(&shov);
	alex.takeTool(&shov);

	std::cout << std::endl << "========== IV.3 INHERITANCE ==========" << std::endl;
	Hammer ham;
	bob.giveTool(&ham);
	bob.giveTool(&shov);
	bob.takeTools();

	std::cout << std::endl << "Transfer hammer from Bob to Alex" << std::endl;
	alex.giveTool(&ham);
	bob.takeTool(&ham);
	alex.takeTool(&ham);

	std::cout << std::endl << "Return one tool then all tools" << std::endl;
	alex.removeTool(&ham);
	alex.removeTools();
	alex.takeTools();

	std::cout << std::endl << "========== IV.4 ASSOCIATION ==========" << std::endl;
	Workshop forge("Forge");
	Workshop mine("Mine");

	forge.registerWorker(&bob);
	forge.registerWorker(&alex);
	mine.registerWorker(&alex);
	mine.registerWorker(&bob);

	std::cout << std::endl << "A worker can be in multiple workshops" << std::endl;
	forge.executeWorkDay();
	mine.executeWorkDay();

	std::cout << std::endl << "Worker leaves one workshop freely" << std::endl;
	forge.releaseWorker(&alex);
	forge.executeWorkDay();
	mine.executeWorkDay();

	std::cout << std::endl << "Scoped worker auto-leaves workshops on destruction" << std::endl;
	{
		Shovel eveShovel;
		Worker eve("Eve");
		eve.giveTool(&eveShovel);
		forge.registerWorker(&eve);
		mine.registerWorker(&eve);
		forge.executeWorkDay();
		eve.removeTools();
	}
	forge.executeWorkDay();
	mine.executeWorkDay();

	bob.removeTools();
	alex.removeTools();

	std::cout << std::endl << "========== END ==========" << std::endl;

	return 0;
}
