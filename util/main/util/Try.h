/**
 * Created by Hal@shurabaP on 2015/06/06.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef HARUNEKO_TRY_H
#define HARUNEKO_TRY_H

#include <functional>
#include <QString>
#include <QSharedData>
#include "Execption.h"

namespace haruneko {
namespace util {

    /**
     * Try class support some monadic functions.
     * This class has two states, Success and Failure.
     * If an exception was thrown while instantiation,
     * Try will be Failure, otherwise Success.
     */
    template <class A> class Try final {
        std::function<A()> f;
        Try(): f() { }
    public:
        Try(const std::function<Try<A>()> &g): Try([g]() -> A { return g().get(); }) { }
        Try(const std::function<A()> &g) : f(g) { }
        Try(const Try<A> &other) : Try(other.f) { }
        Try<A> &operator=(const Try<A> &other) { this->f = other.f; return *this; }

        static Try<A> success(const A &a)  { return Try([a]() -> A { return a; }); }


        template <class B> Try<B> flatMap(const std::function<Try<B>(A)> &g) const {
            auto _f(f);
            return Try<B>([_f, g]() -> Try<B> { return g(_f()); });
        }

        template <class B> Try<B> map(const std::function<B(A)> &g) const {
            auto _f(f);
            return Try<B>([_f, g]() -> B { return g(_f());});
        }

        A get() const throw(const Exception &)  {
            return f();
        }

        bool isSuccess() const {
            try {
                f();
                return true;
            } catch(...) {
                return false;
            }
        };
        bool isFailure() const {
            return !isSuccess();
        }
    };
}
}

#endif //HARUNEKO_TRY_H
