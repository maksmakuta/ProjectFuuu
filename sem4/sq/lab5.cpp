#include <cstdio>
#include <string>
#include <utility>
#include <vector>

class line;

typedef std::string str;
typedef std::vector<line> vec;

class line{
private:
    str name;
    int value;
public:
    line(){
        this->value = 0;
        this->name = "null";
    }

    line(str n, int v){
        this->value = v;
        this->name = std::move(n);
    }

    str getName(){return name;}
    int getValue(){return value;}

};

namespace data{

    class baseData{
    private:
        vec *data;
    public:
        baseData(){
            data = new vec;
        }

        vec* getData(){return data;}
        void setData(vec *dat){this->data = dat;}

        vec::iterator iterator(int i){
            auto dIt = data->begin();
            if(i == 0) return dIt;
            dIt+=i;
            return dIt;
        }
        void add(line l){
            data->push_back(l);
        }
        void remove(int i){
            data->erase(iterator(i));
        }
        line read(int i){
            return data->at(i);
        }
        void replace(int i ,line & l){
            data->insert(iterator(i),l);
        }
        virtual str toFile() = 0;
        ~baseData(){
            delete data;
        }
    };
    
    class iniData : public baseData{
    public:
        iniData() : baseData(){}

        str toFile() override{
            str f;
            for(line l : *getData()){
                f += l.getName() + " = " + std::to_string(l.getValue()) + "\n";
            }
            return f;
        }

    };
    
    class jsonData : public baseData{
    public:
        jsonData() : baseData(){}
        str toFile() override{
            str f;
            f+= "{\n";
            for(int a = 0;a < getData()->size();a++){
                line l = read(a);

                if(a + 1 >= getData()->size())
                    f += "\t" + l.getName() + " : " + std::to_string(l.getValue()) + "\n";
                else
                    f += "\t" + l.getName() + " : " + std::to_string(l.getValue()) + ",\n";
            }
            f+="}\n";
            return f;

        }
    };
}

class Adapter{

public:
    Adapter(){}

    data::jsonData toJson(data::iniData data){
        data::jsonData obj;
        obj.setData(data.getData());
        return obj;
    }

    data::iniData toIni(data::jsonData data){
        data::iniData obj;
        obj.setData(data.getData());
        return obj;
    }

    data::jsonData* toJson(data::iniData *data){
        auto obj = new data::jsonData();
        obj->setData(data->getData());
        return obj;
    }

    data::iniData* toIni(data::jsonData *data){
        auto obj = new data::iniData();
        obj->setData(data->getData());
        return obj;
    }

};

int main() {
    auto ini = new data::iniData();
    ini->add(line("isStart",1));
    ini->add(line("money",62220));
    ini->add(line("isFall",0));
    printf("%s\n",ini->toFile().c_str());

    auto json = Adapter().toJson(ini);
    json->remove(1);
    printf("%s\n",json->toFile().c_str());
    return 0;
}
