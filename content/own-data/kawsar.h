/**
 * Author: Md. Arik Rayhan
 * Date: 2023-11-01
 * License: CC0
 * Description: OR/AND/XOR are associative and commutative.
 * Time: O(n)
 * Status: Tested on codeforces
 */
#pragma once

//	A ^ 0 = A
//	A ^ A = 0
//	If A ^ B =C, then A ^ C =B
//	A ^ B ^ B = A
//	A & B <= min (A, B)
//	A | B >= max (A, B)
//  (A | B) + (A & B) = A + B
//  (A & 1) is 1 if A is odd, else 0
//	A & (A-1) is 0 if A is a power of 2 (except when A = 0)

