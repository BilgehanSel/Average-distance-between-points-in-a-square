#include <iostream>
#include <time.h>
#include <math.h>


struct RandomPoint {
    RandomPoint() {
        x = double(std::rand() % 100000) / 100000.0;
        y = double(std::rand() % 100000) / 100000.0;
    }
    double x, y;
};

double DistancePoints(RandomPoint const &p1, RandomPoint const &p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}


int main() {
    unsigned iterations = 10000000;
    std::srand(unsigned(time(0)));

    double total_sum;

    for (int i = 0; i != iterations; i++) {
        RandomPoint p1, p2;
        total_sum += DistancePoints(p1, p2);
    }

    std::cout << "Average is: " << total_sum / iterations << std::endl;
    return 0;
}
