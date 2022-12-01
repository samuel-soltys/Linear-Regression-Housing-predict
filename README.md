# Linear Regression Housing prediction
My implementation of linear regression from scratch with C++. It's done using an algorithm called Batch Gradient Descent and 500 000 iterations of it. The learning rate is set to 0.00004. This program predicts the price of a house based on its size (in m²). The training dataset is manually imported from current sell offers in the location Rusovce - Bratislava, Slovakia.

# The prediction:
After 500 000 iterations of Batch Gradient Descent the cost function will start to converge to the global minimum. This is the linear function that predicts the price of houses from the training dataset:
```
y = 662.872x + 502517
```
