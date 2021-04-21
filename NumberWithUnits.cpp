#include "NumberWithUnits.hpp"
using namespace std;
using ariel::NumberWithUnits;

namespace ariel
{
   NumberWithUnits::NumberWithUnits(int num, string unit)
   {
      number = num;
      units = unit;
   }
   void NumberWithUnits::read_units(ifstream& units_file)
   {
   }
   const NumberWithUnits operator+(const NumberWithUnits& num_u1,const NumberWithUnits& num_u2)
   {
      if (!(NumberWithUnits::conected_units(num_u1, num_u2)))
      {
         throw invalid_argument(ariel::IA_ERROR);
      }
      return num_u1;
   }
   const NumberWithUnits operator+(NumberWithUnits& num_u)
   {
      return num_u;
   }
   const NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& num_u)
   {
      if (!(conected_units(*this, num_u)))
      {
         throw invalid_argument(ariel::IA_ERROR);
      }
      return num_u;
   }
   const NumberWithUnits operator-(const NumberWithUnits& num_u1,const NumberWithUnits& num_u2)
   {
      if (!(NumberWithUnits::conected_units(num_u1, num_u2)))
      {
         throw invalid_argument(ariel::IA_ERROR);
      }
      return num_u1;
   }
   const NumberWithUnits operator-(NumberWithUnits& num_u)
   {
      return num_u;
   }
   const NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits& num_u)
   {
      if (!(conected_units(*this, num_u)))
      {
         throw invalid_argument(ariel::IA_ERROR);
      }
      return num_u;
   }
   bool operator<(const NumberWithUnits& num_u1,const NumberWithUnits& num_u2)
   {
      if (!(NumberWithUnits::conected_units(num_u1, num_u2)))
      {
         throw invalid_argument(ariel::IA_ERROR);
      }
      return true;
   }
   bool operator<=(const NumberWithUnits& num_u1,const NumberWithUnits& num_u2) 
   {
      if (!(NumberWithUnits::conected_units(num_u1, num_u2)))
      {
         throw invalid_argument(ariel::IA_ERROR);
      }
      return true;
   }
   bool operator>(const NumberWithUnits& num_u1,const NumberWithUnits& num_u2) 
   {
      if (!(NumberWithUnits::conected_units(num_u1, num_u2)))
      {
         throw invalid_argument(ariel::IA_ERROR);
      }
      return true;
   }
   bool operator>=(const NumberWithUnits& num_u1,const NumberWithUnits& num_u2)
   {
      if (!(NumberWithUnits::conected_units(num_u1, num_u2)))
      {
         throw invalid_argument(ariel::IA_ERROR);
      }
      return true;
   }
   bool operator==(const NumberWithUnits& num_u1,const NumberWithUnits& num_u2) 
   {
      if (!(NumberWithUnits::conected_units(num_u1, num_u2)))
      {
         throw invalid_argument(ariel::IA_ERROR);
      }
      return true;
   }
   bool operator!=(const NumberWithUnits& num_u1,const NumberWithUnits& num_u2) 
   {
      if (!(NumberWithUnits::conected_units(num_u1, num_u2)))
      {
         throw invalid_argument(ariel::IA_ERROR);
      }
      return true;
   }
   NumberWithUnits& operator++(NumberWithUnits& num_u)
   {
      return num_u;
   }
   NumberWithUnits& NumberWithUnits::operator++(int num)
   {
      return *this;
   }
   NumberWithUnits& operator--(NumberWithUnits& num_u)
   {
       return num_u;
   }
   NumberWithUnits& NumberWithUnits::operator--(int num)
   {
      return *this;
   }
   NumberWithUnits operator*(double real_num,NumberWithUnits& num_u)
   {
     return num_u;
   }
   NumberWithUnits operator*(NumberWithUnits& num_u,double real_num)
   {
    return num_u;
   }
   ostream& operator<<(ostream& out, const NumberWithUnits& num_u)
   {
   
      return out;
   }
   istream& operator>>(istream& in, NumberWithUnits& num_u)
   {
      return in;
   }

   bool NumberWithUnits::conected_units(const NumberWithUnits& num_u1, const NumberWithUnits& num_u2)
   {
      return true;
   }
}