#include <cctype>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#define MOD 10000

using namespace std;

inline int mod(int x) { 
    return (x % MOD + MOD) % MOD; 
}

class matrix {
   public:
      vector<int> polje;
      int n, m;

      matrix(int N, int M) {
         n = N; m = M;
         polje.resize(n * m);
         for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
               polje[i * m + j] = 0;
      }

      int& operator () (int r, int s) {
         return polje[r * m + s];
      }


      friend matrix operator * (matrix A, matrix B) {
         matrix C(A.n, B.m);
         for (int i = 0; i < C.n; i++)
            for (int j = 0; j < C.m; j++) {
               C(i,j) = 0;
               for (int k = 0; k < A.m; k++) {
                  C(i,j) += A(i,k) * B(k,j);
                  C(i,j) %= MOD;
               }
            }
         return C;
      }

      friend matrix operator ^ (matrix A, int k) {
         if (k == 1) return A;
         if (k % 2 == 1) return A * (A ^ (k - 1));
         matrix ret = A ^ (k / 2);
         return ret * ret;
      }
};

vector<string> code;
int line;

pair<matrix, int> solve(matrix stanje) {
   matrix trans(27, 27);
   for (int i = 0; i < 27; ++i) trans(i,i) = 1;
   int print = 0;

   istringstream iss(code[line++]);
   string s;

   while (iss >> s) {
      if (s == "STOP") break;
      else if (s == "REPEAT") {
         int koliko;
         iss >> koliko;

         int pamti = line;
         pair<matrix, int> t = solve(trans * stanje);
         print |= t.second;

         if (t.second == 1) {
            trans = t.first * trans;
            for (int i = 1; i < koliko; i++) {
               line = pamti;
               trans = solve(trans * stanje).first * trans;
            }
         } else {
            trans = (t.first ^ koliko) * trans;
         }
      } else if (s == "PRINT") {
         print = 1;
         string var;
         iss >> var;
         cout << var << " = " << mod((trans * stanje)(var[0] - 'a', 0)) << endl;
      } else {
         matrix izraz(27, 27);
         for (int i = 0; i < 27; i++) izraz(i,i) = 1;
         izraz(s[0]-'a',s[0]-'a') = 0;

         string op, var;
         while(iss >> op >> var) {
            int k = 1;
            int v = 26;
            if (isalpha( var[var.size()-1])) v = var[var.size()-1]-'a';
            if (var[0] == '-' || isdigit( var[0])) sscanf(var.c_str(), "%d", &k);
            if (op == "-" ) k *= -1;
            izraz( s[0]-'a', v ) += k;
         }
         trans = izraz * trans;
      }
   }
   return make_pair(trans, print);
}

int main(void) {
   matrix stanje(27, 1);
   stanje(26,0) = 1;

   while (true) {
      string s;
      getline(cin, s);
      code.push_back(s);
   }

   line = 1;
   solve(stanje);

   return 0;
}
