#pragma once

#include <cstddef>
#include <memory>
#include <string_view>
#include <utility>

#if __cplusplus >= 202002L
#include <compare>
#endif

namespace life {

template<typename CharT>
class basic_life_string_view {
    std::basic_string_view<CharT> data_;
    std::shared_ptr<void> life_;
public:
    using traits_type = typename std::basic_string_view<CharT>::traits_type;
    using value_type = typename std::basic_string_view<CharT>::value_type;
    using pointer = typename std::basic_string_view<CharT>::pointer;
    using const_pointer = typename std::basic_string_view<CharT>::const_pointer;
    using reference = typename std::basic_string_view<CharT>::reference;
    using const_reference = typename std::basic_string_view<CharT>::const_reference;
    using const_iterator = typename std::basic_string_view<CharT>::const_iterator;
    using iterator = const_iterator;
    using const_reverse_iterator = typename std::basic_string_view<CharT>::const_reverse_iterator;
    using reverse_iterator = const_reverse_iterator;
    using size_type = typename std::basic_string_view<CharT>::size_type;
    using difference_type = typename std::basic_string_view<CharT>::difference_type;
    static constexpr size_type npos = std::basic_string_view<CharT>::npos;

    basic_life_string_view(std::basic_string_view<CharT> sv)
        : data_{sv}, life_{} {}
    basic_life_string_view(std::basic_string_view<CharT> sv, std::shared_ptr<void> life)
        : data_{sv}, life_{std::move(life)} {}

    template <class T>
    static basic_life_string_view allocate(T&& data) {
        auto p = std::make_shared<T>(std::forward<T>(data));
        return {*p, p};
    }

    std::basic_string_view<CharT> string_view() const noexcept {
        return data_;
    }
    std::shared_ptr<void> life() const noexcept {
        return life_;
    }

    const_iterator begin() const noexcept {
        return data_.begin();
    }
    const_iterator end() const noexcept {
        return data_.end();
    }
    const_iterator cbegin() const noexcept {
        return data_.cbegin();
    }
    const_iterator cend() const noexcept {
        return data_.cend();
    }
    const_reverse_iterator rbegin() const noexcept {
        return data_.rbegin();
    }
    const_reverse_iterator rend() const noexcept {
        return data_.rend();
    }
    const_reverse_iterator crbegin() const noexcept {
        return data_.crbegin();
    }
    const_reverse_iterator crend() const noexcept {
        return data_.crend();
    }

    size_type size() const noexcept {
        return data_.size();
    }
    size_type length() const noexcept {
        return data_.length();
    }
    size_type max_size() const noexcept {
        return data_.max_size();
    }
    bool empty() const noexcept {
        return data_.empty();
    }

    const_reference operator[](size_type pos) const {
        return data_[pos];
    }
    const_reference at(size_type pos) const {
        return data_.at(pos);
    }
    const_reference front() const {
        return data_.front();
    }
    const_reference back() const {
        return data_.back();
    }
    const_pointer data() const noexcept {
        return data_.data();
    }

    void remove_prefix(size_type n) {
        data_.remove_prefix(n);
    }
    void remove_suffix(size_type n) {
        data_.remove_suffix(n);
    }
    void swap(basic_life_string_view& sv) noexcept {
        data_.swap(sv.data_);
        life_.swap(sv.life_);
    }
    friend void swap(basic_life_string_view& a, basic_life_string_view& b) noexcept {
        a.swap(b);
    }

