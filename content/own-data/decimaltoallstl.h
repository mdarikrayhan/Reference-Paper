/**
 * Author: Md. Arik Rayhan
 * Date: 2023-11-01
 * License:
 * Description:
 * Time:
 * Status:
 */

long long n = stoll(str, nullptr, base);
ans = to_string(n);
string binary = bitset<64>(n).to_string();
stringstream ss;
ss << std::oct << n;
string octal = ss.str();
ans = octal;
stringstream ss;
ss << std::hex << n;
string hexa = ss.str();
transform(hexa.begin(), hexa.end(), hexa.begin(), ::toupper);
ans = hexa;