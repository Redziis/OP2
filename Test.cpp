#include "Test.h"


void generateStudents(int n, string fileName) {
    std::ifstream test;
    test.open(fileName.append(std::to_string(n)).append(".txt"));
    test.close();
    if (test.fail())
    {
        std::ofstream output(fileName);
        std::stringstream endBuffer;
        using chronoClock = std::chrono::high_resolution_clock;
        unsigned seed = static_cast<long unsigned int> (chronoClock::now().time_since_epoch().count());
        std::mt19937 generator(seed);
        std::uniform_int_distribution<int> distribution(0, 10);
        std::uniform_int_distribution<int> distributionSize(2, 20);

        cout << "Generating..." << endl;
        auto start = std::chrono::high_resolution_clock::now();

        int a = 7;//distributionSize(generator);

        for (int i = 1; i <= n; i++)
        {

            endBuffer << endl;
            int b = log10(i) + 1;
            endBuffer << "Vardas" << i << string(25 - (6 + b), ' ') << "Pavarde" << i << string(25 - (7 + b), ' ');
            for (int j = 0; j < a; j++)
            {
                endBuffer << distribution(generator) << "    ";
            }
        }
        output << endBuffer.str();
        output.close();

        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
        std::cout << "Generating " << n << " took " << diff.count() << " s" << endl;
    }
}

