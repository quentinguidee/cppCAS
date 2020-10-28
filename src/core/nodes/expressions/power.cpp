#include "power.hpp"

#include "values/integer.hpp"

Power::Power(Expression &base, Expression &power) :
    base(base),
    power(power)
{
}

Power::Power(const Power &power) :
    base(*power.base.clone()),
    power(*power.power.clone())
{
}

/**
 * | Impl.                  | Expr.      | Returns        | Only if...   |
 * |------------------------|------------|----------------|--------------|
 * | Power::simplified()    | b^1        | b              |              |
 * | Power::simplified()    | b^0        | 1              |              |
 * | ~                      | b^(m+n)    | b^m . b^n      | m,n∈ℤ+       |
 * | ~                      | (b^m)^n    | b^(mn)         | b≠0, m,n∈ℤ   |
 * | ~                      | (bc)^n     | b^n . c^n      | b,c∈ℤ0, n∈ℤ  |
 * | ~                      | (bc)^n     | b^n . c^n      | b,c∈ℝ0+, n∈ℝ |
 * | Power::simplified()    | 0^n        | 0              | n∈ℝ0+        |
 * | Power::simplified()    | 0^0        | 1              |              |
 * | Power::simplified()    | 0^n        | undef          | n∈ℝ0-        |
 * | Power::simplified()    | 1^n        | 1              |              |
 * | ~                      | abs(x)^p   | x^p            | p is even    |
 */
Expression *Power::simplified() const
{
    if (power.isZero())
    {
        return new Integer(1);
    }
    else if (power.isOne())
    {
        return base.clone();
    }
    else if (base.isZero())
    {
        if (power.isStrictlyPositive())
        {
            return new Integer(0);
        }
        else if (power.isZero())
        {
            return new Integer(1);
        }
        else
        {
            // = UNDEFINED
            throw TODO();
        }
    }
    else if (base.isOne())
    {
        return new Integer(1);
    }
    return base._power(*power.clone());
}

std::string Power::toString() const
{
    return base.toString() + "^" + power.toString();
}

std::string Power::toLaTeX() const
{
    return "{" + base.toLaTeX() + "}^{" + power.toLaTeX() + "}";
}

bool Power::isPositive() const
{
    if (base.isPositive())
    {
        return true;
    }
    else if (base.isNegative() && power.isEven())
    {
        return true;
    }
    return false;
}

bool Power::isNegative() const
{
    if (isZero())
    {
        return true;
    }
    else if (base.isNegative() && power.isOdd())
    {
        return true;
    }
    return false;
}
