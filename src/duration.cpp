#include "duration.hpp"
#include <assert.h>

Duration::Duration (){
    time = 0;
}

Duration::Duration(int t){
    assert(t >= 0);
    time = t;
}
int Duration::get_duration(){
    return time;}

bool Duration::tick(){
    time++;
    return check_and_update_alarm();  
}

bool Duration::tick(int dt){
    assert(dt > 0);
    time += dt;
    return check_and_update_alarm();
}

void Duration::set_alarm(int t){
    assert (t>time);
    alarm = t; 
    alarm_been_set = true;
}

bool Duration::check_and_update_alarm(){
    if(alarm_been_set == false){
        return false;
    }
    if (time >=alarm)
    {
        alarm_been_set = false;
        return true;
    }
    return false;
}
Duration::~Duration() {}

