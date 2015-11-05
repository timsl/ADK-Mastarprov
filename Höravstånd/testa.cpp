#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    int n, k, temp;
    //cin >> k;
    k = 39;

    vector<int> test = {0, 39, 44, 46, 56, 77, 180, 322, 322, 322, 350, 800, 900, 1010, 2023, 2030, 2030, 2040, 2050, 3000, 5000, 5000, 5050, 5100, 5150, 5200};

   // vector<int> test = {0,3,5};// = {0,3,5};

    n = test.size();
     
    cout << n << endl;
    /*
    for(auto i = 0; i < n; i++) {
        cin >> temp;
        test.push_back(temp);
    }
    */
    
    temp = test[0]; 
    for(int i = 0; i < n; i++){
        test[i] = test[i] - temp;
    }

    vector<int> r, r2;

    int minstuff[n];

    for(int i = 0; i < n; i++) {
        r.push_back(test[i] - (k*i));
        r2.push_back(test[i] - (k*i));
    }

    sort(r2.begin(), r2.end());
    r2.erase(unique(r2.begin(), r2.end()), r2.end());

    int m = r2.size();
    int f[n][m];  

    for(int j = 0; j < m; j++) {
        f[0][j] = abs(r[0] - r2[j]);
    }

    int min = 2000000000;
    for(int x = 1; x < n; x++) {
        for(int j = 0; j < m; j++) {
            for(int h = j; h < m; h++) {
                if(f[x-1][h] >= r2[j]){
                    if(f[x-1][h] <= min)
                        min = f[x-1][h];
                }
            }
            if(min == 2000000000)
                min = f[x-1][m-1];

            
            f[x][j] = min + abs(r[x] - r2[j]);
            min = 2000000000;
        }
    }
    min = 2000000000; 
    
    for(int j = 0; j < m; j++) {
        if(f[n-1][j] < min)
            min = f[n-1][j];
    }

    /*
    for(int j = 0; j < m; j++){
        for(int x = 0; x < n; x++){
            cout << f[x][j] << " ";  
        }

        cout << endl;
    }
    */
    cout << endl << min << endl;
    
}
