#include "Executor.h"

int main(int argc, char **argv) {

    using namespace median_online;
    Executor<Parser, Parser> executor(argc, argv);

    executor.execute();

	return 0;
}
