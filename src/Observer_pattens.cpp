#include"Observer_pattens_shared_ptr.h"

int main(){
    Me me;
    //ObserverInterface* wife=new Wife;
    //ObserverInterface* son=new Son;
    auto wife=std::make_shared<Wife>();
    auto son=std::make_shared<Son>();
    me.Add(wife);
    me.Add(son);

    me.Notify();
}