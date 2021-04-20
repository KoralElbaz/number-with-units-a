  
#include <iostream>
#include <fstream>
#include <map>
#include "NumberWithUnits.hpp"
using namespace std;

namespace ariel
{
    static map<string, map<string, double>> unitList; 

    NumberWithUnits::NumberWithUnits(double num , const string &unit)
    {
        cout << num << unit<<endl;
        this->num = num;
        this->unit = unit;
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
            throw invalid_argument{"Types not from the same system!"};
        }

    }

    void incomeUnit(const string unit1, const string unit2){
        for (auto map: unitList[unit2]){
                double val = unitList[unit1][unit2] * map.second;
                unitList[unit1][map.first] = val;
                unitList[map.first][unit1] = 1/val;
        }
    }  

    void NumberWithUnits::read_units(std::ifstream &units_file)
    {
        string unit1 , unit2 , c;
        double val1 , val2;

        while(units_file >> val1 >> unit1 >> c  >> val2 >>unit2 )
        {
            //cout << val1 << " " <<unit1 << " "<< c  << " "<<val2 <<"  "<<unit2 <<endl;
            unitList[unit1][unit2]=val2;
            unitList[unit2][unit1]=1/val2;
            incomeUnit(unit1, unit2);
            incomeUnit(unit2, unit1);            
        }
        // for (auto pair1 : unitList){
        //         for (auto pair2 : unitList[pair1.first])
        //         {
        //             cout << pair1.first<<" "<< pair2.first<<" "<< pair2.second<<endl;
        //         }
        //     }
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
        return n1;
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
       n1.num-= integrityCheck(n2.num,n2.unit , n1.unit );
        return n1;
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
        return NumberWithUnits(++other.num, other.unit);
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
        return NumberWithUnits(c.num*n, c.unit);
    }

    NumberWithUnits operator*(const NumberWithUnits &c, const double n)
    {
        return NumberWithUnits(c.num*n, c.unit);

    }


    //================ input - output ====================//
    std::ostream &operator<<(std::ostream &os, const NumberWithUnits &o){
        os << o.num << "[" << o.unit << "]";
        return os;
    }

    std::istream &operator>>(std::istream &is, NumberWithUnits &o){
        string s;
        is >> o.num >> s >> o.unit;
        return is;
    }

    
};
