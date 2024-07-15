#pragma once

#include <cstddef>
#include <memory>
#include <string_view>
#include <utility>

#if __cplusplus >= 202002L
#include <compare>
#endif

namespace life {

class life_string_view {
    std::string_view data_;
    std::shared_ptr<void> life_;
public:
    using traits_type = std::string_view::traits_type;
    using value_type = std::string_view::value_type;
    using pointer = std::string_view::pointer;
    using const_pointer = std::string_view::const_pointer;
    using reference = std::string_view::reference;
    using const_reference = std::string_view::const_reference;
    using const_iterator = std::string_view::const_iterator;
    using iterator = const_iterator;
    using const_reverse_iterator = std::string_view::const_reverse_iterator;
    using reverse_iterator = const_reverse_iterator;
    using size_type = std::string_view::size_type;
    using difference_type = std::string_view::difference_type;
    static constexpr size_type npos = std::string_view::npos;

    life_string_view(std::string_view sv)
        : data_{sv}, life_{} {}
    life_string_view(std::string_view sv, std::shared_ptr<void> life)
        : data_{sv}, life_{life} {}

    template <class T>
    static life_string_view allocate(T&& data) {
        auto p = std::make_shared<T>(std::forward<T>(data));
        return {*p, p};
    }

    std::string_view string_view() const noexcept {
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
    void swap(life_string_view& sv) noexcept {
        data_.swap(sv.data_);
        life_.swap(sv.life_);
    }
    friend void swap(life_string_view& a, life_string_view& b) noexcept {
        a.swap(b);
    }

    size_type copy(char* s, size_type n, size_type pos = 0) const {
        return data_.copy(s, n, pos);
    }
    life_string_view substr(size_type start = 0, size_type n = npos) const {
        return {data_.substr(start, n), life_};
    }
    int compare(life_string_view sv) const noexcept {
        return data_.compare(sv.data_);
    }
    int compare(size_type pos1, size_type n1, life_string_view sv) const {
        return data_.compare(pos1, n1, sv.data_);
    }
    int compare(size_type pos1, size_type n1, life_string_view sv, size_type pos2, size_type n2) const {
        return data_.compare(pos1, n1, sv.data_, pos2, n2);
    }
    int compare(const char* s) const {
        return data_.compare(s);
    }
    int compare(size_type pos1, size_type n1, const char* s) const {
        return data_.compare(pos1, n1, s);
    }
    int compare(size_type pos1, size_type n1, const char* s, size_type n2) const {
        return data_.compare(pos1, n1, s, n2);
    }
#if __cplusplus >= 202002L
    bool starts_with(life_string_view x) const noexcept {
        return data_.starts_with(x.data_);
    }
    bool starts_with(char x) const noexcept {
        return data_.starts_with(x);
    }
    bool starts_with(const char* x) const {
        return data_.starts_with(x);
    }
    bool ends_with(life_string_view x) const noexcept {
        return data_.ends_with(x.data_);
    }
    bool ends_with(char x) const noexcept {
        return data_.ends_with(x);
    }
    bool ends_with(const char* x) const {
        return data_.ends_with(x);
    }
#endif
#if __cplusplus >= 202302L
    bool contains(life_string_view x) const noexcept {
        return data_.contains(x.data_);
    }
    bool contains(char x) const noexcept {
        return data_.contains(x);
    }
    bool contains(const char* x) const {
        return data_.contains(x);
    }
#endif

    size_type find(life_string_view sv, size_type pos = 0) const noexcept {
        return data_.find(sv.data_, pos);
    }
    size_type find(char c, size_type pos = 0) const noexcept {
        return data_.find(c, pos);
    }
    size_type find(const char* s, size_type pos, size_type n) const {
        return data_.find(s, pos, n);
    }
    size_type find(const char* s, size_type pos = 0) const {
        return data_.find(s, pos);
    }
    size_type rfind(life_string_view s, size_type pos = npos) const noexcept {
        return data_.rfind(s.data_, pos);
    }
    size_type rfind(char c, size_type pos = npos) const noexcept {
        return data_.rfind(c, pos);
    }
    size_type rfind(const char* s, size_type pos, size_type n) const {
        return data_.rfind(s, pos, n);
    }
    size_type rfind(const char* s, size_type pos = npos) const {
        return data_.rfind(s, pos);
    }
    size_type find_first_of(life_string_view sv, size_type pos = 0) const noexcept {
        return data_.find_first_of(sv.data_, pos);
    }
    size_type find_first_of(char c, size_type pos = 0) const noexcept {
        return data_.find_first_of(c, pos);
    }
    size_type find_first_of(const char* s, size_type pos, size_type n) const {
        return data_.find_first_of(s, pos, n);
    }
    size_type find_first_of(const char* s, size_type pos = 0) const {
        return data_.find_first_of(s, pos);
    }
    size_type find_last_of(life_string_view sv, size_type pos = npos) const noexcept {
        return data_.find_last_of(sv.data_, pos);
    }
    size_type find_last_of(char c, size_type pos = npos) const noexcept {
        return data_.find_last_of(c, pos);
    }
    size_type find_last_of(const char* s, size_type pos, size_type n) const {
        return data_.find_last_of(s, pos, n);
    }
    size_type find_last_of(const char* s, size_type pos = npos) const {
        return data_.find_last_of(s, pos);
    }
    size_type find_first_not_of(life_string_view sv, size_type pos = 0) const noexcept {
        return data_.find_first_not_of(sv.data_, pos);
    }
    size_type find_first_not_of(char c, size_type pos = 0) const noexcept {
        return data_.find_first_not_of(c, pos);
    }
    size_type find_first_not_of(const char* s, size_type pos, size_type n) const {
        return data_.find_first_not_of(s, pos, n);
    }
    size_type find_first_not_of(const char* s, size_type pos = 0) const {
        return data_.find_first_not_of(s, pos);
    }
    size_type find_last_not_of(life_string_view sv, size_type pos = npos) const noexcept {
        return data_.find_last_not_of(sv.data_, pos);
    }
    size_type find_last_not_of(char c, size_type pos = npos) const noexcept {
        return data_.find_last_not_of(c, pos);
    }
    size_type find_last_not_of(const char* s, size_type pos, size_type n) const {
        return data_.find_last_not_of(s, pos, n);
    }
    size_type find_last_not_of(const char* s, size_type pos = npos) const {
        return data_.find_last_not_of(s, pos);
    }

    friend bool operator==(life_string_view a, life_string_view b) noexcept {
        return a.data_ == b.data_;
    }
    friend bool operator==(life_string_view a, const char* b) noexcept {
        return a.data_ == b;
    }
#if __cplusplus < 202002L
    friend bool operator==(const char* a, life_string_view b) noexcept {
        return a == b.data_;
    }
    friend bool operator!=(life_string_view a, life_string_view b) noexcept {
        return a.data_ != b.data_;
    }
    friend bool operator!=(life_string_view a, const char* b) noexcept {
        return a.data_ != b;
    }
    friend bool operator!=(const char* a, life_string_view b) noexcept {
        return a != b.data_;
    }
#endif

#if __cplusplus >= 202002L
    friend auto operator<=>(life_string_view a, life_string_view b) noexcept {
        return a.data_ <=> b.data_;
    }
    friend auto operator<=>(const life_string_view& a, const char* b) noexcept {
        return a.data_ <=> b;
    }
#else
    friend bool operator<(life_string_view a, life_string_view b) noexcept {
        return a.data_ < b.data_;
    }
    friend bool operator<(const life_string_view& a, const char* b) noexcept {
        return a.data_ < b;
    }
    friend bool operator<(const char* a, const life_string_view& b) noexcept {
        return a < b.data_;
    }
    friend bool operator<=(life_string_view a, life_string_view b) noexcept {
        return a.data_ <= b.data_;
    }
    friend bool operator<=(const life_string_view& a, const char* b) noexcept {
        return a.data_ <= b;
    }
    friend bool operator<=(const char* a, const life_string_view& b) noexcept {
        return a <= b.data_;
    }
    friend bool operator>(life_string_view a, life_string_view b) noexcept {
        return a.data_ > b.data_;
    }
    friend bool operator>(const life_string_view& a, const char* b) noexcept {
        return a.data_ > b;
    }
    friend bool operator>(const char* a, const life_string_view& b) noexcept {
        return a > b.data_;
    }
    friend bool operator>=(life_string_view a, life_string_view b) noexcept {
        return a.data_ >= b.data_;
    }
    friend bool operator>=(const life_string_view& a, const char* b) noexcept {
        return a.data_ >= b;
    }
    friend bool operator>=(const char* a, const life_string_view& b) noexcept {
        return a >= b.data_;
    }
#endif

    friend std::ostream& operator<<(std::ostream& os, life_string_view sv) {
        return os << sv.data_;
    }
};

} // namespace life

namespace std {
    template <>
    struct hash<life::life_string_view> {
        std::size_t operator()(life::life_string_view sv) const noexcept {
            return std::hash<std::string_view>{}(sv.string_view());
        }
    };
} // namespace std
