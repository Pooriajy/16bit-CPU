#include <iostream>
#include <cstring>
#include <math.h>
#include <map>
#include <bits/stdc++.h>
#include <bitset>
using namespace std;


char rega[16] = {'1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','1'};
char regb[16] = {'0','0','1','0','1','0','0','1','0','0','0','0','0','0','0','0'};
char regc[16] = {'0','0','1','0','0','0','0','1','1','1','0','0','0','0','0','0'};
char regd[16] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
char rege[16] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
char regf[16] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
char regg[16] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
char regh[16] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};

map<string,char*> Registers={
  {"000",rega},
  {"001",regb},
  {"010",regc},
  {"011",regd},
  {"100",rege},
  {"101",regf},
  {"110",regg},
  {"111",regh},
};


string toBinary(int n) // convert decimal to binary
{
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    return r;
}
int convert(long long n) { // binary to decimal
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}
int stringTointeger(string str)
{
    int temp = 0;
    for (int i = 0; i < str.length(); i++) {
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}
string CharToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}
bool fulladder(bool a, bool b, bool carry=false){
    bool ret = a^b^carry;
    carry = carry && (a^b) || a && b;
    return ret;
}

void add(char inst[16]){
  auto imcheck = string(1,inst[9]) + string(1,inst[10]) + string(1,inst[11]) + string(1,inst[12]); //bits of 0 if its RRR add
  if(imcheck == "0000"){ // add registers
    string RegA = string(1,inst[3]) + string(1,inst[4]) + string(1,inst[5]);
    string RegB = string(1,inst[6]) + string(1,inst[7]) + string(1,inst[8]);
    string RegC = string(1,inst[13]) + string(1,inst[14]) + string(1,inst[15]);
    bitset<16> f(CharToString(Registers[RegB], 16));
    bitset<16> s(CharToString(Registers[RegC], 16));
    cout << f << endl << s << endl;
    bitset<16> ans;
    for(int i=0;i<16;i++){ans[i] = fulladder(f[i],s[i]);}
    string bits = ans.to_string<char, string::traits_type, string::allocator_type>();
    for(int i=0;i<16;i++){Registers[RegA][i]=bits[i];}

  }
}

void addi(char inst[16]){
  string RegA = string(1,inst[3]) + string(1,inst[4]) + string(1,inst[5]);
  string RegB = string(1,inst[6]) + string(1,inst[7]) + string(1,inst[8]);
  string imm = string(1,inst[9]) +string(1,inst[10]) +string(1,inst[11]) +string(1,inst[12]) +string(1,inst[13]) +string(1,inst[14]) +string(1,inst[15]);

  bitset<16> f(CharToString(Registers[RegA],16));
  bitset<16> s(CharToString(Registers[RegB],16));
  bitset<16> I(imm);
  bitset<16> ans;
  for(int i=0;i<16;i++){ans[i]=fulladder(s[i],I[i]);}
  string bits = ans.to_string<char, string::traits_type, string::allocator_type>();
  for(int i=0;i<16;i++){Registers[RegA][i]=bits[i];}
}

void nand(char inst[16]){
  string RegA = string(1,inst[3]) + string(1,inst[4]) + string(1,inst[5]);
  string RegB = string(1,inst[6]) + string(1,inst[7]) + string(1,inst[8]);
  string RegC = string(1,inst[13]) + string(1,inst[14]) + string(1,inst[15]);

  bitset<16>f(CharToString(Registers[RegB],16));
  bitset<16>s(CharToString(Registers[RegC],16));
  bitset<16> ans = (~(f & s));
  string bits = ans.to_string<char, string::traits_type, string::allocator_type>();
  for(int i=0;i<16;i++){Registers[RegA][i]=bits[i];}
}

void lui(char inst[16]){
  cout << "test1";
  string Reg = string(1,inst[3]) + string(1,inst[4]) + string(1,inst[5]);
  string imm = string(1,inst[6]) + string(1,inst[7]) + string(1,inst[8]) + string(1,inst[9]) + string(1,inst[10]) + string(1,inst[11]) + string(1,inst[12])+string(1,inst[13])+string(1,inst[14])+string(1,inst[15]);
  bitset<16> f;
  for(int i=15;i>9;i--){f[i] = imm[i];}
  cout << "test2";
  string bits = f.to_string<char, string::traits_type, string::allocator_type>();
  cout << "test3";
  for(int i=0;i<16;i++){Registers[Reg][i]=bits[i];}
  cout << "test4";

}


void Decoder(char inst[16]){
  string opcode = std::string(1,inst[0]) + string(1,inst[1]) + string(1,inst[2]);
  if(opcode == "000"){add(inst);}
  else if(opcode == "001"){addi(inst);}
  else if(opcode=="010"){nand(inst);}
  else if(opcode == "011"){lui(inst);}
}









int main(){
  cout << "started cpu" << endl;
  while(true){
    char instruction[16];
    string ins;
    cin >> ins;
    if(ins == "preg"){
      auto iter = Registers.begin();
      while(iter != Registers.end()){
        cout <<"[" << iter->first << "] ";
        for(int i=0;i<16;i++){
          cout << iter->second[i];
        }
        cout << endl;
        iter++;
      }
    }
    else{
      for(int i=0;i<16;i++){instruction[i]=ins[i];}
    // strcpy(instruction, inst);
    Decoder(instruction);
    cout << endl;
  }

  }
  return 0;
}
