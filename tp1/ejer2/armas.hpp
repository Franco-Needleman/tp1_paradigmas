#ifndef ARMAS_HPP
#define ARMAS_HPP

#include <string>
using namespace std;

class armas {
public:
    virtual string gettipo() const = 0;
    virtual int getdamage() const = 0;
    virtual string quees() const = 0;  
    virtual ~armas() = default;
};
#endif