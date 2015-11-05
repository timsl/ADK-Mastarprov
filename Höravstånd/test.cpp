#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    
    vector<int> test1 = {0, 5, 7};

    int k = 1;

    vector<int> resVector;

    int matris[test1.size()][(k*2+1)];


    for(int i = 0; i < test1.size(); i++){
        resVector.push_back(test1[i] - k*i);
    }

    for(int i = 0; i < (k*2+1); i++){
        matris[0][i] = abs(test1[0] - (i-k));
        //cout << matris[0][i] << " min: 3 ";
    }
    cout << endl;

    

    int min = 30;
    for(int i = 1; i < test1.size(); i++) {
        for(int j = 0; j < (k*2+1); j++) {
            
            for(int e = j; e < (k*2+1); e++) {
                if(matris[i-1][e] < min)
                    min = matris[i-1][e];
            } 

            
             
            
            matris[i][j] = abs(resVector[i] - (j-k)) + min; 
            //cout << (resVector[i]-(j-k)) << " min: " << min << " "; 
            min = 30;
        }
        cout << endl;
    }

 
    for(int i = 0; i < (k*2+1); i++) {
        
        for(int j = 0; j < test1.size(); j++) {
            cout << matris[j][i] << " ";
        }
        cout << endl;
    } 
}
