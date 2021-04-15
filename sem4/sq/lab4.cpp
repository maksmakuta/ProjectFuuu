#include <cstdio>
#include <string>
#include <utility>

typedef std::string str;
namespace IO {
    void println(str text){
        printf("%s\n",text.c_str());
    }
    void print(str text){
        printf("%s",text.c_str());
    }
}
enum PC_type{
    Ofice, Standart, Gaming, Proffesional
};

namespace Components{
    class Detailed{
    public:
        virtual void info() = 0;
    };
    enum OS{
        ArchLinux,
        Kubuntu,
        Manjaro,
        Fedora,
        Debian,
        Ubuntu,
        Windows_XP,
        Windows_Vista,
        Windows_7,
        Windows_10,
        macOS_Hign_Sierra,
        macOS_Mojave
    };

    str toStr(OS o) {
        switch (o) {
            case ArchLinux:         return "ArchLinux        ";
            case Kubuntu:           return "Kubuntu          ";
            case Manjaro:           return "Manjaro          ";
            case Fedora:            return "Fedora           ";
            case Debian:            return "Debian           ";
            case Ubuntu:            return "Ubuntu           ";
            case Windows_XP:        return "Windows XP       ";
            case Windows_Vista:     return "Windows Vista    ";
            case Windows_7:         return "Windows 7        ";
            case Windows_10:        return "Windows 10       ";
            case macOS_Hign_Sierra: return "macOS High Sierra";
            case macOS_Mojave:      return "macOS Mojave     ";
        }
    }

    enum CPU{
        Intel_Core_i3,
        Intel_Core_i5,
        Intel_Core_i7,
        Intel_Core_i9,
        Ryzen_3xxx,
        Ryzen_5xxx,
        Ryzen_7xxx,
        Ryzen_9xxx
    };
    str toStr(CPU o) {
        switch (o) {
            case Intel_Core_i3:    return "Intel Core i3";
            case Intel_Core_i5:    return "Intel Core i5";
            case Intel_Core_i7:    return "Intel Core i7";
            case Intel_Core_i9:    return "Intel Core i9";
            case Ryzen_3xxx:       return "Ryzen 3xxx   ";
            case Ryzen_5xxx:       return "Ryzen 5xxx   ";
            case Ryzen_7xxx:       return "Ryzen 7xxx   ";
            case Ryzen_9xxx:       return "Ryzen 9xxx   ";
        }
    }
    enum GPU{
        Nvidia_MX150,
        Nvidia_RTX_2080,
        Nvidia_RTX_2080Ti,
        Nvidia_RTX_3050,
        Nvidia_RTX_3060,
        Nvidia_RTX_3070,
        Nvidia_RTX_3080,
        Nvidia_RTX_3090,
        AMD_Radeon_3xxx,
        AMD_Radeon_4xxx,
        AMD_Radeon_5xxx,
        AMD_Radeon_6xxx
    };
    str toStr(GPU o) {
        switch (o) {
            case Nvidia_MX150:       return "Nvidia MX 150     ";
            case Nvidia_RTX_2080:    return "Nvidia RTX 2080   ";
            case Nvidia_RTX_2080Ti:  return "Nvidia RTX 2080Ti ";
            case Nvidia_RTX_3050:    return "Nvidia RTX 3050   ";
            case Nvidia_RTX_3060:    return "Nvidia RTX 3060   ";
            case Nvidia_RTX_3070:    return "Nvidia RTX 3070   ";
            case Nvidia_RTX_3080:    return "Nvidia RTX 3080   ";
            case Nvidia_RTX_3090:    return "Nvidia RTX 3090   ";
            case AMD_Radeon_3xxx:    return "AMD Radeon 3xxx   ";
            case AMD_Radeon_4xxx:    return "AMD Radeon 4xxx   ";
            case AMD_Radeon_5xxx:    return "AMD Radeon 5xxx   ";
            case AMD_Radeon_6xxx:    return "AMD Radeon 6xxx   ";
        }
    }

    enum Ram_type{
        DDR,DDR2,DDR3,DDR3X,DDR4,DDR4X,DDR5,
        LPDDR,LPDDR2,LPDDR3,LPDDR3X,LPDDR4,LPDDR4X,LPDDR5
    };

    class RAM : public Detailed{
        private:
            Ram_type t;
            int value;
        public:
        RAM(){}
        RAM(Ram_type type, int v){
            this->t = type;
            this->value = v;
        }
        str toStr(Ram_type t){
            switch (t) {
                case DDR:       return "DDR";
                case DDR2:      return "DDR2";
                case DDR3:      return "DDR3";
                case DDR4:      return "DDR4";
                case DDR5:      return "DDR5";
                case DDR3X:     return "DDR3X";
                case DDR4X:     return "DDR4X";
                case LPDDR:     return "LPDDR";
                case LPDDR2:    return "LPDDR2";
                case LPDDR3:    return "LPDDR3";
                case LPDDR4:    return "LPDDR4";
                case LPDDR5:    return "LPDDR5";
                case LPDDR3X:   return "LPDDR3X";
                case LPDDR4X:   return "LPDDR4X";
            }
        }
        void info() override{
            IO::println("RAM type : " + toStr(t));
            IO::println("RAM value : " + std::to_string(value));
        }
    };

