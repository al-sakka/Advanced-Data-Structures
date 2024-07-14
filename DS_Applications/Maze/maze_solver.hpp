#include <iostream>
#include <vector>
#include <random>
#include "../../Advanced_DS/Dynamic_Stack.hpp"

class Coordinate
{
public:
    int x, y;
    Coordinate(int X, int Y) : x(X), y(X) {}
};

/*
    A maze solver using dynamic stack data structure
*/
class MazeSolver
{
private:
    std::vector<std::vector<int>> maze;
    std::vector<std::vector<bool>> visited;
    int rows, cols;

public:
    MazeSolver(std::vector<std::vector<int>> mz) : maze(mz)
    {
        rows = maze.size();
        cols = maze[0].size();
        visited.resize(rows, std::vector<bool>(cols, false));
    }

    bool isValid(int x, int y)
    {
        return ((x >= 0) && (x < rows) && (y >= 0) && (y < cols) && (maze[x][y] == 0) && !(visited[x][y]));
    }

    bool solveMaze(int stX, int stY, int endX, int endY)
    {
        DynamicStack<Coordinate> s;
        s.push(Coordinate(stX, stY));
        visited[stX][stY] = true;

        while (!(s.isEmpty()))
        {
            Coordinate current = s.peek();
            s.pop();

            if (current.x == endX && current.y == endY)
            {
                std::cout << "Solved!\n";
                return true;
            }

            int dx[] = {1, -1, 0, 0}; // rows
            int dy[] = {0, 0, 1, -1}; // cols

            for (int i = 0; i < 4; ++i) // 4 directions
            {
                int newX = current.x + dx[i];
                int newY = current.y + dy[i];
                if (isValid(newX, newY))
                {
                    visited[newX][newY] = true;
                    maze[newX][newY] = 5;
                    s.push(Coordinate(newX, newY));
                }
            }
        }

        std::cout << "No Path Found!\n";
        return false;
    }
};