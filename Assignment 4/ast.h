#ifndef AST_H
#define AST_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

using namespace std;

class ASTNode {
public:
    virtual ~ASTNode() {}
    virtual string generate_code(ofstream& outcode, map<string, string>& symbol_to_temp, int& temp_count, int& label_count) const = 0;
};

// Expression node base types

class ExprNode : public ASTNode {
protected:
    string node_type; // Type information (int, float, void, etc.)
public:
    ExprNode(string type) : node_type(type) {}
    virtual string get_type() const { return node_type; }
};

// Variable node (for identifier references)

class VarNode : public ExprNode {
private:
    string name;
    ExprNode* index; // For array indexing, nullptr for simple variables

public:
    VarNode(string name, string type, ExprNode* idx = nullptr)
        : ExprNode(type), name(name), index(idx) {}
    
    ~VarNode() { if(index) delete index; }
    
    bool has_index() const { return index != nullptr; }
    
    string generate_index_code(ofstream& outcode, map<string, string>& symbol_to_temp,
                              int& temp_count, int& label_count) const {
        if (!index) return "";
        
        string idx_result = index->generate_code(outcode, symbol_to_temp, temp_count, label_count);
        return idx_result;
    }
    
    string generate_code(ofstream& outcode, map<string, string>& symbol_to_temp,
                        int& temp_count, int& label_count) const override {
        if (has_index()) {
            // Array element access: arr[idx]
            string idx_str = index->generate_code(outcode, symbol_to_temp, temp_count, label_count);
            string temp_var = "t" + to_string(temp_count++);
            outcode << temp_var << " = " << name << "[" << idx_str << "]" << endl;
            return temp_var;
        } else {
            // Simple variable reference - just return the name
            return name;
        }
    }
    
    string get_name() const { return name; }
};

// Constant value node

class ConstNode : public ExprNode {
private:
    string value;

public:
    ConstNode(string val, string type) : ExprNode(type), value(val) {}
    
    string generate_code(ofstream& outcode, map<string, string>& symbol_to_temp,
                        int& temp_count, int& label_count) const override {
        // Return the constant value directly
        return value;
    }
};

// Binary operation node

class BinaryOpNode : public ExprNode {
private:
    string op;
    ExprNode* left;
    ExprNode* right;

public:
    BinaryOpNode(string op, ExprNode* left, ExprNode* right, string result_type)
        : ExprNode(result_type), op(op), left(left), right(right) {}
    
    ~BinaryOpNode() {
        delete left;
        delete right;
    }
    
    string generate_code(ofstream& outcode, map<string, string>& symbol_to_temp,
                        int& temp_count, int& label_count) const override {
        string left_str = left->generate_code(outcode, symbol_to_temp, temp_count, label_count);
        string right_str = right->generate_code(outcode, symbol_to_temp, temp_count, label_count);
        
        string temp_var = "t" + to_string(temp_count++);
        outcode << temp_var << " = " << left_str << " " << op << " " << right_str << endl;
        
        return temp_var;
    }
};

// Unary operation node

class UnaryOpNode : public ExprNode {
private:
    string op;
    ExprNode* expr;

public:
    UnaryOpNode(string op, ExprNode* expr, string result_type)
        : ExprNode(result_type), op(op), expr(expr) {}
    
    ~UnaryOpNode() { delete expr; }
    
    string generate_code(ofstream& outcode, map<string, string>& symbol_to_temp,
                        int& temp_count, int& label_count) const override {
        string expr_str = expr->generate_code(outcode, symbol_to_temp, temp_count, label_count);
        
        string temp_var = "t" + to_string(temp_count++);
        outcode << temp_var << " = " << op << expr_str << endl;
        
        return temp_var;
    }
};

// Assignment operation node

class AssignNode : public ExprNode {
private:
    VarNode* lhs;
    ExprNode* rhs;

public:
    AssignNode(VarNode* lhs, ExprNode* rhs, string result_type)
        : ExprNode(result_type), lhs(lhs), rhs(rhs) {}
    
