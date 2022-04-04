#include <iostream>
#include <string>

#define FOR(var,begin,end) for(int var = begin;var < end;var++ )

typedef std::string str;

str vigener(const str& text, const str& key,bool op){
  str data;
  FOR(i,0,text.size()){
    int k = key[i % key.size()] - 'A';
    int t = text[i];
    t != ' ' ? data += (char)(((op ? (t + k) : (t - k)) % 26) + 'A') : data += ' ';
  }
  return data;
}

str toUpper(const str& s){
  str data;
  for(char c : s) data += toupper(c);
  return data;
}

int main(int argc, char** argv){https://meet.google.com/thr-gecj-oqy
  if(argc >= 3){
    bool op = argv[1][1] == 'e';
    str key = toUpper(argv[2]),text;
    FOR(i,3,argc) text += toUpper(argv[i]) + " ";
    std::cout << (op ? "Encoded" : "Decoded") << " text -> " << vigener(text,key,op) << std::endl;
  }else{
    std::cout << "Usage: " << argv[0] << " op key text... " << std::endl <<
                 "\t  op    -> -e for encoding OR -d for decoding " << std::endl <<
                 "\t key    -> text used as key (any length)" << std::endl <<
                 "\ttext... -> text that encoded/decoded " << std::endl;
  }
  return 0;
}


