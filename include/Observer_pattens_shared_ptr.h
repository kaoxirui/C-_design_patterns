#pragma once
#ifndef _OBERVER_PATTENS
#define _OBERVER_PATTENS
#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>
class ObserverInterface{
    public:
        virtual void dosomething()=0;
        virtual ~ObserverInterface(){}
};

using pObserverInterface=std::shared_ptr<ObserverInterface>;


class SubjectInterface{
    public:
        virtual void Add(pObserverInterface obr)=0;
        virtual void Remove(pObserverInterface obr)=0;
        virtual void Notify()=0;

        virtual ~SubjectInterface(){}
};

class Me:public SubjectInterface{
    private:
        std::vector<pObserverInterface>observers;
    public:
        void Add(pObserverInterface obr)override{
            observers.push_back(obr);
        }

        void Remove(pObserverInterface obr) override{
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
    
    ~Wife(){
        std::cout<<"wife id destroyed"<<std::endl;
    }
};
class Son:public  ObserverInterface{
public:
    void dosomething() override {
        std::cout<<"爸爸快回来了，不能玩游戏了"<<std::endl;
    }
    ~Son(){
    std::cout<<"Son id destroyed"<<std::endl;
}
};
#endif