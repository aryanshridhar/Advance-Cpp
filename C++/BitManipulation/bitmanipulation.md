### Important Bit manipulation fundamentals - 
<br/>

* <code>AND</code>ing all digits in any number with 1 yields the same number.

```
110101
111111
------
110101

```
* <code>AND</code>ing a number with 1 yields the LSB.
```
110101
000001
------
000001 <- LSB
```
* Few observations about XOR -
    * XOR is commutative.
    * Inverse of XOR is XOR
    * a XOR 0 = a
    * a XOR a = 0
    * Important questions with XOR - https://florian.github.io/xor-trick/#sequences-of-xor-operations.
    * XOR of all numbers from 0 to a - 
        * If a%4 == 0 -> a
        * If a%4 == 1 -> 1
        * If a%4 == 2 -> a + 1
        * If a%4 == 3 -> 0
    

* Left shift - Increases it.
```
a << b = a * pow(2,b);
```

* Right shift - Decreases the number.
```
a >> b = a/pow(2,b);
```

* Bit masking - 
```
1 << n; // n is number to bitsd to be shifted to generate the mask.
```

* Miscellaneous - 

    * 100000 = 111111 + 1 (Similar for all powers of 2 - Widely used technique to make the question easy).
    * Range of numbers can be formed with given n bits - 
    ```
    -pow(2,n-1) to pow(2,n-1)-1
    ```
    * Number of bits in a given decimal number - 
    ```
    int(log(n)) + 1 // Log with base b, where b is base and n is number.
    
    ```
