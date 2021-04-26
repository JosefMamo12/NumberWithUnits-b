#pragma once
#include <iostream>
#include <string.h>
#include <map>


using namespace std;

const double TOLERANCE = 0.000001;
const double ZERO = 0;
const double ONE = 1;

namespace ariel
{
    class NumberWithUnits
    {
        double _num;
        string _type;

    public:
        static void check_and_init(NumberWithUnits &a, const double new_num, const string &new_type);
        static void print_units();
        static void calculate_consequence();
        static void read_units(ifstream &file);
        NumberWithUnits(const double &, const string &);
        NumberWithUnits();
        double num() const
        {
            return _num;
        }
        string type() const
        {
            return _type;
        }
        NumberWithUnits operator+()
        {
            return NumberWithUnits(_num, _type);
        }
        NumberWithUnits &operator+=(const NumberWithUnits &other); // done test
        NumberWithUnits operator-()                                //done test
        {
            return NumberWithUnits(-_num, _type);
        }
        NumberWithUnits &operator-=(const NumberWithUnits &other); // done test
        NumberWithUnits &operator++()                              //dont test
        {
            _num++;
            return *this;
        }
        const NumberWithUnits operator++(int dummy_flag_for_postfix_increment) //done test
        {
            NumberWithUnits copy = *this;
            _num++;
            return copy;
        }
        NumberWithUnits &operator--() //done test
        {
            _num--;
            return *this;
        }
        const NumberWithUnits operator--(int dummy_flag_for_postfix_increment) //done test
        {
            NumberWithUnits copy = *this;
            _num--;
            return copy;
        }
        bool operator==(const NumberWithUnits &) const;
        friend NumberWithUnits operator*(const NumberWithUnits &, const double);            // done test
        friend NumberWithUnits operator*(const double, const NumberWithUnits &);            // done test
        friend NumberWithUnits operator-(const NumberWithUnits &, const NumberWithUnits &); //done test
        friend NumberWithUnits operator+(const NumberWithUnits &, const NumberWithUnits &); // done test

        friend bool operator<(const NumberWithUnits &, const NumberWithUnits &);  //done test
        friend bool operator>(const NumberWithUnits &, const NumberWithUnits &);  // done test
        friend bool operator<=(const NumberWithUnits &, const NumberWithUnits &); //done test
        friend bool operator>=(const NumberWithUnits &, const NumberWithUnits &); //done test
        // friend bool operator==(const NumberWithUnits &, const NumberWithUnits &); //done test
        friend bool operator!=(const NumberWithUnits &, const NumberWithUnits &); //done test

        friend ostream &operator<<(ostream &os, const NumberWithUnits &a);
        friend istream &operator>>(istream &input, NumberWithUnits &a);
    };

}