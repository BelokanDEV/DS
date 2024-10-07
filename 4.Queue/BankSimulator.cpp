#include <ctime>
#include "BankSimulator.h"
int main() {
    srand( (unsigned int) time(NULL) );
    BankSimulator sim;
    sim.readSimulationParameters();
    sim.run();
    sim.printStats();
    return 0;
}