import numpy as np

X = np.linspace(1.0, 10.0, 100)[:, np.newaxis]
y = np.sin(X) + 0.1 * np.power(X, 2) + 0.5 * np.random.randn(100, 1)
X /= np.max(X)

X = np.hstack((np.ones_like(X), X))

order = np.random.permutation(len(X))
split = 20

test_x = X[order[:split]]
test_y = y[order[:split]]

train_x = X[order[split:]]
train_y = y[order[split:]]

def get_gradient(w, x, y):
    y_ = x.dot(w).flatten()
    error = (y.flatten() - y_)
    gradient = -(1.0/len(x)) * error.dot(x)
    return gradient, np.pow(error, 2)

W = np.random.randn(2)
alpha = 0.5
tolerence = 1e-5

iterations = 1
while True:
    gradient, error = get_gradient(W, train_x, train_y)
    W_ = W - alpha * gradient

    if np.sum(abs(W_ - W)) < tolerence:
        print("Converged!")
        break

    if iterations % 100 == 0:
        print(f"Iteration: {iterations} \t| Error {error}")
    
    iterations += 1
    W = W_