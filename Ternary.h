
#ifndef TERNARY_H
#define TERNARY_H

struct ternary{
    unsigned char positive;
    unsigned char negative;
    unsigned char neutral;

    ternary(unsigned char pos, unsigned char neg, unsigned char neu);
};
/*
template<typename T1, typename T2>
class Ternary{
private: 
    T1 alpha;
    T2 beta;
public:
// Constructor
    Ternary();

// Accessor

// Functions

};

*/
#endif // TERNARY_H