    ~AssignNode() {
        delete lhs;
        delete rhs;
    }
    
    string generate_code(ofstream& outcode, map<string, string>& symbol_to_temp,
                        int& temp_count, int& label_count) const override {
        string rhs_str = rhs->generate_code(outcode, symbol_to_temp, temp_count, label_count);
        
        if (lhs->has_index()) {
            // Array element assignment: arr[idx] = expr
            string idx_str = lhs->generate_index_code(outcode, symbol_to_temp, temp_count, label_count);
            outcode << lhs->get_name() << "[" << idx_str << "] = " << rhs_str << endl;
        } else {
            // Simple assignment: var = expr
            outcode << lhs->get_name() << " = " << rhs_str << endl;
        }
        
        return lhs->get_name();
    }
};

// Statement node base types

class StmtNode : public ASTNode {
public:
    virtual string generate_code(ofstream& outcode, map<string, string>& symbol_to_temp,
                                int& temp_count, int& label_count) const = 0;
};

// Expression statement node

class ExprStmtNode : public StmtNode {
private:
    ExprNode* expr;

public:
    ExprStmtNode(ExprNode* e) : expr(e) {}
    ~ExprStmtNode() { if(expr) delete expr; }
    
    string generate_code(ofstream& outcode, map<string, string>& symbol_to_temp,
                        int& temp_count, int& label_count) const override {
        if (expr) {
            expr->generate_code(outcode, symbol_to_temp, temp_count, label_count);
        }
        return "";
    }
};

// Block (compound statement) node

class BlockNode : public StmtNode {
private:
    vector<StmtNode*> statements;

public:
    ~BlockNode() {
        for (auto stmt : statements) {
            delete stmt;
        }
    }
    
    void add_statement(StmtNode* stmt) {
        if (stmt) statements.push_back(stmt);
    }
    
    string generate_code(ofstream& outcode, map<string, string>& symbol_to_temp,
                        int& temp_count, int& label_count) const override {
        for (const auto& stmt : statements) {
            stmt->generate_code(outcode, symbol_to_temp, temp_count, label_count);
        }
        return "";
    }
};

// If conditional statement node

class IfNode : public StmtNode {
private:
    ExprNode* condition;
    StmtNode* then_block;
    StmtNode* else_block; // nullptr if no else branch

public:
    IfNode(ExprNode* cond, StmtNode* then_stmt, StmtNode* else_stmt = nullptr)
        : condition(cond), then_block(then_stmt), else_block(else_stmt) {}
    
    ~IfNode() {
        delete condition;
        delete then_block;
        if (else_block) delete else_block;
    }
    
    string generate_code(ofstream& outcode, map<string, string>& symbol_to_temp,
                        int& temp_count, int& label_count) const override {
        string cond_str = condition->generate_code(outcode, symbol_to_temp, temp_count, label_count);
        
        string label_else = "L" + to_string(label_count++);
        string label_end = "L" + to_string(label_count++);
        
        if (else_block) {
            // if-else: if condition goto then, goto else
            outcode << "if " << cond_str << " goto " << label_else << endl;
            outcode << "goto " << label_end << endl;
            outcode << label_else << ":" << endl;
            then_block->generate_code(outcode, symbol_to_temp, temp_count, label_count);
            outcode << "goto " << label_end << endl;
            outcode << label_end << ":" << endl;
            else_block->generate_code(outcode, symbol_to_temp, temp_count, label_count);
            outcode << "goto " << label_end << endl;
            outcode << label_end << ":" << endl;
        } else {
            // if only: if condition goto then, goto end
            outcode << "if " << cond_str << " goto " << label_else << endl;
            outcode << "goto " << label_end << endl;
            outcode << label_else << ":" << endl;
            then_block->generate_code(outcode, symbol_to_temp, temp_count, label_count);
            outcode << "goto " << label_end << endl;
            outcode << label_end << ":" << endl;
        }
        
        return "";
    }
};

// While loop statement node

