#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <string>
#include "units.h"
namespace ProvisiList
{
class Ingredient
{
private:
    std::string m_name;
    double m_quantity;
    UnitOfMeasurement m_unit;

public:
    Ingredient(const std::string name, double quantity, UnitOfMeasurement unit) :
        m_name(name),
        m_quantity(quantity),
        m_unit(unit)
    {}

    void Set_Quantity(double quantity) {m_quantity = quantity;}
    void Set_Unit_Of_Measurement(UnitOfMeasurement unit){m_unit = unit;}

    std::string Get_Name() const {return m_name;}
    double Get_Quantity() const {return m_quantity;}
    UnitOfMeasurement Get_Unit_Of_Measurement() const {return m_unit;}
};
}
#endif // INGREDIENT_H
