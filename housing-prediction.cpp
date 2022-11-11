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

float derivative_w(float w, float b, vector<pair<int,int> > training_houses) {
    
    float J = 0;
    
    for(int i = 0; i < training_houses.size(); i++) {
        J += (linear_function(training_houses[i].first, w, b) - training_houses[i].second) * training_houses[i].first;
    }
    
    return(J / training_houses.size());
}

float derivative_b(float w, float b, vector<pair<int,int> > training_houses) {
    
    float J = 0;
    
    for(int i = 0; i < training_houses.size(); i++) {
        J += linear_function(training_houses[i].first, w, b) - training_houses[i].second;
    }
    
    return(J / training_houses.size());
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
    
    // batch gradient descent
    float learning_rate = 0.00004;
    
    float tmp_w, tmp_b;
    float min_cost = 99999999999999999;
    for(int i = 0; i < 500000; i++) {
        cout << "iteration n." << i << endl;
        cout << "starting cost_function: " << cost_function << endl;
        // repeat until find the minimum
        tmp_w = w - learning_rate * derivative_w(w, b, training_houses);
        tmp_b = b - learning_rate * derivative_b(w, b, training_houses);;

        w = tmp_w;
        b = tmp_b;
        
        cout << "w: " << w << endl;
        cout << "b: " << b << endl;
        cost_function = squared_error_cost_function(w, b, training_houses);
        cout << "result cost_function: " << cost_function << endl;
        cout << "----------------" << endl;
        min_cost = min(min_cost, cost_function);
    }
    cout << "----------------" << endl;
    cout << "----------------" << endl;
    cout << "----------------" << endl;
    cout << "w: " << w << endl;
    cout << "b: " << b << endl;
    
    int size;
    cout << "Size of a house in feet: ";
    cin >> size;

    cout << "Predicted price: " << w*size+b << endl;
    cout << "With squared_error_cost function value: " << cost_function << endl;
    return 0;
}