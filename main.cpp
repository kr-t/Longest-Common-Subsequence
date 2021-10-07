#include "lcs.hpp"

int main()
{
    /* Open input file */
    std::ifstream inputFile("input.txt");

    if( inputFile.is_open() )
    {
        /* Declare variables to store input */
        unsigned int numberOfSequences;
        std::string originalPattern, comperativePattern;

        /* Use vector to declare unknown number of threads*/
        std::vector<std::future<std::string>> threadNumbers; 

        /* Store number of sequences and move cursor through the space */
        inputFile >> numberOfSequences;
        inputFile.seekg(1, inputFile.cur);

        /* Store original pattern to be compared to other strings */
        std::getline(inputFile, originalPattern);

        /* Create threads to compare original and comperative patterns till EOF */
        while (std::getline(inputFile, comperativePattern))
        {
            threadNumbers.push_back(std::async(std::launch::async, longestCommonSubsequence, comperativePattern, originalPattern));
        }
        
        inputFile.close();

        /* Open output file */
        std::ofstream outputFile("output.txt");

        /* Check if number of sequences and run threads are equal */
        if( outputFile.is_open() && (numberOfSequences == threadNumbers.size()))
        {
            /* Write output and close file */
            for (unsigned int i = 0; i < numberOfSequences; i++)
            {
                outputFile << threadNumbers[i].get() << std::endl;
            }

            outputFile.close();
        }
    }

    return 0;
}
