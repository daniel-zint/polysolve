#pragma once

#include "Newton.hpp"
#include "Utils.hpp"

#include <polysolve/linear/Solver.hpp>

namespace polysolve::nonlinear
{
    class DenseNewton : public Newton
    {
    public:
        using Superclass = Newton;
        using typename Superclass::Scalar;
        using typename Superclass::TVector;

        DenseNewton(const json &solver_params,
                    const json &linear_solver_params,
                    const double dt, const double characteristic_length,
                    spdlog::logger &logger);

        std::string name() const override { return "DenseNewton"; }

    protected:
        double solve_linear_system(Problem &objFunc,
                                   const TVector &x, const TVector &grad,
                                   TVector &direction) override;
    };

} // namespace polysolve::nonlinear
