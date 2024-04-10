#include <iostream>
#include <vector>
#include <random>
using namespace std;

/*
    - This is a binary based maze
        - 1 : Wall
        - 0 : Path

    - The goal is to find a way through the path (0's) and avoid walls (1's).
*/
class Maze
{
private:
    int getRandomInt(int min, int max)
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }

    /*
        Pick a random number of 0 and 1 based on a probability.
    */
    int pickRandom(int probability)
    {
        if (getRandomInt(1, 10) > probability)
        {
            return 1;
        }
        return 0;
    }

public:
    int rows;
    int cols;
    vector<vector<int>> matrix;

    Maze(size_t n, size_t m) : rows(n), cols(m), matrix(n, vector<int>(m)) {}

    ~Maze()
    {
        // TODO : clear vector data.
        matrix.clear();
    }

    int startIndex = getRandomInt(1, rows - 2);
    int endIndex = getRandomInt(1, rows - 2);
    /*
        Generates a new maze with random path.
    */
    void generate()
    {

        // setup walls
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (i == 0 || i == (rows - 1) || j == 0 || j == (cols - 1))
                {
                    matrix[i][j] = 1;
                }
                if ((i == startIndex && j == 0) || (i == endIndex && j == (cols - 1)) || (i == startIndex && j == 1) || (i == endIndex && j == (cols - 2)))
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // setup path
        for (int i = 1; i < (rows - 1); ++i)
        {
            for (int j = 1; j < (cols - 1); ++j)
            {
                if (!((i == startIndex && j == 1) || (i == endIndex && j == (cols - 2))))
                {
                    matrix[i][j] = pickRandom(7);
                }
            }
        }
    }

    /*
        Print the matrix of the maze.
    */
    void print()
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};