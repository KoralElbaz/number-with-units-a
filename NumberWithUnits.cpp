  
#include <iostream>
#include <fstream>
#include <map>
#include "NumberWithUnits.hpp"
using namespace std;

namespace ariel
{
    static map<string, map<string, double>> unitList; 

    static void read_units(std::ifstream &units_file)
    {
        ifstream inFile;
    }   
    //============== help functions ============//
    double integrityCheck(double val , string src , string dest){
        if(src==dest){
            return val;
        }
        try{
           return (val * unitList.at(src).at(dest));
        }
        catch(const exception& e) {
            throw invalid_argument{"Illegal unit!"};
        }

    }


    //================ + ====================//
    
    NumberWithUnits operator+(const NumberWithUnits &n1){
        //double numCheck=integrityCheck(n1._num,n1._unit);
        return NumberWithUnits(n1.num,n1.unit);

    }
    NumberWithUnits operator+(const NumberWithUnits &n1, const NumberWithUnits &n2){
        double numCheck=integrityCheck(n2.num,n2.unit , n1.unit );
        return NumberWithUnits(n1.num+numCheck,n1.unit);

    }
    NumberWithUnits operator+=(NumberWithUnits &n1, const NumberWithUnits &n2){
        n1.num+= integrityCheck(n2.num,n2.unit , n1.unit );
        return n1.num;
    }

    //================ - ====================//
    NumberWithUnits operator-(const NumberWithUnits &n1)
    {
        //double numCheck=integrityCheck(other._num,other._unit);
        return NumberWithUnits((-1)*n1.num,n1.unit);

    }
    NumberWithUnits operator-(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        double numCheck=integrityCheck(n2.num,n2.unit , n1.unit );
        return NumberWithUnits(n1.num-numCheck,n1.unit);

    }
    NumberWithUnits operator-=(NumberWithUnits &n1, const NumberWithUnits &n2)
    {
       n1.num+= integrityCheck(n2.num,n2.unit , n1.unit );
        return n1.num;
    }

    //================ <=> ====================//    V

    bool operator>(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return (n1.num>integrityCheck(n2.num,n2.unit , n1.unit));
    }
    bool operator>=(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return  (n1.num>=integrityCheck(n2.num,n2.unit , n1.unit));

    }
    bool operator<(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return (n1.num<integrityCheck(n2.num,n2.unit , n1.unit));

    }
    bool operator<=(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return (n1.num<=integrityCheck(n2.num,n2.unit , n1.unit));

    }
    bool operator==(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return  (n1.num==integrityCheck(n2.num,n2.unit , n1.unit));

    }
    bool operator!=(const NumberWithUnits &n1, const NumberWithUnits &n2)
    {
        return (n1.num!=integrityCheck(n2.num,n2.unit , n1.unit));

    }



    //================ ++ -- ====================//

    NumberWithUnits operator++(NumberWithUnits &other)
    {
        return NumberWithUnits(--other.num, other.unit);
    }

    NumberWithUnits operator++(NumberWithUnits &other , int)
    {
        return NumberWithUnits(other.num++, other.unit);
    }

    NumberWithUnits operator--(NumberWithUnits &other)
    {
        return NumberWithUnits(--other.num, other.unit);
    }

    NumberWithUnits operator--(NumberWithUnits &other , int)
    {
        return NumberWithUnits(other.num-- ,other.unit);
    }


   

    //================ * ====================//

    NumberWithUnits operator*(const double n, const NumberWithUnits &c)
    {
        return NumberWithUnits(o.num*n, o.unit);
    }

    NumberWithUnits operator*(const NumberWithUnits &c, const double n);
    {
        return NumberWithUnits(o.num*n, o.unit);

    }

            
    NumberWithUnits operator*=(const double n, const NumberWithUnits &c)
    {
        c.num*=n;
        return c;
    }

    NumberWithUnits operator*=(const NumberWithUnits &c, const double n)
    {
        c.num*=n;
        return c;
    }




    //================ input - output ====================//
    std::ostream &operator<<(std::ostream &os, const NumberWithUnits &o){
         out << o.num << "[" << o.unit << "]";
        return out;
    }

    std::istream &operator>>(std::istream &is, NumberWithUnits &o){
        string s;
        in >> o.num >> s >> o.unit;
        return in;
    }

    
};
