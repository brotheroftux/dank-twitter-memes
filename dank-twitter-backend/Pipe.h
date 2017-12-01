#ifndef PIPE_H
#define PIPE_H

using namespace std;

template <typename T>
class Pipe {
    T data;
    
public:
    Pipe (T data) : data(data) {}
    
    const T& unpack () const {
        return data;
    }
    
    template <typename F>
    auto operator| (F reducer) const -> Pipe<decltype(reducer(declval<T>()))> {
        auto reduced = reducer(data);
        return Pipe<decltype(reduced)>(reduced);
    }
    
    Pipe<T> operator|| (T & destination) const {
        destination = unpack();
        return *this;
    }
};

template <typename T>
Pipe<T> make_pipe (T data) {
    return Pipe<T>(data);
}

#endif /* PIPE_H */
