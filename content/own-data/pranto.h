/**
 * Author: Md. Arik Rayhan
 * Date: 2023-11-01
 * License: CC0
 * Description: OR/AND/XOR are associative and commutative.
 * Time: O(n)
 * Status: Tested on codeforces
 */

//	A ^ 0 = A
//	A ^ A = 0
//	If A ^ B =C, then A ^ C =B
//	A ^ B ^ B = A
//	A & B <= min (A, B)
//	A | B >= max (A, B)
//  (A | B) + (A & B) = A + B
//  (A & 1) is 1 if A is odd, else 0
//	A & (A-1) is 0 if A is a power of 2 (except when A = 0)

Left shift (a<<b = a*2^b)
Right shift (a>>b = a/2^b)
Bitwise AND (a&b)
Bitwise OR (a|b)
Bitwise XOR (a^b)
Bitwise NOT (~a = -a-1)
For all odd numbers the last bit is 1, and for even its 0 
Odd/Even (n&1)? cout << "Odd" : cout << "Even";

Some properties of bitwise operations:
1. a|b=a^b+a&b 
2. a^(a&b)=(a|b)^b 
3. b^(a&b)=(a|b)^a 
4. (a&b)^(a|b)=a^b

Addition:
1. a+b=a|b+a&b
2. a+b=a^b+2(a&b)

Subtraction:
1. a-b=(a^(a&b))-((a|b)^a) 
2. a-b=((a|b)^b)-((a|b)^a) 
3. a-b=(a^(a&b))-(b^(a&b)) 
4. a-b=((a|b)^b)-(b^(a&b))

// some bit operations

(n>>k)&1 -> kth bit on or off // needs modification
n|(a<<k) -> kth bit on
n&((1<<30)-1-(1<<k)) -> kth bit off
n&((1<<k)-1) -> last k bits on
__builtin_popcount(x) // number of set bits
__builtin_clz(x) // number of leading zeros
__builtin_ctz(x) // number of trailing zeros

int get_ith_bit(int n, int i)
{
     int mask = (1<<i);
     return (n&mask)>0?1:0;
}

int clear_ith_bit(int n, int i)
{
     int mask = ~(1<<i);
     n = (n&mask);
     return n;
}

int set_ith_bit(int n, int i)
{
     int mask = (1<<i);
     n=(n|mask);
     return n;
}

int update_ith_bit(int n, int i, int v)
{
     clearIthBit(n,i);
     int mask = (v<<i);
     n=(n|mask);
     return n;
}

int clear_last_i_bit(int n, int i)
{
     int mask = (-1<<i);
     n = (n&mask);
     return n;
}

int clear_bits_in_range(int n, int i, int j)
{
     int a = (-1<<j+1);
     int b = (i<<i-1);
     int mask = (a|b);
     n = (n&mask);
     return n;
}

int replace_bits_in_range(int n, int v, int i, int j)
{
     n = clear_bits_in_range(n,i,j);
     int mask = (v<<i);
     cout << (n|mask);
}

int count_set_bits(int n)
{
     int cont=0;
     while(n>0)
     {
         int last_bit = (n&1);
         cont+=last_bit;
         n = n>>1;
}
     return cont;
}

