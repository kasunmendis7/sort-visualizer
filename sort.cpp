#include <SDL2/SDL.h>
#include <iostream>
#include <random>
#include <ranges>
#include <algorithm>

int main()
{
    std::random_device rd;
    std::uniform_int_distribution d(1,99);
    std::vector<int> v;

    // Populate our vector with random numbers
    for (int i=0; i<100; i++)
    {
        v.push_back(d(rd));
    }

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(100*10, 100*10, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 10, 10);
    // Sort algorithm
    for (unsigned i = 0; i < v.size(); i++)
    {
        for(unsigned j=i; j<v.size(); j++)
        {
            if (v[i] > v[j])
            {
                std::swap(v[i], v[j]);
            }
        }
    }
    for (int i : v)
    {
        std::cout << i << " ";
    }
    if(std::ranges::is_sorted(v))
    {
        std::cout << "\nSorted\n";
    }
    else
    {
        std::cout << "\nNot sorted\n";
    }
    
}