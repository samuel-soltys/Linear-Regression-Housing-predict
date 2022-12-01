# Linear Regression Housing prediction
My implementation of linear regression from scratch with Python. It's done using an algorithm called Batch Gradient Descent and 50 iterations of it. The learning rate is set to 0.00003. This program predicts the price of a house based on its size (in m²). The training dataset is manually imported from current sell offers in the location Rusovce - Bratislava, Slovakia. The prediction is not accurate beacause of small dataset and not accurate data.

# The prediction:
After 50 iterations of Batch Gradient Descent, teh cost function will start to converge to the global minimum of it. This is the prediction in linear function form that predicts the price of houses from the training dataset:
```
y = 2574 * x + 202
```
