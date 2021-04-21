#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <utility>

namespace ariel
{
    const unsigned int FIVE = 5;
    const std::string IA_ERROR =  "the units do not match";
    class NumberWithUnits
    {
    public:
        NumberWithUnits(int num, std::string unit);
        static void read_units(std::ifstream& units_file);

        friend const NumberWithUnits operator+(const NumberWithUnits& num_u1,const NumberWithUnits& num_u2);
        friend const NumberWithUnits operator+(NumberWithUnits& num_u);
        const NumberWithUnits& operator+=(const NumberWithUnits& num_u);
        friend const NumberWithUnits operator-(const NumberWithUnits& num_u1,const NumberWithUnits& num_u2);
        friend const NumberWithUnits operator-(NumberWithUnits& num_u);
        const NumberWithUnits& operator-=(const NumberWithUnits& num_u);

        friend bool operator<(const NumberWithUnits& num_u1,const NumberWithUnits& num_u2);
        friend bool operator<=(const NumberWithUnits& num_u1,const NumberWithUnits& num_u2);
        friend bool operator>(const NumberWithUnits& num_u1,const NumberWithUnits& num_u2);
        friend bool operator>=(const NumberWithUnits& num_u1,const NumberWithUnits& num_u2);
        friend bool operator==(const NumberWithUnits& num_u1,const NumberWithUnits& num_u2);
        friend bool operator!=(const NumberWithUnits& num_u1,const NumberWithUnits& num_u2);

        friend NumberWithUnits& operator++(NumberWithUnits& num_u);
        NumberWithUnits& operator++(int num);
        friend NumberWithUnits& operator--(NumberWithUnits& num_u);
        NumberWithUnits& operator--(int num);

        friend NumberWithUnits operator*(double real_num,NumberWithUnits& num_u);
        friend NumberWithUnits operator*(NumberWithUnits& num_u,double real_num);
        friend std::ostream& operator<<(std::ostream& out,const NumberWithUnits& num_u);
        friend std::istream& operator>>(std::istream& in,NumberWithUnits& num_u);

        static bool conected_units(const NumberWithUnits& num_u1 ,const NumberWithUnits& num_u2);

        


    private:
       double number;
       std::string units;
      
       
    };

}