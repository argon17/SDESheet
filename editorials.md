# Bit Manipulation
* it should be 1L << c as the calculation is happening in long
* The ASCII value of 0,1.. is 48,49 and so on. So whenever I am typecasting the number it's storing 48 instead of zero. So I have taken modulo of each no with 48 eventually providing me the original number.


## Finding Gray code

Notice that i-th bit of G(n) equals 1 only when i-th bit of n equals 1 and i+1-th bit equals 0 or the other way around (i-th bit equals 0 and i+1-th bit equals 1). Thus, G(n)=n⊕(n>>1):


Odd | Even
----|----
n&1 | (n&1)^1

# Constraints

* 10^5 : a O(n) or O (n^2) solution.
* 10^6 : O(nlogn) solution, in most cases.
* 100 :  O (n^3 ) Solution
* 20 : bitmask, O (2^n) solution.
<br><br>
<img src="https://codeforces.com/predownloaded/83/0d/830da2701ec5d3baacbea1af54eb16a4021abf6b.jpg">

###  Why memoization not passing all test cases, the time complexity is the same still why such behavior?
> due to use of stack in recursion