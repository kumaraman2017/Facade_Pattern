#include<iostream>
using namespace std;

// Subsystems
class PowerSupply{
    public:
        void providePower(){
            cout<<"Power supply is started"<<endl;
        }
};

class CoolingSystem{
    public:
        void StartFan(){
            cout<<"Cooling System"<<endl;
        }  
};

class CPU{
    public:
        void intialize(){
            cout<<"CPU: initialization has started"<<endl;
        }
};

class Memory {
public:
    void selfTest() {
        cout << "Memory: Self-test passed..." << endl;
    }
};

class HardDrive {
public:
    void spinUp() {
        cout << "Hard Drive: Spinning up..." << endl;
    }
};

class BIOS {
public:
    void boot(CPU& cpu, Memory& memory) {
        cout << "BIOS: Booting CPU and Memory checks..." << endl;
        cpu.intialize();
        memory.selfTest();
    }
};

class OperatingSystem {
public:
    void load() {
        cout << "Operating System: Loading into memory..." << endl;
    }
};

// Facade
class ComputerFacade{
    private:
        PowerSupply ps;
        Memory m;
        HardDrive hd;
        BIOS b;
        CoolingSystem c;
        OperatingSystem o;
        CPU cp;
    public:
        void startComputer(){
            ps.providePower();
            c.StartFan();
            b.boot(cp,m);
            hd.spinUp();
            o.load();
            cout<<"Computer is booted sucessfully"<<endl;
        }
};

// Client
int main(){
    ComputerFacade co;
    co.startComputer();
    return 0;
}