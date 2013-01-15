#ifndef FEEDER_H
#define FEEDER_H

class Feeder {
private:
    int direction = 0; //change to uint32 later if needed
    void set_direction(int);
public:
    Feeder();
    ~Feeder();
    void feeder_up();
    void feeder_down();
    void feeder_stop_move();
};

#endif // FEEDER_H
