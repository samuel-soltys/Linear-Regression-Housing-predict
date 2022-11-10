#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

typedef long long ll;

float linear_function(int x, float w, float b) {
    return(w * x + b);
}

float squared_error_cost_function(float w, float b, vector<pair<int,int> > training_houses) {
    float J = 0;
    
    // sum((y_(i) - y(i))^2)
    for(int i = 0; i < training_houses.size(); i++) {
        J += pow(linear_function(training_houses[i].first, w, b) - training_houses[i].second, 2);
    }
    
    // J = 1/2m * sum((y(i) - y(i))^2)    
    return(J / (2 * training_houses.size()));
}


int main() {
    
    vector<pair<int,int> > training_houses;
    
    training_houses.push_back(make_pair(94, 660000));
    training_houses.push_back(make_pair(211, 890000));
    training_houses.push_back(make_pair(154, 648000));
    training_houses.push_back(make_pair(150, 535000));
    training_houses.push_back(make_pair(226, 300000));
    training_houses.push_back(make_pair(150, 569000));
    training_houses.push_back(make_pair(120, 780000));
    training_houses.push_back(make_pair(92, 399990));
    training_houses.push_back(make_pair(500, 870000));
    
    // y = linear_function(x)
    float w = 0, b = 0;
    
    // test of cost function
    float cost_function = squared_error_cost_function(w, b, training_houses);
    
    cout << "Squared_error_cost function value: " << cost_function << endl;
    return 0;
}