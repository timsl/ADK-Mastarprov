#include <queue>
#include <iostream>

int main(int argc, char* argv[]){

    // Fictional case... should work for any.
    int workerHours[] = {1,2,3};
    int amtWorkers = sizeof(workerHours)/sizeof(workerHours[0]);
    int lowest, totalCost = 0;


    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for(int i = 0; i < amtWorkers; ++i)
        pq.push(workerHours[i]);

    while(!pq.empty()){
        lowest = pq.top(); pq.pop();
        totalCost += lowest*amtWorkers;
        amtWorkers--;
    }
    
    std::cout << totalCost;

}
