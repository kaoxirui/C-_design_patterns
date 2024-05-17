#pragma once
#ifndef _OBERVER_PATTENS
#define _OBERVER_PATTENS
#include<iostream>
#include<vector>
#include<algorithm>
class ObserverInterface{
    public:
        virtual void dosomething()=0;
        virtual ~ObserverInterface(){}
};
class SubjectInterface{
    public:
        virtual void Add(ObserverInterface* obr)=0;
        virtual void Remove(ObserverInterface* obr)=0;
        virtual void Notify()=0;

        virtual ~SubjectInterface(){}
};

class Me:public SubjectInterface{
    private:
        std::vector<ObserverInterface*>observers;
    public:
        void Add(ObserverInterface* obr)override{
            observers.push_back(obr);
        }

        void Remove(ObserverInterface* obr) override{
            auto pos=std::find(observers.begin(),observers.end(),obr);
            if(pos!=observers.end()){
                observers.erase(pos);
            }
        }
        void Notify()override{
            for(const auto& obs:observers){
                obs->dosomething();
            }
        }
};

class Wife:public ObserverInterface{
    public:
        void dosomething() override{
        std::cout<<"老公快回来了，开始做饭"<<std::endl;
    }
};
class Son:public  ObserverInterface{
public:
    void dosomething() override {
        std::cout<<"爸爸快回来了，不能玩游戏了"<<std::endl;
    }
};
#endif