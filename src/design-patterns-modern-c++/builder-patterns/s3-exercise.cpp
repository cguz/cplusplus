#include <string>
#include <ostream>
#include <iostream>
#include <vector>
using namespace std;

class Code {
    
    public: 
        string name;
        string type;

        vector<Code> fields;

        Code() {}

        Code(const string& name, const string& type) : name{name}, type{type} {}
        
        friend ostream& operator<<(ostream& os, const Code& obj)
        {
            return os << "  " << obj.type << " " << obj.name << ";";
        }
};

class CodeBuilder
{
    Code root;

    public:
        CodeBuilder(const string& class_name)
        {
            this->root.name = class_name;
        }

        CodeBuilder& add_field(const string& name, const string& type)
        {
            this->root.fields.emplace_back(Code{name, type});
            return *this;
        }

        friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
        {
            os << "class " << obj.root.name << endl;
            os << "{" << endl;

            for (const auto& field : obj.root.fields){
                os << field << endl;
            }

            os << "};";

            return os;
        }

};

int main(){

    CodeBuilder code = CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");

    cout << code;

    getchar();
    return 0;
}