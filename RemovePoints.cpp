#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

double calculateArea(const vector<Point>& polygon) {
    double area = 0.0;
    int n = polygon.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += (polygon[i].x * polygon[j].y - polygon[j].x * polygon[i].y);
    }
    return abs(area) / 2.0;
}

int main() {
    vector<Point> points = {
        {1, 2}, {2, 2.3}, {4.5, 3.5},
        {1, 3}, {3, 2},
        {6, 8}
    };

    double maxArea = 0.0;
    int pointToRemove = -1;

    for (int i = 0; i < points.size(); ++i) {
        vector<Point> remainingPoints;
        for (int j = 0; j < points.size(); ++j) {
            if (j != i) {
                remainingPoints.push_back(points[j]);
            }
        }

        double areaWithoutPoint = calculateArea(remainingPoints);

        if (areaWithoutPoint > maxArea) {
            maxArea = areaWithoutPoint;
            pointToRemove = i;
        }
    }

    if (pointToRemove != -1) {
        cout << "Remove point at index " << pointToRemove << " to maximize the area. New area: " << maxArea << endl;
    } else {
        cout << "No point to remove to maximize the area." << endl;
    }

    return 0;
}
