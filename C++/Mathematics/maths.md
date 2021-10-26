Basic Maths-

- Sieve of Eratosthenes - Used to effectively find out the prime numbers till a number specified - https://www.geeksforgeeks.org/sieve-of-eratosthenes. </br>
  TC: O(nlog(log(n))) (Harmonic progression using taylor series).

- Newton Raphson Method - Used to calculate the sqaure root of number using formula - https://www.geeksforgeeks.org/find-root-of-a-number-using-newtons-method/.

```
root = 0.5 * (X + (N / X)) where X is any guess which can be assumed to be N or 1.
```

- N= p<sup>a</sup>q<sup>b</sup>r<sup>c</sup>, where ap,q,r are prime factors of N. Then:

  - Number of factors = (a+1)(b+1)(c+1).
  - Product of factors = N<sup>No of factors/2</sup>
  - Sum of factors: (p<sup>0</sup>+p<sup>1</sup>+...+p<sup>a</sup>) (q<sup>0</sup>+ q<sup>1</sup>+....+q<sup>b</sup>) (r<sup>0</sup>+r<sup>1</sup>+...+r<sup>c</sup>)/ (p<sup>a</sup>-1)(q<sup>b</sup>-1)(r<sup>c</sup>-1)

- Euclidean Algorithm for HCF:

```
hcf(a,b) = hcf(b,a%b);
hcf(a,b) = a if b == 0;
```

Example:

```
hcf(20,28) = hcf(28,20) = hcf(20,8) = hcf(8,4) = hcf(4,0) = 4
```

- Miscellaneous -
  - LCM(a,b) * HCF(a,b) = a*b
