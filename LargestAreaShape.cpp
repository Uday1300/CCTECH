#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double calculateArea(const vector<Point>& polygon) {
    int n = polygon.size();
    double area = 0.0;
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

    int n = points.size();
    double largestArea = 0.0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            vector<Point> polygon;
            polygon.push_back(points[i]);
            polygon.push_back(points[j]);

            for (int k = 0; k < n; ++k) {
                if (k != i && k != j) {
                    bool isInside = true;
                    for (int l = 0; l < polygon.size(); ++l) {
                        if (distance(polygon[l], points[k]) < 1e-9) {
                            isInside = false;
                            break;
                        }
                    }
                    if (isInside) {
                        polygon.push_back(points[k]);
                    }
                }
            }

            if (polygon.size() >= 3) {
                double area = calculateArea(polygon);
                largestArea = max(largestArea, area);
            }
        }
    }

    cout << "Largest area of the shape formed: " << largestArea << endl;

    return 0;
}