    size_type copy(CharT* s, size_type n, size_type pos = 0) const {
        return data_.copy(s, n, pos);
    }
    basic_life_string_view substr(size_type start = 0, size_type n = npos) const {
        return {data_.substr(start, n), life_};
    }
    int compare(const basic_life_string_view& sv) const noexcept {
        return data_.compare(sv.data_);
    }
    int compare(size_type pos1, size_type n1, const basic_life_string_view& sv) const {
        return data_.compare(pos1, n1, sv.data_);
    }
    int compare(size_type pos1, size_type n1, const basic_life_string_view& sv, size_type pos2, size_type n2) const {
        return data_.compare(pos1, n1, sv.data_, pos2, n2);
    }
    int compare(const CharT* s) const {
        return data_.compare(s);
    }
    int compare(size_type pos1, size_type n1, const CharT* s) const {
        return data_.compare(pos1, n1, s);
    }
    int compare(size_type pos1, size_type n1, const CharT* s, size_type n2) const {
        return data_.compare(pos1, n1, s, n2);
    }
#if __cplusplus >= 202002L
    bool starts_with(const basic_life_string_view& x) const noexcept {
        return data_.starts_with(x.data_);
    }
    bool starts_with(CharT x) const noexcept {
        return data_.starts_with(x);
    }
    bool starts_with(const CharT* x) const {
        return data_.starts_with(x);
    }
    bool ends_with(const basic_life_string_view& x) const noexcept {
        return data_.ends_with(x.data_);
    }
    bool ends_with(CharT x) const noexcept {
        return data_.ends_with(x);
    }
    bool ends_with(const CharT* x) const {
        return data_.ends_with(x);
    }
#endif
#if __cplusplus >= 202302L
    bool contains(const basic_life_string_view& x) const noexcept {
        return data_.contains(x.data_);
    }
    bool contains(CharT x) const noexcept {
        return data_.contains(x);
    }
    bool contains(const CharT* x) const {
        return data_.contains(x);
    }
#endif

    size_type find(const basic_life_string_view& sv, size_type pos = 0) const noexcept {
        return data_.find(sv.data_, pos);
    }
    size_type find(CharT c, size_type pos = 0) const noexcept {
        return data_.find(c, pos);
    }
    size_type find(const CharT* s, size_type pos, size_type n) const {
        return data_.find(s, pos, n);
    }
    size_type find(const CharT* s, size_type pos = 0) const {
        return data_.find(s, pos);
    }
    size_type rfind(const basic_life_string_view& s, size_type pos = npos) const noexcept {
        return data_.rfind(s.data_, pos);
    }
    size_type rfind(CharT c, size_type pos = npos) const noexcept {
        return data_.rfind(c, pos);
    }
    size_type rfind(const CharT* s, size_type pos, size_type n) const {
        return data_.rfind(s, pos, n);
    }
    size_type rfind(const CharT* s, size_type pos = npos) const {
        return data_.rfind(s, pos);
    }
    size_type find_first_of(const basic_life_string_view& sv, size_type pos = 0) const noexcept {
        return data_.find_first_of(sv.data_, pos);
    }
    size_type find_first_of(CharT c, size_type pos = 0) const noexcept {
        return data_.find_first_of(c, pos);
    }
    size_type find_first_of(const CharT* s, size_type pos, size_type n) const {
        return data_.find_first_of(s, pos, n);
    }
    size_type find_first_of(const CharT* s, size_type pos = 0) const {
        return data_.find_first_of(s, pos);
    }
    size_type find_last_of(const basic_life_string_view& sv, size_type pos = npos) const noexcept {
        return data_.find_last_of(sv.data_, pos);
    }
    size_type find_last_of(CharT c, size_type pos = npos) const noexcept {
        return data_.find_last_of(c, pos);
    }
    size_type find_last_of(const CharT* s, size_type pos, size_type n) const {
        return data_.find_last_of(s, pos, n);
    }
    size_type find_last_of(const CharT* s, size_type pos = npos) const {
        return data_.find_last_of(s, pos);
    }
    size_type find_first_not_of(const basic_life_string_view& sv, size_type pos = 0) const noexcept {
        return data_.find_first_not_of(sv.data_, pos);
    }
    size_type find_first_not_of(CharT c, size_type pos = 0) const noexcept {
        return data_.find_first_not_of(c, pos);
    }
    size_type find_first_not_of(const CharT* s, size_type pos, size_type n) const {
        return data_.find_first_not_of(s, pos, n);
    }
    size_type find_first_not_of(const CharT* s, size_type pos = 0) const {
        return data_.find_first_not_of(s, pos);
    }
    size_type find_last_not_of(const basic_life_string_view& sv, size_type pos = npos) const noexcept {
        return data_.find_last_not_of(sv.data_, pos);
    }
    size_type find_last_not_of(CharT c, size_type pos = npos) const noexcept {
        return data_.find_last_not_of(c, pos);
    }
    size_type find_last_not_of(const CharT* s, size_type pos, size_type n) const {
        return data_.find_last_not_of(s, pos, n);
    }
    size_type find_last_not_of(const CharT* s, size_type pos = npos) const {
        return data_.find_last_not_of(s, pos);
    }

