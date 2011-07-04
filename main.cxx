#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

void args(){
  cerr << "usage: isomorphic <word 1> <word 2>" << endl;
  cerr << "program assumes words are ascii" << endl;
}

bool is_oneway_isomorphic(const char * const _w1, const char * const _w2);
bool is_isomorphic(const char * const a, const char * const b);

int main(int argc, char **argv){

  if( argc != 3 ){
    args();
    return EXIT_FAILURE;
  }

  if( is_isomorphic(argv[1], argv[2]) ){
    cout << "Yes, " << argv[1] << " and " << argv[2] << " are isomorphic." << endl;
  }else{
    cout << "No, " << argv[1] << " and " << argv[2] << " are not isomorphic." << endl;
  }

  return EXIT_SUCCESS;
}

bool is_isomorphic(const char * const _w1, const char * const _w2){
  const char * w1 = _w1;
  const char * w2 = _w2;

  if( strlen(w1) != strlen(w2) ){
    return false;
  }

  return is_oneway_isomorphic(w1, w2) && is_oneway_isomorphic(w2, w1);
}

bool is_oneway_isomorphic(const char * const _w1, const char * const _w2){
  const char * w1 = _w1;
  const char * w2 = _w2;

  // assume all ascii characters; otherwise we could use a normal STL map
  char arr[256] = {0};

  while( *w1 ){ // while not end of string '\0'
    char *const c = &arr[ *w1 ];
    if( *c && *c != *w2 ){ // if we already stored a value for c and it's not the same as b
      return false;
    }
    *c = *w2;
    ++w1;
    ++w2;
  }
  
  return true;
}
