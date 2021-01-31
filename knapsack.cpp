#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

// Dynamically computes the maximum value.
const int KS(int n, int C, int *& dynMatrix, int *& values, int *& weights){
    int result = 0;
    // If the value is already computed, return it.
    if(dynMatrix[(n-1)*(C-1)] != 0) result = dynMatrix[(n-1)*(C-1)];

    if(n == 0 || C == 0) result = 0;
    else if(weights[n-1] > C) result = KS(n-1,C,dynMatrix, values, weights);
    else{
        int take = values[n-1] + KS(n-1,C-weights[n-1], dynMatrix, values, weights);
        int pass = KS(n-1, C, dynMatrix, values, weights);
        result = max(take,pass);
    }

    dynMatrix[n*C] = result;
    return result;
}

int main(void){
    // Capacity, Number of Objects, Value, Weight, Resulting Value.
    int C, n, v, w, result;
    vector<int> results;
    ifstream in("sample_in.in");
    cin.rdbuf(in.rdbuf());


    // Reading from standard input.
    // Start by reading capacity.
    while (cin >> C) {
        // Then read the number of items.
        cin >> n;

        // Construct a dynamic programming Matrix.
        int * dynMatrix = new int [n*C];
        int * values = new int [n];
        int * weights = new int [n];        

        // Read the items value and weight.
        for(int i=0; i < n; i++){
            cin >> v;            
            cin >> w;
            values[i] = v;
            weights[i] = w;
        }


        // Dynamically solve the problem.
        result = KS(n,C, dynMatrix, values, weights);

        // Store the result in the array of results.
        results.push_back(result);

        // Cleanup
        delete[] dynMatrix;
        delete[] values;
        delete[] weights;
    }

    // Print to standard output.
    for(int i=0; i < results.size(); i++)
        cout << "Test " << i+1 << " result: " << results[i] << endl;

    // Terminate the program.
    return 0;
}