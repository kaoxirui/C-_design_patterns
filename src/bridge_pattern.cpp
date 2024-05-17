#include<iostream>

class Device
{
public:
    virtual bool isEnable()=0;
    virtual void enable()=0;
    virtual void disable()=0;
    virtual ~Device(){}
};

class TV:public Device{
    bool on=false;
public:
    bool isEnable()override{
        return on;
    }
    void enable() override {
        on = true;
        std::cout << "TV is turned on.\n";
    }

    void disable() override {
        on = false;
        std::cout << "TV is turned off.\n";
    }
};

class Radio : public Device {
    bool on = false;
public:
    bool isEnable() override {
        return on;
    }

    void enable() override {
        on = true;
        std::cout << "Radio is turned on.\n";
    }

    void disable() override {
        on = false;
        std::cout << "Radio is turned off.\n";
    }
};

//定义抽象和扩展抽象
class RemoteControl{
protected:
    Device* device;
public:
    RemoteControl(Device* d):device(d){}
    virtual void togglePower(){
        if(device->isEnable()){
            device->disable();
        }else{
            device->enable();
        }
    }
    virtual ~RemoteControl(){
    
    }
};

class AdvancedRemoteControl:public RemoteControl{
    public:
        AdvancedRemoteControl(Device* d):RemoteControl(d){}
        void mute(){
            std::cout<<"Device is muted"<<std::endl;
        }
};

int main(){
    Device* tv=new TV();
    RemoteControl* remote=new RemoteControl(tv);
    remote->togglePower();

    Device* radio = new Radio();
    AdvancedRemoteControl* advancedRemote = new AdvancedRemoteControl(radio);
    advancedRemote->togglePower(); // Turns Radio on
    advancedRemote->mute(); // Mute the radio

    delete tv;
    delete radio;
    delete remote;
    delete advancedRemote;
    return 0;
}
//这个示例展示了如何使用桥接模式分离设备类型和遥控器的功能，
//使得对遥控器或设备类型的任何修改都不会影响到彼此。这种方式提高了代码的可维护性和扩展性。