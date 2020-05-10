#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int start(0), max(0), count(0);
    while ((start + tank) < dist) {
        for (int i = 0; i < stops.size(); i++){
            if (stops[i] <= (start + tank)){
                max = stops[i];
            }
        }
        start = max;
        count++;
        if (count > stops.size()){
            return -1;
        }
    }
    return count;
}


int main() {
    int d(0);
    cin >> d;
    int m(0);
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
