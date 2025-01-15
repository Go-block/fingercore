#ifndef KEYS_HPP
#define KEYS_HPP



typedef struct core_key_hash * core_key;


core_key key_gen();

void set_option_keygen( core_key key,int fdata,int sdata);

void generate_key(core_key key, int pubkey[2], int prikey [2]);

void free_key(core_key key);
long long modularexpo(long long base, long long exp, long long mod);


#endif




// Language:C++ 
// ProjectType:0 
// Salin kode lengkap dan buka APLIKASI CppCoder untuk menjalankannya. 
// CppCoder APP download link：https://play.google.com/store/apps/details?id=com.ikou.cppcoding 