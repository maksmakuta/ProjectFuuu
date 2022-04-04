#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

typedef std::string str;

struct Char {
  char c;
  float freq;
  str code;
};

typedef std::vector<Char> alphabet;

class SFCoder{
public:

    str encode(const str& text){
      load(text);
      gen(premake());

      for(int a = 0;a < ap.size();a++)
        printf("\'%c\' <-> %.3f -> %s\n", ap[a].c,ap[a].freq,ap[a].code.c_str());
      
      str dat;
      for(char c : text){
        dat += get(c).code;
      }
      ap.clear();
      return dat;
    }

private:
    alphabet ap;
    float mD;

    std::vector<char> premake(){
      std::vector<char> d;
      for(int a = 0;a < ap.size();a++)
        d.push_back(ap[a].c);
      return d;
    }

    void gen(const std::vector<char> list){
      if(list.size() > 1){
        std::vector<char> left,right;
        int stop = 1;
        while(stop <= list.size()){
          float total = 0.f,res = 0.f ;
          for (int i = 0 ; i < list.size(); i++)
            (i < stop ? total : res) += get(list[i]).freq;
          
          if(std::abs(total - res) < mD){
            for (int i = 0;i < list.size();i++){
            int p = at(list[i]);
              if(p != -1){
                if(i < stop){
                  ap[p].code.append("0");
                  left.push_back(list[p]);
                }else{
                  ap[p].code.append("1");
                  right.push_back(list[p]);
                }
              }
            }
          break;
        }
      stop++;
      }
      gen (left);
      gen(right);
      }
    }

    int at(char c){
      for(int a = 0;a < ap.size();a++)
        if(ap[a].c == c) return a;
      return -1; 
    }

    Char get(char c){
      if(at(c) != -1) return ap[at(c)];
      else return Char{0,0,""};
    }
    

    void load(const str& text){
      for(char c : text){
        bool exist = false;
        for(int a = 0;a < ap.size();a++){
          if(ap[a].c == c){
            exist = true;
            ap[a].freq++;
          }
        }
        if(!exist)
          ap.push_back({c,1.f,""});
      }

      for(int a = 0;a < ap.size();a++)
        ap[a].freq /= text.size();

      std::sort(ap.begin(), ap.end(), [](Char a, Char b) { return a.freq > b.freq; });
      this->mD = text.size() / ap.size();
    }

};

int main(int argc,char** argv){
    if(argc > 1){
        str text;
        for(int a = 1;a < argc;a++) text += str(argv[a]);
        text = SFCoder().encode(text);
        std::cout << "Encoded : " << text << std::endl;
    } else {
        std::cout << "Usage: " << argv[0] << " text..." << std::endl;
    }
    return 0;
}