class WhileNode : public StmtNode {
private:
    ExprNode* condition;
    StmtNode* body;

public:
    WhileNode(ExprNode* cond, StmtNode* body_stmt)
        : condition(cond), body(body_stmt) {}
    
    ~WhileNode() {
        delete condition;
        delete body;
    }
    
    string generate_code(ofstream& outcode, map<string, string>& symbol_to_temp,
                        int& temp_count, int& label_count) const override {
        string start_label = "L" + to_string(label_count++);
        string body_label = "L" + to_string(label_count++);
        string end_label = "L" + to_string(label_count++);
        
        outcode << start_label << ":" << endl;
        string cond_str = condition->generate_code(outcode, symbol_to_temp, temp_count, label_count);
        outcode << "if " << cond_str << " goto " << body_label << endl;
        outcode << "goto " << end_label << endl;
        outcode << body_label << ":" << endl;
        body->generate_code(outcode, symbol_to_temp, temp_count, label_count);
        outcode << "goto " << start_label << endl;
        outcode << end_label << ":" << endl;
        
        return "";
    }
};

// For loop statement node

class ForNode : public StmtNode {
private:
    ExprNode* init;
    ExprNode* condition;
    ExprNode* update;
    StmtNode* body;

public:
    ForNode(ExprNode* init_expr, ExprNode* cond_expr, ExprNode* update_expr, StmtNode* body_stmt)
        : init(init_expr), condition(cond_expr), update(update_expr), body(body_stmt) {}
    
    ~ForNode() {
        if (init) delete init;
        if (condition) delete condition;
        if (update) delete update;
        delete body;
    }
    
    string generate_code(ofstream& outcode, map<string, string>& symbol_to_temp,
                        int& temp_count, int& label_count) const override {
        // Initialization
        if (init) {
            init->generate_code(outcode, symbol_to_temp, temp_count, label_count);
        }
        
        string start_label = "L" + to_string(label_count++);
        string body_label = "L" + to_string(label_count++);
        string end_label = "L" + to_string(label_count++);
        
        outcode << start_label << ":" << endl;
        
        // Condition check
        if (condition) {
            string cond_str = condition->generate_code(outcode, symbol_to_temp, temp_count, label_count);
            outcode << "if " << cond_str << " goto " << body_label << endl;
            outcode << "goto " << end_label << endl;
            outcode << body_label << ":" << endl;
        }
        
        // Execute body
        body->generate_code(outcode, symbol_to_temp, temp_count, label_count);
        
        // Update
        if (update) {
            update->generate_code(outcode, symbol_to_temp, temp_count, label_count);
        }
        
        outcode << "goto " << start_label << endl;
        outcode << end_label << ":" << endl;
        
        return "";
    }
};

// Return statement node

class ReturnNode : public StmtNode {
private:
    ExprNode* expr;

public:
    ReturnNode(ExprNode* e) : expr(e) {}
    ~ReturnNode() { if (expr) delete expr; }
    
    string generate_code(ofstream& outcode, map<string, string>& symbol_to_temp,
                        int& temp_count, int& label_count) const override {
        if (expr) {
            string ret_str = expr->generate_code(outcode, symbol_to_temp, temp_count, label_count);
            outcode << "return " << ret_str << endl;
        } else {
            outcode << "return" << endl;
        }
        return "";
    }
};

// Declaration statement node

class DeclNode : public StmtNode {
private:
    string type;
    vector<pair<string, int>> vars; // Variable identifier and array dimension (0 for regular vars)

public:
    DeclNode(string t) : type(t) {}
    
    void add_var(string name, int array_size = 0) {
        vars.push_back(make_pair(name, array_size));
    }
    
    string generate_code(ofstream& outcode, map<string, string>& symbol_to_temp,
                        int& temp_count, int& label_count) const override {
        for (const auto& var : vars) {
            if (var.second == 0) {
                // Regular variable declaration
                outcode << "// Declaration: " << type << " " << var.first << endl;
            } else {
                // Array declaration
                outcode << "// Declaration: " << type << " " << var.first << "[" << var.second << "]" << endl;
            }
        }
        return "";
    }
    
