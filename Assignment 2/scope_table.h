#ifndef SCOPE_TABLE_H
#define SCOPE_TABLE_H

#include "symbol_info.h"

class scope_table
{
private:
    int bucket_count;
    int unique_id;
    scope_table *parent_scope = NULL;
    vector<list<symbol_info *>> table;

    int hash_function(string name)
    {
        unsigned long hash_val = 5381;
        for (char ch : name)
        {
            hash_val = ((hash_val << 5) + hash_val) + ch;
        }
        return hash_val % bucket_count;
    }

public:
    scope_table() {}

    scope_table(int bucket_count, int unique_id, scope_table *parent_scope = NULL)
        : bucket_count(bucket_count), unique_id(unique_id), parent_scope(parent_scope)
    {
        table.resize(bucket_count);
    }

    scope_table *get_parent_scope()
    {
        return parent_scope;
    }

    int get_unique_id()
    {
        return unique_id;
    }

    symbol_info *lookup_in_scope(symbol_info* symbol)
    {
        string symbol_name = symbol->get_name();
        int bucket_idx = hash_function(symbol_name);
        
        for (symbol_info *entry : table[bucket_idx])
        {
            if (entry->get_name() == symbol_name)
            {
                return entry; 
            }
        }
        return nullptr;
    }

    bool insert_in_scope(symbol_info* symbol)
    {
        if (lookup_in_scope(symbol) != nullptr)
        {
            return false;
        }
        
        int bucket_idx = hash_function(symbol->get_name());
        table[bucket_idx].push_back(symbol);
        return true;
    }

    bool delete_from_scope(symbol_info* symbol)
    {
        string symbol_name = symbol->get_name();
        int bucket_idx = hash_function(symbol_name);
        
        for (auto iter = table[bucket_idx].begin(); iter != table[bucket_idx].end(); ++iter)
        {
            if ((*iter)->get_name() == symbol_name)
            {
                table[bucket_idx].erase(iter);
                return true;
            }
        }
        return false;
    }

    void print_scope_table(ofstream& outlog)
    {
        outlog << "ScopeTable # " << to_string(unique_id) << endl;

        for (int bucket_id = 0; bucket_id < bucket_count; ++bucket_id)
        {
            if (!table[bucket_id].empty())
            {
                outlog << bucket_id << " --> " << endl;
                
                for (symbol_info *entry : table[bucket_id])
                {
                    outlog << "< " << entry->get_name() << " : " << entry->get_type() << " >" << endl;

                    if (entry->get_symbol_type() == "Function Definition")
                    {
                        vector<string> parameters = entry->get_params();
                        int param_count = parameters.size();
                        entry->set_size(param_count);

                        outlog << entry->get_symbol_type() << endl;
                        outlog << "Return Type: " << entry->get_return_type() << endl;
                        outlog << "Number of Parameters: " << param_count << endl;

                        outlog << "Parameter Details: ";
                        for (size_t idx = 0; idx < param_count; idx++) 
                        {
                            outlog << parameters[idx];
                            if (idx != param_count - 1) 
                            {
                                outlog << ", ";
                            }
                        }
                        outlog << endl;
                    }
                    else
                    {
                        outlog << entry->get_symbol_type() << endl;
                        outlog << "Type: " << entry->get_return_type() << endl;
                        
                        if (entry->get_symbol_type() == "Array")
                        {
                            outlog << "Size: " << entry->get_size() << endl;
                        }
                    }
                }
                outlog << endl;
            }
        }
    }

    ~scope_table()
    {
        for (int bucket_id = 0; bucket_id < bucket_count; ++bucket_id)
        {
            for (symbol_info *entry : table[bucket_id])
            {
                delete entry;
            }
        }
    }
};

#endif