    friend bool operator==(const basic_life_string_view& a, const basic_life_string_view& b) noexcept {
        return a.data_ == b.data_;
    }
    friend bool operator==(const basic_life_string_view& a, const CharT* b) noexcept {
        return a.data_ == b;
    }
#if __cplusplus < 202002L
    friend bool operator==(const CharT* a, const basic_life_string_view& b) noexcept {
        return a == b.data_;
    }
    friend bool operator!=(const basic_life_string_view& a, const basic_life_string_view& b) noexcept {
        return a.data_ != b.data_;
    }
    friend bool operator!=(const basic_life_string_view& a, const CharT* b) noexcept {
        return a.data_ != b;
    }
    friend bool operator!=(const CharT* a, const basic_life_string_view& b) noexcept {
        return a != b.data_;
    }
#endif

#if __cplusplus >= 202002L
    friend auto operator<=>(const basic_life_string_view& a, const basic_life_string_view& b) noexcept {
        return a.data_ <=> b.data_;
    }
    friend auto operator<=>(const basic_life_string_view& a, const CharT* b) noexcept {
        return a.data_ <=> b;
    }
#else
    friend bool operator<(const basic_life_string_view& a, const basic_life_string_view& b) noexcept {
        return a.data_ < b.data_;
    }
    friend bool operator<(const basic_life_string_view& a, const CharT* b) noexcept {
        return a.data_ < b;
    }
    friend bool operator<(const CharT* a, const basic_life_string_view& b) noexcept {
        return a < b.data_;
    }
    friend bool operator<=(const basic_life_string_view& a, const basic_life_string_view& b) noexcept {
        return a.data_ <= b.data_;
    }
    friend bool operator<=(const basic_life_string_view& a, const CharT* b) noexcept {
        return a.data_ <= b;
    }
    friend bool operator<=(const CharT* a, const basic_life_string_view& b) noexcept {
        return a <= b.data_;
    }
    friend bool operator>(const basic_life_string_view& a, const basic_life_string_view& b) noexcept {
        return a.data_ > b.data_;
    }
    friend bool operator>(const basic_life_string_view& a, const CharT* b) noexcept {
        return a.data_ > b;
    }
    friend bool operator>(const CharT* a, const basic_life_string_view& b) noexcept {
        return a > b.data_;
    }
    friend bool operator>=(const basic_life_string_view& a, const basic_life_string_view& b) noexcept {
        return a.data_ >= b.data_;
    }
    friend bool operator>=(const basic_life_string_view& a, const CharT* b) noexcept {
        return a.data_ >= b;
    }
    friend bool operator>=(const CharT* a, const basic_life_string_view& b) noexcept {
        return a >= b.data_;
    }
#endif

    friend std::ostream& operator<<(std::ostream& os, const basic_life_string_view& sv) {
        return os << sv.data_;
    }
};

using life_string_view = basic_life_string_view<char>;
using life_wstring_view = basic_life_string_view<wchar_t>;
using life_u16string_view = basic_life_string_view<char16_t>;
using life_u32string_view = basic_life_string_view<char32_t>;
#if __cplusplus >= 202002L
using life_u8string_view = basic_life_string_view<char8_t>;
#endif

} // namespace life

namespace std {
    template <>
    struct hash<life::life_string_view> {
        std::size_t operator()(const life::life_string_view& sv) const noexcept {
            return std::hash<std::string_view>{}(sv.string_view());
        }
    };
    template <>
    struct hash<life::life_wstring_view> {
        std::size_t operator()(const life::life_wstring_view& sv) const noexcept {
            return std::hash<std::wstring_view>{}(sv.string_view());
        }
    };
    template <>
    struct hash<life::life_u16string_view> {
        std::size_t operator()(const life::life_u16string_view& sv) const noexcept {
            return std::hash<std::u16string_view>{}(sv.string_view());
        }
    };
    template <>
    struct hash<life::life_u32string_view> {
        std::size_t operator()(const life::life_u32string_view& sv) const noexcept {
            return std::hash<std::u32string_view>{}(sv.string_view());
        }
    };
#if __cplusplus >= 202002L
    template <>
    struct hash<life::life_u8string_view> {
        std::size_t operator()(const life::life_u8string_view& sv) const noexcept {
            return std::hash<std::u8string_view>{}(sv.string_view());
        }
    };
#endif
} // namespace std
