#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "middleearth.h"

using namespace std;

float computeDistance(MiddleEarth& me, string start, vector<string> dests);

string appendRoute(const string& start, const vector<string>& dests);

void printRoute(string start, vector<string> dests);

int main(int argc, char** argv)
{
    // check the number of parameters
    if (argc != 6)
    {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf(argv[1], "%d", &width);
    sscanf(argv[2], "%d", &height);
    sscanf(argv[3], "%d", &num_cities);
    sscanf(argv[4], "%d", &rand_seed);
    sscanf(argv[5], "%d", &cities_to_visit);
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    vector<string> copied = dests;

    float minimum = numeric_limits<float>::max();
    string start, route;
    for (const string& first:copied)
    {
        dests.erase(remove(dests.begin(), dests.end(), first), dests.end());
        sort(dests.begin(), dests.end());
        minimum = computeDistance(me, first, dests);
        while (next_permutation(dests.begin(), dests.end()))
        {
            float distance = computeDistance(me, first, dests);
            if (distance < minimum)
            {
                minimum = distance;
                start = first;
                route = appendRoute(start, dests);
                printRoute(start, dests);
                cout << " " << fixed << setprecision(4) << minimum << endl;
            }
        }
        dests.push_back(first);
    }
    dests.erase(remove(dests.begin(), dests.end(), start), dests.end());
    cout << "Your journey will take you along the path " << route << endl
         << "and will have length " << fixed << setprecision(4)
         << minimum << endl;
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth& me, string start, vector<string> dests)
{
    float total = me.getDistance(start, dests.front());
    for (int i = 1; i < dests.size(); ++i) // dests.size() can be as low as 1
    {
        total += me.getDistance(dests.at(i - 1), dests.at(i));
    }
    total += me.getDistance(dests.back(), start);
    return total;
}

string appendRoute(const string& start, const vector<string>& dests)
{
    string route = start;
    for (const string& dest:dests)
    {
        route += " -> " + dest;
    }
    route += " -> " + start;
    return route;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.  The output should be of the form:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(string start, vector<string> dests)
{
    cout << appendRoute(start, dests);
}
