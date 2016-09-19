//
// Created by Arthur Anderson on 9/18/16.
//

#ifndef BEARS_DEN_WEAKORDEREDPAIR_H
#define BEARS_DEN_WEAKORDEREDPAIR_H

#include <ostream>

namespace bears_den{
    namespace internal {
        template<typename HighType = int8_t, typename LowType = int8_t>
        struct TWeakOrder {

            HighType high_;
            LowType low_;

            TWeakOrder(HighType high, LowType low) : high_(high), low_(low) {}

            bool operator<(const TWeakOrder<HighType, LowType> &lhs) const {
                return high_ < lhs.high_ || (high_ == lhs.high_ && low_ < lhs.low_);
            }

            bool operator==(const TWeakOrder<HighType, LowType> &lhs) const {
                return high_ == lhs.high_ && low_ == lhs.low_;
            }

            std::ostream& Print(std::ostream &out, char sep) const {
                out << high_ << sep << low_;
                return out;
            }

            std::wostream& Print(std::wostream &out, wchar_t sep) const {
                out << high_ << sep << low_;
                return out;
            }
        };


    }
}

#endif //BEARS_DEN_WEAKORDEREDPAIR_H
