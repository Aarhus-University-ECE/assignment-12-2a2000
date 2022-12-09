#ifndef _DURATION_H_
#define _DURATION_H_
#include <stdio.h>


class Duration{
private:
    int time; //seconds that has elapsed
    int alarm; // to creat an alarm
    bool alarm_been_set; // alarm setting
public:
    
    Duration ();
    Duration (int t);
    ~Duration (); // to set time to zero 
    int get_duration(); // to return the time value 
    bool tick(); // Tic to incremenete 
    bool tick(int dt); // add dt to the current time 

    void set_alarm(int t);

    // b) sets the time attribute to 0
    bool check_and_update_alarm ();
};
#endif
