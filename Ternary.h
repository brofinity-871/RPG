
#ifndef TERNARY_H
#define TERNARY_H

// All objects will have affects that either benefit or hinder the character. Few have no consequences. 
struct ternary{
    unsigned char positive;     // Summation of all positive affects from current instance. 
    bool neutral;               // Checking-bit. You are either inspecting/operating/accessing this ternary, or not. 
    unsigned char negative;     // Summation of all negative affects from current instance.

    // Constructor
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