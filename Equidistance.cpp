#include <iostream>
#include <vector>
using namespace std;

struct Point {
    double x, y;
};

int main() {
    vector<Point> points = {
        {1, 2}, {2, 2.3}, {4.5, 3.5},
        {1, 3}, {3, 2},
        {6, 8}
    };

    double centroidX = 0.0;
    double centroidY = 0.0;

    for (const Point& p : points) {
        centroidX += p.x;
        centroidY += p.y;
    }

    int numPoints = points.size();
    centroidX /= numPoints;
    centroidY /= numPoints;

    cout << "Centroid of the shape is (" << centroidX << ", " << centroidY << ")" << endl;

    return 0;
}
