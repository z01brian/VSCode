#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m; cin >> n >> m;

    long long points = (n+1)*(m+1);
    long long triangles = ((points)*(points-1)*(points-2))/6;
    triangles -= (m+1) * ((n+1)*(n)*(n-1))/6;
    triangles -= (n+1) * ((m+1)*(m)*(m-1))/6;

    for (int x = 1; x<=n+1; x++) { //x distance
        for (int y = 1; y<=m+1; y++) { //y distance
            long long diagonalPoints = gcd(x, y)-1; //points with xDistance x and yDistance y should be gcd(x, y)-1
            long long pairs = (n+1-x)*(m+1-y);
            triangles -= 2 * pairs * diagonalPoints;
        }
    }
    cout << triangles;
    return 0;
  
}