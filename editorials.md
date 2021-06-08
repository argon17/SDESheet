# Bit Manipulation
* it should be 1L << c as the calculation is happening in long
* The ASCII value of 0,1.. is 48,49 and so on. So whenever I am typecasting the number it's storing 48 instead of zero. So I have taken modulo of each no with 48 eventually providing me the original number.