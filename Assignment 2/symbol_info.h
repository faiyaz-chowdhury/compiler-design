#ifndef SYMBOL_INFO_H
#define SYMBOL_INFO_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>
using namespace std;

class symbol_info
{
private:
    string name;
    string type;

    string symbol_category = "UNDEFINED"; // variable, array, or function
    string data_type;
    vector<string> param_list; // Parameters for functions
    int array_size;    // Size for arrays or param count for functions

public:
    symbol_info(string name, string type)
    {
        this->name = name;
        this->type = type;
        this->array_size = 0;
    }

    string get_name()
    {
        return name;
    }

    string get_type()
    {
        return type;
    }

    string get_symbol_type()
    {
        return symbol_category;
    }

    string get_return_type()
    {
        return data_type;
    }

    int get_size()
    {
        return array_size;
    }

    vector<string> get_params()
    {
        return param_list;
    }

    void set_name(string name)
    {
        this->name = name;
    }

    void set_type(string type)
    {
        this->type = type;
    }

    void set_symbol_type(string sym_type)
    {
        this->symbol_category = sym_type;
    }

    void set_return_type(string ret_type)
    {
        this->data_type = ret_type;
    }

    void set_size(int sz)
    {
        this->array_size = sz;
    }

    void add_param_type(string param)
    {
        param_list.push_back(param);
    }

    ~symbol_info()
    {
        // Memory cleanup if needed
    }
};

#endif