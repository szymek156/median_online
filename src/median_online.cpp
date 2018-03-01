#include "Executor.h"
#include "MedianDummy.h"
#include "MedianPrioQueue.h"
#include "ParserGenerator.h"

int main(int argc, char **argv) {

    using namespace median_online;
    Executor<ParserGenerator, MedianDummy<int> > executor(argc, argv);

    executor.execute();

	return 0;
}
