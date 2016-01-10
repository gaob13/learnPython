N = int(raw_input())
K = int(raw_input())
M = int(raw_input())

def f(n):
    if n == 1:
        return [0, (K-1) % M, (K-1) % M]
    if n == 2:
        return [(K-1) % M, (K-1)*(K-1) % M, K*(K-1) % M]
    half = (n - 1) / 2
    f_half = f(half)
    f_halF = [f_half[1], (K-1)*f_half[2], f_half[1]+(K-1)*f_half[2]]
    if n % 2 == 1:
        return [(f_half[2] * f_halF[0] + f_half[1] * f_half[0]) % M, (f_half[2] * f_halF[1] + f_half[1] * f_half[1]) % M, \
                (f_half[2] * f_halF[2] + f_half[1] * f_half[2]) % M]
    else:
        return [(f_halF[2] * f_halF[0] + f_halF[1] * f_half[0]) % M, (f_halF[2] * f_halF[1] + f_halF[1] * f_half[1]) % M, \
                (f_halF[2] * f_halF[2] + f_halF[1] * f_half[2]) % M ]

print f(N)[2]
