#include <iostream>
#include <chrono>
#include <cstdlib>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <executable>" << std::endl;
        return 1;
    }

    // Get the name of the executable to run
    std::string executable = argv[1];

    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "Started to calculate..." << std::endl;

    // Execute the provided executable
    int status = system(executable.c_str());

    // Record end time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration in seconds
    std::chrono::duration<double> duration = end - start;

    // Output the execution time
    std::cout << "Successfully!" << std::endl;
    std::cout << "Execution time: " << duration.count() << " seconds." << std::endl;

    return status;
}
