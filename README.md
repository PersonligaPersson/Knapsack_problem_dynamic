# Knapsack_problem_dynamic
A solution to the knapsack problem using dynamic programming.

## Pseudo Code
n := Number of Items.
C := Knapsack Capcity.
arr[n][C] := Matrix of Items and Remaining Capacities.
w[n] := Weight of Item n.
result := Value in the Knapsack.

initialize arr[n][C] = null
def KS(n,C):
    if arr[n][C] != null -> return a[n][C]
    if n == 0 or C == 0
        result = 0
    else if w[n] > C:
        result = KS(n-1,C)
    else:
        take = KS(n-1, C-w[n])
        pass = KS(n-1, C)
        result = max( take, pass )
    arr[n][C] = result
    return result

## Time Complexity Analysis
There are at most n*C entries in the matrix. That means that the number of calls will be restricted to the n*C different entries. This means that the function has the time complexity of O(n*C).