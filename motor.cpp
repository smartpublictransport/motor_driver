#include <thread>
#include <chrono>
#include "motor.h"


Motor::Motor():m_speed(0),m_acceleration(0){}

void Motor::set_acceleration(int a)
{
    if (a >= -10 && a < 10) {
        m_acceleration = a;
    }
}

void Motor::set_speed(int s)
{
    if (m_acceleration == 0 || m_speed == s) return;
    if (m_speed < s ) {
        //TODO: Posibly call this function on a seperate thread to be asynchronous
        decrease_speed (s);
    }
    else {
        //TODO: Posibly call this function on a seperate thread to be asynchronous
        increase_speed(s);
    }
}

void Motor::hard_stop ()
{
    while ( m_speed > 0) {
        m_speed --;
    }
}

void Motor::soft_stop ()
{
    while ( m_speed > 0) {
        m_speed --;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int Motor::get_speed()
{
    return m_speed;
}

int Motor::get_acceleration ()
{
    return m_acceleration;
}

void Motor::decrease_speed(int s)
{
    int sleep_time = 0;
    if (m_acceleration >= 0) return;
    if (m_acceleration >= -3 ){
        sleep_time = 3;
    } else if (m_acceleration >= -6 ) {
        sleep_time = 2;
    } else {
        sleep_time = 1;
    }
    while (s < m_speed && m_speed > 0) {
        m_speed --;
        std::this_thread::sleep_for(std::chrono::seconds(sleep_time));
    }
}


void Motor::increase_speed(int s)
{
    int sleep_time = 0;
    if (m_acceleration <= 0) return;
    if (m_acceleration <= 3 ){
        sleep_time = 3;
    } else if (m_acceleration <= 6 ) {
        sleep_time = 2;
    } else {
        sleep_time = 1;
    }
    while (s < m_speed && m_speed > 0) {
        m_speed ++;
        std::this_thread::sleep_for(std::chrono::seconds(sleep_time));
    }
}
