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

// a ^ a = 0
// a ^ 0 = a
// a ^ b = 0 ==> a = b
// a ^ b = b ^ a
// (a ^ b) ^ c = a ^ (b ^ c)
// a ^ b ^ a = (a ^a) ^ b = 0 ^ b = b
// a ^ a ^..... ^ a = 0 (even number of a's)
// a ^ a ^..... ^ a = a (odd number of a's)
// a ^ b = c ==> a = b ^ c ==> a ^ b ^ c = 0

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


(max of max) or (min of min) is BINARY SEARCH you dumb STUPID fuck

find the position of something on a string 
a = find(s.begin(), s.end() , '3') - s.begin() ;// we are finding the position of 3 in this case

//Vector
vector<int> v(n); // we take a array of vector with fixed length
cin>>v[i];
v.sort(v.begin(), v.end());
v.begin() is inclusive (eta soho sort hobe)
And v.end() is exclusive (eta sara sort hobe)
always point the position after the last position of the vector -> 1,2,3,4[v.end()] 
cout<< (int)v.size() << nl; //v.size() e typecasting must

max element of a vector
*max_element(v.begin(), v.end())
removing a element (x) from vector 
v.erase(find(v.bigin() , v.end () , x))

//map<pair<int,int>,string > m ;
cin can be done like this -> m[{x,y}]=s;
        int x , y ; cin>> x >> y ;
        pair<int , int> xx ;
        xx= make_pair(x,y);
        auto it= m.find(xx);
        if(it!=m.end())
        {
            cout<< (*it).second << nl;
        }

In map 
cost += m[x]; // it will work but its not a good practice
because if x dosent exists then there will be a extra value named x inserted into the map
size will increase.
if( m.find(x) != m.end() ) // Good practice
{ cost += m[x]; }

//Stringstream
string s;
  getline(cin, s);
  stringstream ss;
  ss << s;
  string word;
  while (ss >> word) {
    cout << word << '\n';}
 
//find anything on a string
(find(s.begin() , s.end() , ' ') != s.end())
        {
            
        }

//check if all the char of the string is same
if (unique(s.begin(), s.end()) == s.begin() + 1 )
    {
        cout << " all are same bro "<< nl;
    }

//input string after int
problem first string dosent input in 
cin.ignore();
getline(cin,s);

//string to int
int x = stoi(s); //string to int
ll x = stoll(s) ; //string to long long

//substring 
s= "pranto" ; //indexing starts with 0 as usual 
ans = s.substr(1,3); starts taking substring from 1 and takes 3 char from there
ans = "ran"
s.substr(1); starts taking substring from and 1 to the end 
ans = "ranto"


// Print the number of times the character 'e' appears in the string.
  cout << std::count(str.begin(), str.end(), ch) << endl;



/*Rearranges the elements in the range [first,last) in
  to the next lexicographically greater permutation.  */
void print(int a[], int n);
int main()
{
  int myints[] = {1, 4, 3}, n = 3;

  sort(myints, myints + n);
  /*sort to see all the combinations of lower to higher
  dont sort if you want to see only the next higher permutation*/

  cout << "The n! possible permutations with 3 elements:\n";
  /*first it will print the original array then
    it will print the next higher permutation  */
  do
  {
    print(myints, n);
  } while (next_permutation(myints, myints + n));

  cout << "After loop: ";
  print(myints, n); // sorted array asending order

  return 0;
}

/*Rearranges the elements in the range [first,last) in
  to the next lexicographically lower permutation.  */
int main()
{
  int myints[] = {1, 4, 3}, n = 3;

  sort(myints, myints + n, greater<int>());
  /*sort to see all the combinations of higher to lower
  dont sort if you want to see only the next lower permutation*/

  cout << "The n! possible permutations with 3 elements:\n";
  /*first it will print the original array then
    it will print the next lower permutation  */
  do
  {
    print(myints, n);
  } while (prev_permutation(myints, myints + n));

  cout << "After loop: ";

  return 0;
}


Legendres formula
n! is multiplication of {1, 2, 3, 4,....n}.
How many numbers in {1, 2, 3, 4, .....n} are divisible by p? 
Every pth number is divisible by p in {1, 2, 3, 4, ...... n}. Therefore in n!, there are [n/p] numbers divisible by p. So we know that the value of x (largest power of p that divides n!) is at-least [n/p]. 
Can x be larger than [n/p] ? 
Yes, there may be numbers which are divisible by p2, p3, .....
How many numbers in {1, 2, 3, 4, ...... n} are divisible by p^2, p^3,...? 
There are [n/(p2)] numbers divisible by p2 (Every p2th number would be divisible). Similarly, there are [n/(p3)] numbers divisible by p3 and so on.
What is the largest possible value of x? 
So the largest possible power is [n/p] + [n/(p^2)] + [n/(p^3)] +.....
int Legendres formula(long long n, long long p) {
  int ans = 0;
  while (n) {
    ans += n / p; // now many times we can devide this by n , n^2 , n^3 how many times we can devide this like it
    n /= p;
  }
  return ans;
}
#num of digits
num_of_digit = floor(log10(n))+ 1 ; // 10 base
Big gcd
gcd(a,b) == gcd(a%b , b ) ; 
log(a*b) = log(a) + log(b)

I need in c++  logb(x)
but c++ only have log2 and log 10
 logb(x) = log2(x) / log2(b) ;

n^m prime factor
prime factor of n = 2^3 * 3^5 * 5^9
prime factor of n^m = 2^(3*m) * 3^(5*m) * 5^(9*m)

In some range some numbers are both divisible by x and y
Only divisible by x and y is (n/x) - n/(lcm(x,y))

partial_sum(a, a + 5, b, myfun); prefix sum can be calculated by this

how to clean the nodes used in graph
for (int i = 1 ; i <= n ; i++) {
  visited[i] = false;
  g[i].clear() ;
}
g[i].clear() empty all the data from the node