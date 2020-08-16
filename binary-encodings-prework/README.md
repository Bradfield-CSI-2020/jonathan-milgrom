# Binary Representation of Data

## Hexadecimal
### Simple conversion
#### What are the numbers 9, 136 and 247 in hexadecimal?

1. 9 is decimal is **9 in hex**

1. 136 in decimal is: 

    136 / 16 = 8
    136 % 16 = 8

    **88 in hex**

1. 247 in decimal is:

    247 / 16 = 15 => f
    247 % 16 = 7

    **f7 in hex**

#### In CSS, two ways to specify colors are hexadecimal and rgb. For instance, pure red would be 0xff0000 or rgb(255, 0, 0);. How many colors can be represented in each form?

hexidemicals at order of 2 can represent 16 ^ 2 different combinations, which is 255 + 1 (for zero), the same as rgba.

So each can reprensent 256^3 colors == **16,777,216**

#### 17 bytes is how many hexidecimal characters

Theres are 8 bits in every byte => 2 hex characters in every byte (2 (bits) ^4 == 16 ) => **2 * 17 characters => 34**

#### Convert the first 5 bytes in the file by hand to binary. Write these down as you’ll use them again in a later exercise

68|65|6c|6c|6f = 0110100001100101011011000110110001101111




## Integers
### Basic conversion

1. 4 in decimal is **100 in binary**

1. 65 in decimal is 

    2^6 (64) + 2^0 = 65

    **1000001**

1. 105 in decimal is 

    2^6 (64) + 2^5 (32) + 2^3 (8) + 2^0  (1)

    **1101001**

1. 255 in decimal is 

    2^8 - 1

    2^2 - 1 = 3 right, which is expressed as 11 (or 2 "1"s), so
    2^8 - 1 will be expressed as 8 "1"s

    **11111111**

1. 10 in binary is

    2 in decimal

1. 11 in binary is

    is 3 in decimal

1. 1101100

   2^6 (64) + 2^5 (32) + 2^2 (8) + 4

   108

1.  1010101

    2^6 (64) + 16 + 4 + 1

    85

###  Unsigned binary addition

1. 11111111 + 00001101 

    ```
    11111111
    +
    00001101 
    ____
    00001100
    carry out 1
    ```

### Two’s complement conversion

1. 01111111 + 10000000

    ```
    01111111
    +
    10000000
    ___
    11111111
    ```

    2^8 bits means 256 combinations. with 2's compliment, lowest order 2^7 are reserved for positive numbers plus zero (normal binary representation) the higher order 2^7 are reserved for negative.

    This means that highest order positve number is
    01111111 = 2^6 (64) + 32 + 16 + 8 + 4 + 2 + 1 = 127
    10000000 = the most negative number (addition afterall should make it less negative) = -128

    -128 + 127 should give us -1

    and indeed it does: 11111111 (the highest order bit arrangement is the least negative number)

    Notice that the highest absolute value for n bits comes from -2^(n-1); where as the highest absolute value for unsigned n bits is 2^n - 1.

## Byte ordering

### Its over 9001

"file 9001"

raw bits: 00100011 00101001
in hex: 23 29

big-endian means what it looks like above

16^3 (2) + 16^2 (3) + 16 (2) + 9 = 9001

Big endian!

### TCP

TCP Header: af00bc06441e7368eff2a00281ff5600 (32 chars)

(2 hex chars per byte => 16 bytes)

Looking at [the protocal](https://en.wikipedia.org/wiki/Transmission_Control_Protocol#TCP_segment_structure):

```
af00: source port (44800)
bc06: destination port (48134)
441e7368: sequence number (1142846312)
eff2a002: ack number (4025655298)
81ff: a bunch of stuff
5600: window size
```

## IEEE Floating Point





