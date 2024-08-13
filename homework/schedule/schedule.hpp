#include <functional>
#include <chrono>
#include <thread>

template<typename Func, typename... Args>
void schedule(Func func, std::chrono::seconds dur, Args... args) {
    if (dur > std::chrono::seconds(0)) {
        std::this_thread::sleep_for(dur);
    }
    std::invoke(func, std::forward<Args>(args)...);
}