#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "scope_table.h"

class symbol_table
{
private:
    scope_table *current_scope;
    int bucket_count;
    int current_scope_id;
    ofstream* log_file;

public:
    symbol_table(int bucket_count, ofstream* log)
    {
        this->bucket_count = bucket_count;
        this->current_scope = NULL;  
        this->current_scope_id = 1;   
        this->log_file = log;              
    }

    ~symbol_table()
    {
        while (current_scope != NULL)
        {
            exit_scope();
        }
    }

    void enter_scope()
    {
        scope_table *new_scope_table = new scope_table(bucket_count, current_scope_id++, current_scope);
        current_scope = new_scope_table;
        *log_file << "New ScopeTable with ID " << current_scope->get_unique_id() << " created" << endl << endl;
    }

    void exit_scope()
    {
        if (current_scope == NULL)
        {
            *log_file << "No scope available to exit." << endl << endl;
            return;
        }
        
        *log_file << "Scopetable with ID " << current_scope->get_unique_id() << " removed" << endl << endl;
        scope_table *scope_to_delete = current_scope;
        current_scope = current_scope->get_parent_scope();  
        delete scope_to_delete;  
    }

    bool insert(symbol_info* symbol)
    {
        if (current_scope == NULL)
        {
            return false;  
        }
        return current_scope->insert_in_scope(symbol);
    }
    
    symbol_info* lookup(symbol_info* symbol)
    {
        string symbol_name = symbol->get_name();
        scope_table *scope_ptr = current_scope;
        
        while (scope_ptr != NULL)
        {
            symbol_info* found_symbol = scope_ptr->lookup_in_scope(symbol);
            if (found_symbol != NULL)
            {
                return found_symbol;  
            }
            scope_ptr = scope_ptr->get_parent_scope();  
        }
        return NULL;  
    }

    void print_current_scope()
    {
        if (current_scope != NULL)
        {
            current_scope->print_scope_table(*log_file);
        }
        else
        {
            *log_file << "No active scope available." << endl;
        }
    }

    void print_all_scopes(ofstream& outlog)
    {
        outlog << "################################" << endl << endl;
        scope_table *scope_ptr = current_scope;
        
        while (scope_ptr != NULL)
        {
            scope_ptr->print_scope_table(outlog);
            scope_ptr = scope_ptr->get_parent_scope();
        }
        outlog << "################################" << endl << endl;
    }
};

#endif