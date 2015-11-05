#include <vector>
#include <iostream>

using namespace std;

int dist(int n, int k, vector<int> p){
    int start, mindist;
    int amtright, prevdist;


    if(n % 2 == 0) {
        if(p[n/2] - p[0] > p[n/2+1] - p[n-1])
            start = n/2;
        else
            start = n/2+1;
    }

    
    
    vector<int> dist;
    vector<vector<string>> stacks; 
    vector<string> temp;
    for(int i = 1; i < n; i++) {
        dist.push_back(p[i] - p[i-1] - k);

        if (p[i] - p[0] < k) {
            temp.push_back(p[i]);
        }
    }

}

int main(int argc, char* argv[]) {
    
    // Vector med personer, varje person står på int position.
    vector<int> personer = {1, 5, 4, 4, 8, 12};
    
    int n = personer.size();
    
    // Max hearing distance.
    int k = 3;

    int start, currentDist;


    std::cout << currentDist << std::endl;

}
