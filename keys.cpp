#include "keys.hpp"
#include <iostream>
#include <iterator>
#include <stdio.h>


struct core_key_hash {
  int first_prime_core;
  int second_prime_core;
  long long phi;
  long long private_sel[2];
  long long public_sel[2];
};



static int gcd (int a, int b){
    while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

core_key key_gen() {
  core_key sel_key = (core_key)malloc(sizeof(core_key_hash));
  if (!sel_key) {
    return nullptr;
  }
  return sel_key;
}
static int mod_inverse(int e, int phi) {

  for (int d = 1; d < phi; d++) {
    if ((d * e) % phi == 1) {
      return d;
    }
  }
  return -1;
}

void set_option_keygen(core_key sel_key, int fgen, int sgen) {

  if (sel_key) {
    sel_key->first_prime_core = fgen;
    sel_key->second_prime_core = sgen;
    sel_key->phi = (fgen - 1) * (sgen - 1);
  }
}

void generate_key(core_key sel_key, int pub[2], int priv[2]) {
  // get public key
  int decripted_key = sel_key->first_prime_core / 2;
  while (decripted_key < sel_key->phi) {
    if (gcd(decripted_key, sel_key->phi) == 1) {
      break;
    }
    decripted_key++;
  }
  // debug blok
  if (decripted_key == sel_key->phi) {
    std::cerr << "\033[31m  [error ] decripted_key is invalid " << std::endl;
  }
  // end debug blok&
  long long n = sel_key->second_prime_core * sel_key->first_prime_core;
  int inver = mod_inverse(decripted_key, sel_key->phi);
  sel_key->public_sel[0] = decripted_key;
  sel_key->public_sel[1] = sel_key->private_sel[1] = n;
  sel_key->private_sel[0] = inver;
  if (inver == -1) {
    std::cerr << " \033[31m [Error ] mod inverse not found!\033[0m"<< std::endl;
  }

  pub[0] = sel_key->public_sel[0];
  pub[1] = sel_key->public_sel[1];
  priv[0] = sel_key->private_sel[0];
  priv[1] = sel_key->private_sel[1];
}


  
  


void free_key(core_key sel_key) {
    if (sel_key) {
        delete sel_key;
    }
}

long long modularexpo(long long base, long long expo, long long mod){
  long long result = 1;
  base = base % mod;
  while(expo > 0){
    if (expo % 2 == 1){
      result = (result * base) % mod;
    }
    expo = expo >>1;
    base = (base * base) % mod;
  }
  return result;
}


// Language:C++ 
// ProjectType:0 
// Salin kode lengkap dan buka APLIKASI CppCoder untuk menjalankannya. 
// CppCoder APP download link：https://play.google.com/store/apps/details?id=com.ikou.cppcoding 