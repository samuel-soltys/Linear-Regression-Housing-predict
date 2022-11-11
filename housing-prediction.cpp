#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
typedef long long ll;

float linear_function(int x, float w, float b) { return(w * x + b); }

float squared_error_cost_function(float w, float b, vector<pair<int,int> > training_houses) {
    // Starting value of cost function
    float J = 0;
    
    // Summing up all the differences between predicted y values (using linear_function(w,b))
    // and the y values of training samples
    // Formula:
    // sum( (ŷ(i) - y(i))^2 )  or  sum( ( f[w,b](x(i)) - y(i) )^2 )  
    for(int i = 0; i < training_houses.size(); i++) {
        J += pow(linear_function(training_houses[i].first, w, b) - training_houses[i].second, 2);
    }
    
    // The sum divided by 2 times the size of training dataset
    return(J / (2 * training_houses.size()));
}

float derivative_w(float w, float b, vector<pair<int,int> > training_houses) {
    // Calculating the derivative of w using cost function formula
    // Formula:
    // sum( ( f[w,b](x(i)) - y(i) )  * x(i) ) / m

    float J = 0;
    
    for(int i = 0; i < training_houses.size(); i++) {
        J += (linear_function(training_houses[i].first, w, b) - training_houses[i].second) * training_houses[i].first;
    }
    
    return(J / training_houses.size());
}

float derivative_b(float w, float b, vector<pair<int,int> > training_houses) {
    // Calculating the derivative of b using cost function formula
    // Formula:
    // sum( ( f[w,b](x(i)) - y(i) ) ) / m
    
    float J = 0;
    
    for(int i = 0; i < training_houses.size(); i++) {
        J += linear_function(training_houses[i].first, w, b) - training_houses[i].second;
    }
    
    return(J / training_houses.size());
}

int main() {
    // Training dataset
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
    
    // Starting values of w and b
    float w = 0, b = 0;
    
    // Batch Gradient Descent
    float learning_rate = 0.00004;
    float tmp_w, tmp_b;
    float min_cost = squared_error_cost_function(w, b, training_houses);
    
    // 500 000 iterations of Batch Gradient Descent - updating w and b using learning rate times their derivatives
    for(int i = 0; i < 500000; i++) {
        tmp_w = w - learning_rate * derivative_w(w, b, training_houses);
        tmp_b = b - learning_rate * derivative_b(w, b, training_houses);;

        w = tmp_w;
        b = tmp_b;
    }
    
    float result_cost_function = squared_error_cost_function(w, b, training_houses);

    cout << "Result:" << endl;
    cout << "w: " << w << endl;
    cout << "b: " << b << endl;
    cout << "Linear function: " << w << "x + " << b << endl;
    cout << "Squared Error Cost Function value: " << result_cost_function << endl;
    cout << "----------------" << "\n\n";
    
    // Prediction - input and output
    int size;
    cout << "Enter size of a house in meters squared: ";
    cin >> size;
    cout << "Predicted price: " << w * size + b << endl;
    
    return 0;
}