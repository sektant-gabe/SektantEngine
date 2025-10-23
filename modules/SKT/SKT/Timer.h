#pragma once

#include <chrono>

namespace SKT {

//----------------------------------------------------------------------------/
// A framework that relates a time point to real physical time
using clock = std::chrono::high_resolution_clock;
// A reference to a specific point in time, like one's birthday, etc
//  high_resolution_clock is the clock with the shortest tick period
using timePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
// Durations measure time spans, like one minute, two hours, ten ms
using floatSeconds = std::chrono::duration<float>;
//----------------------------------------------------------------------------/

class ScopeTimer
{
public:
    ScopeTimer(const ScopeTimer &)            = default;
    ScopeTimer(ScopeTimer &&)                 = delete;
    ScopeTimer &operator=(const ScopeTimer &) = default;
    ScopeTimer &operator=(ScopeTimer &&)      = delete;
    explicit ScopeTimer(float *output) : StartTime(clock::now()), RetVal(output) {}
    ~ScopeTimer()
    {
        EndTime                    = SKT::clock::now();
        SKT::floatSeconds duration = EndTime - StartTime;
        *RetVal                    = duration.count();
    }

private:
    SKT::timePoint StartTime;
    SKT::timePoint EndTime;
    float         *RetVal;
};
}// namespace SKT
