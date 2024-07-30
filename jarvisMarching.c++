#include <bits/stdc++.h>
using namespace std;

// Function to determine the orientation of the triplet (p, q, r)
// Returns 0 if collinear, 1 if clockwise, -1 if counterclockwise
int orientation(const vector<int>& p, const vector<int>& q, const vector<int>& r) {
    int val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
    if (val == 0) return 0; // collinear
    return (val > 0) ? 1 : -1; // clockwise or counterclockwise
}

void marchJarvis(vector<vector<int>>& points) {
    int n = points.size();
    if (n < 3) return; // Convex hull is not possible

    // Initialize Result
    vector<int> hull;

    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i][0] < points[l][0])
            l = i;

    // Start from leftmost point, keep moving counterclockwise
    // until reach the start point again. This loop runs O(h) times
    // where h is the number of points in the result or output.
    int p = l, q;
    do {
        // Add current point to result
        hull.push_back(p);

        // Search for a point 'q' such that orientation(p, x, q) is counterclockwise
        // for all points 'x'. The idea is to keep track of last visited most
        // counterclockwise point in q. If any point 'i' is more counterclockwise
        // than q, then update q.
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            // If i is more counterclockwise than current q, then update q
            if (orientation(points[p], points[i], points[q]) == -1)
                q = i;
        }

        // Now q is the most counterclockwise with respect to p
        // Set p as q for next iteration, so that q is added to result 'hull'
        p = q;

    } while (p != l); // While we don't come to first point

    // Print result
    for (int i : hull)
        cout << "(" << points[i][0] << ", " << points[i][1] << ")" << endl;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    marchJarvis(points);

    return 0;
}
#https://www.youtube.com/watch?v=El7A7B0-T6U