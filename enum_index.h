#ifndef ENUM_INDEX_H
#define ENUM_INDEX_H

#include <cstddef>
#include <type_traits>

/** @brief Restrict get int for an enumaration */
template <typename T>
concept IsEnum = std::is_enum_v<T>;

/** @brief Function to get the index of an enumerated item. */
template <IsEnum T> constexpr size_t enum_index(T index)
{
    return static_cast<size_t>(index);
}

#endif // ENUM_INDEX_H
