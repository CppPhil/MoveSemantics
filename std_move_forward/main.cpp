#include <type_traits>

template <typename Type> 
inline constexpr std::remove_reference_t<Type>&& move(Type&& arg) noexcept {
    return static_cast<std::remove_reference_t<Type>&&>(arg);
}

template <typename Type>
inline constexpr Type&& forward(std::remove_reference_t<Type>& arg) noexcept {
    return static_cast<Type&&>(arg);
}

template <typename Type> 
inline constexpr Type&& forward(std::remove_reference_t<Type>&& arg) noexcept {
    static_assert(!std::is_lvalue_reference<Type>::value,
                  "bad forward call: can not forward an rvalue as an lvalue.");
    return static_cast<Type&&>(arg);
}

int main() { }
