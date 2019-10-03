#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

class Motor{
    public:
        Motor();
        void set_acceleration(int a);
        void set_speed(int s);
        void hard_stop();
        void soft_stop();
        int get_speed();
        int get_acceleration();
    
    private:
        int m_speed;
        int m_acceleration;

        void decrease_speed(int s);
        void increase_speed(int s);
};
#endif
