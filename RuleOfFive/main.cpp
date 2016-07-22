#include <cstring>

class RuleOfFive final {
public:
    explicit RuleOfFive(const char* string)
        : string_{ new char[std::strlen(string) + 1] } {
        std::strcpy(string_, string);
    }

    RuleOfFive(const RuleOfFive& other) // copy constructor
        : string_{ new char[std::strlen(other.string_) + 1] } {
        std::strcpy(string_, other.string_);
    }

    RuleOfFive(RuleOfFive&& other) noexcept // move constructor
        : string_{ other.string_ } {
        other.string_ = nullptr;
    }

    RuleOfFive& operator=(const RuleOfFive& other) { // copy assignment operator
        auto tmp = new char[std::strlen(other.string_) + 1];
        std::strcpy(tmp, other.string_);
        delete[] string_;
        string_ = tmp;
        return *this;
    }

    RuleOfFive& operator=(RuleOfFive&& other) noexcept { // move assignment operator 
        auto tmp = other.string_;
        other.string_ = nullptr;
        delete[] string_;
        string_ = tmp;
        return *this;
    }

    ~RuleOfFive() { // destructor
        delete[] string_;
    }

private:
    char* string_;
};


int main() { }
