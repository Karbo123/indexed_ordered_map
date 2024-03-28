#pragma once

#include "orbtree.h"

namespace indexed {
template <typename TypeKey, typename TypeVal> struct WeightOne {
    using argument_type = std::pair<TypeKey, TypeVal>;
    using result_type = std::size_t;
    constexpr result_type operator()(const argument_type &p) const { return 1; }
};

template <typename TypeKey, typename TypeVal, typename Compare = std::less<TypeKey>>
struct ordered_map : public orbtree::simple_mapC<TypeKey, TypeVal, WeightOne<TypeKey, TypeVal>, uint32_t, Compare> {
    auto index(std::size_t i) { return this->lower_bound_rank(i); }
};

} // namespace indexed