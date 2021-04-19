
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


namespace ariel
{

    class NumberWithUnits
    {
        private:
            double num;
            string unit;  
    
        public:
            NumberWithUnits(double num , string unit)
            {
                num=num;
                unit=unit;
            }
            double getNum()const{
                return num;
            }

            string getUnit()const{
                return unit;
            }
            static void read_units(std::ifstream &units_file);
    
            //================ + ====================//
            friend NumberWithUnits operator+(const NumberWithUnits &n1);
            friend NumberWithUnits operator+(const NumberWithUnits &n1, const NumberWithUnits &n2);
            friend NumberWithUnits operator+=(NumberWithUnits &n1, const NumberWithUnits &n2);

            //================ - ====================//
            friend NumberWithUnits operator-(const NumberWithUnits &n1);
            friend NumberWithUnits operator-(const NumberWithUnits &n1, const NumberWithUnits &n2);
            friend NumberWithUnits operator-=(NumberWithUnits &n1, const NumberWithUnits &n2);

            //================ <=> ====================//
            friend bool operator>(const NumberWithUnits &n1, const NumberWithUnits &n2);
            friend bool operator>=(const NumberWithUnits &n1, const NumberWithUnits &n2);
            friend bool operator<(const NumberWithUnits &n1, const NumberWithUnits &n2);
            friend bool operator<=(const NumberWithUnits &n1, const NumberWithUnits &n2);
            friend bool operator==(const NumberWithUnits &n1, const NumberWithUnits &n2);
            friend bool operator!=(const NumberWithUnits &n1, const NumberWithUnits &n2);


            //================ ++ -- ====================//
            friend NumberWithUnits operator++(NumberWithUnits &other);
            friend NumberWithUnits operator++(NumberWithUnits &other , int);

            friend NumberWithUnits operator--(NumberWithUnits &other);
            friend NumberWithUnits operator--(NumberWithUnits &other , int);

            //================ * ====================//
            friend NumberWithUnits operator*(const double n, const NumberWithUnits &c);
            friend NumberWithUnits operator*(const NumberWithUnits &c, const double n);
            
            friend NumberWithUnits operator*=(const double n, const NumberWithUnits &c);
            friend NumberWithUnits operator*=(const NumberWithUnits &c, const double n);

            //================ input - output ====================//
            friend std::ostream &operator<<(std::ostream &os, const NumberWithUnits &c);

            friend std::istream &operator>>(std::istream &is, NumberWithUnits &c);

    };
}