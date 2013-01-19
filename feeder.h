#ifndef FEEDER_H
#define FEEDER_H

class Feeder {
private:
    int direction;
    void set_direction(int);
public:
    Feeder();
    ~Feeder();
    void feeder_up();
    void feeder_down();
    void feeder_stop();
};

#endif // FEEDER_H
