# Programa para multiplicar dos matrices 3x3 usando lista comprehension

# 3x3 matriz A
import numpy as np

X = np.loadtxt("m1.txt", dtype='i', delimiter=' ')


# 3x3 matriz B
Y = np.loadtxt("m2.txt", dtype='i', delimiter=' ')

# resultado es 3x3 Matriz C
result = [[sum(a*b for a,b in zip(X_row,Y_col)) for Y_col in zip(*Y)] for X_row in X]

for r in result:
   print(r)