    string get_type() const { return type; }
    const vector<pair<string, int>>& get_vars() const { return vars; }
};

// Function declaration node

class FuncDeclNode : public ASTNode {
private:
    string return_type;
    string name;
    vector<pair<string, string>> params; // Parameter data type and identifier
    BlockNode* body;

public:
    FuncDeclNode(string ret_type, string n) : return_type(ret_type), name(n), body(nullptr) {}
    ~FuncDeclNode() { if (body) delete body; }
    
    void add_param(string type, string name) {
        params.push_back(make_pair(type, name));
    }
    
    void set_body(BlockNode* b) {
        body = b;
    }
    
    string generate_code(ofstream& outcode, map<string, string>& symbol_to_temp,
                        int& temp_count, int& label_count) const override {
        outcode << endl << "// Function: " << return_type << " " << name << "(";
        
        // Print parameter list
        for (size_t i = 0; i < params.size(); i++) {
            outcode << params[i].first << " " << params[i].second;
            if (i < params.size() - 1) outcode << ", ";
        }
        outcode << ")" << endl;
        
        // Function body
        if (body) {
            body->generate_code(outcode, symbol_to_temp, temp_count, label_count);
        }
        
        outcode << endl;
        
        return "";
    }
};

// Helper class for managing function arguments

class ArgumentsNode : public ASTNode {
private:
    vector<ExprNode*> args;

public:
    ~ArgumentsNode() {
        // Arguments will be managed by FuncCallNode
    }
    
    void add_argument(ExprNode* arg) {
        if (arg) args.push_back(arg);
    }
    
    ExprNode* get_argument(int index) const {
        if (index >= 0 && index < args.size()) {
            return args[index];
        }
        return nullptr;
    }
    
    size_t size() const {
        return args.size();
    }
    
    const vector<ExprNode*>& get_arguments() const {
        return args;
    }
    
    string generate_code(ofstream& outcode, map<string, string>& symbol_to_temp,
                        int& temp_count, int& label_count) const override {
        // This node doesn't directly generate code
        return "";
    }
};

// Function call node

class FuncCallNode : public ExprNode {
private:
    string func_name;
    vector<ExprNode*> arguments;

public:
    FuncCallNode(string name, string result_type)
        : ExprNode(result_type), func_name(name) {}
    
    ~FuncCallNode() {
        for (auto arg : arguments) {
            delete arg;
        }
    }
    
    void add_argument(ExprNode* arg) {
        if (arg) arguments.push_back(arg);
    }
    
    string generate_code(ofstream& outcode, map<string, string>& symbol_to_temp,
                        int& temp_count, int& label_count) const override {
        // Evaluate and generate params for arguments
        vector<string> arg_strs;
        for (const auto& arg : arguments) {
            string arg_str = arg->generate_code(outcode, symbol_to_temp, temp_count, label_count);
            arg_strs.push_back(arg_str);
        }
        
        // Output param statements for each argument
        for (const auto& arg_str : arg_strs) {
            outcode << "param " << arg_str << endl;
        }
        
        // Call function
        string temp_var = "t" + to_string(temp_count++);
        outcode << temp_var << " = call " << func_name << ", " << arguments.size() << endl;
        
        return temp_var;
    }
};

// Program node (AST root)

class ProgramNode : public ASTNode {
private:
    vector<ASTNode*> units;

public:
    ~ProgramNode() {
        for (auto unit : units) {
            delete unit;
        }
    }
    
    void add_unit(ASTNode* unit) {
        if (unit) units.push_back(unit);
    }
    
    string generate_code(ofstream& outcode, map<string, string>& symbol_to_temp,
                        int& temp_count, int& label_count) const override {
        for (const auto& unit : units) {
            unit->generate_code(outcode, symbol_to_temp, temp_count, label_count);
        }
        return "";
    }
};

#endif // AST_H
