#include <cstring>

class RuleOfThree {
public:
    explicit RuleOfThree(const char* string)
        : string_(new char[std::strlen(string) + 1]) {
        std::strcpy(string_, string);
    }

    RuleOfThree(const RuleOfThree& other) // copy constructor
        : string_(new char[std::strlen(other.string_) + 1]) {
        std::strcpy(string_, other.string_);
    }

    RuleOfThree& operator=(const RuleOfThree& other) { // copy assignment operator
        char* tmp = new char[std::strlen(other.string_) + 1];
        std::strcpy(tmp, other.string_);
        delete[] string_;
        string_ = tmp;
        return *this;
    }

    ~RuleOfThree() { // destructor
        delete[] string_;
    }

private:
    char* string_;
};


int main() { }
