# Matrix Calculator

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

C++ Matrix Calculator With Accuracy 100% In Calculations.
It supports the following operations:
- Addition
- Substraction
- Multiplication
- Scalar Multiplication
- Transposing
- Finding The Determinant
- Finding The Inverse.
- Divide By Another Matrix
- Power


>User can input matrices of any size up to 100 x 100.
>All values are of float data types.
>Any error in user input, the program should output the word “ERROR”
in uppercase letters and exits.
# Installation
    
  - Download the repository with the command ```git clone https://github.com/Hanaffi/Matrix-Calculator.git ```
  - Run these files using any compiler (For example GCC)

You can also:
  - Copy the source code
  - Paste it in online IDE such as [Ideone](https://ideone.com)
  - Make sure to choose the programming language C++14
  - Enter the matrix you would like to perform operations on




### Usage
The program use a defined string format to represent the matrix in the user input and output
sections.
For example , the string representation of the Matrix is :
[10 2.13 3;-5 0 4;16.5 1 8]
In the program, the user enters a matrix in the defined string format then
asked to enter an operator from the list mentioned eariler


#####  Input / Output Samples
[1 -2.5 3;4 5.25 6;7 8 9.12] <br/>
\+ <br/>
[3 4.2 10.2;12 -1 0;67 2 13] <br/>
[4 1.7 13.2;16 4.25 6;74 10 22.12] <br/>
___
[1 -2.5;4 5.2] <br/>
^ <br/>
2 <br/> 
[-9 -15.5;24.8 17.04] <br/>
___
[1 -2.5;4 5.2] <br/>
T <br/>
[1 4;-2.5 5.2] <br/>
___
[1 -2.5;4 5.2] <br/>
D <br/>
15.2 <br/>
___
[1 -2.5;4 5.2] <br/> 
I <br/>
[0.3421 0.1645;-0.2632 0.0658] <br/>
___
[1 -2.5 10;4 5.2]  <br/>
ERROR <br/>
>(In consistant number of columns) <br/>
___
[1 -2.5 10;4 5.2 12] <br/>
D <br/>
ERROR <br/>
>(error in the operator requirement, non-square matrix is invalid for
Determinant operator) <br/>
___
[1 -2.5 3;4 5.25 6;7 8 9.12] <br/>
\* <br/>
[3 4.2 10.2;12 -1 0] <br/>
ERROR <br/>
>(error in the operator requirement, number of columns of the first matrix is
not the same as number of rows of the second matrix, this is invalid for Multiply
operator) <br/>
___


### Contact

aehanaffi@gmail.com




### Todos

 - Add GUI

License
----


The MIT License (MIT)

Copyright (c) 2020 Ahmed Essam

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

**Free Software, Hell Yeah!**