    enum ROM_Drive{
        SSD,HDD,SHD
    };

    class ROM : public Detailed{
        private:
            ROM_Drive drv;
            int value;
        public:
        ROM(){}
        ROM(ROM_Drive d,int v){
            this->value = v;
            this->drv = d;
        }
        str toStr(ROM_Drive t) {
            switch (t) {
                case SSD: return "SSD";
                case HDD: return "HDD";
                case SHD: return "SHD";
            }
        }
        void info() override{
            IO::println("ROM type : " + toStr(drv));
            IO::println("ROM value : " + std::to_string(value));
        }
    };
}


class PC : public Components::Detailed{
private:
    Components::OS  os;
    Components::CPU proccesor;
    Components::GPU videoCard;
    Components::RAM memoryRam;
    Components::ROM memoryRom;
public:
    PC(Components::OS  o,Components::CPU cpu, Components::GPU gpu,Components::RAM ram,Components::ROM rom){
        this->os        = o;
        this->proccesor = cpu;
        this->videoCard = gpu;
        this->memoryRam = std::move(ram);
        this->memoryRom = std::move(rom);
    }

    void info() override{
        IO::println("OS : " + Components::toStr(os));
        IO::println("CPU : " + Components::toStr(proccesor));
        IO::println("GPU : " + Components::toStr(videoCard));
        memoryRam.info();
        memoryRom.info();
    }
};

namespace Creator {
    class Builder{
        virtual void setOS(Components::OS) = 0;
        virtual void setCPU(Components::CPU) = 0;
        virtual void setGPU(Components::GPU) = 0;
        virtual void setROM(Components::ROM) = 0;
        virtual void setRAM(Components::RAM) = 0;
        virtual PC* pc() = 0;
    };
    class PCBuilder{
        public:
        PCBuilder(){

        }
        PC* getPC(PC_type t){
            switch (t) {
                case Ofice:     return createOfficePC();
                case Standart:  return createStandartPC();
                case Gaming:    return createGamingPC();
                case Proffesional: return createProfesonalPC();
            }
            return nullptr;
        }

        PC* createOfficePC(){
            return new PC(Components::OS::Windows_XP,
                          Components::CPU::Intel_Core_i3,
                          Components::GPU::AMD_Radeon_3xxx,
                          Components::RAM(Components::Ram_type::DDR3,4),
                          Components::ROM(Components::ROM_Drive::HDD,512));
        }
        PC* createStandartPC(){
            return new PC(Components::OS::Windows_7,
                          Components::CPU::Intel_Core_i5,
                          Components::GPU::AMD_Radeon_4xxx,
                          Components::RAM(Components::Ram_type::DDR3X,6),
                          Components::ROM(Components::ROM_Drive::HDD,1024));
        }
        PC* createGamingPC(){
            return new PC(Components::OS::Windows_10,
                          Components::CPU::Intel_Core_i7,
                          Components::GPU::Nvidia_RTX_2080Ti,
                          Components::RAM(Components::Ram_type::DDR4X,16),
                          Components::ROM(Components::ROM_Drive::SSD,2048));
        }
        PC* createProfesonalPC(){
            return new PC(Components::OS::Windows_10,
                          Components::CPU::Intel_Core_i9,
                          Components::GPU::Nvidia_RTX_3080,
                          Components::RAM(Components::Ram_type::DDR5,64),
                          Components::ROM(Components::ROM_Drive::SSD,2048));
        }

    };
    class ManualPCBuilder : public Builder{
    private:
        Components::OS o;
        Components::CPU c;
        Components::GPU g;
        Components::RAM a;
        Components::ROM r;
    public:
        ManualPCBuilder(){

        }
        void setCPU(Components::CPU cpu) override{
            this->c = cpu;
        }
        void setGPU(Components::GPU gpu) override{
            this->g = gpu;
        }
        void setOS(Components::OS os) override{
            this->o = os;
        }
        void setRAM(Components::RAM ram) override{
            this->a = ram;
        }
        void setROM(Components::ROM rom) override{
            this->r = rom;
        }

        PC * pc() override{
            return new PC(o,c,g,a,r);
        }

    };
}

int main() {
    auto *builder = new Creator::PCBuilder();
    PC* pc = builder->getPC(PC_type::Gaming);
    pc->info();

    IO::println(" ");

    auto mBuilder = new Creator::ManualPCBuilder();
    mBuilder->setOS(Components::ArchLinux);
    mBuilder->setCPU(Components::Intel_Core_i3);
    mBuilder->setGPU(Components::Nvidia_MX150);
    mBuilder->setRAM(Components::RAM(Components::Ram_type::DDR4X,8));
    mBuilder->setROM(Components::ROM(Components::ROM_Drive::SSD,240));
    pc = mBuilder->pc();
    pc->info();
    return 0;
}