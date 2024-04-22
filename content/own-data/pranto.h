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

void print(int a[], int n)
{
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}

/*Rearranges the elements in the range [first,last) in
  to the next lexicographically lower permutation.  */
void print(int a[], int n);
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
  print(myints, n); // sorted array descending order

  return 0;
}

void print(int a[], int n)
{
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}