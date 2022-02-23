#include <iostream>
#include <string>

typedef std::string str;

str caesar(const str& text,int step){
  str data;
  for(char c : text){
    if(c != ' '){
      char d = c <= 'Z' ? 'A' : 'a';
      int ci = std::abs(c - d) + step % 26;
      if(ci < 0 ) ci += 25;
      if(ci > 25) ci -= 25;
      data += (char)(d + ci);
    }else
      data += " ";
  }
  return data;
}

int main(int argc, char** argv){
  if(argc >= 2){
    int step = std::stoi(argv[1]);
    str text;
    for(int a = 2; a < argc;a++)
      text += " " + str(argv[a]);
    std::cout << " -> " << caesar(text,step) << "\n";
  }else{
    std::cout << "Usage : " << argv[0] << " step text " << std::endl;
  }
	return 0;
}
